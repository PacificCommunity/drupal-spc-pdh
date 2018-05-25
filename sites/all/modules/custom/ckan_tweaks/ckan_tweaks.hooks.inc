<?php
/**
 * Implements hook_theme().
 */
function ckan_tweaks_theme($existing, $type, $theme, $path)
{
  if($type == 'module')
  {
    return [
      'ckan_dataset_overview' => [
        'variables' => array('dataset'=>3),
        'template' => 'ckan_dataset_overview'
      ]
    ];
  }
  return [];
}

/**
 * Implements hook_block_info().
 */
function ckan_tweaks_block_info() {
  $blocks['ckan_tweaks-recent_datasets'] = [
    'info' => t('CKAN recently upated datasets')
  ];
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ckan_tweaks_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'ckan_tweaks-recent_datasets':
      $node = menu_get_object();
      $id = _ckan_tweaks_get_thematic_area_from_node($node);
      $recent = _ckan_tweaks_search_datasets(
        [
          'q' => sprintf(CKAN_SEARCH_CRIT_THEMATIC_AREA, $id),
          CKAN_SEARCH_PARAM_POPULAR_FIRST => true
        ]
      );
      $ckan_url = $recent['ckan_url'];

      $datasets = array_map(
        _ckan_tweaks_create_dataset_mapper($ckan_url),
        $recent['results']
      );

      // NOTE: Here we pull dataset count for thematic area
      $total = _ckan_tweaks_count_datasets_for_thematic_area($id);

      foreach ($datasets as &$dataset) {
        $dataset = theme('ckan_dataset_overview', ['dataset'=>$dataset]);
      }

      $block['subject'] = t('Recent CKAN updates [@total total]', ['@total' => $total]);
      $block['content'] = implode('', $datasets);

      break;
  }
  return $block;
}
