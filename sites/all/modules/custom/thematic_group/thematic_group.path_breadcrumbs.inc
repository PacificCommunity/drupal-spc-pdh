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
  $path_breadcrumb->name = 'Stories List by Topic';
  $path_breadcrumb->path = 'stories/by-topic/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Stories',
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

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_articles';
  $path_breadcrumb->name = 'Search stories';
  $path_breadcrumb->path = 'search/articles/%term/%thematic_area';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Search Stories',
      1 => '!term',
      2 => '!thematic_area',
    ),
    'paths' => array(
      0 => 'search/stories',
      1 => 'search/stories/!term',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'term' => array(
        'position' => 2,
      ),
      'thematic_area' => array(
        'position' => 3,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['search_articles'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_articles_default';
  $path_breadcrumb->name = 'Search Articles Default';
  $path_breadcrumb->path = 'search/articles';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Search Stories',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['search_articles_default'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_articles_term';
  $path_breadcrumb->name = 'Search Stories Term';
  $path_breadcrumb->path = 'search/articles/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Search Stories',
      1 => '!term',
    ),
    'paths' => array(
      0 => 'search/stories',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'term' => array(
        'position' => 2,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['search_articles_term'] = $path_breadcrumb;

  return $export;
}
