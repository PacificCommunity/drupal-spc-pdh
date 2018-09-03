<?php
/**
 * @file
 * dashboard_secondary_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dashboard_secondary_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dashboard_secondary_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dashboard_secondary_page_image_default_styles() {
  $styles = array();

  // Exported image style: dashboard_sp_image.
  $styles['dashboard_sp_image'] = array(
    'label' => 'Dashboard SP image (255x255)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 255,
          'height' => 255,
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
function dashboard_secondary_page_node_info() {
  $items = array(
    'dsp' => array(
      'name' => t('Dashboard Secondary Page'),
      'base' => 'node_content',
      'description' => t('Provides content type for dashboard secondary pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
