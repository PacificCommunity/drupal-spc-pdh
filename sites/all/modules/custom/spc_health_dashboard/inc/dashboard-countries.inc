<?php

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
  if (!$country) {
    drupal_not_found();
  }
  $country_name = '<h4>' . $country . '</h4>'; // Should be changed.
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => t('Status of NCD policy and legislation in <br><strong>Pacific Island countries</strong> and territories'),
      'content' => 'Hello Home dashboard',
      'breadcrumbs' => 'NCD Dashboard >',
      'search' => 'Search',
      'subtitle' => $country_name,
    ]);
}
