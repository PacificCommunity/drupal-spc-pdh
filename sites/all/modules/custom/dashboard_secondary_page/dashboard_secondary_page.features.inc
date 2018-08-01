<?php
/**
 * @file
 * dashboard_secondary_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dashboard_secondary_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dashboard_secondary_page_node_info() {
  $items = array(
    'dsp' => array(
      'name' => t('Dashboard Secondary Page'),
      'base' => 'node_content',
      'description' => t('Provides content type for dashboard secondary pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
