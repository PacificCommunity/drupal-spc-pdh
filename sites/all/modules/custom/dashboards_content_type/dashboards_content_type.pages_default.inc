<?php
/**
 * @file
 * dashboards_content_type.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dashboards_content_type_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_bab11f01-6388-4d01-a594-23983f3ff552';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Dashboard',
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
              'dashboards' => 'dashboards',
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
      'center' => NULL,
      'one_fw_main' => NULL,
    ),
    'one_fw_main' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0213ca9e-e272-4344-99df-7f9a4aeceec2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_bab11f01-6388-4d01-a594-23983f3ff552';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9faf1a7a-9023-403d-a605-48d28358d08e';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '9faf1a7a-9023-403d-a605-48d28358d08e';
  $display->content['new-9faf1a7a-9023-403d-a605-48d28358d08e'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-9faf1a7a-9023-403d-a605-48d28358d08e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_bab11f01-6388-4d01-a594-23983f3ff552'] = $handler;

  return $export;
}
