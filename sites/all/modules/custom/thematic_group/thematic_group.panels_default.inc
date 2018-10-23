<?php
/**
 * @file
 * thematic_group.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function thematic_group_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'latest_datasets_and_insight';
  $mini->category = '';
  $mini->admin_title = 'Latest datasets and insight';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_50_top' => NULL,
      'two_50_first' => NULL,
      'two_50_second' => NULL,
      'two_50_bottom' => NULL,
      'one_main' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc8a6dc2-7df6-400f-96a0-172254721344';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'latest_datasets_and_insight';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $pane->panel = 'one_main';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_tweaks-popular_datasets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Popular Datasets',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $display->content['new-76244da1-1c2e-45c3-adaa-b36e4cc17d39'] = $pane;
  $display->panels['one_main'][0] = 'new-76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['latest_datasets_and_insight'] = $mini;

  return $export;
}
