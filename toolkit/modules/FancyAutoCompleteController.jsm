/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const { classes: Cc, interfaces: Ci, utils: Cu } = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");
Cu.import("resource://gre/modules/Log.jsm");



this.EXPORTED_SYMBOLS = ["FancyAutoCompleteController"];


function FancyAutoCompleteController() {};
// TODO: XBL sends over a pointer to the iframe, can we use WebChannel from here instead
// of from XBL?
FancyAutoCompleteController.prototype = {
  // XBL sends over an event. Let's see what we see.
  onKeyPress: function(aEvent) {
    debugger;
  }
};
