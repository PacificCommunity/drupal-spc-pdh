<?php

/**
 * Implementation of hook_init().
*/
function spc_chart_init() {
	$module_path = drupal_get_path('module', 'spc_chart');
	drupal_add_js(array('spcChart' => array('path' => $module_path)), array('type' => 'setting'));
	drupal_add_js($module_path . '/js/d3.v5.min.js');
	drupal_add_js($module_path . '/js/script.js');
}

function spc_chart_preprocess_field(&$variables) {
	if ($variables['element']['#bundle'] == 'dashboards' && $variables['element']['#field_name'] == 'field_body_text') {
		if (!empty($variables['element']['#object']->field_interactive_chart_source)) {
			$variables['items'][0]['#prefix'] = '<h2>SDGs Progress Wheels</h2><div id="sdgChart"></div>';
		}
	}
}
