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

  // Exported permission: 'create thematic_group content'.
  $permissions['create thematic_group content'] = array(
    'name' => 'create thematic_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any thematic_group content'.
  $permissions['delete any thematic_group content'] = array(
    'name' => 'delete any thematic_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own thematic_group content'.
  $permissions['delete own thematic_group content'] = array(
    'name' => 'delete own thematic_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any thematic_group content'.
  $permissions['edit any thematic_group content'] = array(
    'name' => 'edit any thematic_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own thematic_group content'.
  $permissions['edit own thematic_group content'] = array(
    'name' => 'edit own thematic_group content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
