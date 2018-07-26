<?php
/**
 * @file
 * articles_content_type.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function articles_content_type_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'articles_list_page';
  $path_breadcrumb->name = 'Articles List Page';
  $path_breadcrumb->path = 'blog';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Articles',
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
  $export['articles_list_page'] = $path_breadcrumb;

  return $export;
}
