<?php

function _ckan_tweaks_count_datasets_for_thematic_area($id) {
  $params = [
    'q' => sprintf(CKAN_SEARCH_CRIT_THEMATIC_AREA, $id),
    'rows' => 0
  ];
  return _ckan_tweaks_search_datasets($params)['count'];

}

function _ckan_tweaks_search_datasets($params) {
  $client = govcms_ckan_client();

  $resp = $client->get('action/package_search', $params);
  if (!$resp->valid) {
    watchdog(
      'ckan_tweaks',
      'Cannot obtain recent datasets: %status',
      ['%status' => $resp->status],
      WATCHDOG_WARNING
    );
    return ['count' => 0, 'results' => []];
  }
  return [
    'count' => $resp->data->count,
    'results' => $resp->data->results,
    'ckan_url' => variable_get('govcms_ckan_endpoint_url', '')
  ];
}

function _ckan_tweaks_create_dataset_mapper($ckan_url) {
  return function ($dataset) use ($ckan_url) {
    return [
      'title' => $dataset->title,
      'description' => $dataset->short_notes,
      'image_url' => $dataset->organization_image_url,
      'ckan_url' => $ckan_url . '/dataset/' . $dataset->name
    ];
  };
}
