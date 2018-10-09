<?php
/**
 * @file
 * thematic_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function thematic_group_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_tweets|node|thematic_group|form';
  $field_group->group_name = 'group_latest_tweets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'thematic_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest Tweets',
    'weight' => '38',
    'children' => array(
      0 => 'field_twitter_account_names',
      1 => 'field_show_tweets',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-latest-tweets field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_latest_tweets|node|thematic_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_with_icon|node|thematic_group|group_with_icon';
  $field_group->group_name = 'group_with_icon';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'thematic_group';
  $field_group->mode = 'group_with_icon';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon',
      1 => 'field_fa_icon',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-with-icon field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_with_icon|node|thematic_group|group_with_icon'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Latest Tweets');

  return $field_groups;
}
