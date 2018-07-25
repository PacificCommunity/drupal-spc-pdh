<?php
/**
 * @file
 * data_insights_content_type.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function data_insights_content_type_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_insights|data_insights_individual_page';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_insights';
  $ds_fieldsetting->view_mode = 'data_insights_individual_page';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'author',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'body-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_data_insights_preview' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'preview',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'insights-topic',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|data_insights|data_insights_individual_page'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|data_insights|data_insights_list_page';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'data_insights';
  $ds_fieldsetting->view_mode = 'data_insights_list_page';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|data_insights|data_insights_list_page'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function data_insights_content_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_insights|data_insights_individual_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_insights';
  $ds_layout->view_mode = 'data_insights_individual_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'author',
        2 => 'post_date',
        3 => 'field_topic',
        4 => 'field_data_insights_preview',
        5 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'author' => 'ds_content',
      'post_date' => 'ds_content',
      'field_topic' => 'ds_content',
      'field_data_insights_preview' => 'ds_content',
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
  $export['node|data_insights|data_insights_individual_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_insights|data_insights_list_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_insights';
  $ds_layout->view_mode = 'data_insights_list_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_data_insights_preview',
        2 => 'field_topic',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_data_insights_preview' => 'ds_content',
      'field_topic' => 'ds_content',
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
  $export['node|data_insights|data_insights_list_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|data_insights|data_insights_on_topic_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'data_insights';
  $ds_layout->view_mode = 'data_insights_on_topic_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_data_insights_preview',
      ),
    ),
    'fields' => array(
      'field_data_insights_preview' => 'ds_content',
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
  $export['node|data_insights|data_insights_on_topic_page'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function data_insights_content_type_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'data_insights_individual_page';
  $ds_view_mode->label = 'Data Insights Individual Page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['data_insights_individual_page'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'data_insights_list_page';
  $ds_view_mode->label = 'Data Insights List page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['data_insights_list_page'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'data_insights_on_topic_page';
  $ds_view_mode->label = 'Data Insights on Topic page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['data_insights_on_topic_page'] = $ds_view_mode;

  return $export;
}
