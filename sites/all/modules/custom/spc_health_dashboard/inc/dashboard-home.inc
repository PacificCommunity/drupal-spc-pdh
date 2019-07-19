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

/**
 * Returns dashboard home content template.
 *
 * @return string
 * Content data array.
 * @throws \Exception
 */
function spc_health_dashboard_home_content() {
  $data = [];

  $health_dashboard_data = get_health_dashboard_data('health_json_fid', 'default');

  $spc_health_chart = health_dashboard_chart_summary($health_dashboard_data['countries-data']);
  drupal_add_js(['spc_health_chart' => ['summary_chart' => $spc_health_chart]], ['type' => 'setting']);

  $data['background'] = $health_dashboard_data['home-page']['background'];
  $data['methods'] = $health_dashboard_data['home-page']['methods'];
  $data['chart'] = $health_dashboard_data['home-page']['chart'];
  $data['countries'] = variable_get('health_dashboard_countries', []);
  $data['flag_base_path'] = drupal_get_path('module', 'spc_health_dashboard') . '/img/flags';
  $categories = variable_get('health_dashboard_categories_list', []);
  $category_menu = [];
  foreach ($categories as $key => $value) {
    if ($value['#wrapper']) {
      $categories[$key]['#wrapper'] = FALSE;
      $indicators[$key] = $value;
      $category_menu['wrapper'] = [
        '#title' => $value['#wrapper'],
        '#indicators' => $indicators,
      ];
    }
    else {
      $category_menu[$key] = $categories[$key];
    }
  }
  $data['categories'] = $category_menu;

  $content = theme('spc_health_dashboard_home_content', ['data' => $data]);

  return $content;
}

/**
 * Returns dashboard chart data for counties summary array.
 *
 * @return array
 * Summary data array.
 */
function health_dashboard_chart_summary($countries_data){
  $summary = [];
  
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
    @$count = $detales['present'] + $detales['under-development'] + $detales['not-present'];

    @$summary_filtred[] = [
      'indicator' => ucfirst(str_replace('-', ' ', $key)),
      'present' => ($detales['present']/$count) * 100,
      'under-development' => ($detales['under-development']/$count) * 100,
      'not-present' => ($detales['not-present']/$count) * 100
      ] ;
  }
  
  return $summary_filtred;
}
