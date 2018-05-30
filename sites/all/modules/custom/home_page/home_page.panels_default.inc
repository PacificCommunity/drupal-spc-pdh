<?php
/**
 * @file
 * home_page.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function home_page_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'blog_preview';
  $mini->category = 'Home Page';
  $mini->admin_title = 'Blog preview';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'minipanel_one_main_fw' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '063a336d-2621-43b1-a302-db7fcb43f04a';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'blog_preview';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7545418a-c403-40e9-835b-2be3335359c8';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'block';
  $pane->subtype = 'bean-article-on-home-page';
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
  $pane->uuid = '7545418a-c403-40e9-835b-2be3335359c8';
  $display->content['new-7545418a-c403-40e9-835b-2be3335359c8'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-7545418a-c403-40e9-835b-2be3335359c8';
  $pane = new stdClass();
  $pane->pid = 'new-3f7a85b7-7328-49ac-b648-7f39df5a3fda';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="/blog" class="view-all-link">View All</a>',
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
  $pane->uuid = '3f7a85b7-7328-49ac-b648-7f39df5a3fda';
  $display->content['new-3f7a85b7-7328-49ac-b648-7f39df5a3fda'] = $pane;
  $display->panels['minipanel_one_main_fw'][1] = 'new-3f7a85b7-7328-49ac-b648-7f39df5a3fda';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['blog_preview'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'data_category';
  $mini->category = 'Home Page';
  $mini->admin_title = 'Data category';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'minipanel_one_main_fw' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '84f283f1-ff2b-4357-8d3d-e66b37c3a020';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'data_category';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d81f15e8-602a-42a8-87cc-5c120a104342';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'block';
  $pane->subtype = 'bean-browse-by-data-category';
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
  $pane->uuid = 'd81f15e8-602a-42a8-87cc-5c120a104342';
  $display->content['new-d81f15e8-602a-42a8-87cc-5c120a104342'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-d81f15e8-602a-42a8-87cc-5c120a104342';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['data_category'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'data_insights';
  $mini->category = 'Home Page';
  $mini->admin_title = 'Data insights';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'minipanel_one_main_fw' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '14f9ae78-b7ff-4ac0-9d4b-a8aa11237585';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'data_insights';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ca363cdb-2029-4a30-a17a-c551ac5d9568';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'block';
  $pane->subtype = 'views-data_insights_promoted-block';
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
  $pane->uuid = 'ca363cdb-2029-4a30-a17a-c551ac5d9568';
  $display->content['new-ca363cdb-2029-4a30-a17a-c551ac5d9568'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-ca363cdb-2029-4a30-a17a-c551ac5d9568';
  $pane = new stdClass();
  $pane->pid = 'new-633f1b3e-6783-402e-bda4-33e5e0e03e50';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="/data-insights" class="view-all-link">View All</a>',
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
  $pane->uuid = '633f1b3e-6783-402e-bda4-33e5e0e03e50';
  $display->content['new-633f1b3e-6783-402e-bda4-33e5e0e03e50'] = $pane;
  $display->panels['minipanel_one_main_fw'][1] = 'new-633f1b3e-6783-402e-bda4-33e5e0e03e50';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['data_insights'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'datasets_on_home_page';
  $mini->category = 'Home Page';
  $mini->admin_title = 'Datasets on Home Page';
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
  $display->uuid = 'fffef516-1e37-4281-9bc5-1b12a7d26492';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'datasets_on_home_page';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-62fd3d7b-aa9c-496a-986c-d3e9001b0521';
  $pane->panel = 'two_50_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Latest Datasets',
    'title_heading' => 'h2',
    'body' => '<div class=\'dataset-on-home-page\'>
<p class=\'dataset-title\'>Supporting Data Driven Progress Towards SDGs in Pacific Agriculture and Fisheries</p>
<div class=\'dataset-groups\'><p><img src="https://dev.spc.links.com.au/sites/default/files/geoscience.png" /> Geosience</p></div>
<p class=\'dataset-date\'>Release Date: <span>May 28, 2018</span></p>
<div class=\'dataset-formats\'>File Format: <span>HTML</span><span>JSON</span></div>
</div>',
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
  $pane->uuid = '62fd3d7b-aa9c-496a-986c-d3e9001b0521';
  $display->content['new-62fd3d7b-aa9c-496a-986c-d3e9001b0521'] = $pane;
  $display->panels['two_50_first'][0] = 'new-62fd3d7b-aa9c-496a-986c-d3e9001b0521';
  $pane = new stdClass();
  $pane->pid = 'new-16e146b8-03d8-4014-a2f5-30acd3bb1904';
  $pane->panel = 'two_50_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="/data" class="view-all-link">View All</a>',
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
  $pane->uuid = '16e146b8-03d8-4014-a2f5-30acd3bb1904';
  $display->content['new-16e146b8-03d8-4014-a2f5-30acd3bb1904'] = $pane;
  $display->panels['two_50_first'][1] = 'new-16e146b8-03d8-4014-a2f5-30acd3bb1904';
  $pane = new stdClass();
  $pane->pid = 'new-76f9f0f6-90f4-4ffa-8af3-d1c695ee883e';
  $pane->panel = 'two_50_second';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Popular Datasets',
    'title_heading' => 'h2',
    'body' => '<div class=\'dataset-on-home-page\'>
<p class=\'dataset-title\'>Supporting Data Driven Progress Towards SDGs in Pacific Agriculture and Fisheries</p>
<div class=\'dataset-groups\'><p><img src="https://dev.spc.links.com.au/sites/default/files/geoscience.png" /> Geosience</p></div>
<p class=\'dataset-date\'>Release Date: <span>May 28, 2018</span></p>
<div class=\'dataset-formats\'>File Format: <span>HTML</span><span>JSON</span></div>
</div>',
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
  $pane->uuid = '76f9f0f6-90f4-4ffa-8af3-d1c695ee883e';
  $display->content['new-76f9f0f6-90f4-4ffa-8af3-d1c695ee883e'] = $pane;
  $display->panels['two_50_second'][0] = 'new-76f9f0f6-90f4-4ffa-8af3-d1c695ee883e';
  $pane = new stdClass();
  $pane->pid = 'new-718d8023-bac3-4a73-83d0-8f3f8e574c10';
  $pane->panel = 'two_50_second';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="/data" class="view-all-link">View All</a>',
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
  $pane->uuid = '718d8023-bac3-4a73-83d0-8f3f8e574c10';
  $display->content['new-718d8023-bac3-4a73-83d0-8f3f8e574c10'] = $pane;
  $display->panels['two_50_second'][1] = 'new-718d8023-bac3-4a73-83d0-8f3f8e574c10';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['datasets_on_home_page'] = $mini;

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
