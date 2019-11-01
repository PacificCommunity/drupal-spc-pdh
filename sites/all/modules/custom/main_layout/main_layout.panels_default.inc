<?php

/**
 * @file
 * main_layout.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function main_layout_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer';
  $mini->category = 'Basic Elements';
  $mini->admin_title = 'Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'one_main' => NULL,
      'two_50_top' => NULL,
      'two_50_first' => NULL,
      'two_50_second' => NULL,
      'two_50_bottom' => NULL,
      'two_33_66_top' => NULL,
      'two_33_66_first' => NULL,
      'two_33_66_second' => NULL,
      'two_33_66_bottom' => NULL,
    ),
    'two_50_top' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fcaaf868-55b0-4658-b81c-da0df739c76c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'footer';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9249440d-656f-420a-87c3-19268c25088b';
  $pane->panel = 'two_50_top';
  $pane->type = 'block';
  $pane->subtype = 'bean-partner-logos';
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
    'css_class' => 'footer-logos',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9249440d-656f-420a-87c3-19268c25088b';
  $display->content['new-9249440d-656f-420a-87c3-19268c25088b'] = $pane;
  $display->panels['two_50_top'][0] = 'new-9249440d-656f-420a-87c3-19268c25088b';
  $pane = new stdClass();
  $pane->pid = 'new-6fb19fad-fe86-4aa6-aa90-3615809dc482';
  $pane->panel = 'two_50_top';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-who-we-are-menu';
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
    'css_class' => 'footer-menus-block',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6fb19fad-fe86-4aa6-aa90-3615809dc482';
  $display->content['new-6fb19fad-fe86-4aa6-aa90-3615809dc482'] = $pane;
  $display->panels['two_50_top'][1] = 'new-6fb19fad-fe86-4aa6-aa90-3615809dc482';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}