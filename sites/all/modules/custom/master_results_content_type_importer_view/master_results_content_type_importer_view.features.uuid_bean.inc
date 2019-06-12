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
    'label' => 'Master results framework',
    'description' => NULL,
    'title' => '',
    'type' => 'banner_with_title',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'master-results-framework',
    'view_mode' => 'default',
    'created' => 1560171363,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'c7ed0a5a-3f6a-42bb-a7a6-ddd6debb7af0',
    'uuid' => '514590dc-2d20-433a-be58-7030d9257892',
    'field_background' => array(),
    'field_title_bg' => array(
      'und' => array(
        0 => array(
          'value' => '<h1><strong>Master</strong> results framework</h1>',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '5af01c98-d9e4-4a28-bc13-e4aab6ef425e',
  );
  return $beans;
}
