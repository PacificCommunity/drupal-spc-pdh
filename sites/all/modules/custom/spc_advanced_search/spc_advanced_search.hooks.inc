<?php

$module_path = drupal_get_path('module', 'spc_advanced_search');
drupal_add_js('window.advanced_search_conf_url="/'.$module_path.'"', 'inline');
drupal_add_js($module_path . '/js/1.js');
drupal_add_js($module_path . '/js/main.js');
drupal_add_js($module_path . '/js/runtime.js');

function spc_advanced_search_block_info() {    
	$blocks['spc_advanced_search'] = array(
	  'info' => t('SPC Advanced search'),
	);
	return $blocks;
}

function spc_advanced_search_block_view($delta = '') {
	switch ($delta) {
		case 'spc_advanced_search':
		$block['subject'] = t('SPC Advanced search');
		$block['content'] = '<div id="advanced-search-application"></div>';
		break;
	}
	return $block;
}
