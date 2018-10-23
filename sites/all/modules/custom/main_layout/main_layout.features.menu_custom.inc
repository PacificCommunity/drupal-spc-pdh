<?php
/**
 * @file
 * main_layout.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function main_layout_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-resources-menu.
  $menus['menu-resources-menu'] = array(
    'menu_name' => 'menu-resources-menu',
    'title' => 'Resources menu',
    'description' => '',
  );
  // Exported menu: menu-who-we-are-menu.
  $menus['menu-who-we-are-menu'] = array(
    'menu_name' => 'menu-who-we-are-menu',
    'title' => 'Who we are menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Resources menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Who we are menu');

  return $menus;
}
