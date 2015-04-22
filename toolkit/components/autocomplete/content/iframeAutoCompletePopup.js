/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

const {classes: Cc, interfaces: Ci, utils: Cu} = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");
Cu.import("resource://gre/modules/WebChannel.jsm");

Services.console.logStringMessage('inside mypopup js file woot!');

function MyPopup() {
  Services.console.logStringMessage('inside mypopup js constructor yeah!');
  this.controller = Cc["@mozilla.org/autocomplete/controller;1"].getService(Ci.nsIAutoCompleteController);
  // the XBL popup adds handlers for: searchbegin, searchcomplete, textentered, textreverted
  // the XBL popup also says "for security reasons delay searches on pasted values". wat?

  // XBL popup creates a <panel type="autocomplete" noautofocus="true"> element and makes it the
  // child of the element with anonid="popupset"
  // regardless of the XBL bindings, we do need to attach to an input at this point
  this.popup = document.getElementById("MyPopupAutoCompleteRichResult");


  // XBL does a lot of stuff with this.inputField, but I'm not sure where it is set.
  // TODO: do we need to "insertControllerAt()" to link this JS code with the urlbar?
  this.input = gURLBar.inputField;

  // XXX finally, something new: init iframe, init webchannel on frame load
  this.browser = document.getElementById("yaywut");
  var prefBranch = Cc["@mozilla.org/preferences-service;1"].getService(Ci.nsIPrefService).getBranch("");
  // TODO replace remote default frame location with browser-local chrome:// frame location
  this.frameURL = prefBranch.getPrefType('services.universalSearch.frameURL') ?
                   prefBranch.getCharPref('services.universalSearch.frameURL') : 'http://localhost/iframe.html';
  this.frameBaseURL = prefBranch.getPrefType('services.universalSearch.baseURL') ?
                       prefBranch.getCharPref('services.universalSearch.baseURL') : 'http://localhost';

  // TODO: constructor might be fired multiple times, XBL is weird.
  // 1. load the frame in the browser.
  // 2. init the webchannel connection to the browser frame.
  if (!this.initialized) {
    this.browser.addEventListneer('load', this._onBrowserLoaded.bind(this), true);
    this.browser.setAttribute('src', this.frameURL + "?cachebust=" + Date.now());
    this.initialized = true;
  }
};
MyPopup.prototype = {
  maxResults: 6,
  channel: null,
  frameURL: null,
  frameBaseURL: null,
  channelListener: function(id, msg, sender) {
    if (id !== this.channelId) { return; }
    if (msg.type == 'autocomplete-url-clicked') {
      // TODO handle click event
    }
  },
  _initChannel: function() {
    this.channelId = "ohai";
    this.browser.messageManager.loadFrameScript('chrome://browser/content/content.js', true);
    this.channel = new WebChannel(this.channelId, Services.io.newURI(this.frameBaseURL, null, null));
    this.channel.listen(this.channelListener.bind(this)); // TODO bind needed?
  },
  _onBrowserLoaded: function() {
    this.browser.removeEventListener('load', this._onBrowserLoaded.bind(this), true);
    this._initChannel();
  },

  // nsIAutoCompletePopup
  input: null,
  frameReady: false,
  popupOpen: false, // TODO getter/setter with iframe passthru?
  selectedIndex: -1, // TODO setter should fire 'selected' message to the iframe
  selectBy: function(reverse, page) {
    if (reverse) {
      this.selectedIndex = (this.selectedIndex === 0) ? 0 : this.selectedIndex - 1;
    } else if (page) {
      // we will only have one page ever, so just jump to the end
      this.selectedIndex = Math.min(this.controller.matchCount, this.maxResults);
    }
  },
  invalidate: function() {
    if (!this.popupOpen) { return; }
    var matchCount = Math.min(this.controller.matchCount, this.maxResults);
    if (!matchCount) {
      // XXX setting selectedIndex will fire a 'selectedIndex' msg down to iframe
      this.selectedIndex = -1;
      // hide when there's no matches
      this.popupOpen = false;
      return;
    }
    var results = [];
    for (var i = 0; i < matchCount; i++) {
      results.push({
        url: Cc["@mozilla.org/intl/texttosuburi;1"].getService(Ci.nsITextToSubURI).
             unEscapeURIForUI("UTF-8", this.controller.getValueAt(i)),
        image: null, // TODO _getImageURLForResolution
        title: this.controller.getCommentAt(i),
        type: this.controller.getStyleAt(i),
        text: this.controller.searchString.trim()
      });
    }
    // TODO send to the iframe
  },
  openAutocompletePopup: function(aInput, aElement) {
    // largely copied from the rich-result-popup _openAutocompletePopup method
    if (this.popupOpen) { return; }
    this.input = aInput;
    // "clear any previous selection, see bugs 400671 and 488357" - from XBL
    this.selectedIndex = -1;
    this.invalidate();
    this.popup.openPopup(aElement, "after_start", 0, 0, false, false);
  },
  closePopup: function() {
    this.popupOpen = false;
    this.popup.hidePopup(); // XUL built-in method
  }
};

// TODO: do I need to do anything else with this JS object? attach it to something? declare something somewhere?
