<?php
/**
 * @file
 * thematic_group.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function thematic_group_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_1fc6b1ce-4cd3-48e1-bf44-c5f9d1f5bb8c';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Thematic group',
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
              'thematic_group' => 'thematic_group',
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
  $display->uuid = '67c97cd3-2939-4910-b76e-d709e0e78f3f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_1fc6b1ce-4cd3-48e1-bf44-c5f9d1f5bb8c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $pane->panel = 'one_fw_main';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
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
  $pane->uuid = '4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $display->content['new-4ce022c5-0b6a-422e-9df0-b82a44a5af38'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1fc6b1ce-4cd3-48e1-bf44-c5f9d1f5bb8c'] = $handler;

  return $export;
}
