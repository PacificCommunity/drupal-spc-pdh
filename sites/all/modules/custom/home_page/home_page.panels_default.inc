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
  $display->layout = 'one_fw';
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
  $pane->pid = 'new-a23eef4f-f927-4451-a429-3d70e150ebb2';
  $pane->panel = 'one_fw_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Data Insights</h2>
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
  $pane->uuid = 'a23eef4f-f927-4451-a429-3d70e150ebb2';
  $display->content['new-a23eef4f-f927-4451-a429-3d70e150ebb2'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-a23eef4f-f927-4451-a429-3d70e150ebb2';
  $pane = new stdClass();
  $pane->pid = 'new-9c300bbf-2b3f-458b-8891-e92c45b3b333';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'data_insights_promoted';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->uuid = '9c300bbf-2b3f-458b-8891-e92c45b3b333';
  $display->content['new-9c300bbf-2b3f-458b-8891-e92c45b3b333'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-9c300bbf-2b3f-458b-8891-e92c45b3b333';
  $pane = new stdClass();
  $pane->pid = 'new-633f1b3e-6783-402e-bda4-33e5e0e03e50';
  $pane->panel = 'one_fw_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p class="rtecenter"><a class="view-all-link" href="/data-insights">View All</a></p>
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '633f1b3e-6783-402e-bda4-33e5e0e03e50';
  $display->content['new-633f1b3e-6783-402e-bda4-33e5e0e03e50'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-633f1b3e-6783-402e-bda4-33e5e0e03e50';
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
  $pane->pid = 'new-235cc7f0-ceb5-4eb4-a4dc-b6149b16a8fb';
  $pane->panel = 'two_50_first';
  $pane->type = 'block';
  $pane->subtype = 'ckan_tweaks-ckan_tweaks-recent_datasets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Latest Datasets',
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
  $pane->uuid = '235cc7f0-ceb5-4eb4-a4dc-b6149b16a8fb';
  $display->content['new-235cc7f0-ceb5-4eb4-a4dc-b6149b16a8fb'] = $pane;
  $display->panels['two_50_first'][0] = 'new-235cc7f0-ceb5-4eb4-a4dc-b6149b16a8fb';
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
  $pane->pid = 'new-0b9ed538-e3a5-4415-bf4e-0953ad3f9aab';
  $pane->panel = 'two_50_second';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0b9ed538-e3a5-4415-bf4e-0953ad3f9aab';
  $display->content['new-0b9ed538-e3a5-4415-bf4e-0953ad3f9aab'] = $pane;
  $display->panels['two_50_second'][0] = 'new-0b9ed538-e3a5-4415-bf4e-0953ad3f9aab';
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
  $pane = new stdClass();
  $pane->pid = 'new-3cde4525-cc8c-461a-8a74-d726a8854ffc';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views';
  $pane->subtype = 'browse_by_data_category';
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
    'display' => 'block_1',
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
    'css_class' => 'topics-home',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3cde4525-cc8c-461a-8a74-d726a8854ffc';
  $display->content['new-3cde4525-cc8c-461a-8a74-d726a8854ffc'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-3cde4525-cc8c-461a-8a74-d726a8854ffc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2b4efde0-2143-4d0f-b9e9-3da0bee7cbca';
  $mini->display = $display;
  $export['home_banner'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'stories_on_the_hp';
  $mini->category = '';
  $mini->admin_title = 'Stories on the HP';
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
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3f404461-52e1-48b8-9db6-fd8f3e8da946';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'stories_on_the_hp';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6fac0acd-c0de-42b0-a031-c189a819cd8b';
  $pane->panel = 'one_fw_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'articles_list-home_latest';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Latest Stories',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'latest-stories-slider',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6fac0acd-c0de-42b0-a031-c189a819cd8b';
  $display->content['new-6fac0acd-c0de-42b0-a031-c189a819cd8b'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-6fac0acd-c0de-42b0-a031-c189a819cd8b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6fac0acd-c0de-42b0-a031-c189a819cd8b';
  $mini->display = $display;
  $export['stories_on_the_hp'] = $mini;

  return $export;
}