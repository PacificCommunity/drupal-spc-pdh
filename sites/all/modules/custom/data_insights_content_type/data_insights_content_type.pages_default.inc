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
  $pane->css = array();
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
    'build_mode' => 'teaser',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '2ded9f8f-c095-44ef-93ab-8049a95b4234';
  $display->content['new-2ded9f8f-c095-44ef-93ab-8049a95b4234'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-2ded9f8f-c095-44ef-93ab-8049a95b4234';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1b5aac9f-5f79-4bf3-937e-21eb3c95e7ec';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_5fa66dd4-2eff-4cbc-a83a-2900442871b0'] = $handler;

  return $export;
}
