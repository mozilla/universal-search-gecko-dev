/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const { classes: Cc, interfaces: Ci, utils: Cu } = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");
Cu.import("resource://gre/modules/Log.jsm");
Cu.import("resource://gre/modules/WebChannel.jsm");

this.EXPORTED_SYMBOLS = ["UniversalSearch"];

var UniversalSearch = {
  USearchAutoCompletePopup: USearchAutoCompletePopup,
  USearchAutoCompleteInput: USearchAutoCompleteInput,
  USearchAutoCompleteController: USearchAutoCompleteController
};

// implements nsIAutoCompletePopup
var USearchAutoCompletePopup = function() {};
USearchAutoCompletePopup.prototype = {
  input: /* nsIAutoCompleteInput */ null,
  overrideValue: '',
  selectedIndex: 0,
  popupOpen: false,

  openAutoCompletePopup: function(/* nsIAutoCompleteInput */ input, /* nsIDOMElement */ element) {},
  closePopup: function() {},
  invalidate: function() {},
  selectBy: function(/* boolean */ reverse, /* boolean */page) {}
};

var USearchAutoCompleteController = function(iframe) {
  // TODO: XBL sends over a pointer to the iframe, can we use WebChannel from here instead
  // of from XBL? seems like yes
  this._iframe = iframe;
};

USearchAutoCompleteController.prototype = {
  // XBL sends over an event. Let's see what we see.
  onKeyPress: function(aEvent) {
    debugger;
  }

  /********************* start of nsIAutoCompleteController interface *************/

  // properties:
  input: null, // nsIAutoCompleteInput
  searchStatus: Ci.nsIAutoCompleteController.STATUS_NONE, // none, searching, complete_no_match, complete_match
  matchCount: 0,
  searchString: '',
  
  // methods:
  startSearch: function(searchString) {},
  stopSearch: function() {},
  handleText: function() {}, // see extensive comments in IDL
  handleEnter: function(isPopupSelection) {}, // returns boolean
  handleEscape: function() {}, // returns boolean
  handleStartComposition: function() {},
  handleEndComposition: function() {},
  handleTab: function() {},
  handleKeyNavigation: function(key) {}, // returns boolean
  handleDelete: function() {}, // returns boolean
  getValueAt: function(index) {}, // returns string
  getLabelAt: function(index) {}, // returns string
  getCommentAt: function(index) {}, // returns string
  getStyleAt: function(index) {}, // returns string, the "style hint" for the selected item
  getImageAt: function(index) {}, // returns string, the url for the image
  getFinalCompleteValue: function(index) {}, // returns another string

  /********************* end of nsIAutoCompleteController interface ***************/
};

// implements nsIAutoCompleteInput
var USearchAutoCompleteInput = function() {};
USearchAutoCompleteInput.prototype = {
  popup: null, // nsIAutoCompletePopup
  controller: null, // nsIAutoCompleteController
  popupOpen: false,
  disableAutoComplete: false, // disable autocomplete functionality
  completeDefaultIndex: false,
  completeSelectedIndex: false,
  forceComplete: false,
  minResultsForPopup: 3,
  maxRows: 10,
  showCommentColumn: true, // show a second column containing the comment for each autocomplete result
  showImageColumn: true, // show a third column containing an additional image for each autocomplete result
  timeout: 20, // msec to wait after typing before starting autocomplete search
  searchParam: '', // ??
  searchCount: 1, // ?? "number of autocomplete session to search"
  textValue: null, // text in the autocomplete textbox
  selectionStart: null, // starting index of the cursor in the textbox
  selectionEnd: null, // ending index of the cursor in the textbox
  consumeRollupEvent: true, // consume (true) or dispatch (false) the rollup event
  inPrivateContext: false, // r we privat browsin?
  noRollupOnCaretMove: true,

  // methods return nothing unless otherwise noted
  selectTextRange: function (startIndex, endIndex) {},
  onSearchBegin: function() {},
  onSearchComplete: function() {},
  onTextEntered: function() {}, // return true if user wants to prevent the enter
  onTextReverted: function() {}, // return true if user wants to prevent the revert
  getSearchAt: function(index) {}
};
