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
    'results' => $resp->data->results
  ];
}

function _ckan_tweaks_get_ckan_url() {
  return variable_get('govcms_ckan_endpoint_url', '');
}

function _ckan_tweaks_create_dataset_mapper($ckan_url) {
  return function ($dataset) use ($ckan_url) {
    $release_date = date_create($dataset->metadata_created);
    return [
      'title' => $dataset->title,
      'description' => $dataset->short_notes,
      'image_url' => $dataset->organization_image_url,
      'ckan_url' => $ckan_url . '/dataset/' . $dataset->name,
      'organization' => $dataset->organization->title,
      'release_date' => date_format($release_date, 'F j, Y'),
      'resources' => $dataset->resources
    ];
  };
}

function _ckan_tweaks_organization_list() {
  $client = govcms_ckan_client();
  $response = $client->get('action/organization_list', ['all_fields' => TRUE]);
  return $response->valid ? $response->data : [];
}

function _ckan_tweaks_thematic_area_list() {
  $client = govcms_ckan_client();
  $response = $client->get('action/spc_thematic_area_list');
  return $response->valid ? $response->data : [];
}

function _ckan_tweaks_get_thematic_area_from_node($node) {
  if (isset($node->field_ckan_thematic_group_id)) {
    return $node->field_ckan_thematic_group_id[LANGUAGE_NONE][0]['value'];
  }
}
