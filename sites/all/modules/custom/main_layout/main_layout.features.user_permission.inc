<?php
/**
 * @file
 * main_layout.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function main_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any partner_logos bean'.
  $permissions['create any partner_logos bean'] = array(
    'name' => 'create any partner_logos bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any social_links bean'.
  $permissions['create any social_links bean'] = array(
    'name' => 'create any social_links bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any partner_logos bean'.
  $permissions['delete any partner_logos bean'] = array(
    'name' => 'delete any partner_logos bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any social_links bean'.
  $permissions['delete any social_links bean'] = array(
    'name' => 'delete any social_links bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any partner_logos bean'.
  $permissions['edit any partner_logos bean'] = array(
    'name' => 'edit any partner_logos bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any social_links bean'.
  $permissions['edit any social_links bean'] = array(
    'name' => 'edit any social_links bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any partner_logos bean'.
  $permissions['view any partner_logos bean'] = array(
    'name' => 'view any partner_logos bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any social_links bean'.
  $permissions['view any social_links bean'] = array(
    'name' => 'view any social_links bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
