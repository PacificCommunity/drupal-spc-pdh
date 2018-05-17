<?php
/**
 * @file
 * spc_home.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function spc_home_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'home_banner';
  $mini->category = 'Home Page';
  $mini->admin_title = 'Home Banner';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main_fw' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6153e40e-34ea-47dc-b71a-f8132be4d5d1';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'home_banner';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2b4efde0-2143-4d0f-b9e9-3da0bee7cbca';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-home-banner';
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
  $pane->uuid = '2b4efde0-2143-4d0f-b9e9-3da0bee7cbca';
  $display->content['new-2b4efde0-2143-4d0f-b9e9-3da0bee7cbca'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-2b4efde0-2143-4d0f-b9e9-3da0bee7cbca';
  $pane = new stdClass();
  $pane->pid = 'new-25512a04-102a-41fd-9b18-ed94e04ecbcf';
  $pane->panel = 'one_fw_main';
  $pane->type = 'block';
  $pane->subtype = 'bean-ckan-search';
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
  $pane->uuid = '25512a04-102a-41fd-9b18-ed94e04ecbcf';
  $display->content['new-25512a04-102a-41fd-9b18-ed94e04ecbcf'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-25512a04-102a-41fd-9b18-ed94e04ecbcf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2b4efde0-2143-4d0f-b9e9-3da0bee7cbca';
  $mini->display = $display;
  $export['home_banner'] = $mini;

  return $export;
}
