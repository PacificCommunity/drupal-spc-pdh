<?php

/**
 * @file
 * home_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function home_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel_context_8907be75-9023-421a-b4f1-de9d9ab18b92';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Home',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '12043562-553b-493f-a7c6-5b4098857136';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_8907be75-9023-421a-b4f1-de9d9ab18b92';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d0044610-f057-41a9-950f-76d46147504a';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-homepage-backgrounds';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd0044610-f057-41a9-950f-76d46147504a';
  $display->content['new-d0044610-f057-41a9-950f-76d46147504a'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-d0044610-f057-41a9-950f-76d46147504a';
  $pane = new stdClass();
  $pane->pid = 'new-17f835fa-82b6-4062-8db5-ba52c7e7f587';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'home_banner';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '17f835fa-82b6-4062-8db5-ba52c7e7f587';
  $display->content['new-17f835fa-82b6-4062-8db5-ba52c7e7f587'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-17f835fa-82b6-4062-8db5-ba52c7e7f587';
  $pane = new stdClass();
  $pane->pid = 'new-cc3b4e93-95d2-4708-a164-4e516e8f451d';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'home_page-home_page_stats_show';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cc3b4e93-95d2-4708-a164-4e516e8f451d';
  $display->content['new-cc3b4e93-95d2-4708-a164-4e516e8f451d'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-cc3b4e93-95d2-4708-a164-4e516e8f451d';
  $pane = new stdClass();
  $pane->pid = 'new-34ff7308-3e2b-4102-adb1-9dec7b8d3de4';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'dashboards_on_home_page';
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
    'display' => 'default',
    'override_title' => 0,
    'override_title_text' => 'Dashboards',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'dashboards-home',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '34ff7308-3e2b-4102-adb1-9dec7b8d3de4';
  $display->content['new-34ff7308-3e2b-4102-adb1-9dec7b8d3de4'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-34ff7308-3e2b-4102-adb1-9dec7b8d3de4';
  $pane = new stdClass();
  $pane->pid = 'new-f26b1da5-ff16-4919-814c-54cb9bcd09f7';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'data_insights';
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f26b1da5-ff16-4919-814c-54cb9bcd09f7';
  $display->content['new-f26b1da5-ff16-4919-814c-54cb9bcd09f7'] = $pane;
  $display->panels['one_fw_main'][4] = 'new-f26b1da5-ff16-4919-814c-54cb9bcd09f7';
  $pane = new stdClass();
  $pane->pid = 'new-236ae88a-4fbd-4499-9e20-c293dbba6ca1';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-home-members-countries';
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
    'css_id' => '',
    'css_class' => 'member-countries',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '236ae88a-4fbd-4499-9e20-c293dbba6ca1';
  $display->content['new-236ae88a-4fbd-4499-9e20-c293dbba6ca1'] = $pane;
  $display->panels['one_fw_main'][5] = 'new-236ae88a-4fbd-4499-9e20-c293dbba6ca1';
  $pane = new stdClass();
  $pane->pid = 'new-02ca8d4b-ae3c-4f9b-a209-3f1bd17643d8';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'stories_on_the_hp';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '02ca8d4b-ae3c-4f9b-a209-3f1bd17643d8';
  $display->content['new-02ca8d4b-ae3c-4f9b-a209-3f1bd17643d8'] = $pane;
  $display->panels['one_fw_main'][6] = 'new-02ca8d4b-ae3c-4f9b-a209-3f1bd17643d8';
  $pane = new stdClass();
  $pane->pid = 'new-9205a530-2050-4804-b56d-2bd6b5231ae0';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_dataset_tabs_block';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '9205a530-2050-4804-b56d-2bd6b5231ae0';
  $display->content['new-9205a530-2050-4804-b56d-2bd6b5231ae0'] = $pane;
  $display->panels['one_fw_main'][7] = 'new-9205a530-2050-4804-b56d-2bd6b5231ae0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
