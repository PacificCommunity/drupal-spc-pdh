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

  return $field_groups;
}
