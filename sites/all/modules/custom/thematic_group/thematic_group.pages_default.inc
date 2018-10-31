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
  $pane->pid = 'new-40b8b493-2c78-4d5c-9147-2db7dc5d4851';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-thematic-group-backgrounds';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '40b8b493-2c78-4d5c-9147-2db7dc5d4851';
  $display->content['new-40b8b493-2c78-4d5c-9147-2db7dc5d4851'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-40b8b493-2c78-4d5c-9147-2db7dc5d4851';
  $pane = new stdClass();
  $pane->pid = 'new-784926bc-d93f-4704-b671-6794d1edce72';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'browse_by_data_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'topic_dropdown',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '784926bc-d93f-4704-b671-6794d1edce72';
  $display->content['new-784926bc-d93f-4704-b671-6794d1edce72'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-784926bc-d93f-4704-b671-6794d1edce72';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5bd8518a-6dbd-406e-8780-3f96a6f61427';
  $display->content['new-5bd8518a-6dbd-406e-8780-3f96a6f61427'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-5bd8518a-6dbd-406e-8780-3f96a6f61427';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $display->content['new-4ce022c5-0b6a-422e-9df0-b82a44a5af38'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $pane = new stdClass();
  $pane->pid = 'new-7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'latest_datasets_and_insight';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'thematic-group-popular-datasets',
    'css_class' => 'panel-style-narrow panel-style-background-image',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $display->content['new-7bcf81d9-e00f-438d-bf0e-656b021b301e'] = $pane;
  $display->panels['one_fw_main'][4] = 'new-7bcf81d9-e00f-438d-bf0e-656b021b301e';
  $pane = new stdClass();
  $pane->pid = 'new-956cbdde-e6d7-456a-9998-72c0c9160ee2';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'data_insight_thematic';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 1,
    'override_title_text' => 'Data Insights',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'thematic_insight',
    'css_class' => 'panel-style-narrow',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '956cbdde-e6d7-456a-9998-72c0c9160ee2';
  $display->content['new-956cbdde-e6d7-456a-9998-72c0c9160ee2'] = $pane;
  $display->panels['one_fw_main'][5] = 'new-956cbdde-e6d7-456a-9998-72c0c9160ee2';
  $pane = new stdClass();
  $pane->pid = 'new-6ac2635d-f456-48be-b754-d09687317c08';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'latest_stories';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
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
    'css_class' => 'thematic-group-articles panel-style-narrow',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '6ac2635d-f456-48be-b754-d09687317c08';
  $display->content['new-6ac2635d-f456-48be-b754-d09687317c08'] = $pane;
  $display->panels['one_fw_main'][6] = 'new-6ac2635d-f456-48be-b754-d09687317c08';
  $pane = new stdClass();
  $pane->pid = 'new-dbb951a4-5c98-4608-a390-c518710e5ea3';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'articles_list-topic_latest';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Articles',
    'override_title_heading' => 'h2',
    'arguments' => array(
      'nid' => '',
    ),
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'thematic-group-articles panel-style-narrow',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'dbb951a4-5c98-4608-a390-c518710e5ea3';
  $display->content['new-dbb951a4-5c98-4608-a390-c518710e5ea3'] = $pane;
  $display->panels['one_fw_main'][7] = 'new-dbb951a4-5c98-4608-a390-c518710e5ea3';
  $pane = new stdClass();
  $pane->pid = 'new-fd88377d-2526-4207-a19c-644795a46ff0';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'spc_twitter-spc_twitter_topic_tweets';
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
    'css_id' => '',
    'css_class' => 'container latest-tweets-block panel-style-narrow',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'fd88377d-2526-4207-a19c-644795a46ff0';
  $display->content['new-fd88377d-2526-4207-a19c-644795a46ff0'] = $pane;
  $display->panels['one_fw_main'][8] = 'new-fd88377d-2526-4207-a19c-644795a46ff0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4ce022c5-0b6a-422e-9df0-b82a44a5af38';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1fc6b1ce-4cd3-48e1-bf44-c5f9d1f5bb8c'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function thematic_group_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'articles_by_topic';
  $page->task = 'page';
  $page->admin_title = 'Articles by topic';
  $page->admin_description = '';
  $page->path = 'articles/by-topic/%node';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_articles_by_topic__panel';
  $handler->task = 'page';
  $handler->subtask = 'articles_by_topic';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0ee05058-668c-4b96-94d2-8f94cb922e8d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_articles_by_topic__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-200984d1-dd6f-47eb-9370-9d48ef2b3c5e';
  $pane->panel = 'middle';
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
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '200984d1-dd6f-47eb-9370-9d48ef2b3c5e';
  $display->content['new-200984d1-dd6f-47eb-9370-9d48ef2b3c5e'] = $pane;
  $display->panels['middle'][0] = 'new-200984d1-dd6f-47eb-9370-9d48ef2b3c5e';
  $pane = new stdClass();
  $pane->pid = 'new-1cac2adc-44cb-48fe-9502-621d7afa91cd';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'articles_by_topic_page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '%node:nid',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1cac2adc-44cb-48fe-9502-621d7afa91cd';
  $display->content['new-1cac2adc-44cb-48fe-9502-621d7afa91cd'] = $pane;
  $display->panels['middle'][1] = 'new-1cac2adc-44cb-48fe-9502-621d7afa91cd';
  $pane = new stdClass();
  $pane->pid = 'new-d11d9b66-0558-4eed-b035-4469ffef6a3b';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'articles_by_topic_page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '6',
    'pager_id' => '0',
    'offset' => '1',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '%node:nid',
    'url' => '',
    'display' => 'block_2',
    'context' => array(
      0 => '',
    ),
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
    'css_class' => 'container articles-list',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd11d9b66-0558-4eed-b035-4469ffef6a3b';
  $display->content['new-d11d9b66-0558-4eed-b035-4469ffef6a3b'] = $pane;
  $display->panels['middle'][2] = 'new-d11d9b66-0558-4eed-b035-4469ffef6a3b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['articles_by_topic'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'articles_search';
  $page->task = 'page';
  $page->admin_title = 'Articles Search';
  $page->admin_description = 'Provides search articles list';
  $page->path = 'search/articles/!term/!thematic_area';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'term' => array(
      'id' => 1,
      'identifier' => 'Term',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'thematic_area' => array(
      'id' => 2,
      'identifier' => 'Thematic Area',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_articles_search__panel';
  $handler->task = 'page';
  $handler->subtask = 'articles_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search List',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Search ';
  $display->uuid = 'c14ff77e-1dc3-44b9-a2d7-5650cd84506f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_articles_search__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b29d238a-a968-4340-85c0-7e616a431dad';
  $pane->panel = 'middle';
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
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b29d238a-a968-4340-85c0-7e616a431dad';
  $display->content['new-b29d238a-a968-4340-85c0-7e616a431dad'] = $pane;
  $display->panels['middle'][0] = 'new-b29d238a-a968-4340-85c0-7e616a431dad';
  $pane = new stdClass();
  $pane->pid = 'new-4f5428cb-7bac-499b-b0d7-84f3984f1597';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'search_articles-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'keys' => '%term:html_safe',
      'field_ckan_thematic_group_id_value' => '%thematic_area:html_safe',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container articles-list',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4f5428cb-7bac-499b-b0d7-84f3984f1597';
  $display->content['new-4f5428cb-7bac-499b-b0d7-84f3984f1597'] = $pane;
  $display->panels['middle'][1] = 'new-4f5428cb-7bac-499b-b0d7-84f3984f1597';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b29d238a-a968-4340-85c0-7e616a431dad';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['articles_search'] = $page;

  return $pages;

}
