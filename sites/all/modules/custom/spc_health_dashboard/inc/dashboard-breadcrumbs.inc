<?php

/**
 * Returns empty breadcrumbs for the home page.
 *
 * @return string
 * Styled content.
 *
 * @throws \Exception
 */
function _home_breadcrumbs() {
  $content = theme('spc_health_dashboard_home_breadcrumbs', ['breadcrumbs' => []]);
  return $content;
}

/**
 * Returns country breadcrumbs.
 *
 * @param $selected_country
 * Selected country key.
 *
 * @return string
 * Styled content.
 *
 * @throws \Exception
 */
function _country_breadcrumbs($selected_country) {
  $countries = variable_get('health_dashboard_countries', []);
  $country_name = $countries[$selected_country]['#title'];
  unset($countries[$selected_country]);
  foreach ($countries as $key => $country) {
    $countries[$key]['url'] = HEALTH_DASHBOARD_URL . '/country/' . $key;
    $countries[$key]['title'] = $country['#title'];
  }
  $breadcrumbs[] = [
    'title' => t('MANA Dashboard'),
    'url' => HEALTH_DASHBOARD_URL,
    'submenu' => []
  ];
  $breadcrumbs[] = [
    'title' => $country_name,
    'url' => HEALTH_DASHBOARD_URL . '/country/' . $selected_country,
    'submenu' => $countries
  ];
  $content = theme(
    'spc_health_dashboard_breadcrumbs',
    ['breadcrumbs' => $breadcrumbs]
  );
  return $content;
}

/**
 * Returns category breadcrumbs.
 *
 * @param string $category
 * Category key.
 * @param string $indicator
 * Indicator key.
 *
 *  * @return string
 * Styled content.
 *
 * @throws \Exception
 */
function _category_breadcrumbs($category, $indicator) {
  $all_categories = variable_get('health_dashboard_categories_list', []);
  $category_name = $all_categories[$category]['#title'];

  if ($indicator) {
    $indicator_name = $all_categories[$category]['#indicators'][$indicator]['title'];
    $indicators = $all_categories[$category]['#indicators'];
    foreach ($all_categories[$category]['#indicators'] as $key => $item) {
      $indicators[$key] = [];
      $indicators[$key]['url'] = HEALTH_DASHBOARD_URL . '/' . $category . '/' . $key;
      $indicators[$key]['title'] = $item['title'];
    }
  }

  unset($all_categories[$category]);
  foreach ($all_categories as $key => $item) {
    $all_categories[$key]['url'] = HEALTH_DASHBOARD_URL . '/' . $key;
    $all_categories[$key]['title'] = $item['#title'];
  }
  $breadcrumbs[] = [
    'title' => t('MANA Dashboard'),
    'url' => HEALTH_DASHBOARD_URL,
    'submenu' => []
  ];
  $breadcrumbs[] = [
    'title' => $category_name,
    'url' => HEALTH_DASHBOARD_URL . '/' . $category,
    'submenu' => $all_categories
  ];
  if ($indicator) {
    $breadcrumbs[] = [
      'title' => $indicator_name,
      'url' => HEALTH_DASHBOARD_URL . '/' . $category . '/' . $indicator,
      'submenu' => $indicators
    ];
  }
  $content = theme(
    'spc_health_dashboard_breadcrumbs',
    ['breadcrumbs' => $breadcrumbs]
  );
  return $content;
}
