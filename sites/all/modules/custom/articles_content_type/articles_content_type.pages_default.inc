<?php
/**
 * @file
 * articles_content_type.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function articles_content_type_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Article Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'article' => 'article',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
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
  $display->uuid = '0686608d-8a78-4d73-bd1c-ac49dc16ef45';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-05ae13c2-c9c1-4802-99ef-6f1495517d67';
  $pane->panel = 'one_fw_main';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '05ae13c2-c9c1-4802-99ef-6f1495517d67';
  $display->content['new-05ae13c2-c9c1-4802-99ef-6f1495517d67'] = $pane;
  $display->panels['one_fw_main'][0] = 'new-05ae13c2-c9c1-4802-99ef-6f1495517d67';
  $pane = new stdClass();
  $pane->pid = 'new-5ce633a0-d332-4931-b938-31b7380a0027';
  $pane->panel = 'one_fw_main';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'article container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5ce633a0-d332-4931-b938-31b7380a0027';
  $display->content['new-5ce633a0-d332-4931-b938-31b7380a0027'] = $pane;
  $display->panels['one_fw_main'][1] = 'new-5ce633a0-d332-4931-b938-31b7380a0027';
  $pane = new stdClass();
  $pane->pid = 'new-5d1901c9-3186-42d3-b292-cbc30100598d';
  $pane->panel = 'one_fw_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Related Datasets',
    'title_heading' => 'h2',
    'body' => '<div class="container">
<div class="dataset-preview">
<p><a href="https://dev.spc.links.com.au/data/dataset/public-domain-wcpfc-purse-seine-catch-data">Public Domain WCPFC Purse Seine Catch Data </a></p>

<div class="dataset-groups">
<p><img alt="..." src="https://dev.spc.links.com.au/sites/default/files/geoscience-sm_1.png" /> Geosience</p>
</div>

<p>Release Date: <span>May 28, 2018</span></p>

<div class="dataset-formats">File Format: <span>HTML</span> <span>JSON</span></div>
</div>

<div class="dataset-preview">
<p><a href="https://dev.spc.links.com.au/data/dataset/public-domain-wcpfc-purse-seine-catch-data">Public Domain WCPFC Purse Seine Catch Data </a></p>

<div class="dataset-groups">
<p><img alt="..." src="https://dev.spc.links.com.au/sites/default/files/geoscience-sm_1.png" /> Geosience</p>
</div>

<p>Release Date: <span>May 28, 2018</span></p>

<div class="dataset-formats">File Format: <span>HTML</span> <span>JSON</span></div>
</div>
</div>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'related-datasets',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5d1901c9-3186-42d3-b292-cbc30100598d';
  $display->content['new-5d1901c9-3186-42d3-b292-cbc30100598d'] = $pane;
  $display->panels['one_fw_main'][2] = 'new-5d1901c9-3186-42d3-b292-cbc30100598d';
  $pane = new stdClass();
  $pane->pid = 'new-cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $pane->panel = 'one_fw_main';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_similar_posts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'similar_posts',
      'links' => 1,
      'use_content_language' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Similar Posts',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'similar-posts',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $display->content['new-cffe60f8-73ee-4213-9cd0-767d0be2159a'] = $pane;
  $display->panels['one_fw_main'][3] = 'new-cffe60f8-73ee-4213-9cd0-767d0be2159a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_61172999-3eed-41bd-b184-c26a42d5ead1'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function articles_content_type_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'articles';
  $page->task = 'page';
  $page->admin_title = 'Articles';
  $page->admin_description = 'Provides articles list page';
  $page->path = 'blog';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_articles__panel';
  $handler->task = 'page';
  $handler->subtask = 'articles';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'articles-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7749ef16-8f7d-4c30-9e80-a72eea0d2f0e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_articles__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5057d41b-d093-4085-9295-3af44889af76';
  $pane->panel = 'middle';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'breadcrumb-box container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5057d41b-d093-4085-9295-3af44889af76';
  $display->content['new-5057d41b-d093-4085-9295-3af44889af76'] = $pane;
  $display->panels['middle'][0] = 'new-5057d41b-d093-4085-9295-3af44889af76';
  $pane = new stdClass();
  $pane->pid = 'new-29543fbb-9df4-49d7-a9e3-cc1d40acd1b8';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'articles_page_content';
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
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'articles-page-content',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '29543fbb-9df4-49d7-a9e3-cc1d40acd1b8';
  $display->content['new-29543fbb-9df4-49d7-a9e3-cc1d40acd1b8'] = $pane;
  $display->panels['middle'][1] = 'new-29543fbb-9df4-49d7-a9e3-cc1d40acd1b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['articles'] = $page;

  return $pages;

}
