<?php

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
  if ($category == 'null') {
    drupal_not_found();
  }
  $indicator_name = '<h2>' . $category . '</h2>'; // Should be changed.
  if ($indicator) {
    $indicator_name = '<h2>' . $indicator . '</h2>'; // Should be changed.
  }
  return theme(
    'spc_health_dashboard_page',
    [
      'title' => t('Status of NCD policy and legislation in <br><strong>Pacific Island countries</strong> and territories'),
      'content' => 'Hello Home dashboard',
      'breadcrumbs' => 'Breadcrumbs',
      'search' => 'Search',
      'subtitle' => $indicator_name,
    ]);
}
