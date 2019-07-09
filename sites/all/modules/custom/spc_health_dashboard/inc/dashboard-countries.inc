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
  $country_name = '<h4>' . $country . '</h4>'; // Should be changed.
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => t('Status of NCD policy and legislation in <br><strong>Pacific Island countries</strong> and territories'),
      'content' => 'Hello Home dashboard',
      'breadcrumbs' => _country_breadcrumbs($country),
      'search' => 'Search',
      'subtitle' => $country_name,
    ]);
}
