<?php

/**
 * @file
 * ckeditor_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ckeditor_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imce',
  );

  return $permissions;
}
