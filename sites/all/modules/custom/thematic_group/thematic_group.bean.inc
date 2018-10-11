<?php
/**
 * @file
 * thematic_group.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function thematic_group_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'thematic_group_backgrounds';
  $bean_type->label = 'Thematic Group Backgrounds';
  $bean_type->options = '';
  $bean_type->description = 'Provides background images and styles for Thematic Group page.';
  $export['thematic_group_backgrounds'] = $bean_type;

  return $export;
}
