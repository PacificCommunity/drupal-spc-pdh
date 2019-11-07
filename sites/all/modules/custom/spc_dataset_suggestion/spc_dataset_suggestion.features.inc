<?php

/**
 * @file
 * spc_dataset_suggestion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function spc_dataset_suggestion_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function spc_dataset_suggestion_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function spc_dataset_suggestion_node_info() {
  $items = array(
    'dataset_suggestion' => array(
      'name' => t('Dataset Suggestion'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Dataset Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
