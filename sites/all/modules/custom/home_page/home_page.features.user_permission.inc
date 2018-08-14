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

  // Exported permission: 'delete any homepage_backgrounds bean'.
  $permissions['delete any homepage_backgrounds bean'] = array(
    'name' => 'delete any homepage_backgrounds bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any homepage_backgrounds bean'.
  $permissions['edit any homepage_backgrounds bean'] = array(
    'name' => 'edit any homepage_backgrounds bean',
    'roles' => array(),
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

  return $permissions;
}
