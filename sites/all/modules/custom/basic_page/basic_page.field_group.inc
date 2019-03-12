<?php

/**
 * @file
 * basic_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function basic_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bp_banner_block|node|page|basic_page';
  $field_group->group_name = 'group_bp_banner_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'basic_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'div_background_image',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'background_image' => 'field_banner_image_bp',
        'image_style' => 'dashboard_banner',
        'classes' => 'banner-with-title',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bp_banner_block|node|page|basic_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bp_banner_block|node|page|default';
  $field_group->group_name = 'group_bp_banner_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'div_background_image',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'background_image' => 'field_banner_image_bp',
        'image_style' => 'dashboard_banner',
        'classes' => 'banner-with-title',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bp_banner_block|node|page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries_wrapper|node|page|default';
  $field_group->group_name = 'group_countries_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-countries-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_countries_wrapper|node|page|default'] = $field_group;

  return $field_groups;
}
