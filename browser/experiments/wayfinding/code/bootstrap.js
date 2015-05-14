let {classes: Cc, interfaces: Ci, utils: Cu} = Components;

Cu.import("resource:///modules/experiments/Experiments.jsm");
XPCOMUtils.defineLazyModuleGetter(this, "resource://gre/modules/TelemetryLog.jsm");

//TODO made-up Telemetry keys, define this someplace
const TELEMETRY_LOG_KEYS = {
  
  
};

function startup(data, reasonCode) {
  // grab the places service
  // grab the telemetry log service
  // TODO do we need to define the telemetry key somewhere?
  // init the experiment:
    // grab the Experiments object or whatever
    // decide which branch of the experiment we are in
  // actual contents of experiment:
    // check if the user has 30 days of data, if not, bail
      // TODO: even if they don't have 30 days of data, how many days do they have?
    // check how many visits total,
    // how many searches total,
    // shove this in the telemetry pipe and be done.
}
function shutdown() {}
function install() {}
function uninstall() {}
