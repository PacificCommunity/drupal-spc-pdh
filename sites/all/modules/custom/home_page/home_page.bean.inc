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

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'homepage_backgrounds';
  $bean_type->label = 'Homepage Backgrounds';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['homepage_backgrounds'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'members_countries';
  $bean_type->label = 'Members Countries';
  $bean_type->options = '';
  $bean_type->description = 'Provides block for members countries';
  $export['members_countries'] = $bean_type;

  return $export;
}
