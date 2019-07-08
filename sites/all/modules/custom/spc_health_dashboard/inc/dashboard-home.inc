<?php

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
      'content' => 'Hello Home dashboard',
      'breadcrumbs' => 'Breadcrumbs',
      'search' => 'Search',
    ]);
}
