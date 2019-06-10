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
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Oops. The result list is empty. Try to change a filter value.';
  /* Field: Content: Divisional business plan objective */
  $handler->display->display_options['fields']['field_master_results_object']['id'] = 'field_master_results_object';
  $handler->display->display_options['fields']['field_master_results_object']['table'] = 'field_data_field_master_results_object';
  $handler->display->display_options['fields']['field_master_results_object']['field'] = 'field_master_results_object';
  $handler->display->display_options['fields']['field_master_results_object']['element_label_colon'] = FALSE;
  /* Field: Content: Divisional business plan Result area */
  $handler->display->display_options['fields']['field_master_results_plan_area']['id'] = 'field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['table'] = 'field_data_field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['field'] = 'field_master_results_plan_area';
  $handler->display->display_options['fields']['field_master_results_plan_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_plan_area']['type'] = 'text_plain';
  /* Field: Content: Divisional Business Plan Key Performance Information */
  $handler->display->display_options['fields']['field_master_results_kpi']['id'] = 'field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['table'] = 'field_data_field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['field'] = 'field_master_results_kpi';
  $handler->display->display_options['fields']['field_master_results_kpi']['element_label_colon'] = FALSE;
  /* Field: Content: KPI type */
  $handler->display->display_options['fields']['field_master_results_kpi_type']['id'] = 'field_master_results_kpi_type';
  $handler->display->display_options['fields']['field_master_results_kpi_type']['table'] = 'field_data_field_master_results_kpi_type';
  $handler->display->display_options['fields']['field_master_results_kpi_type']['field'] = 'field_master_results_kpi_type';
  $handler->display->display_options['fields']['field_master_results_kpi_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_kpi_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Result achieved or not achieved */
  $handler->display->display_options['fields']['field_master_results_results']['id'] = 'field_master_results_results';
  $handler->display->display_options['fields']['field_master_results_results']['table'] = 'field_data_field_master_results_results';
  $handler->display->display_options['fields']['field_master_results_results']['field'] = 'field_master_results_results';
  $handler->display->display_options['fields']['field_master_results_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_results']['type'] = 'text_plain';
  /* Field: Content: Type of Result */
  $handler->display->display_options['fields']['field_master_result_type_result']['id'] = 'field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['table'] = 'field_data_field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['field'] = 'field_master_result_type_result';
  $handler->display->display_options['fields']['field_master_result_type_result']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_type_result']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Which PICTs benefited from the result? (region\country) */
  $handler->display->display_options['fields']['field_master_result_country']['id'] = 'field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['table'] = 'field_data_field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['field'] = 'field_master_result_country';
  $handler->display->display_options['fields']['field_master_result_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_country']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_master_result_country']['delta_offset'] = '0';
  /* Field: Content: Which Sustainable Development Goals (SDG) does this result most contribute to? */
  $handler->display->display_options['fields']['field_master_results_sdg']['id'] = 'field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['table'] = 'field_data_field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['field'] = 'field_master_results_sdg';
  $handler->display->display_options['fields']['field_master_results_sdg']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_sdg']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_master_results_sdg']['delta_offset'] = '0';
  /* Field: Content: Complete or in progress? Does the result relate to a body of work that is completed or in progress?  */
  $handler->display->display_options['fields']['field_master_result_status']['id'] = 'field_master_result_status';
  $handler->display->display_options['fields']['field_master_result_status']['table'] = 'field_data_field_master_result_status';
  $handler->display->display_options['fields']['field_master_result_status']['field'] = 'field_master_result_status';
  $handler->display->display_options['fields']['field_master_result_status']['element_label_colon'] = FALSE;
  /* Field: Content: What was SPC's contribution to the result? */
  $handler->display->display_options['fields']['field_master_results_contribut']['id'] = 'field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['table'] = 'field_data_field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['field'] = 'field_master_results_contribut';
  $handler->display->display_options['fields']['field_master_results_contribut']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_contribut']['type'] = 'text_plain';
  /* Field: Content: Sub-result area */
  $handler->display->display_options['fields']['field_master_result_sub_result']['id'] = 'field_master_result_sub_result';
  $handler->display->display_options['fields']['field_master_result_sub_result']['table'] = 'field_data_field_master_result_sub_result';
  $handler->display->display_options['fields']['field_master_result_sub_result']['field'] = 'field_master_result_sub_result';
  $handler->display->display_options['fields']['field_master_result_sub_result']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_result_sub_result']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Strategy / Grouping  */
  $handler->display->display_options['fields']['field_master_results_strategy']['id'] = 'field_master_results_strategy';
  $handler->display->display_options['fields']['field_master_results_strategy']['table'] = 'field_data_field_master_results_strategy';
  $handler->display->display_options['fields']['field_master_results_strategy']['field'] = 'field_master_results_strategy';
  $handler->display->display_options['fields']['field_master_results_strategy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_strategy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Division */
  $handler->display->display_options['fields']['field_master_results_division']['id'] = 'field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['table'] = 'field_data_field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['field'] = 'field_master_results_division';
  $handler->display->display_options['fields']['field_master_results_division']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_division']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Development objective */
  $handler->display->display_options['fields']['field_master_results_dev_obj']['id'] = 'field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['table'] = 'field_data_field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['field'] = 'field_master_results_dev_obj';
  $handler->display->display_options['fields']['field_master_results_dev_obj']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_master_results_dev_obj']['type'] = 'taxonomy_term_reference_plain';
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
  /* Filter criterion: Content: Which PICTs benefited from the result? (region\country) (field_master_result_country) */
  $handler->display->display_options['filters']['field_master_result_country_tid']['id'] = 'field_master_result_country_tid';
  $handler->display->display_options['filters']['field_master_result_country_tid']['table'] = 'field_data_field_master_result_country';
  $handler->display->display_options['filters']['field_master_result_country_tid']['field'] = 'field_master_result_country_tid';
  $handler->display->display_options['filters']['field_master_result_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_result_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['operator_id'] = 'field_master_result_country_tid_op';
  $handler->display->display_options['filters']['field_master_result_country_tid']['expose']['label'] = 'Filter by Country';
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
  /* Filter criterion: Content: Strategy / Grouping  (field_master_results_strategy) */
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['id'] = 'field_master_results_strategy_tid';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['table'] = 'field_data_field_master_results_strategy';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['field'] = 'field_master_results_strategy_tid';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['expose']['operator_id'] = 'field_master_results_strategy_tid_op';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['expose']['label'] = 'Filter by Strategy';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['expose']['operator'] = 'field_master_results_strategy_tid_op';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['expose']['identifier'] = 'field_master_results_strategy_tid';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_strategy_tid']['vocabulary'] = 'strategy_grouping';
  /* Filter criterion: Content: Which Sustainable Development Goals (SDG) does this result most contribute to? (field_master_results_sdg) */
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['id'] = 'field_master_results_sdg_tid';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['table'] = 'field_data_field_master_results_sdg';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['field'] = 'field_master_results_sdg_tid';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['operator_id'] = 'field_master_results_sdg_tid_op';
  $handler->display->display_options['filters']['field_master_results_sdg_tid']['expose']['label'] = 'Filter by SDG';
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
  /* Filter criterion: Content: KPI type (field_master_results_kpi_type) */
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['id'] = 'field_master_results_kpi_type_tid';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['table'] = 'field_data_field_master_results_kpi_type';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['field'] = 'field_master_results_kpi_type_tid';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['expose']['operator_id'] = 'field_master_results_kpi_type_tid_op';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['expose']['label'] = 'Filter by result level';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['expose']['operator'] = 'field_master_results_kpi_type_tid_op';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['expose']['identifier'] = 'field_master_results_kpi_type_tid';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_kpi_type_tid']['vocabulary'] = 'kpi_type';
  /* Filter criterion: Content: Year (field_master_results_year) */
  $handler->display->display_options['filters']['field_master_results_year_tid']['id'] = 'field_master_results_year_tid';
  $handler->display->display_options['filters']['field_master_results_year_tid']['table'] = 'field_data_field_master_results_year';
  $handler->display->display_options['filters']['field_master_results_year_tid']['field'] = 'field_master_results_year_tid';
  $handler->display->display_options['filters']['field_master_results_year_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_master_results_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_results_year_tid']['expose']['operator_id'] = 'field_master_results_year_tid_op';
  $handler->display->display_options['filters']['field_master_results_year_tid']['expose']['label'] = 'Filter by Year';
  $handler->display->display_options['filters']['field_master_results_year_tid']['expose']['operator'] = 'field_master_results_year_tid_op';
  $handler->display->display_options['filters']['field_master_results_year_tid']['expose']['identifier'] = 'field_master_results_year_tid';
  $handler->display->display_options['filters']['field_master_results_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_master_results_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_master_results_year_tid']['vocabulary'] = 'year';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master Results';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'master-results-framework';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'accordion_block');
  $export['master_results_framework'] = $view;

  return $export;
}
