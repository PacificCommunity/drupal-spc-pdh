<?php

/**
 * @file
 * spc_content_editing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function spc_content_editing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
