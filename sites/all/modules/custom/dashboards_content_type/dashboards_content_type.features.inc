<?php

/**
 * @file
 * dashboards_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dashboards_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dashboards_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function dashboards_content_type_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: dashboards
  $nodequeues['dashboards'] = array(
    'name' => 'dashboards',
    'title' => 'Dashboards',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'dashboards',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function dashboards_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: dashboard_banner.
  $styles['dashboard_banner'] = array(
    'label' => 'Dashboard Banner',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 310,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: dashboard_goal__140x140.
  $styles['dashboard_goal__140x140'] = array(
    'label' => 'Dashboard Goal (140x140)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: dashboard_logo.
  $styles['dashboard_logo'] = array(
    'label' => 'Dashboard Logo',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 210,
          'height' => 70,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dashboards_content_type_node_info() {
  $items = array(
    'dashboards' => array(
      'name' => t('Dashboards'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
