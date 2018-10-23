<?php
/**
 * @file
 * thematic_group.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function thematic_group_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any thematic_group_backgrounds bean'.
  $permissions['create any thematic_group_backgrounds bean'] = array(
    'name' => 'create any thematic_group_backgrounds bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create thematic_group content'.
  $permissions['create thematic_group content'] = array(
    'name' => 'create thematic_group content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any thematic_group content'.
  $permissions['delete any thematic_group content'] = array(
    'name' => 'delete any thematic_group content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any thematic_group_backgrounds bean'.
  $permissions['delete any thematic_group_backgrounds bean'] = array(
    'name' => 'delete any thematic_group_backgrounds bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete own thematic_group content'.
  $permissions['delete own thematic_group content'] = array(
    'name' => 'delete own thematic_group content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any thematic_group content'.
  $permissions['edit any thematic_group content'] = array(
    'name' => 'edit any thematic_group content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any thematic_group_backgrounds bean'.
  $permissions['edit any thematic_group_backgrounds bean'] = array(
    'name' => 'edit any thematic_group_backgrounds bean',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit own thematic_group content'.
  $permissions['edit own thematic_group content'] = array(
    'name' => 'edit own thematic_group content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'view any ckan_search bean'.
  $permissions['view any ckan_search bean'] = array(
    'name' => 'view any ckan_search bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
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

  // Exported permission: 'view any thematic_group_backgrounds bean'.
  $permissions['view any thematic_group_backgrounds bean'] = array(
    'name' => 'view any thematic_group_backgrounds bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
