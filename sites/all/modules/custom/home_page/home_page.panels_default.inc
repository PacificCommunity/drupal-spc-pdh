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
  $pane->pid = 'new-1002a62e-977e-4dba-8b46-4cc1b036861e';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'block';
  $pane->subtype = 'node-recent';
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
  $pane->uuid = '1002a62e-977e-4dba-8b46-4cc1b036861e';
  $display->content['new-1002a62e-977e-4dba-8b46-4cc1b036861e'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-1002a62e-977e-4dba-8b46-4cc1b036861e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1002a62e-977e-4dba-8b46-4cc1b036861e';
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
  $pane->pid = 'new-7043e1f5-0c5f-4e10-8317-79cfe621b6c5';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Browse by Data category',
    'title' => 'Browse by Data category',
    'title_heading' => 'h2',
    'body' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla pellentesque, leo a euismod accumsan, lectus arcu blandit sem, ut rutrum orci nulla eget orci. Sed orci odio, aliquet et tristique id, dapibus vitae nibh. Nunc dictum et diam nec facilisis. Nulla facilisi. Nulla facilisi. Duis ex dolor, facilisis quis sapien eu, dapibus lobortis augue. Nulla sodales mollis risus, non tempor lectus faucibus sed. Sed vel libero nibh. Vivamus in tortor orci. Praesent maximus, dolor a pharetra pulvinar, sem augue egestas est, et tristique nisl lorem nec leo.',
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
  $pane->uuid = '7043e1f5-0c5f-4e10-8317-79cfe621b6c5';
  $display->content['new-7043e1f5-0c5f-4e10-8317-79cfe621b6c5'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-7043e1f5-0c5f-4e10-8317-79cfe621b6c5';
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
  $pane->pid = 'new-87b0552b-034a-43c4-b986-6a4580a28b3d';
  $pane->panel = 'minipanel_one_main_fw';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Data insights',
    'title' => 'Data insights',
    'title_heading' => 'h2',
    'body' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque molestie sapien sit amet justo malesuada, facilisis lobortis purus commodo. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Donec luctus leo vel ipsum imperdiet ultrices. Phasellus et ligula leo. Duis auctor felis id fermentum tincidunt. Aliquam eu est vitae augue pellentesque iaculis eget condimentum sem. Praesent condimentum convallis libero non lacinia. Donec ac sapien tempor, tempor neque a, tempus quam. Aliquam volutpat dui in nulla iaculis, at condimentum libero malesuada. Praesent fringilla massa id lorem congue malesuada. Suspendisse eget ullamcorper erat. Ut elementum tristique porta.',
    'format' => 'filtered_html',
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
  $pane->uuid = '87b0552b-034a-43c4-b986-6a4580a28b3d';
  $display->content['new-87b0552b-034a-43c4-b986-6a4580a28b3d'] = $pane;
  $display->panels['minipanel_one_main_fw'][0] = 'new-87b0552b-034a-43c4-b986-6a4580a28b3d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['data_insights'] = $mini;

  return $export;
}
