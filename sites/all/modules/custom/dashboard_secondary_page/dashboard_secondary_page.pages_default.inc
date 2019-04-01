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
  $pane->pid = 'new-510a252d-42d6-4443-9e6c-14adb62691ac';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-banner-no-title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '%node:title',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'overridden-title',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '510a252d-42d6-4443-9e6c-14adb62691ac';
  $display->content['new-510a252d-42d6-4443-9e6c-14adb62691ac'] = $pane;
  $display->panels['middle'][0] = 'new-510a252d-42d6-4443-9e6c-14adb62691ac';
  $pane = new stdClass();
  $pane->pid = 'new-8fb1b918-aaf5-4e24-83f5-9c186c1a8373';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'dashboard_for_sdp';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
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
  $pane->uuid = '8fb1b918-aaf5-4e24-83f5-9c186c1a8373';
  $display->content['new-8fb1b918-aaf5-4e24-83f5-9c186c1a8373'] = $pane;
  $display->panels['middle'][1] = 'new-8fb1b918-aaf5-4e24-83f5-9c186c1a8373';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '94f25777-1130-4d35-8f14-7acc829e3675';
  $display->content['new-94f25777-1130-4d35-8f14-7acc829e3675'] = $pane;
  $display->panels['middle'][2] = 'new-94f25777-1130-4d35-8f14-7acc829e3675';
  $pane = new stdClass();
  $pane->pid = 'new-63fda8cf-1190-442d-b308-9efb6c1f8479';
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
    'override_title_text' => 'Link to all related datasets',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container dsp-datasets-wrapper',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '63fda8cf-1190-442d-b308-9efb6c1f8479';
  $display->content['new-63fda8cf-1190-442d-b308-9efb6c1f8479'] = $pane;
  $display->panels['middle'][3] = 'new-63fda8cf-1190-442d-b308-9efb6c1f8479';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_3fd542d7-ebeb-420a-9bb3-596b9533b5c8'] = $handler;

  return $export;
}
