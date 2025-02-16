<?php

/**
 * @file
 * dashboard_secondary_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dashboard_secondary_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dsp|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dsp';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|dsp|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dashboard_secondary_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dsp|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dsp';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_body',
        1 => 'field_dsp_icon',
        2 => 'title',
        3 => 'body',
        4 => 'field_dsp_targets',
      ),
    ),
    'fields' => array(
      'group_body' => 'ds_content',
      'field_dsp_icon' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_dsp_targets' => 'ds_content',
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
  $export['node|dsp|default'] = $ds_layout;

  return $export;
}
