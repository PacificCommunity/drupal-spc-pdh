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
    'created' => 1560528230,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '36dfb698-e6f2-4f3f-8416-eabf052494f1',
    'uuid' => '7728c00d-7bb3-4992-8387-52e210aaf7d9',
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
