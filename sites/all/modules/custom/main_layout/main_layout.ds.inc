<?php

/**
 * @file
 * main_layout.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function main_layout_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_partners|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_partners';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_partner_link',
        1 => 'field_partner_logo',
      ),
    ),
    'fields' => array(
      'field_partner_link' => 'ds_content',
      'field_partner_logo' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_partners|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_social_section|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_social_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_social_link',
        1 => 'field_social_icon',
      ),
    ),
    'fields' => array(
      'field_social_link' => 'ds_content',
      'field_social_icon' => 'ds_content',
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
  $export['field_collection_item|field_social_section|default'] = $ds_layout;

  return $export;
}
