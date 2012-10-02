<?php
/**
 * @file
 * hr_reliefweb.features.inc
 */

/**
 * Implements hook_custom_pub_defaults().
 */
function hr_reliefweb_custom_pub_defaults() {
  $options = array();
  // Exported option: reliefweb
  $options['reliefweb'] = array(
    'type' => 'reliefweb',
    'name' => t('Submit to Reliefweb'),
    'node_types' => array(
      'document' => t('Document'),
      'map' => t('Visual'),
    ),
  );

  return $options;
}
