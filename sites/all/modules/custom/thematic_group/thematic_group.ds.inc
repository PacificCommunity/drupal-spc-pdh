<?php

/**
 * @file
 * thematic_group.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function thematic_group_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|thematic_group|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'thematic_group';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|thematic_group|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|thematic_group|group_with_icon';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'thematic_group';
  $ds_fieldsetting->view_mode = 'group_with_icon';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'p',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_fa_icon' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|thematic_group|group_with_icon'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|thematic_group|topic_preview';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'thematic_group';
  $ds_fieldsetting->view_mode = 'topic_preview';
  $ds_fieldsetting->settings = array(
    'ds_fa_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_fa_icon' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'prefix' => '<a href="[node:url]">',
          'suffix' => '</a>',
        ),
      ),
    ),
  );
  $export['node|thematic_group|topic_preview'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function thematic_group_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|thematic_group|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'thematic_group';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
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
  $export['node|thematic_group|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|thematic_group|group_with_icon';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'thematic_group';
  $ds_layout->view_mode = 'group_with_icon';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_with_icon',
        1 => 'field_fa_icon',
        2 => 'field_icon',
        3 => 'title',
      ),
    ),
    'fields' => array(
      'group_with_icon' => 'ds_content',
      'field_fa_icon' => 'ds_content',
      'field_icon' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|thematic_group|group_with_icon'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|thematic_group|topic_preview';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'thematic_group';
  $ds_layout->view_mode = 'topic_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_fa_icon',
        1 => 'field_fa_icon',
        2 => 'field_icon',
        3 => 'title',
      ),
    ),
    'fields' => array(
      'ds_fa_icon' => 'ds_content',
      'field_fa_icon' => 'ds_content',
      'field_icon' => 'ds_content',
      'title' => 'ds_content',
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
  $export['node|thematic_group|topic_preview'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function thematic_group_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'group_with_icon';
  $ds_view_mode->label = 'Group with icon';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['group_with_icon'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'topic_preview';
  $ds_view_mode->label = 'Topic preview';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['topic_preview'] = $ds_view_mode;

  return $export;
}
