<?php

/**
 * @file
 * master_results_content_type_importer_view.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function master_results_content_type_importer_view_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-pacific-community-results-block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'pacific-community-results-block',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
