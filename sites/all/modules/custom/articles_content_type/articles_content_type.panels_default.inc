<?php

/**
 * @file
 * articles_content_type.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function articles_content_type_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'articles_page_content';
  $mini->category = 'Articles';
  $mini->admin_title = 'Articles page content';
  $mini->admin_description = 'Provides container for articles page';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'middle' => NULL,
      'default' => NULL,
      'minipanel_one_main' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
    'minipanel_one_main' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '86321456-3383-4bfd-b347-40778b0f7125';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'articles_page_content';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-68d8209c-f1a4-4e02-9576-0695f4c11e24';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'articles_list-panel_pane_2';
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
    'css_class' => 'container articles-list',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '68d8209c-f1a4-4e02-9576-0695f4c11e24';
  $display->content['new-68d8209c-f1a4-4e02-9576-0695f4c11e24'] = $pane;
  $display->panels['middle'][0] = 'new-68d8209c-f1a4-4e02-9576-0695f4c11e24';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['articles_page_content'] = $mini;

  return $export;
}
