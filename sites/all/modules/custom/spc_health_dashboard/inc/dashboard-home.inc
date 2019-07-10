<?php

include_once drupal_get_path('module', 'spc_health_dashboard') . '/inc/dashboard-breadcrumbs.inc';

/**
 * Returns Health dashboard home page.
 *
 * @return string
 * Formatted template.
 * @throws \Exception
 */
function spc_health_dashboard_home_page() {
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => t('Status of NCD policy and legislation in <br><strong>Pacific Island countries</strong> and territories'),
      'breadcrumbs' => _home_breadcrumbs(),
      'search' => spc_health_dashboard_home_search(),
      'content' => spc_health_dashboard_home_content(),
    ]
  );
}

function spc_health_dashboard_home_search() {
  $data = array();
  
  $content = theme('spc_health_dashboard_home_search', array('search' => $data));
  
  return $content;
}

function spc_health_dashboard_home_content(){
  $data = array();
  
  $health_dashboard_data = get_health_dashboard_data();
  
  $spc_health_chart = health_dashboard_chart_summary($health_dashboard_data['countries-data']);
  drupal_add_js(array('spc_health_chart' => array('summary_chart' => $spc_health_chart)), array('type' => 'setting'));
  
  $data['background'] = $health_dashboard_data['home-page']['background'];
  $data['methods'] = $health_dashboard_data['home-page']['methods'];
  $data['chart']  = $health_dashboard_data['home-page']['chart'];
  
  $content = theme('spc_health_dashboard_home_content', array('data' => $data));
  
  return $content;
}

function health_dashboard_chart_summary($countries_data){
  $summary = array();
  
  foreach($countries_data as $country => $data){
    foreach($data['indicators'] as $key => $indicator){
      
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
  }
  
  $summary_filtred = [];
  foreach($summary as $key => $detales){
    $count = 0;
    $count = $detales['present'] + $detales['under-development'] + $detales['not-present'];

    $summary_filtred[] = [
      'indicator' => ucfirst(str_replace('-', ' ', $key)),
      'present' => ($detales['present']/$count) * 100,
      'under-development' => ($detales['under-development']/$count) * 100,
      'not-present' => ($detales['not-present']/$count) * 100
      ] ;
  }
  
  return $summary_filtred;
}
