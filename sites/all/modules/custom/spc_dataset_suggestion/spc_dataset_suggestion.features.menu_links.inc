<?php

/**
 * @file
 * spc_dataset_suggestion.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function spc_dataset_suggestion_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_dataset-suggestion:node/add/dataset-suggestion.
  $menu_links['navigation_dataset-suggestion:node/add/dataset-suggestion'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/dataset-suggestion',
    'router_path' => 'node/add/dataset-suggestion',
    'link_title' => 'Dataset Suggestion',
    'options' => array(
      'identifier' => 'navigation_dataset-suggestion:node/add/dataset-suggestion',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dataset Suggestion');

  return $menu_links;
}
