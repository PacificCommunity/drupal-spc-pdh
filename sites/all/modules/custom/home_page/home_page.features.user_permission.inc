<?php
/**
 * @file
 * home_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function home_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any homepage_backgrounds bean'.
  $permissions['create any homepage_backgrounds bean'] = array(
    'name' => 'create any homepage_backgrounds bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any members_countries bean'.
  $permissions['create any members_countries bean'] = array(
    'name' => 'create any members_countries bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any homepage_backgrounds bean'.
  $permissions['delete any homepage_backgrounds bean'] = array(
    'name' => 'delete any homepage_backgrounds bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any members_countries bean'.
  $permissions['delete any members_countries bean'] = array(
    'name' => 'delete any members_countries bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any homepage_backgrounds bean'.
  $permissions['edit any homepage_backgrounds bean'] = array(
    'name' => 'edit any homepage_backgrounds bean',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any members_countries bean'.
  $permissions['edit any members_countries bean'] = array(
    'name' => 'edit any members_countries bean',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any homepage_backgrounds bean'.
  $permissions['view any homepage_backgrounds bean'] = array(
    'name' => 'view any homepage_backgrounds bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any members_countries bean'.
  $permissions['view any members_countries bean'] = array(
    'name' => 'view any members_countries bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
