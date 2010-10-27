<?php
// $Id: station_log.admin.inc 216 2010-10-26 05:28:36Z cmk $

function station_log_admin_settings() {
  // Get the first web stream found to set the default shoutcast history url
  $default_schedule_nid = variable_get('station_schedule_default', 0);
}
