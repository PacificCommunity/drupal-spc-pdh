<?php

/**
 * @file
 * general_modules.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function general_modules_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
}
