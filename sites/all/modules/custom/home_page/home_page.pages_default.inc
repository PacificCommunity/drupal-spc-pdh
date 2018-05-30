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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '17f835fa-82b6-4062-8db5-ba52c7e7f587';
  $display->content['new-17f835fa-82b6-4062-8db5-ba52c7e7f587'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-17f835fa-82b6-4062-8db5-ba52c7e7f587';
  $pane = new stdClass();
  $pane->pid = 'new-63a88106-5b10-4a80-959e-8965fe91d13f';
  $pane->panel = 'one_fw_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="data-category-title"><h2>Browse by Data Category</h2></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '63a88106-5b10-4a80-959e-8965fe91d13f';
  $display->content['new-63a88106-5b10-4a80-959e-8965fe91d13f'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-63a88106-5b10-4a80-959e-8965fe91d13f';
  $pane = new stdClass();
  $pane->pid = 'new-30c9dbb2-c313-4ea7-b380-db0e386418b7';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'data_category';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '30c9dbb2-c313-4ea7-b380-db0e386418b7';
  $display->content['new-30c9dbb2-c313-4ea7-b380-db0e386418b7'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-30c9dbb2-c313-4ea7-b380-db0e386418b7';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f26b1da5-ff16-4919-814c-54cb9bcd09f7';
  $display->content['new-f26b1da5-ff16-4919-814c-54cb9bcd09f7'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-f26b1da5-ff16-4919-814c-54cb9bcd09f7';
  $pane = new stdClass();
  $pane->pid = 'new-933b1597-31a5-43da-816d-f065d38a1c53';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'blog_preview';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '933b1597-31a5-43da-816d-f065d38a1c53';
  $display->content['new-933b1597-31a5-43da-816d-f065d38a1c53'] = $pane;
  $display->panels['one_fw_main'][4] = 'new-933b1597-31a5-43da-816d-f065d38a1c53';
  $pane = new stdClass();
  $pane->pid = 'new-7b27c8e1-534e-4371-a946-7081425b0c24';
  $pane->panel = 'one_fw_main';
  $pane->type = 'panels_mini';
  $pane->subtype = 'datasets_on_home_page';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '7b27c8e1-534e-4371-a946-7081425b0c24';
  $display->content['new-7b27c8e1-534e-4371-a946-7081425b0c24'] = $pane;
  $display->panels['one_fw_main'][5] = 'new-7b27c8e1-534e-4371-a946-7081425b0c24';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
