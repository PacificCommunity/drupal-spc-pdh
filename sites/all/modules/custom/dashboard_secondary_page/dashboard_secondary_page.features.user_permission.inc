<?php

/**
 * @file
 * dashboard_secondary_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dashboard_secondary_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dsp content'.
  $permissions['create dsp content'] = array(
    'name' => 'create dsp content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any dsp content'.
  $permissions['delete any dsp content'] = array(
    'name' => 'delete any dsp content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dsp content'.
  $permissions['delete own dsp content'] = array(
    'name' => 'delete own dsp content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dsp content'.
  $permissions['edit any dsp content'] = array(
    'name' => 'edit any dsp content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dsp content'.
  $permissions['edit own dsp content'] = array(
    'name' => 'edit own dsp content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
