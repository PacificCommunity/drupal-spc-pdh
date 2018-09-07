<?php
/**
 * @file
 * dashboards_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dashboards_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dashboards content'.
  $permissions['create dashboards content'] = array(
    'name' => 'create dashboards content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any dashboards content'.
  $permissions['delete any dashboards content'] = array(
    'name' => 'delete any dashboards content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dashboards content'.
  $permissions['delete own dashboards content'] = array(
    'name' => 'delete own dashboards content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dashboards content'.
  $permissions['edit any dashboards content'] = array(
    'name' => 'edit any dashboards content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dashboards content'.
  $permissions['edit own dashboards content'] = array(
    'name' => 'edit own dashboards content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
