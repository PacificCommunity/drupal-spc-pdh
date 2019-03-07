<?php

/**
 * @file
 * dashboards_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dashboards_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner_content|node|dashboards|full';
  $field_group->group_name = 'group_banner_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_banner';
  $field_group->data = array(
    'label' => 'Banner content',
    'weight' => '7',
    'children' => array(
      0 => 'field_banner_title_db',
      1 => 'ckan_search_form',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-banner-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_banner_content|node|dashboards|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banner|node|dashboards|full';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon_logo',
      1 => 'group_banner_content',
    ),
    'format_type' => 'div_background_image',
    'format_settings' => array(
      'label' => 'Banner',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'background_image' => 'field_main_image',
        'image_style' => 'dashboard_banner',
        'classes' => 'banner-with-title',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_banner|node|dashboards|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body|node|dashboards|full';
  $field_group->group_name = 'group_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '1',
    'children' => array(
      0 => 'field_body_text',
      1 => 'field_dashboard_notes',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'dashboard-body-container',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_body|node|dashboards|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chart_settings|node|dashboards|form';
  $field_group->group_name = 'group_chart_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chart settings',
    'weight' => '10',
    'children' => array(
      0 => 'field_interactive_chart_source',
      1 => 'field_chart_help_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-chart-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_chart_settings|node|dashboards|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chart|node|dashboards|dashboard_highlight';
  $field_group->group_name = 'group_chart';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboard_highlight';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chart wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'field_dashboard_label',
      1 => 'chart_static',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Chart wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-chart',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_chart|node|dashboards|dashboard_highlight'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_left|node|dashboards|dashboard_highlight';
  $field_group->group_name = 'group_content_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboard_highlight';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Content left',
    'weight' => '22',
    'children' => array(
      0 => 'field_banner_title_db',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content_left|node|dashboards|dashboard_highlight'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_left|node|dashboards|dashboards_preview';
  $field_group->group_name = 'group_content_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboards_preview';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Content left',
    'weight' => '18',
    'children' => array(
      0 => 'field_icon_logo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content_left|node|dashboards|dashboards_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_right|node|dashboards|dashboard_highlight';
  $field_group->group_name = 'group_content_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboard_highlight';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Content right',
    'weight' => '23',
    'children' => array(
      0 => 'field_body_text',
      1 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content-right',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content_right|node|dashboards|dashboard_highlight'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_right|node|dashboards|dashboards_preview';
  $field_group->group_name = 'group_content_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboards_preview';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Content right',
    'weight' => '19',
    'children' => array(
      0 => 'field_body_text',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content-right',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content_right|node|dashboards|dashboards_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|dashboards|dashboard_highlight';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboard_highlight';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_content_left',
      1 => 'group_content_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|dashboards|dashboard_highlight'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|dashboards|dashboards_preview';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'dashboards_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_content_left',
      1 => 'group_content_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|dashboards|dashboards_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_search|node|dashboards|full';
  $field_group->group_name = 'group_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Find data',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Find data',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'dashboard-search-container',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_search|node|dashboards|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner');
  t('Banner content');
  t('Body');
  t('Chart settings');
  t('Chart wrapper');
  t('Content');
  t('Content left');
  t('Content right');
  t('Find data');

  return $field_groups;
}
