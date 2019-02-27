<?php

/**
 * @file
 * main_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function main_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_f9a98f20-2aaf-4069-9127-c7acc313b74c';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main Template',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'top' => NULL,
      'top_mobile' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '323f6b2b-e527-4f7c-b520-da51a5fd8cb8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template__panel_context_f9a98f20-2aaf-4069-9127-c7acc313b74c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-76756daa-4481-490d-92e2-d11c2348a824';
  $pane->panel = 'one_fw_main';
  $pane->type = 'pane_header';
  $pane->subtype = 'pane_header';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '76756daa-4481-490d-92e2-d11c2348a824';
  $display->content['new-76756daa-4481-490d-92e2-d11c2348a824'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-76756daa-4481-490d-92e2-d11c2348a824';
  $pane = new stdClass();
  $pane->pid = 'new-7cf39553-5f6a-467e-83ca-825bbac3d063';
  $pane->panel = 'one_fw_main';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7cf39553-5f6a-467e-83ca-825bbac3d063';
  $display->content['new-7cf39553-5f6a-467e-83ca-825bbac3d063'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-7cf39553-5f6a-467e-83ca-825bbac3d063';
  $pane = new stdClass();
  $pane->pid = 'new-45d1a1a5-f548-4cb4-8ed1-6354b280769f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '45d1a1a5-f548-4cb4-8ed1-6354b280769f';
  $display->content['new-45d1a1a5-f548-4cb4-8ed1-6354b280769f'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-45d1a1a5-f548-4cb4-8ed1-6354b280769f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_f9a98f20-2aaf-4069-9127-c7acc313b74c'] = $handler;

  return $export;
}
