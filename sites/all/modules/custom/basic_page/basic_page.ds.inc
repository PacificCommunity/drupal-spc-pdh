<?php

/**
 * @file
 * basic_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function basic_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|basic_page';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'basic_page';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
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
  $export['node|page|basic_page'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
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
  $export['node|page|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function basic_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|basic_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'basic_page';
  $ds_layout->layout = 'panels-one_fw';
  $ds_layout->settings = array(
    'regions' => array(
      'one_fw_main' => array(
        0 => 'group_bp_banner_block',
        1 => 'body',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'group_bp_banner_block' => 'one_fw_main',
      'body' => 'one_fw_main',
      'title' => 'one_fw_main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'one_fw_main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|page|basic_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-one';
  $ds_layout->settings = array(
    'regions' => array(
      'one_main' => array(
        0 => 'group_bp_banner_block',
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'group_bp_banner_block' => 'one_main',
      'title' => 'one_main',
      'body' => 'one_main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'one_main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|page|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function basic_page_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'basic_page';
  $ds_view_mode->label = 'Basic Page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['basic_page'] = $ds_view_mode;

  return $export;
}
