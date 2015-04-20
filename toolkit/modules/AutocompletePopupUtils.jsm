/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
 * This code holds a new tab-like experience we are experimentally putting in
 * the autocomplete popup when the urlbar is empty, instead of the current browser
 * implementation, which hides the popup when the urlbar is empty.
 */

// jsm extraction todo list:
// - make SearchRecord a true constructor, since this could be invoked multiple times
// - move _data inside SearchRecord: it should be an instance property
//   - actually, data should too (the results per-request)
// - what symbols are we going to export, exactly? figure it out.



this.EXPORTED_SYMBOLS = ['AutocompletePopupUtils'];

const {classes: Cc, interfaces: Ci, utils: Cu} = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/PlacesUtils.jsm");
Cu.import("resource://gre/modules/Promise.jsm");
Cu.import("resource://gre/modules/Services.jsm");

// welp. here comes the Promise boilerplate.

// here's our data structure shared among the promise keepers
// searchRecords = { <visitId>: { query: <visit>, isFinalResult: boolean, result: <visit> or null } }
// where <visitId> is the integer visitId
// and <visit> is a mashup of moz_places and moz_historyviews:
//     <visit> := { visitId, fromVisit, title, url }
// and isFinalResult is only true if we've gotten to a content page, not on a search provider website
var isDoingSomething = false;
var _data = {};
var searchRecords = {
  _extractSearchTerms: function(searchURL) {
    // input: https://www.google.com/?q=foo+bar&blah
    // output: "foo bar"

    if (!searchURL) return;

    // match on q=stuff, up to an '&' or the end of the string
    var query = searchURL.match(/q=(.*)(&|$)/);

    // regexp will return null if no match.
    // in that case, just return whatever we started with,
    // it's better than nothing.
    if (!query) { return searchURL; }

    // string.replace with 'g' flag gets a thumbs down from MDN, so:
    return decodeURIComponent(query[1].split('+').join(' '));
  },
  addQuery: function(id, url, title, visitId) {
    var result = {
      id: id,
      url: url,
      title: title,
      searchTerms: title && this._extractSearchTerms(title),
      visitId: visitId
    };
    _data[id] = { query: result, result: null, isFinalResult: false };
  },
  getInitialVisitIDs: function() {
    var results = [];
    for (var item in _data) {
      results.push(_data[item].query.visitId);
    }
    return Promise.resolve(results);
  },
  getQueryByVisitId: function(visitId) {
    for (var item in _data) {
      // for our purposes, we don't care if the previous item was a query or an intermediate result page.
      // in either case, we will assign a new result. so return the item.
      if (_data[item].query.visitId === visitId || (_data[item].result && _data[item].result.visitId === visitId)) {
        return _data[item];
      }
    }
  },
  setResult: function(queryVisitId, resultId, resultUrl, resultTitle, resultVisitId) {
    var isResult = false;
    // find the item with that visit id, could be the initial query or the initial result, which we will overwrite
    var search = this.getQueryByVisitId(queryVisitId);

    // if that failed, try the other way
    //search = this.getQueryByVisitId(resultVisitId);
    if (!search) {
      return;
    }

    // set its result
    search.result = {
      id: resultId,
      url: resultUrl,
      title: resultTitle,
      visitId: resultVisitId
    };
    // stupidly assume we're done when we leave your search provider
    // stupidly assume we've left your search provider when the name doesn't match the url
    // TODO: do better about handling other cases, like you started a new search with
    //       a different search phrase
    // XXX for starters, assuming google or yahoo is your search provider
    var matches = {
      // seems like google results or interstitial pages could be any of:
      // google.com/url (interstitial / redirect page)
      // google.com/search, google.com/?, google.com/webhp?
      google: /google\.com\/(search|url|webhp|\?)/,
      yahoo: /search\.yahoo\.com/
    };
    var searchEngineName = Services.search.defaultEngine.name.toLowerCase();
    var searchDomainRegex = matches[searchEngineName];
    search.isFinalResult = !resultUrl.match(searchDomainRegex);
  },
  getIncompleteVisitIDs: function() {
    // return the query visit IDs where the current result is a search-related page, not a content page
    var incompleteItems = [];
    for (var item in _data) {
      if (_data[item].result && !_data[item].isFinalResult) {
        incompleteItems.push(_data[item].result.visitId);
      }
    }
    return Promise.resolve(incompleteItems);
  },
  getCompletedSearches: function() {
    var donezo = [];
    for (var item in _data) {
      if (_data[item].isFinalResult) {
        donezo.push(_data[item])
      }
    }
    return donezo;
  }
};

// meanwhile, what we send to the front-end will just be:
// { searchEngineName, searches: [ { searchQuery, response: { url, title, favicon } }, ... ] }

var onError = function(err) {
  isRunning = false;
  return Promise.reject(err); // TODO is this correct? or do I just return?
};

var getRecentSearches = function(db) {
  try {
    // first, grab the search provider's default url, minus the query string
    // for example, for google en-US this is "https://www.google.com/search?q=&ie=utf-8&oe=utf-8"
    // the cheapest way: url.split('?')[0].
    // (TODO the right way: nsIURL something-or-other...)
    var searchPage = Services.search.defaultEngine.searchForm;
    var searchURL = searchPage.split('?')[0];
    // sqlite syntax: LIKE "foo%" means "starts with foo"
    var likeSearchURL = searchURL + '%'; 
    // ok, now grab the most recent 50 history items with that URL.
    // we need to grab a lot of items because these searches may not have led
    // to a result page - for instance, if the person doesn't like results and
    // types a new query into the search bar.
    var recentSearchesQuery = 'SELECT p.id, p.url, p.title, v.id AS visitId ' +
      'FROM moz_places p, moz_historyvisits v ' +
      'WHERE p.id = v.place_id AND p.url LIKE :engineURL ' +
      'ORDER BY v.visit_date DESC LIMIT 100;';
    recentSearchesQuery = recentSearchesQuery.replace(":engineURL", '"' + likeSearchURL + '"');
    return db.execute(recentSearchesQuery);
  } catch (ex) {
    return Promise.reject(ex);
  }
};

// the DB returns us some kind of funky wrapped XPCOM object.
// but we need to actually do stuff with the rows. So, convert
// them into an array, and pass that down the promise chain.
var processRecentSearches = function(recentSearches) {
  var processed = [];
  try {
    recentSearches.forEach(function(r) {
      searchRecords.addQuery(
        r.getResultByName('id'),
        r.getResultByName('url'),
        r.getResultByName('title'),
        r.getResultByName('visitId')
      );
    });
    // TODO: do we reject if there were no results?
    return Promise.resolve();
  } catch (ex) {
    return Promise.reject(ex);
  }
};

var getNextVisits = function(visitIDs) {
  try {
    // if no visit IDs were passed in, then maybe we were done on the first hop
    // and this is the second hop; just return an empty array, rather than throw
    if (!visitIDs || !visitIDs.length) { return Promise.resolve([]); }

    // find page visits which have the supplied visit IDs as referrers
    var nextStepQuery = "SELECT p.id, p.url, p.title, v.id as visitId, v.from_visit as fromVisit " +
      "FROM moz_places p, moz_historyvisits v " +
      "WHERE p.id = v.place_id AND v.from_visit IN :searches;";
    nextStepQuery = nextStepQuery.replace(':searches', '(' + visitIDs.join(', ') + ')');
    //TODO: do we have to manually shut down the PlacesUtils DB connections?
    // TODO: not sure why, but I can't just pass the stringified array into the query.
    //       I have to manually do the substitution. Why?
    return PlacesUtils.promiseDBConnection().then(function(db) {
      return db.execute(nextStepQuery);
    });
  } catch (ex) {
    return Promise.reject(ex);
  }
};

var processResultPages = function(rows) {
  try {
    rows.forEach(function(p) {
      // fromVisit is how we get back to the original item
      // in the case of multiple hops, we overwrite the previous result

      // actually, the above seems to be wrong! I think I swapped it!
      searchRecords.setResult(
        p.getResultByName('fromVisit'),
        p.getResultByName('id'),
        p.getResultByName('url'),
        p.getResultByName('title'),
        p.getResultByName('visitId')
      );
    });
    isRunning = false; // unset our horrible global state tracker
    var finalResults = searchRecords.getCompletedSearches();
    return Promise.resolve(finalResults);
  } catch(ex) {
    return Promise.reject(ex);
  }
};

var isRunning = false;
var AutocompletePopupUtils = {};
AutocompletePopupUtils.getRecentSearches = function() {

  // first, get a list of recent searches.
  // then, for each search, look at the next hop in the visits DB.
  // if that next hop URL doesn't match the search engine URL, we're done.
  // for the remainder, we try a second hop.
  // give up after 2 hops, for now.
  // finally, send over the subset of the data that the front-end can use.

  // get some recent searches, look 2 hops down the referrer chain
  // via the Places DB from_visit pointer, and send down the searches
  // where a non-search page was reached by the second hop

  // TODO: how to cleanly handle throttling?
  if (isRunning) {
    return Promise.reject('sorry, already running'); 
  } else {
    isRunning = true;

  return PlacesUtils.promiseDBConnection()
    .then(getRecentSearches, onError)
    .then(processRecentSearches, onError)
    .then(searchRecords.getInitialVisitIDs, onError) // returns a Promise-wrapped list of search visit IDs
    .then(getNextVisits, onError)
    .then(processResultPages, onError)
    .then(searchRecords.getIncompleteVisitIDs, onError) // returns a Promise-wrapped list of unfinished searches
    .then(getNextVisits, onError)
    .then(processResultPages, onError);
  }
};
