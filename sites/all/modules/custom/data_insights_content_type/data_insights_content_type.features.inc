<?php

/**
 * @file
 * data_insights_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function data_insights_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function data_insights_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function data_insights_content_type_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F d, Y'] = 'F d, Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function data_insights_content_type_date_format_types() {
  $format_types = array();
  // Exported date format type: insights_date_format
  $format_types['insights_date_format'] = 'Insights date format';
  return $format_types;
}

/**
 * Implements hook_node_info().
 */
function data_insights_content_type_node_info() {
  $items = array(
    'data_insights' => array(
      'name' => t('Data Insights'),
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
