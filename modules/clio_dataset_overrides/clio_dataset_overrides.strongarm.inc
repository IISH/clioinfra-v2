<?php
/**
 * @file
 * clio_dataset_overrides.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function clio_dataset_overrides_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dkan_dataset_form_additional_info';
  $strongarm->value = 0;
  $export['dkan_dataset_form_additional_info'] = $strongarm;

  return $export;
}
