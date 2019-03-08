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
  $ds_fieldsetting->id = 'node|dashboards|dashboard_highlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dashboards';
  $ds_fieldsetting->view_mode = 'dashboard_highlight';
  $ds_fieldsetting->settings = array(
    'chart_static' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View DASHBOARD',
        'link class' => 'banner-button btn',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_body_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'dashboard-description',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_banner_title_db' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-cl' => 'banner-title',
        ),
      ),
    ),
  );
  $export['node|dashboards|dashboard_highlight'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dashboards|dashboards_preview';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dashboards';
  $ds_fieldsetting->view_mode = 'dashboards_preview';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'p',
        'class' => 'dashboard-title',
        'ft' => array(),
      ),
    ),
    'field_body_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'dashboard-description',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
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
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_body_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
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
          'fis-cl' => 'dashboard-logo-wrapper',
          'fis-at' => '',
          'fis-def-at' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'dashboard-logo',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_dashboard_notes' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Note',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'dashboard-notes',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
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
  $ds_field->field = 'chart_static';
  $ds_field->label = 'Chart Static';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dashboards|*';
  $ds_field->properties = array();
  $export['chart_static'] = $ds_field;

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
  $ds_layout->id = 'node|dashboards|dashboard_highlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dashboards';
  $ds_layout->view_mode = 'dashboard_highlight';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_icon_logo',
        1 => 'chart_static',
        2 => 'group_content',
        3 => 'field_dashboard_label',
        4 => 'field_banner_title_db',
        5 => 'group_chart',
        6 => 'field_body_text',
        7 => 'node_link',
        8 => 'group_content_left',
        9 => 'group_content_right',
      ),
    ),
    'fields' => array(
      'field_icon_logo' => 'ds_content',
      'chart_static' => 'ds_content',
      'group_content' => 'ds_content',
      'field_dashboard_label' => 'ds_content',
      'field_banner_title_db' => 'ds_content',
      'group_chart' => 'ds_content',
      'field_body_text' => 'ds_content',
      'node_link' => 'ds_content',
      'group_content_left' => 'ds_content',
      'group_content_right' => 'ds_content',
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
  $export['node|dashboards|dashboard_highlight'] = $ds_layout;

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
        0 => 'group_content',
        1 => 'field_icon_logo',
        2 => 'title',
        3 => 'field_body_text',
        4 => 'group_content_left',
        5 => 'group_content_right',
      ),
    ),
    'fields' => array(
      'group_content' => 'ds_content',
      'field_icon_logo' => 'ds_content',
      'title' => 'ds_content',
      'field_body_text' => 'ds_content',
      'group_content_left' => 'ds_content',
      'group_content_right' => 'ds_content',
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
        0 => 'group_banner',
        1 => 'group_body',
        2 => 'field_body_text',
        3 => 'field_dashboard_notes',
        4 => 'field_icon_logo',
        5 => 'group_banner_content',
        6 => 'field_banner_title_db',
        7 => 'ckan_search_form',
      ),
    ),
    'fields' => array(
      'group_banner' => 'ds_content',
      'group_body' => 'ds_content',
      'field_body_text' => 'ds_content',
      'field_dashboard_notes' => 'ds_content',
      'field_icon_logo' => 'ds_content',
      'group_banner_content' => 'ds_content',
      'field_banner_title_db' => 'ds_content',
      'ckan_search_form' => 'ds_content',
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
  $ds_view_mode->view_mode = 'dashboard_highlight';
  $ds_view_mode->label = 'Dashboard Highlight';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dashboard_highlight'] = $ds_view_mode;

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
