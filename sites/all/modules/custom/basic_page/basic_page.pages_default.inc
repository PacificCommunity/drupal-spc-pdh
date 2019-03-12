<?php

/**
 * @file
 * basic_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function basic_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_1e152165-0954-49a7-9a6e-8865d2f60ff3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Basic Page',
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
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'page' => 'page',
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
  $display->uuid = 'ed5e5cdb-ea65-44e1-9f7b-2f5a747626ec';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_1e152165-0954-49a7-9a6e-8865d2f60ff3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-de881892-fc5f-45db-9646-b302130982e8';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'basic_page',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '%title',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'basic-page',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'de881892-fc5f-45db-9646-b302130982e8';
  $display->content['new-de881892-fc5f-45db-9646-b302130982e8'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-de881892-fc5f-45db-9646-b302130982e8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1e152165-0954-49a7-9a6e-8865d2f60ff3'] = $handler;

  return $export;
}
