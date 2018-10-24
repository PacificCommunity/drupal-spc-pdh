<?php

$libraries = libraries_get_libraries();
if (isset($libraries['PHPExcel'])) {
  $phpExcel = $libraries['PHPExcel'];
}
require_once $phpExcel.'/Classes/PHPExcel.php';

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
			if ($cached = cache_get('sdgChartData', 'cache')) {
				$countries = $cached->data;
			}
			if (empty($countries)) {

				$file_url = $variables['element']['#object']->field_interactive_chart_source[LANGUAGE_NONE][0]['url'];
				$file = system_retrieve_file($file_url, NULL, FALSE, FILE_EXISTS_REPLACE);
				// $file = system_retrieve_file('hhttp://example.com/ddd', NULL, FALSE, FILE_EXISTS_REPLACE);
				// print("<pre>".print_r($file,true)."</pre>");

				$filecontent = file_get_contents($file);
				$tmpfname = tempnam(sys_get_temp_dir(),"tmpxls");
				file_put_contents($tmpfname,$filecontent);
				
				$excelReader = PHPExcel_IOFactory::createReaderForFile($tmpfname);
				$excelObj = $excelReader->load($tmpfname);
				$worksheet = $excelObj->getSheet(0);
				$countries = array();
				

				$columns = range('B', 'S');
				$rows = range(1, 81);

				foreach ($columns as $column) {
					foreach ($rows as $row) {
						if ($row == 1) {
							$cellValue = $worksheet->getCell($column.$row)->getValue();
							if (!empty($cellValue)) {
								$countyKey = drupal_html_class($cellValue);

								if (substr($countyKey, 0, strlen('code--')) == 'code--') {
									$countyKey = substr($countyKey, strlen('code--'));
								} 
								$countries[$countyKey] = array();
							}
						} else {
							$cellValue = $worksheet->getCell($column.$row)->getValue();
							array_push($countries[$countyKey], $cellValue);
						}
					}
				}
				// cache_set('sdgChartData', $countries, 'cache', time() + 60*60*24);
			}
			drupal_add_js(array('spcChart' => array('countriesData' => $countries)), array('type' => 'setting'));
			$variables['items'][0]['#prefix'] = '<h2>SDGs Progress Wheels</h2><div id="sdgChart"></div>';
		}
	}
}
 