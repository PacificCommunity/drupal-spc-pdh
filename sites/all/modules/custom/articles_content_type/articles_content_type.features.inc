<?php

/**
 * @file
 * articles_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function articles_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function articles_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function articles_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: featured_article.
  $styles['featured_article'] = array(
    'label' => 'Featured Article',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1010,
          'height' => 292,
        ),
        'weight' => 1,
      ),
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 292,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: list_page_article.
  $styles['list_page_article'] = array(
    'label' => 'List Page Article',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 192,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: stories_slides.
  $styles['stories_slides'] = array(
    'label' => 'Stories slides (320x224)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 224,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function articles_content_type_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
