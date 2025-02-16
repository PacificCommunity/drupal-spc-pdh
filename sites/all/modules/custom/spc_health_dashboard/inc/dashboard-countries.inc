<?php

include_once drupal_get_path('module', 'spc_health_dashboard') . '/inc/dashboard-breadcrumbs.inc';

/**
 * Returns Health dashboard country pages.
 *
 * @param string $country (optional)
 *
 * @return string
 * Formatted template.
 * @throws \Exception
 */
function spc_health_dashboard_country($country = NULL) {
  $countries = variable_get('health_dashboard_countries', []);
  if (!isset($country, $countries[$country])) {
    drupal_not_found();
  }
  
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => _health_dashboard_title(),
      'content' => spc_health_dashboard_country_content($country),
      'breadcrumbs' => _country_breadcrumbs($country),
      'search' => spc_health_dashboard_home_search(),
      'subtitle' => '',
    ]);
}

/**
 * Returns dashboard country content template.
 *
 * @return array
 * Content data array.
 */
function spc_health_dashboard_country_content($country){
  $data = array();
  
  $health_dashboard_data = get_health_dashboard_data('health_json_fid', 'default');
  
  foreach($health_dashboard_data['countries-data'] as $country_data){
    
    if ($country_data['id'] == $country){
      $data['title'] = $country_data['title'] . t(' - summary of status of indicators across the categories&nbsp(%)');
      $data['country'] = $country_data['title'];
      $data['country_id'] = $country_data['id'];
      $data['indicators'] = $country_data['indicators'];
      $data['categories'] = variable_get('health_dashboard_categories_list', []);
      $country_chart = _health_dashboard_country_chart($country_data['indicators']);
      
      if (!empty($fid = variable_get('pdf_' . $country . '_fid'))){
          $pdf_country_file = file_load($fid);
          $pdf_country_file_url = file_create_url($pdf_country_file->uri);
          $data['chart-pdf-export'] = $pdf_country_file_url;
      }
    }
    
  }
  
  $indicator_detales = [];
  
  if ($indicator_detales = get_health_dashboard_data('health_indicators_fid', 'indicators')) {
    drupal_add_js(array('spc_health_chart' => array('indicator_detales' => $indicator_detales)), array('type' => 'setting'));
  }

  drupal_add_js(array('spc_health_chart' => array('summary_chart' => $country_chart)), array('type' => 'setting'));
  $content = theme('spc_health_dashboard_country_content', array('data' => $data));
  
  return $content;
}

/**
 * Returns dashboard chart data for counties summary array.
 *
 * @return array
 * Summary data array.
 */
function _health_dashboard_country_chart($country_data){
  $summary = array();
  
    foreach($country_data as $key => $indicator){
      
      switch ($indicator['value']){
        case 'present':
        case 'low':
        case 'medium':
        case 'high':  
            @$summary[$indicator['indicator-category']]['present'] += 1;
          break;  
        case 'under-development':
            @$summary[$indicator['indicator-category']]['under-development'] += 1;
          break;
        case 'not-present':
            @$summary[$indicator['indicator-category']]['not-present'] += 1;
          break;
      }
    } 
  
  $summary_filtred = [];
  foreach($summary as $key => $detales){
    $count = 0;
    $count = @$detales['present'] + @$detales['under-development'] + @$detales['not-present'];

    $summary_filtred[] = [
      'indicator' => ucfirst(str_replace('-', ' ', $key)),
      'present' => (@$detales['present']/$count) * 100,
      'under-development' => (@$detales['under-development']/$count) * 100,
      'not-present' => (@$detales['not-present']/$count) * 100
      ] ;
  }
  
  return $summary_filtred;
}
