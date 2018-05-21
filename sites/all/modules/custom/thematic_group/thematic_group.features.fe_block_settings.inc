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

  $export['ckan_tweaks-ckan_tweaks-recent_datasets'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'ckan_tweaks-recent_datasets',
    'module' => 'ckan_tweaks',
    'node_types' => array(
      0 => 'thematic_group',
    ),
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
      'spc' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'spc',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
