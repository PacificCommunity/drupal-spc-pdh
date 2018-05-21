<?php
/**
 * @file
 * home_page.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function home_page_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'article_on_home_page';
  $bean_type->label = 'Article on Home Page';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['article_on_home_page'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'browse_by_data_category';
  $bean_type->label = 'Browse by Data Category';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['browse_by_data_category'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'ckan_search';
  $bean_type->label = 'CKAN Search';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['ckan_search'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'home_banner';
  $bean_type->label = 'Home banner';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['home_banner'] = $bean_type;

  return $export;
}
