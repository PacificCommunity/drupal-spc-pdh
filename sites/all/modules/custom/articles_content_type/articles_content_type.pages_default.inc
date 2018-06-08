<?php
/**
 * @file
 * articles_content_type.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function articles_content_type_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Article Page',
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
              'article' => 'article',
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
  $display->uuid = '0686608d-8a78-4d73-bd1c-ac49dc16ef45';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-05ae13c2-c9c1-4802-99ef-6f1495517d67';
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
  $pane->css = array(
    'css_id' => 'article-breadcrumbs',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '05ae13c2-c9c1-4802-99ef-6f1495517d67';
  $display->content['new-05ae13c2-c9c1-4802-99ef-6f1495517d67'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-05ae13c2-c9c1-4802-99ef-6f1495517d67';
  $pane = new stdClass();
  $pane->pid = 'new-5ce633a0-d332-4931-b938-31b7380a0027';
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
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'article',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5ce633a0-d332-4931-b938-31b7380a0027';
  $display->content['new-5ce633a0-d332-4931-b938-31b7380a0027'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-5ce633a0-d332-4931-b938-31b7380a0027';
  $pane = new stdClass();
  $pane->pid = 'new-9f94a7a9-ea30-4fec-8f2e-2fd4ba5ab505';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_tweaks-recent_datasets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Related Datasets',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'related-datasets',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9f94a7a9-ea30-4fec-8f2e-2fd4ba5ab505';
  $display->content['new-9f94a7a9-ea30-4fec-8f2e-2fd4ba5ab505'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-9f94a7a9-ea30-4fec-8f2e-2fd4ba5ab505';
  $pane = new stdClass();
  $pane->pid = 'new-cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_similar_posts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'similar_posts',
      'links' => 1,
      'use_content_language' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Similar Posts',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'similar-posts',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $display->content['new-cffe60f8-73ee-4213-9cd0-767d0be2159a'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1'] = $handler;

  return $export;
}
