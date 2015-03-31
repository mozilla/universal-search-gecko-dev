/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const { classes: Cc, interfaces: Ci, utils: Cu } = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");


this.EXPORTED_SYMBOLS = ["FancyAutoCompleteController"];


this.FancyAutoCompleteController = function FancyAutoCompleteController() {
  var aConsoleService = Components.classes["@mozilla.org/consoleservice;1"].
       getService(Components.interfaces.nsIConsoleService);
  aConsoleService.logStringMessage('FancyAutoCompleteController constructor invoked');
};
this.FancyAutoCompleteController.prototype = {};
