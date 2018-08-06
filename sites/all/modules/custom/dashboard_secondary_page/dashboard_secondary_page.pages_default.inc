<?php
/**
 * @file
 * dashboard_secondary_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dashboard_secondary_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_3fd542d7-ebeb-420a-9bb3-596b9533b5c8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Dashboard Secondary Page',
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
              'dsp' => 'dsp',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1723f719-d6ea-430f-9a05-e7ad773952f7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_3fd542d7-ebeb-420a-9bb3-596b9533b5c8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-94f25777-1130-4d35-8f14-7acc829e3675';
  $pane->panel = 'middle';
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
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '94f25777-1130-4d35-8f14-7acc829e3675';
  $display->content['new-94f25777-1130-4d35-8f14-7acc829e3675'] = $pane;
  $display->panels['middle'][0] = 'new-94f25777-1130-4d35-8f14-7acc829e3675';
  $pane = new stdClass();
  $pane->pid = 'new-a53806b1-4706-48e9-a71b-1e64bde69a9a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_dsp_datasets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a53806b1-4706-48e9-a71b-1e64bde69a9a';
  $display->content['new-a53806b1-4706-48e9-a71b-1e64bde69a9a'] = $pane;
  $display->panels['middle'][1] = 'new-a53806b1-4706-48e9-a71b-1e64bde69a9a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_3fd542d7-ebeb-420a-9bb3-596b9533b5c8'] = $handler;

  return $export;
}
