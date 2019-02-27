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
  $pane->pid = 'new-172702ea-7dd6-42fb-a26e-5173122929b0';
  $pane->panel = 'one_fw_main';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
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
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '172702ea-7dd6-42fb-a26e-5173122929b0';
  $display->content['new-172702ea-7dd6-42fb-a26e-5173122929b0'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-172702ea-7dd6-42fb-a26e-5173122929b0';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9faf1a7a-9023-403d-a605-48d28358d08e';
  $display->content['new-9faf1a7a-9023-403d-a605-48d28358d08e'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-9faf1a7a-9023-403d-a605-48d28358d08e';
  $pane = new stdClass();
  $pane->pid = 'new-d77fbd0e-fe3c-493b-ae43-489aacb1b58b';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'dashboard_goals-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container dashboard-goals',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd77fbd0e-fe3c-493b-ae43-489aacb1b58b';
  $display->content['new-d77fbd0e-fe3c-493b-ae43-489aacb1b58b'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-d77fbd0e-fe3c-493b-ae43-489aacb1b58b';
  $pane = new stdClass();
  $pane->pid = 'new-179b9d45-cc36-4b03-81a3-f79c7458245d';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_interactive_chart_source';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '179b9d45-cc36-4b03-81a3-f79c7458245d';
  $display->content['new-179b9d45-cc36-4b03-81a3-f79c7458245d'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-179b9d45-cc36-4b03-81a3-f79c7458245d';
  $pane = new stdClass();
  $pane->pid = 'new-ee757a18-bc47-4feb-a6b1-b400f372f355';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_chart_help_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'container chart-help-text',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ee757a18-bc47-4feb-a6b1-b400f372f355';
  $display->content['new-ee757a18-bc47-4feb-a6b1-b400f372f355'] = $pane;
  $display->panels['one_fw_main'][4] = 'new-ee757a18-bc47-4feb-a6b1-b400f372f355';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_bab11f01-6388-4d01-a594-23983f3ff552'] = $handler;

  return $export;
}
