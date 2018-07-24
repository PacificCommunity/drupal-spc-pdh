<?php
/**
 * @file
 * data_insights_content_type.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function data_insights_content_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_insights|data_insights_on_topic_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_insights';
  $ds_layout->view_mode = 'data_insights_on_topic_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_data_insights_preview',
      ),
    ),
    'fields' => array(
      'field_data_insights_preview' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|data_insights|data_insights_on_topic_page'] = $ds_layout;

  return $export;
}
