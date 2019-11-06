<?php

/**
 * @file
 * general_modules.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function general_modules_user_default_roles() {
  $roles = array();

  // Exported role: Content Editor.
  $roles['Content Editor'] = array(
    'name' => 'Content Editor',
    'weight' => 3,
  );

  // Exported role: Site Admin.
  $roles['Site Admin'] = array(
    'name' => 'Site Admin',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
