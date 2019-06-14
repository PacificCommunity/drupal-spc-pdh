<?php

/**
 * @file
 * master_results_content_type_importer_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function master_results_content_type_importer_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'master_results_framework';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Master Results Framework';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'container master-results-accordion-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'List intro';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="upper-text">
<h3>Pacific Community</h3>
<h4>Results Explorer</h4>
The Pacific Community Results Report highlights the results achieved by SPC with our 26 Member countries and territories, and development partners in 2018. Our performance is described against the nine development objectives and five organisational objectives set out in the Pacific Community Strategic Plan 2016-2020.<br><br>
For more information, see the 2018 results report:
</div>
<div class="master-result-middle">
<div class="master-result-images">
<div class="master-result-img1"><a href="https://spccfpstore1.blob.core.windows.net/digitallibrary-docs/files/cc/cc6f8540645d3f3a6343f5081e6bf337.pdf?sv=2015-12-11&sr=b&sig=AHBqnCAmDt%2BeMqpxnmJ6IXvjUH9HD7o1uTMWUlsn6co%3D&se=2019-12-10T15%3A06%3A35Z&sp=r&rscc=public%2C%20max-age%3D864000%2C%20max-stale%3D86400&rsct=application%2Fpdf&rscd=inline%3B%20filename%3D%22Pacific_Community_Results_Report_2018_E.pdf%22" title="English" target="_blank"><img src="/sites/all/themes/spc/img/Cover_ENG.jpg"></a></div> 
<div class="master-result-img2"><a href="https://spccfpstore1.blob.core.windows.net/digitallibrary-docs/files/4f/4ffb8cb83b44bd840720922fdd97f72a.pdf?sv=2015-12-11&sr=b&sig=TF9aeylkEcyGGFgeuqBlvNNM%2Bk0byEe92InRDe84Dag%3D&se=2019-12-10T15%3A06%3A32Z&sp=r&rscc=public%2C%20max-age%3D864000%2C%20max-stale%3D86400&rsct=application%2Fpdf&rscd=inline%3B%20filename%3D%22Rapport_de_resultats_2018_de_la_Communaute_du_Pacifique_.pdf%22" title="English" target="_blank"><img src="/sites/all/themes/spc/img/Cover_FR.jpg"></a></div> 
</div>
<div class="master-result-chapters">
<h4>2018 Results Report Downloads</h4>

Results Highlight (EN | <a href="http://purl.org/spc/digilib/doc/zfe2d" target="_blank">FR</a>)<br>
Full Report (<a href="https://www.spc.int/DigitalLibrary/Doc/SPC/Annual_Reports/Pacific_Community_Results_Report_2018_E.html" target="_blank">EN</a> | <a href="https://www.spc.int/DigitalLibrary/Doc/SPC/Annual_Reports/Rapport_de_resultats_2018_de_la_Communaute_du_Pacifique_.html" target="_blank">FR</a>)<br>
Executive Summary (<a href="http://purl.org/spc/digilib/doc/vm7bf" target="_blank">EN</a> | <a href="http://purl.org/spc/digilib/doc/oz3q2" target="_blank">FR</a>)<br>
<br>
Spotlight: The Pacific Community’s contribution to the Sustainable Development Goals (<a href="http://purl.org/spc/digilib/doc/wjgu5" target="_blank">EN</a> | <a href="http://purl.org/spc/digilib/doc/uqpqq" target="_blank">FR</a>)<br>
Spotlight: Partnership Highlights (<a href="http://purl.org/spc/digilib/doc/iq5x6" target="_blank">EN</a> | FR)<br>
<br>
<br>
Chapter 1 : Strengthening sustainable management of natural resources (<a href="https://indd.adobe.com/view/c4b89d1e-ff36-4b21-8adc-ad3f1f58f6cc" target="_blank">EN</a>)<br>
Chapter 2: Improving pathways to international markets (<a href="https://indd.adobe.com/view/bfcc5bd4-22bf-4190-9d87-cb133ff3a491" target="_blank">EN</a>)<br>
Chapter 3: Strengthening sustainable transport and energy security (<a href="https://indd.adobe.com/view/f13dcf34-bad5-42c9-b073-39a46c173ec4" target="_blank">EN</a>)<br>
Chapter 4: Strengthening access to and use of statistics in policy development and monitoring of progress (<a href="https://indd.adobe.com/view/eace2d33-0359-4d75-93bf-ff29986f52f3" target="_blank">EN</a>)<br>
Chapter 5: Improving multi-sectoral responses to climate change and disasters (<a href="https://indd.adobe.com/view/6825b747-6730-4aa9-9d0f-7c298cc39314" target="_blank">EN</a>)<br>
Chapter 6: Advancing social development (human rights, gender equality, cultural diversity and opportunities for young people) (<a href="https://indd.adobe.com/view/e48b4c67-7655-453c-895e-f0fbd6c8a09f" target="_blank">EN</a>)<br>
Chapter 7: Improving multi-sectoral responses to prevent non-communicable diseases and enhance food security (<a href="https://indd.adobe.com/view/58ff75f6-2d52-4cd6-87f8-49a8544ca5a6" target="_blank">EN</a>)<br>
Chapter 8: Strengthening regional public health surveillance and response (<a href="https://indd.adobe.com/view/6cfd27a8-f878-4c1e-879f-f6f1a0933d7c" target="_blank">EN</a>)<br>
Chapter 9: Improving education quality (<a href="https://indd.adobe.com/view/fe1bf426-6b86-40d7-a8b8-4c00712af1e7" target="_blank">EN</a>)<br>
</div>
</div>
<div class="bottom-text">
<h4>Results Explorer Tool</h4>
Explore our results by Country, SDG, SPC Objective and SPC Division<br>
<i>This is a beta version for use by our members. For queries and feedback, please contact <a href="mailto:spl@spc.int">spl@spc.int</a>.</i>
</div>';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Oops. The result list is empty. Try to change a filter value.';
  /* Field: Content: SPC Development Objective */
  $handler->display->display_options['fields']['field_master_results_dev_obj']['id'] = 'field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['table'] = 'field_data_field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['field'] = 'field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_dev_obj']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Result Information */
  $handler->display->display_options['fields']['field_master_results_kpi']['id'] = 'field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['table'] = 'field_data_field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['field'] = 'field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['label'] = 'Result information';
  $handler->display->display_options['fields']['field_master_results_kpi']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_master_results_kpi']['alter']['text'] = '<b>[field_master_results_kpi-value]</b>';
  $handler->display->display_options['fields']['field_master_results_kpi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_kpi']['type'] = 'text_plain';
  /* Field: Content: Contribution to SDGs */
  $handler->display->display_options['fields']['field_master_results_sdg']['id'] = 'field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['table'] = 'field_data_field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['field'] = 'field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_sdg']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_master_results_sdg']['delta_offset'] = '0';
  /* Field: Content: PICTs benefitting from the result */
  $handler->display->display_options['fields']['field_master_result_country']['id'] = 'field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['table'] = 'field_data_field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['field'] = 'field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['label'] = 'PICTs benefitting from result';
  $handler->display->display_options['fields']['field_master_result_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_country']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_master_result_country']['delta_offset'] = '0';
  /* Field: Content: SPC Division */
  $handler->display->display_options['fields']['field_master_results_division']['id'] = 'field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['table'] = 'field_data_field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['field'] = 'field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_division']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Divisional Business Plan Result Area (KRA) */
  $handler->display->display_options['fields']['field_master_results_plan_area']['id'] = 'field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['table'] = 'field_data_field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['field'] = 'field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['label'] = 'Divisional Business Plan Key Result Area (KRA)';
  $handler->display->display_options['fields']['field_master_results_plan_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_plan_area']['type'] = 'text_plain';
  /* Field: Content: Type of Result */
  $handler->display->display_options['fields']['field_master_result_type_result']['id'] = 'field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['table'] = 'field_data_field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['field'] = 'field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_type_result']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: What was SPC's contribution to the result (End 2018)? */
  $handler->display->display_options['fields']['field_master_results_contribut']['id'] = 'field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['table'] = 'field_data_field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['field'] = 'field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['label'] = 'What was SPC’S contribution to the result';
  $handler->display->display_options['fields']['field_master_results_contribut']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_contribut']['type'] = 'text_plain';
  /* Field: Content: PICTs benefitting from the result */
  $handler->display->display_options['fields']['field_master_result_country_1']['id'] = 'field_master_result_country_1';
  $handler->display->display_options['fields']['field_master_result_country_1']['table'] = 'field_data_field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country_1']['field'] = 'field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_country_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_master_result_country_1']['delta_offset'] = '0';
  /* Field: Content: Link to results report chapter (English) */
  $handler->display->display_options['fields']['field_master_results_link']['id'] = 'field_master_results_link';
  $handler->display->display_options['fields']['field_master_results_link']['table'] = 'field_data_field_master_results_link';
  $handler->display->display_options['fields']['field_master_results_link']['field'] = 'field_master_results_link';
  $handler->display->display_options['fields']['field_master_results_link']['label'] = 'Links to results report chapter (English)';
  $handler->display->display_options['fields']['field_master_results_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_master_results_link']['alter']['text'] = '<a href="[field_master_results_link-value]" target="_blank">[field_master_results_link-value]</a>';
  $handler->display->display_options['fields']['field_master_results_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_link']['type'] = 'text_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'master_results' => 'master_results',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: SPC Development Objective (field_master_results_dev_obj) */
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['id'] = 'field_master_results_dev_obj_tid';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['table'] = 'field_data_field_master_results_dev_obj';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['field'] = 'field_master_results_dev_obj_tid';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['expose']['operator_id'] = 'field_master_results_dev_obj_tid_op';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['expose']['label'] = 'SPC Development Objective';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['expose']['operator'] = 'field_master_results_dev_obj_tid_op';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['expose']['identifier'] = 'field_master_results_dev_obj_tid';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_dev_obj_tid']['vocabulary'] = 'development_objective';
  /* Filter criterion: Content: Contribution to SDGs (field_master_results_sdg) */
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['id'] = 'field_master_results_sdg_tid';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['table'] = 'field_data_field_master_results_sdg';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['field'] = 'field_master_results_sdg_tid';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['operator_id'] = 'field_master_results_sdg_tid_op';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['label'] = 'SDG';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['operator'] = 'field_master_results_sdg_tid_op';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['identifier'] = 'field_master_results_sdg_tid';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['vocabulary'] = 'sdg';
  /* Filter criterion: Content: PICTs benefitting from the result (field_master_result_country) */
  $handler->display->display_options['filters']['field_master_result_country_tid']['id'] = 'field_master_result_country_tid';
  $handler->display->display_options['filters']['field_master_result_country_tid']['table'] = 'field_data_field_master_result_country';
  $handler->display->display_options['filters']['field_master_result_country_tid']['field'] = 'field_master_result_country_tid';
  $handler->display->display_options['filters']['field_master_result_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_result_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['operator_id'] = 'field_master_result_country_tid_op';
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['operator'] = 'field_master_result_country_tid_op';
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['identifier'] = 'field_master_result_country_tid';
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_result_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_result_country_tid']['vocabulary'] = 'country';
  /* Filter criterion: Content: SPC Division (field_master_results_division) */
  $handler->display->display_options['filters']['field_master_results_division_tid']['id'] = 'field_master_results_division_tid';
  $handler->display->display_options['filters']['field_master_results_division_tid']['table'] = 'field_data_field_master_results_division';
  $handler->display->display_options['filters']['field_master_results_division_tid']['field'] = 'field_master_results_division_tid';
  $handler->display->display_options['filters']['field_master_results_division_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_division_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_division_tid']['expose']['operator_id'] = 'field_master_results_division_tid_op';
  $handler->display->display_options['filters']['field_master_results_division_tid']['expose']['label'] = 'SPC Division';
  $handler->display->display_options['filters']['field_master_results_division_tid']['expose']['operator'] = 'field_master_results_division_tid_op';
  $handler->display->display_options['filters']['field_master_results_division_tid']['expose']['identifier'] = 'field_master_results_division_tid';
  $handler->display->display_options['filters']['field_master_results_division_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_division_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_division_tid']['vocabulary'] = 'division';
  /* Filter criterion: Content: Select Year (field_master_results_year2) */
  $handler->display->display_options['filters']['field_master_results_year2_value']['id'] = 'field_master_results_year2_value';
  $handler->display->display_options['filters']['field_master_results_year2_value']['table'] = 'field_data_field_master_results_year2';
  $handler->display->display_options['filters']['field_master_results_year2_value']['field'] = 'field_master_results_year2_value';
  $handler->display->display_options['filters']['field_master_results_year2_value']['value'] = array(
    2018 => '2018',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master Results';
  $handler->display->display_options['path'] = 'master-results-framework';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'accordion_block');
  $export['master_results_framework'] = $view;

  return $export;
}
