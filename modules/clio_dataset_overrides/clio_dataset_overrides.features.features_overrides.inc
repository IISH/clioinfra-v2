<?php
/**
 * @file
 * clio_dataset_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function clio_dataset_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_temporal_coverage.settings|granularity|day"] = 0;
  $overrides["field_base.field_temporal_coverage.settings|granularity|hour"] = 0;
  $overrides["field_base.field_temporal_coverage.settings|granularity|minute"] = 0;
  $overrides["field_base.field_temporal_coverage.settings|granularity|month"] = 0;
  $overrides["field_base.field_temporal_coverage.settings|granularity|second"] = 0;
  $overrides["field_base.field_temporal_coverage.settings|timezone_db"] = '';
  $overrides["field_base.field_temporal_coverage.settings|tz_handling"] = 'none';

  // Exported overrides for: field_group
  $overrides["field_group.group_additional|node|dataset|default.data|children|1"] = 'field_spatial_geographical_cover';
  $overrides["field_group.group_additional|node|dataset|default.data|children|10"] = 'field_indicator';
  $overrides["field_group.group_additional|node|dataset|default.data|children|11"] = 'release_date';
  $overrides["field_group.group_additional|node|dataset|default.data|children|12"] = 'modified_date';
  $overrides["field_group.group_additional|node|dataset|default.data|children|13"] = 'identifier';
  $overrides["field_group.group_additional|node|dataset|default.data|children|14"]["DELETED"] = TRUE;
  $overrides["field_group.group_additional|node|dataset|default.data|children|2"] = 'field_temporal_coverage';
  $overrides["field_group.group_additional|node|dataset|default.data|children|3"] = 'field_production_date';
  $overrides["field_group.group_additional|node|dataset|default.data|children|4"] = 'field_unit_of_analysis';
  $overrides["field_group.group_additional|node|dataset|default.data|children|5"] = 'field_methodologies';
  $overrides["field_group.group_additional|node|dataset|default.data|children|6"] = 'field_data_quality';
  $overrides["field_group.group_additional|node|dataset|default.data|children|7"] = 'field_period_of_collection';
  $overrides["field_group.group_additional|node|dataset|default.data|children|8"] = 'field_data_collectors';
  $overrides["field_group.group_additional|node|dataset|default.data|children|9"] = 'field_sources';
  $overrides["field_group.group_additional|node|dataset|default.data|format_settings|instance_settings|classes"]["DELETED"] = TRUE;
  $overrides["field_group.group_additional|node|dataset|default.data|format_settings|instance_settings|desc"] = '';
  $overrides["field_group.group_additional|node|dataset|default.data|format_settings|instance_settings|first_column"] = '';
  $overrides["field_group.group_additional|node|dataset|default.data|format_settings|instance_settings|second_column"] = '';
  $overrides["field_group.group_additional|node|dataset|default.data|weight"] = 4;
  $overrides["field_group.group_additional|node|dataset|form.data|children|0"] = 'field_author';
  $overrides["field_group.group_additional|node|dataset|form.data|children|1"] = 'field_resources';
  $overrides["field_group.group_additional|node|dataset|form.data|children|10"] = 'field_sources';
  $overrides["field_group.group_additional|node|dataset|form.data|children|11"]["DELETED"] = TRUE;
  $overrides["field_group.group_additional|node|dataset|form.data|children|12"]["DELETED"] = TRUE;
  $overrides["field_group.group_additional|node|dataset|form.data|children|13"]["DELETED"] = TRUE;
  $overrides["field_group.group_additional|node|dataset|form.data|children|2"] = 'field_spatial_geographical_cover';
  $overrides["field_group.group_additional|node|dataset|form.data|children|3"] = 'field_temporal_coverage';
  $overrides["field_group.group_additional|node|dataset|form.data|children|4"] = 'field_production_date';
  $overrides["field_group.group_additional|node|dataset|form.data|children|5"] = 'field_unit_of_analysis';
  $overrides["field_group.group_additional|node|dataset|form.data|children|6"] = 'field_methodologies';
  $overrides["field_group.group_additional|node|dataset|form.data|children|7"] = 'field_data_quality';
  $overrides["field_group.group_additional|node|dataset|form.data|children|8"] = 'field_period_of_collection';
  $overrides["field_group.group_additional|node|dataset|form.data|children|9"] = 'field_data_collectors';
  $overrides["field_group.group_primary|node|dataset|form.data|children|1"] = 'field_tags';
  $overrides["field_group.group_primary|node|dataset|form.data|children|2"] = 'field_indicator';

  // Exported overrides for: field_instance
  $overrides["field_instance.node-dataset-field_additional_info.node-dataset-field_additional_info"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_author.display|default|weight"] = 12;
  $overrides["field_instance.node-dataset-field_contact_email.node-dataset-field_contact_email"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_contact_name.node-dataset-field_contact_name"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_data_dictionary.node-dataset-field_data_dictionary"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_frequency.node-dataset-field_frequency"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_granularity.node-dataset-field_granularity"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_license.node-dataset-field_license"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_public_access_level.node-dataset-field_public_access_level"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_related_content.node-dataset-field_related_content"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_resources.widget|weight"] = 20;
  $overrides["field_instance.node-dataset-field_spatial.node-dataset-field_spatial"]["DELETED"] = TRUE;
  $overrides["field_instance.node-dataset-field_spatial_geographical_cover.display|default|weight"] = 10;
  $overrides["field_instance.node-dataset-field_temporal_coverage.display|default|settings|format_type"] = 'year';
  $overrides["field_instance.node-dataset-field_temporal_coverage.display|default|weight"] = 11;
  $overrides["field_instance.node-dataset-field_temporal_coverage.widget|settings|input_format"] = 'custom';
  $overrides["field_instance.node-dataset-field_temporal_coverage.widget|settings|input_format_custom"] = 'Y';
  $overrides["field_instance.node-dataset-field_temporal_coverage.widget|settings|year_range"] = '1500:+10';
  $overrides["field_instance.node-dataset-field_temporal_coverage.widget|type"] = 'date_text';
  $overrides["field_instance.node-dataset-field_temporal_coverage.widget|weight"] = 11;

 return $overrides;
}
