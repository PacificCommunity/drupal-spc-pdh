<?php

include_once drupal_get_path('module', 'spc_health_dashboard') . '/inc/dashboard-breadcrumbs.inc';

/**
 * Returns Health dashboard indicators pages.
 *
 * @param string $category
 * @param string $indicator (optional)
 *
 * @return string
 * Formatted template.
 * @throws \Exception
 */
function spc_health_dashboard_pages($category, $indicator = NULL) {
  $categories = variable_get('health_dashboard_categories_list', []);
  if (!isset($categories, $categories[$category])) {
    drupal_not_found();
  }
  if ($indicator && !isset($categories[$category]['#indicators'][$indicator])) {     
    drupal_not_found();
  }

  if ($indicator) {
     $content = spc_health_dashboard_indicator_content($category, $indicator);
  } else {
    $content = spc_health_dashboard_category_content($category);
  }
  
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => t('Status of NCD policy and legislation in <br><strong>Pacific Island countries</strong> and territories'),
      'content' => $content,
      'breadcrumbs' => _category_breadcrumbs($category, $indicator),
      'search' => spc_health_dashboard_home_search(),
      'subtitle' => '',
    ]);
}


/*
 * 
 */
function spc_health_dashboard_category_content($category){
  $data = [];
  
  $health_dashboard_data = get_health_dashboard_data('health_json_fid', 'default');
  
  $indicator_detales = [];
  
  if ($indicator_detales = get_health_dashboard_data('health_indicators_fid', 'indicators')) {
    $data['indicator_detales'] = $indicator_detales;
    drupal_add_js(array('spc_health_chart' => array('indicator_detales' => $indicator_detales)), array('type' => 'setting'));
  }
  
  if ($category_data = get_health_dashboard_data('health_categories_fid', 'categories')) {
    $data['category_data'] = $category_data[$category];
  }
  
  $categories_list = variable_get('health_dashboard_categories_list');
  
  $current_category = $categories_list[$category];
  $current_category['id'] = $category;
  
  $data['current_category'] = $current_category;
  $data['categories_list'] = $categories_list;
  $data['countries-data'] = $health_dashboard_data['countries-data'];
  
  $content = theme('spc_health_dashboard_category_content', array('data' => $data));
  return $content;
}

/*
 * 
 */
function spc_health_dashboard_indicator_content($category, $indicator){
  $data = [];
  
  $health_dashboard_data = get_health_dashboard_data('health_json_fid', 'default');
  $data['countries-data'] = $health_dashboard_data['countries-data'];
  drupal_add_js(array('spc_health_chart' => array('countries_detales' => $health_dashboard_data['countries-data'])), array('type' => 'setting'));
  
  $indicator_detales = [];
  
  if ($indicator_detales = $indicator_detales = get_health_dashboard_data('health_indicators_fid', 'indicators')) {
    $data['indicator_detales'] = $indicator_detales[$indicator];
    drupal_add_js(array('spc_health_chart' => array('indicator_detales' => $indicator_detales)), array('type' => 'setting'));
  }
  
  if ($category_data = get_health_dashboard_data('health_categories_fid', 'categories')) {
    $data['category_data'] = $category_data[$category];
  }
  
  $data['current_indicator'] = $indicator;
  $data['current_category'] = $category;
  
  $content = theme('spc_health_dashboard_indicator_content', array('data' => $data));
  return $content;
}