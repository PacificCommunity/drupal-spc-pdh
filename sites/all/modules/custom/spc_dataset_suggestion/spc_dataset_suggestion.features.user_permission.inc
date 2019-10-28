<?php

/**
 * @file
 * spc_dataset_suggestion.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function spc_dataset_suggestion_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dataset_suggestion content'.
  $permissions['create dataset_suggestion content'] = array(
    'name' => 'create dataset_suggestion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dataset_suggestion content'.
  $permissions['delete any dataset_suggestion content'] = array(
    'name' => 'delete any dataset_suggestion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own dataset_suggestion content'.
  $permissions['delete own dataset_suggestion content'] = array(
    'name' => 'delete own dataset_suggestion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any dataset_suggestion content'.
  $permissions['edit any dataset_suggestion content'] = array(
    'name' => 'edit any dataset_suggestion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own dataset_suggestion content'.
  $permissions['edit own dataset_suggestion content'] = array(
    'name' => 'edit own dataset_suggestion content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
