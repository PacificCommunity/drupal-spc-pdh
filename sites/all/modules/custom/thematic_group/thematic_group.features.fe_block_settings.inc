<?php
/**
 * @file
 * thematic_group.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function thematic_group_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-thematic-landing-banner'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'thematic-landing-banner',
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

  $export['bean-thematic-page-heading'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'thematic-page-heading',
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
