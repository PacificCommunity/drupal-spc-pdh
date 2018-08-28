<?php
/**
 * @file
 * dashboards_content_type.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dashboards_content_type_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dashboards|dashboards_preview';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dashboards';
  $ds_fieldsetting->view_mode = 'dashboards_preview';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_main_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|dashboards|dashboards_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dashboards|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dashboards';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'ckan_search_form' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => 'title',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'row',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'col-md-12 col-sm-12 col-xs-12',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_body_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'container',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'row',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div ',
          'fi-cl' => 'dashboard-body',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_icon_logo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'row',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'dashboard-logo col-md-12 col-sm-12 col-xs-12',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|dashboards|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dashboards_content_type_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'ckan_search_form';
  $ds_field->label = 'CKAN search form';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dashboards|*';
  $ds_field->properties = array();
  $export['ckan_search_form'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dashboards_content_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dashboards|dashboards_preview';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dashboards';
  $ds_layout->view_mode = 'dashboards_preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_main_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_main_image' => 'ds_content',
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
  $export['node|dashboards|dashboards_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dashboards|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dashboards';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_logo',
        1 => 'title',
        2 => 'field_icon_logo',
        3 => 'group_banner',
        4 => 'ckan_search_form',
        5 => 'field_body_text',
        6 => 'group_body',
      ),
    ),
    'fields' => array(
      'group_logo' => 'ds_content',
      'title' => 'ds_content',
      'field_icon_logo' => 'ds_content',
      'group_banner' => 'ds_content',
      'ckan_search_form' => 'ds_content',
      'field_body_text' => 'ds_content',
      'group_body' => 'ds_content',
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
  $export['node|dashboards|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dashboards_content_type_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dashboards_preview';
  $ds_view_mode->label = 'Dashboards Preview';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dashboards_preview'] = $ds_view_mode;

  return $export;
}
