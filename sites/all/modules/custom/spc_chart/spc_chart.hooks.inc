<?php

$libraries = libraries_get_libraries();
if (isset($libraries['PHPExcel'])) {
  $phpExcel = $libraries['PHPExcel'];
}
require_once $phpExcel.'/Classes/PHPExcel.php';

function spc_chart_preprocess_field(&$variables) {
	if ($variables['element']['#bundle'] == 'dashboards' && $variables['element']['#field_name'] == 'field_interactive_chart_source') {
		if (!empty($variables['element']['#object']->field_interactive_chart_source)) {
			if ($cached = cache_get('sdgChartData', 'cache')) {
				$countries = $cached->data;
			}
			if (empty($countries)) {
				$file_url = $variables['element']['#object']->field_interactive_chart_source[LANGUAGE_NONE][0]['url'];
				$file = system_retrieve_file($file_url, NULL, TRUE, FILE_EXISTS_REPLACE);

				$node_title = $variables['element']['#object']->title;
				$new_filename = drupal_html_class($node_title).'.xlsx';

				if (empty($file)) {
					watchdog('spc_chart', 'Can\'t download a file from '.$file_url.'. Existed file "'.$new_filename.'" will be using.');
					$files = file_load_multiple(array(), array('uri' => 'public://'.$new_filename));
					if (empty($files)) {
						watchdog('spc_chart', 'File "'.$new_filename.'" doesn\'t exist!');
						return;
					}
					$result = reset($files);
				} else {
					watchdog('spc_chart', 'Downloaded file from '.$file_url);
					$file_info = pathinfo($file->uri);
					if ($file_info['extension'] != 'xlsx') {
						watchdog('spc_chart', 'File extension is incorrect! Must be "xlsx".');
						return;
					}

					$new_destination = str_replace($file->filename, $new_filename, $file->uri);
					$file->filename = $new_filename;
					$result = file_move($file, $new_destination, FILE_EXISTS_REPLACE);
				}

				$filecontent = file_get_contents($result->uri);
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
								if (substr($cellValue, 0, strlen('Code -')) == 'Code -') {
									$countyKey = substr($cellValue, strlen('Code -'));
								} 
								$countries[$countyKey] = array();
							}
						} else {
							$cellValue = $worksheet->getCell($column.$row)->getValue();
							array_push($countries[$countyKey], $cellValue);
						}
					}
				}
				cache_set('sdgChartData', $countries, 'cache', time() + 60*60*24);
			}

			$module_path = drupal_get_path('module', 'spc_chart');
			drupal_add_js(array('spcChart' => array('path' => $module_path)), array('type' => 'setting'));
			drupal_add_js(array('spcChart' => array('countriesData' => $countries)), array('type' => 'setting'));
			drupal_add_js($module_path . '/js/select2.min.js');
			drupal_add_js($module_path . '/js/d3.v5.min.js');
			drupal_add_js($module_path . '/js/script.js');
		}
	}
}
