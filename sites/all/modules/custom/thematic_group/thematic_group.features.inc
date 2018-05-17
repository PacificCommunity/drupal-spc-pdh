<?php
/**
 * @file
 * thematic_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function thematic_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function thematic_group_node_info() {
  $items = array(
    'thematic_group' => array(
      'name' => t('Thematic group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
