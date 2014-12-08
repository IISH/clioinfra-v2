<?php
/**
 * @file
 * clio_resource_overrides.features.inc
 */

/**
 * Implements hook_field_group_info_alter().
 */
function clio_resource_overrides_field_group_info_alter(&$data) {
  if (isset($data['group_link_api|node|resource|form'])) {
    $data['group_link_api|node|resource|form']->data['weight'] = 14; /* WAS: 11 */
  }
  if (isset($data['group_link_file|node|resource|form'])) {
    $data['group_link_file|node|resource|form']->data['weight'] = 13; /* WAS: 9 */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function clio_resource_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['node-resource-og_group_ref'])) {
    unset($data['node-resource-og_group_ref']);
  }
}
