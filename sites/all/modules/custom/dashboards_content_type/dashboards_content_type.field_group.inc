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
  $field_group->identifier = 'group_banner|node|dashboards|full';
  $field_group->group_name = 'group_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '1',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Banner',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'background_image' => 'field_main_image',
        'image_style' => 'dashboard_banner',
        'classes' => 'container-fluid dashboard-banner-container',
        'element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_body_text',
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
  $field_group->identifier = 'group_logo|node|dashboards|full';
  $field_group->group_name = 'group_logo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Logo',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon_logo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Logo',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'container-fluid',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_logo|node|dashboards|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_search|node|dashboards|full';
  $field_group->group_name = 'group_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dashboards';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Search',
    'weight' => '2',
    'children' => array(
      0 => 'ckan_search_form',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Search',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'dashboard-search-container',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_search|node|dashboards|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner');
  t('Body');
  t('Logo');
  t('Search');

  return $field_groups;
}
