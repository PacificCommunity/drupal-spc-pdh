<?php
/**
 * @file
 * spc_home.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function spc_home_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'create any home_banner bean'.
  $permissions['create any home_banner bean'] = array(
    'name' => 'create any home_banner bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create featured_use_of_data content'.
  $permissions['create featured_use_of_data content'] = array(
    'name' => 'create featured_use_of_data content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any featured_use_of_data content'.
  $permissions['delete any featured_use_of_data content'] = array(
    'name' => 'delete any featured_use_of_data content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own featured_use_of_data content'.
  $permissions['delete own featured_use_of_data content'] = array(
    'name' => 'delete own featured_use_of_data content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any featured_use_of_data content'.
  $permissions['edit any featured_use_of_data content'] = array(
    'name' => 'edit any featured_use_of_data content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any home_banner bean'.
  $permissions['edit any home_banner bean'] = array(
    'name' => 'edit any home_banner bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit own featured_use_of_data content'.
  $permissions['edit own featured_use_of_data content'] = array(
    'name' => 'edit own featured_use_of_data content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'view any home_banner bean'.
  $permissions['view any home_banner bean'] = array(
    'name' => 'view any home_banner bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
