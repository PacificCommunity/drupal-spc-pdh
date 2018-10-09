<?php
/**
 * @file
 * thematic_group.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function thematic_group_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'articles_list_by_topic';
  $path_breadcrumb->name = 'Articles List by Topic';
  $path_breadcrumb->path = 'articles/by-topic/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Articles',
      1 => 'By Topic',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => 'blog',
      1 => '%node:url',
      2 => '%node:url',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'thematic_group' => 'thematic_group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['articles_list_by_topic'] = $path_breadcrumb;

  return $export;
}
