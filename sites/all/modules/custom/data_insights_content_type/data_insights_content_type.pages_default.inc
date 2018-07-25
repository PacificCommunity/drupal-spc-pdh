<?php
/**
 * @file
 * data_insights_content_type.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function data_insights_content_type_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_5fa66dd4-2eff-4cbc-a83a-2900442871b0';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Data Insight Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'data_insights' => 'data_insights',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd654dfa5-2b48-451d-80fc-d1aef67802a8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_5fa66dd4-2eff-4cbc-a83a-2900442871b0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec';
  $pane->panel = 'one_fw_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec';
  $display->content['new-1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec';
  $pane = new stdClass();
  $pane->pid = 'new-2ded9f8f-c095-44ef-93ab-8049a95b4234';
  $pane->panel = 'one_fw_main';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'data_insights_individual_page',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2ded9f8f-c095-44ef-93ab-8049a95b4234';
  $display->content['new-2ded9f8f-c095-44ef-93ab-8049a95b4234'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-2ded9f8f-c095-44ef-93ab-8049a95b4234';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_5fa66dd4-2eff-4cbc-a83a-2900442871b0'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function data_insights_content_type_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'data_insights';
  $page->task = 'page';
  $page->admin_title = 'Data Insights';
  $page->admin_description = '';
  $page->path = 'data-insights';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_data_insights__panel';
  $handler->task = 'page';
  $handler->subtask = 'data_insights';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4f14d8c0-c078-4bb1-94ca-7bfadec3449c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_data_insights__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c87e7254-9992-470a-9c3e-44fa80a41d25';
  $pane->panel = 'one_fw_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c87e7254-9992-470a-9c3e-44fa80a41d25';
  $display->content['new-c87e7254-9992-470a-9c3e-44fa80a41d25'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-c87e7254-9992-470a-9c3e-44fa80a41d25';
  $pane = new stdClass();
  $pane->pid = 'new-bb10dbdb-6893-43b2-90f6-5640e7e076bc';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'data_insights_list_page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container data-insights-list',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bb10dbdb-6893-43b2-90f6-5640e7e076bc';
  $display->content['new-bb10dbdb-6893-43b2-90f6-5640e7e076bc'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-bb10dbdb-6893-43b2-90f6-5640e7e076bc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c87e7254-9992-470a-9c3e-44fa80a41d25';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['data_insights'] = $page;

  return $pages;

}
