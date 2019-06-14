<?php

/**
 * @file
 * master_results_content_type_importer_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function master_results_content_type_importer_view_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'master_results';
  $page->task = 'page';
  $page->admin_title = 'Master results';
  $page->admin_description = '';
  $page->path = 'master-results';
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
  $handler->name = 'page_master_results__panel';
  $handler->task = 'page';
  $handler->subtask = 'master_results';
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
  $display->layout = 'mothership-html5page-page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'top_mobile' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'efba16d5-dfe8-480a-9b0b-b891307f50fb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_master_results__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-35876f04-eda4-4dbb-aefd-b58180858491';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'master_results_framework';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '35876f04-eda4-4dbb-aefd-b58180858491';
  $display->content['new-35876f04-eda4-4dbb-aefd-b58180858491'] = $pane;
  $display->panels['middle'][0] = 'new-35876f04-eda4-4dbb-aefd-b58180858491';
  $pane = new stdClass();
  $pane->pid = 'new-a3a7e870-495b-498c-802e-db168ae0e3d9';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'bean-pacific-community-results-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3a7e870-495b-498c-802e-db168ae0e3d9';
  $display->content['new-a3a7e870-495b-498c-802e-db168ae0e3d9'] = $pane;
  $display->panels['top'][0] = 'new-a3a7e870-495b-498c-802e-db168ae0e3d9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['master_results'] = $page;

  return $pages;

}
