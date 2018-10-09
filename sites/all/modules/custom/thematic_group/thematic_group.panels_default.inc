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
  $display->layout = 'two_50';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_50_top' => NULL,
      'two_50_first' => NULL,
      'two_50_second' => NULL,
      'two_50_bottom' => NULL,
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
  $pane->pid = 'new-539ef284-2ba5-4b39-8450-db3c5e9e5fdc';
  $pane->panel = 'two_50_first';
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
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '%node:nid',
    'url' => '',
    'display' => 'block_1',
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
  $pane->uuid = '539ef284-2ba5-4b39-8450-db3c5e9e5fdc';
  $display->content['new-539ef284-2ba5-4b39-8450-db3c5e9e5fdc'] = $pane;
  $display->panels['two_50_first'][0] = 'new-539ef284-2ba5-4b39-8450-db3c5e9e5fdc';
  $pane = new stdClass();
  $pane->pid = 'new-76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $pane->panel = 'two_50_second';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_tweaks-popular_datasets';
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
  $pane->uuid = '76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $display->content['new-76244da1-1c2e-45c3-adaa-b36e4cc17d39'] = $pane;
  $display->panels['two_50_second'][0] = 'new-76244da1-1c2e-45c3-adaa-b36e4cc17d39';
  $pane = new stdClass();
  $pane->pid = 'new-1e546a01-22f2-4d4e-8650-ddecd2e504a6';
  $pane->panel = 'two_50_top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Popular Datasets</h2>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1e546a01-22f2-4d4e-8650-ddecd2e504a6';
  $display->content['new-1e546a01-22f2-4d4e-8650-ddecd2e504a6'] = $pane;
  $display->panels['two_50_top'][0] = 'new-1e546a01-22f2-4d4e-8650-ddecd2e504a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['latest_datasets_and_insight'] = $mini;

  return $export;
}
