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
  $pane->pid = 'new-08114e97-1b7d-46c9-a63c-b58478ed1886';
  $pane->panel = 'two_50_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h3',
    'body' => '<h3>CONNECT</h3>
<div class="social-icons"></div>',
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
  $pane->uuid = '08114e97-1b7d-46c9-a63c-b58478ed1886';
  $display->content['new-08114e97-1b7d-46c9-a63c-b58478ed1886'] = $pane;
  $display->panels['two_50_first'][0] = 'new-08114e97-1b7d-46c9-a63c-b58478ed1886';
  $pane = new stdClass();
  $pane->pid = 'new-6027e9da-b03d-4355-a61a-d1a216639f6a';
  $pane->panel = 'two_50_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="row">
<div class="col-md-6">
<h3>WHO WE ARE</h3>

<ul>
	<li>About Us</li>
	<li>Member</li>
	<li>Contact Us</li>
	<li>Staff Email</li>
	<li>Our Work</li>
</ul>
</div>

<div class="col-md-6">
<h3>RESOURCES</h3>

<ul>
    <li><a href="https://dev.spc.links.com.au/content/member-countries">Member Countries</a></li>
	<li>Privacy Policy</li>
	<li>Terms &amp; Condions</li>
	<li>Sitemap</li>
	<li>FAQ</li>
</ul>
</div>
</div>
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6027e9da-b03d-4355-a61a-d1a216639f6a';
  $display->content['new-6027e9da-b03d-4355-a61a-d1a216639f6a'] = $pane;
  $display->panels['two_50_first'][1] = 'new-6027e9da-b03d-4355-a61a-d1a216639f6a';
  $pane = new stdClass();
  $pane->pid = 'new-d882214a-580b-4b52-afd8-f3406fbf6749';
  $pane->panel = 'two_50_second';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h3',
    'body' => '<h3>NEWSLETTER</h3>
<p>Be the first one to know about the latest updated data and our featured publications</p>
<input type="text" placeholder=" Enter your email adres" /> <input type="submit" value="SUBSCRIBE" />',
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
  $pane->uuid = 'd882214a-580b-4b52-afd8-f3406fbf6749';
  $display->content['new-d882214a-580b-4b52-afd8-f3406fbf6749'] = $pane;
  $display->panels['two_50_second'][0] = 'new-d882214a-580b-4b52-afd8-f3406fbf6749';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}
