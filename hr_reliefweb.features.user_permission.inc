<?php
/**
 * @file
 * hr_reliefweb.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_reliefweb_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit_custom_pub_reliefweb.
  $permissions['edit_custom_pub_reliefweb'] = array(
    'name' => 'edit_custom_pub_reliefweb',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'custom_pub',
  );

  return $permissions;
}
