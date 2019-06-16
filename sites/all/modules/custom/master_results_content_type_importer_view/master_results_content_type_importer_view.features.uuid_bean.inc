<?php

/**
 * @file
 * master_results_content_type_importer_view.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function master_results_content_type_importer_view_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Pacific Community Results Block',
    'description' => NULL,
    'title' => '',
    'type' => 'banner_with_title',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'pacific-community-results-block',
    'view_mode' => 'default',
    'created' => 1560530250,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'f78c47e8-8bfa-459c-ab37-236d2bd4ecbc',
    'uuid' => 'd57005e4-1ee6-4456-9fdb-9cf2e75b87f4',
    'field_background' => array(),
    'field_title_bg' => array(
      'und' => array(
        0 => array(
          'value' => '<h1><strong>Pacific Community</strong> Results Explorer</h1>',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '5af01c98-d9e4-4a28-bc13-e4aab6ef425e',
  );
  return $beans;
}
