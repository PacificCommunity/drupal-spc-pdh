<?php

/**
 * @file
 * dotstat_charts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dotstat_charts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
