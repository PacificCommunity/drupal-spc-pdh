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
    'vuuid' => 'fe1d1e7b-ea03-4b2c-960d-84727d1cad5f',
    'uuid' => '514590dc-2d20-433a-be58-7030d9257892',
    'field_background' => array(),
    'field_title_bg' => array(
      'und' => array(
        0 => array(
          'value' => '<h1><strong>Pacific Community</strong> Results Database</h1>',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '4d93f5b4-b6b7-405a-b448-70bf84507cf9',
  );
  return $beans;
}
