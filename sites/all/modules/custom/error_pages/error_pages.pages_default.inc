<?php
/**
 * @file
 * error_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function error_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'access_denied';
  $page->task = 'page';
  $page->admin_title = 'Access denied';
  $page->admin_description = '';
  $page->path = 'access-denied';
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
  $handler->name = 'page_access_denied__panel_context_4dd8fa2e-b63e-4435-b1d6-bdae22b705cb';
  $handler->task = 'page';
  $handler->subtask = 'access_denied';
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
  );
  $display = new panels_display();
  $display->layout = 'one';
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
  $display->uuid = 'ccea45ee-1127-42be-b2fe-9ff6dfe2cb70';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e374f476-b3c7-4d9b-8221-143a37f69cda';
    $pane->panel = 'one_main';
    $pane->type = 'access_denied';
    $pane->subtype = 'access_denied';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e374f476-b3c7-4d9b-8221-143a37f69cda';
    $display->content['new-e374f476-b3c7-4d9b-8221-143a37f69cda'] = $pane;
    $display->panels['one_main'][0] = 'new-e374f476-b3c7-4d9b-8221-143a37f69cda';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['access_denied'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_not_found';
  $page->task = 'page';
  $page->admin_title = 'Page not found';
  $page->admin_description = '';
  $page->path = 'page-not-found';
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
  $handler->name = 'page_page_not_found__panel_context_a2872caa-1648-4b07-94d8-572d23c1003c';
  $handler->task = 'page';
  $handler->subtask = 'page_not_found';
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
  );
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6510d6c0-f5c8-42c3-8955-5429ad29c4e4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-443d375d-96ac-42d4-8146-c4de51febcb3';
    $pane->panel = 'one_main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '443d375d-96ac-42d4-8146-c4de51febcb3';
    $display->content['new-443d375d-96ac-42d4-8146-c4de51febcb3'] = $pane;
    $display->panels['one_main'][0] = 'new-443d375d-96ac-42d4-8146-c4de51febcb3';
    $pane = new stdClass();
    $pane->pid = 'new-b525dddd-5f24-42a9-8cd4-ca840b10023d';
    $pane->panel = 'one_main';
    $pane->type = 'not_found';
    $pane->subtype = 'not_found';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b525dddd-5f24-42a9-8cd4-ca840b10023d';
    $display->content['new-b525dddd-5f24-42a9-8cd4-ca840b10023d'] = $pane;
    $display->panels['one_main'][1] = 'new-b525dddd-5f24-42a9-8cd4-ca840b10023d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_not_found'] = $page;

  return $pages;

}
