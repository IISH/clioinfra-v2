<?php
/**
 * @file
 * clio_resource_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function clio_resource_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_group
  $overrides["field_group.group_link_api|node|resource|form.data|weight"] = 14;
  $overrides["field_group.group_link_file|node|resource|form.data|weight"] = 13;

  // Exported overrides for: field_instance
  $overrides["field_instance.node-resource-og_group_ref.node-resource-og_group_ref"]["DELETED"] = TRUE;

 return $overrides;
}
