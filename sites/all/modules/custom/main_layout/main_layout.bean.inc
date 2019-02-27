<?php

/**
 * @file
 * main_layout.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function main_layout_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'banner_with_title';
  $bean_type->label = 'Banner with title';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['banner_with_title'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'partner_logos';
  $bean_type->label = 'Partner logos';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['partner_logos'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'social_links';
  $bean_type->label = 'Social Links';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['social_links'] = $bean_type;

  return $export;
}
