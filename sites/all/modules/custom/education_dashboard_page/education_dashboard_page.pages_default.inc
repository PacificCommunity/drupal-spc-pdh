<?php

/**
 * @file
 * education_dashboard_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function education_dashboard_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'education_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Education Dashboard';
  $page->admin_description = '';
  $page->path = 'education-dashboard';
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
  $handler->name = 'page_education_dashboard__panel';
  $handler->task = 'page';
  $handler->subtask = 'education_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Education Dashboard',
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
      'middle' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Education Dashboard';
  $display->uuid = 'dc7c666b-f90e-4c3e-871d-2ea8aeb706c8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_education_dashboard__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0edbbbbc-549e-43a9-bc72-0b1e3750f75f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'spc_education_dashboard-education_dashboard_block';
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
  $pane->uuid = '0edbbbbc-549e-43a9-bc72-0b1e3750f75f';
  $display->content['new-0edbbbbc-549e-43a9-bc72-0b1e3750f75f'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-0edbbbbc-549e-43a9-bc72-0b1e3750f75f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['education_dashboard'] = $page;

  return $pages;

}