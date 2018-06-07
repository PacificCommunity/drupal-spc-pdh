<?php
/**
 * @file
 * thematic_group.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function thematic_group_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_articles_and_publications_node']['id'] = 'reverse_field_articles_and_publications_node';
  $handler->display->display_options['relationships']['reverse_field_articles_and_publications_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_articles_and_publications_node']['field'] = 'reverse_field_articles_and_publications_node';
  $handler->display->display_options['relationships']['reverse_field_articles_and_publications_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Search: Search Terms */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['keys']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['keys']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: CKAN thematic group ID (field_ckan_thematic_group_id) */
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['id'] = 'field_ckan_thematic_group_id_value';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['table'] = 'field_data_field_ckan_thematic_group_id';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['field'] = 'field_ckan_thematic_group_id_value';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['relationship'] = 'reverse_field_articles_and_publications_node';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ckan_thematic_group_id_value']['limit'] = '0';
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
    'article' => 'article',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'search/articles';
  $export['search_articles'] = $view;

  return $export;
}
