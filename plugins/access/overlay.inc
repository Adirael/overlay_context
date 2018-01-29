<?php

/**
 * @file
 * Plugin to provide access control based upon node type.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Overlay'),
  'description' => t('Control access for overlayes pages.'),
  'callback' => 'overlay_ctools_access_check',
  'summary' => 'overlay_ctools_access_summary'
);


/**
 * Check for access.
 */
function overlay_ctools_access_check($conf, $context) {
  if(function_exists('overlay_get_mode')) {
    return overlay_get_mode() === 'child';
  }

  return false;
}

function overlay_ctools_access_summary() {
  return t('Current page is displayed inside an overlay');
}
