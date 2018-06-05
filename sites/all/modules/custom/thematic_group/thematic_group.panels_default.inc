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
  $pane->pid = 'new-0eb2a036-cb83-45c3-a6c0-d98e690aae67';
  $pane->panel = 'two_50_first';
  $pane->type = 'block';
  $pane->subtype = 'views-data_insights_promoted-block';
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
    'css_id' => 'thematic_insight',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0eb2a036-cb83-45c3-a6c0-d98e690aae67';
  $display->content['new-0eb2a036-cb83-45c3-a6c0-d98e690aae67'] = $pane;
  $display->panels['two_50_first'][0] = 'new-0eb2a036-cb83-45c3-a6c0-d98e690aae67';
  $pane = new stdClass();
  $pane->pid = 'new-435c4a1a-3d9b-4587-9fa9-bfb8b1941fa8';
  $pane->panel = 'two_50_second';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_tweaks-recent_datasets';
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
  $pane->uuid = '435c4a1a-3d9b-4587-9fa9-bfb8b1941fa8';
  $display->content['new-435c4a1a-3d9b-4587-9fa9-bfb8b1941fa8'] = $pane;
  $display->panels['two_50_second'][0] = 'new-435c4a1a-3d9b-4587-9fa9-bfb8b1941fa8';
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
    'body' => '<h2>Latest Datasets</h2>',
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
  $display->title_pane = 'new-0eb2a036-cb83-45c3-a6c0-d98e690aae67';
  $mini->display = $display;
  $export['latest_datasets_and_insight'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'thematic_articles_and_publicatio';
  $mini->category = '';
  $mini->admin_title = 'Thematic Articles and Publications';
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
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '214794de-cbf3-4540-a29b-ded00a24e83c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'thematic_articles_and_publicatio';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-83bd5702-2554-4752-8ae0-59df75b35b65';
  $pane->panel = 'one_main';
  $pane->type = 'block';
  $pane->subtype = 'views-5a4b599b10ad20ed69c3b49082b1b080';
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
  $pane->uuid = '83bd5702-2554-4752-8ae0-59df75b35b65';
  $display->content['new-83bd5702-2554-4752-8ae0-59df75b35b65'] = $pane;
  $display->panels['one_main'][0] = 'new-83bd5702-2554-4752-8ae0-59df75b35b65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-83bd5702-2554-4752-8ae0-59df75b35b65';
  $mini->display = $display;
  $export['thematic_articles_and_publicatio'] = $mini;

  return $export;
}
