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
    'vuuid' => '5e42fc39-b3e7-4513-8bcc-90316cf8fd0d',
    'uuid' => 'd57005e4-1ee6-4456-9fdb-9cf2e75b87f4',
    'field_background' => array(),
    'field_title_bg' => array(
      'und' => array(
        0 => array(
          'value' => '<h1><strong>Pacific Community</strong> <br />Results Explorer</h1>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '21a8bb9d-7d32-4a73-aebd-9a4031d27d90',
  );
  return $beans;
}
