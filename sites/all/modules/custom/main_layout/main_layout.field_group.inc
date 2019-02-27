<?php

/**
 * @file
 * main_layout.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function main_layout_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_block|bean|banner_with_title|default';
  $field_group->group_name = 'group_background_block';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'banner_with_title';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_title_bg',
    ),
    'format_type' => 'div_background_image',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'background_image' => 'field_background',
        'image_style' => 'dashboard_banner',
        'classes' => 'banner-with-title',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_background_block|bean|banner_with_title|default'] = $field_group;

  return $field_groups;
}
