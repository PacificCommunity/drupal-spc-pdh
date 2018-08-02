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
  $pane->pid = 'new-62912134-5afa-48c9-8b28-d84d78c3120f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-thematic-page-heading';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'thematic-heading-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '62912134-5afa-48c9-8b28-d84d78c3120f';
  $display->content['new-62912134-5afa-48c9-8b28-d84d78c3120f'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-62912134-5afa-48c9-8b28-d84d78c3120f';
  $pane = new stdClass();
  $pane->pid = 'new-5bd8518a-6dbd-406e-8780-3f96a6f61427';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-thematic-landing-banner';
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
  $pane->css = array(
    'css_id' => 'thematic_landing_banner',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5bd8518a-6dbd-406e-8780-3f96a6f61427';
  $display->content['new-5bd8518a-6dbd-406e-8780-3f96a6f61427'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-5bd8518a-6dbd-406e-8780-3f96a6f61427';
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
    'override_title' => 1,
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
  $pane->css = array(
    'css_id' => 'node_content',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $display->content['new-4ce022c5-0b6a-422e-9df0-b82a44a5af38'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $pane = new stdClass();
  $pane->pid = 'new-7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'latest_datasets_and_insight';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Popular Datasets',
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
  $pane->uuid = '7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $display->content['new-7bcf81d9-e00f-438d-bf0e-656b021b301e'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $pane = new stdClass();
  $pane->pid = 'new-5a614e60-7b6c-4dfb-b83d-c0cbd947af5f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_articles_and_publications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
      'bypass_access' => 0,
      'view_mode' => 'related_articles_and_publication',
      'links' => 1,
      'use_content_language' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'thematic-group-articles',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5a614e60-7b6c-4dfb-b83d-c0cbd947af5f';
  $display->content['new-5a614e60-7b6c-4dfb-b83d-c0cbd947af5f'] = $pane;
  $display->panels['one_fw_main'][4] = 'new-5a614e60-7b6c-4dfb-b83d-c0cbd947af5f';
  $pane = new stdClass();
  $pane->pid = 'new-4f5fc7a9-76cb-46cf-8a66-9c78c6ba551f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Latest Tweets</h2>

<div class="col-md-3 col-sm-6 col-xs-12"><img alt="" height="447" src="/sites/all/themes/spc/img/spc/tweet1.png" width="297" /></div>

<div class="col-md-3 col-sm-6 col-xs-12"><img alt="" height="447" src="/sites/all/themes/spc/img/spc/tweet1.png" width="297" /></div>

',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'latest_tweets',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '4f5fc7a9-76cb-46cf-8a66-9c78c6ba551f';
  $display->content['new-4f5fc7a9-76cb-46cf-8a66-9c78c6ba551f'] = $pane;
  $display->panels['one_fw_main'][5] = 'new-4f5fc7a9-76cb-46cf-8a66-9c78c6ba551f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1fc6b1ce-4cd3-48e1-bf44-c5f9d1f5bb8c'] = $handler;

  return $export;
}
