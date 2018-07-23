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
  $blocks['ckan_tweaks-popular_datasets'] = [
    'info' => t('CKAN popular datasets')
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
    case 'ckan_tweaks-popular_datasets':
      $show_popular = intval($delta === 'ckan_tweaks-popular_datasets');
      $node = menu_get_object();
      $id = _ckan_tweaks_get_thematic_area_from_node($node);
      $query_dict = [
        'q' => $node ? sprintf(CKAN_SEARCH_CRIT_THEMATIC_AREA, $id) : '*:*',
        'sort' => constant('CKAN_SEARCH_SORT_' . ($show_popular ? 'MOST_VIEWED' : 'LATEST') . '_FIRST'),
        'rows' => 4
      ];
      if ($node) {
        $query_dict[CKAN_SEARCH_PARAM_POPULAR_FIRST] = TRUE;
      }
      $recent = _ckan_tweaks_search_datasets($query_dict);

      $ckan_url = _ckan_tweaks_get_ckan_url();

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
