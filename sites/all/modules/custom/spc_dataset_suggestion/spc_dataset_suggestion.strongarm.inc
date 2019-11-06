<?php

/**
 * @file
 * spc_dataset_suggestion.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function spc_dataset_suggestion_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_dataset_suggestion';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_dataset_suggestion';
  $strongarm->value = 0;
  $export['comment_anonymous_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_dataset_suggestion';
  $strongarm->value = '2';
  $export['comment_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_dataset_suggestion';
  $strongarm->value = 1;
  $export['comment_default_mode_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_dataset_suggestion';
  $strongarm->value = '50';
  $export['comment_default_per_page_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_dataset_suggestion';
  $strongarm->value = 1;
  $export['comment_form_location_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_dataset_suggestion';
  $strongarm->value = '1';
  $export['comment_preview_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_dataset_suggestion';
  $strongarm->value = 1;
  $export['comment_subject_field_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_dataset_suggestion';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_dataset_suggestion';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_dataset_suggestion';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_view_modes_dataset_suggestion';
  $strongarm->value = array(
    0 => 'default',
    1 => 'teaser',
  );
  $export['ds_extras_view_modes_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__dataset_suggestion';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dataset_suggestion';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_dataset_suggestion';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dataset_suggestion';
  $strongarm->value = array();
  $export['node_options_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dataset_suggestion';
  $strongarm->value = '0';
  $export['node_preview_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dataset_suggestion';
  $strongarm->value = 1;
  $export['node_submitted_dataset_suggestion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'suggestion_rate',
      'tag' => 'vote',
      'title' => 'Suggestion Rate',
      'node_types' => array(
        0 => 'dataset_suggestion',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => 1,
          1 => '+1',
        ),
        1 => array(
          0 => -1,
          1 => '-1',
        ),
      ),
      'template' => 'number_up_down',
      'node_display' => '2',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        1 => '1',
        2 => '2',
        4 => '4',
        5 => '5',
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '3',
      'displayed_just_voted' => '1',
      'description' => '',
      'description_in_compact' => FALSE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'points',
      'theme' => 'rate_template_number_up_down',
      'css' => 'sites/all/modules/contrib/rate/templates/number-up-down/number-up-down.css',
      'translate' => FALSE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_dataset_suggestion';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_dataset_suggestion'] = $strongarm;

  return $export;
}
