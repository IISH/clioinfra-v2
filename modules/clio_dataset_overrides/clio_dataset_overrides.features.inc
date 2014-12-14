<?php
/**
 * @file
 * clio_dataset_overrides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function clio_dataset_overrides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function clio_dataset_overrides_field_default_field_bases_alter(&$data) {
  if (isset($data['field_temporal_coverage'])) {
    $data['field_temporal_coverage']['settings']['granularity']['day'] = 0; /* WAS: 'day' */
    $data['field_temporal_coverage']['settings']['granularity']['hour'] = 0; /* WAS: 'hour' */
    $data['field_temporal_coverage']['settings']['granularity']['minute'] = 0; /* WAS: 'minute' */
    $data['field_temporal_coverage']['settings']['granularity']['month'] = 0; /* WAS: 'month' */
    $data['field_temporal_coverage']['settings']['granularity']['second'] = 0; /* WAS: 'second' */
    $data['field_temporal_coverage']['settings']['timezone_db'] = ''; /* WAS: 'UTC' */
    $data['field_temporal_coverage']['settings']['tz_handling'] = 'none'; /* WAS: 'site' */
  }
}

/**
 * Implements hook_field_group_info_alter().
 */
function clio_dataset_overrides_field_group_info_alter(&$data) {
  if (isset($data['group_additional|node|dataset|default'])) {
    $data['group_additional|node|dataset|default']->data['children']['1'] = 'field_spatial_geographical_cover'; /* WAS: 'field_contact_email' */
    $data['group_additional|node|dataset|default']->data['children']['10'] = 'field_indicator'; /* WAS: 'field_temporal_coverage' */
    $data['group_additional|node|dataset|default']->data['children']['11'] = 'release_date'; /* WAS: 'og_group_ref' */
    $data['group_additional|node|dataset|default']->data['children']['12'] = 'modified_date'; /* WAS: 'release_date' */
    $data['group_additional|node|dataset|default']->data['children']['13'] = 'identifier'; /* WAS: 'modified_date' */
    $data['group_additional|node|dataset|default']->data['children']['2'] = 'field_temporal_coverage'; /* WAS: 'field_contact_name' */
    $data['group_additional|node|dataset|default']->data['children']['3'] = 'field_production_date'; /* WAS: 'field_data_dictionary' */
    $data['group_additional|node|dataset|default']->data['children']['4'] = 'field_unit_of_analysis'; /* WAS: 'field_frequency' */
    $data['group_additional|node|dataset|default']->data['children']['5'] = 'field_methodologies'; /* WAS: 'field_granularity' */
    $data['group_additional|node|dataset|default']->data['children']['6'] = 'field_data_quality'; /* WAS: 'field_license' */
    $data['group_additional|node|dataset|default']->data['children']['7'] = 'field_period_of_collection'; /* WAS: 'field_public_access_level' */
    $data['group_additional|node|dataset|default']->data['children']['8'] = 'field_data_collectors'; /* WAS: 'field_spatial' */
    $data['group_additional|node|dataset|default']->data['children']['9'] = 'field_sources'; /* WAS: 'field_spatial_geographical_cover' */
    $data['group_additional|node|dataset|default']->data['format_settings']['instance_settings']['desc'] = ''; /* WAS: '<div class="fieldset-description"><i class="icon-large icon-info-sign"></i>These fields are compatible with <a href="http://www.w3.org/TR/vocab-dcat/">DCAT</a>, an RDF vocabulary designed to facilitate interoperability between data catalogs published on the Web.</div>' */
    $data['group_additional|node|dataset|default']->data['format_settings']['instance_settings']['first_column'] = ''; /* WAS: 'Field' */
    $data['group_additional|node|dataset|default']->data['format_settings']['instance_settings']['second_column'] = ''; /* WAS: 'Value' */
    $data['group_additional|node|dataset|default']->data['weight'] = 4; /* WAS: 3 */
    unset($data['group_additional|node|dataset|default']->data['children']['14']);
    unset($data['group_additional|node|dataset|default']->data['format_settings']['instance_settings']['classes']);
  }
  if (isset($data['group_additional|node|dataset|form'])) {
    $data['group_additional|node|dataset|form']->data['children']['0'] = 'field_author'; /* WAS: 'field_additional_info' */
    $data['group_additional|node|dataset|form']->data['children']['1'] = 'field_resources'; /* WAS: 'field_author' */
    $data['group_additional|node|dataset|form']->data['children']['10'] = 'field_sources'; /* WAS: 'field_spatial' */
    $data['group_additional|node|dataset|form']->data['children']['2'] = 'field_spatial_geographical_cover'; /* WAS: 'field_contact_email' */
    $data['group_additional|node|dataset|form']->data['children']['3'] = 'field_temporal_coverage'; /* WAS: 'field_contact_name' */
    $data['group_additional|node|dataset|form']->data['children']['4'] = 'field_production_date'; /* WAS: 'field_data_dictionary' */
    $data['group_additional|node|dataset|form']->data['children']['5'] = 'field_unit_of_analysis'; /* WAS: 'field_frequency' */
    $data['group_additional|node|dataset|form']->data['children']['6'] = 'field_methodologies'; /* WAS: 'field_granularity' */
    $data['group_additional|node|dataset|form']->data['children']['7'] = 'field_data_quality'; /* WAS: 'field_public_access_level' */
    $data['group_additional|node|dataset|form']->data['children']['8'] = 'field_period_of_collection'; /* WAS: 'field_related_content' */
    $data['group_additional|node|dataset|form']->data['children']['9'] = 'field_data_collectors'; /* WAS: 'field_resources' */
    unset($data['group_additional|node|dataset|form']->data['children']['11']);
    unset($data['group_additional|node|dataset|form']->data['children']['12']);
    unset($data['group_additional|node|dataset|form']->data['children']['13']);
  }
  if (isset($data['group_primary|node|dataset|form'])) {
    $data['group_primary|node|dataset|form']->data['children']['1'] = 'field_tags'; /* WAS: 'field_license' */
    $data['group_primary|node|dataset|form']->data['children']['2'] = 'field_indicator'; /* WAS: 'field_tags' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function clio_dataset_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['node-dataset-field_additional_info'])) {
    unset($data['node-dataset-field_additional_info']);
  }
  if (isset($data['node-dataset-field_author'])) {
    $data['node-dataset-field_author']['display']['default']['weight'] = 12; /* WAS: 15 */
  }
  if (isset($data['node-dataset-field_contact_email'])) {
    unset($data['node-dataset-field_contact_email']);
  }
  if (isset($data['node-dataset-field_contact_name'])) {
    unset($data['node-dataset-field_contact_name']);
  }
  if (isset($data['node-dataset-field_data_dictionary'])) {
    unset($data['node-dataset-field_data_dictionary']);
  }
  if (isset($data['node-dataset-field_frequency'])) {
    unset($data['node-dataset-field_frequency']);
  }
  if (isset($data['node-dataset-field_granularity'])) {
    unset($data['node-dataset-field_granularity']);
  }
  if (isset($data['node-dataset-field_license'])) {
    unset($data['node-dataset-field_license']);
  }
  if (isset($data['node-dataset-field_public_access_level'])) {
    unset($data['node-dataset-field_public_access_level']);
  }
  if (isset($data['node-dataset-field_related_content'])) {
    unset($data['node-dataset-field_related_content']);
  }
  if (isset($data['node-dataset-field_resources'])) {
    $data['node-dataset-field_resources']['widget']['weight'] = 20; /* WAS: 22 */
  }
  if (isset($data['node-dataset-field_spatial'])) {
    unset($data['node-dataset-field_spatial']);
  }
  if (isset($data['node-dataset-field_spatial_geographical_cover'])) {
    $data['node-dataset-field_spatial_geographical_cover']['display']['default']['weight'] = 10; /* WAS: 11 */
  }
  if (isset($data['node-dataset-field_temporal_coverage'])) {
    $data['node-dataset-field_temporal_coverage']['display']['default']['settings']['format_type'] = 'year'; /* WAS: 'long' */
    $data['node-dataset-field_temporal_coverage']['display']['default']['weight'] = 11; /* WAS: 12 */
    $data['node-dataset-field_temporal_coverage']['widget']['settings']['input_format'] = 'custom'; /* WAS: 'm/d/Y - H:i:s' */
    $data['node-dataset-field_temporal_coverage']['widget']['settings']['input_format_custom'] = 'Y'; /* WAS: '' */
    $data['node-dataset-field_temporal_coverage']['widget']['settings']['year_range'] = '1500:+10'; /* WAS: '-10:+10' */
    $data['node-dataset-field_temporal_coverage']['widget']['type'] = 'date_text'; /* WAS: 'date_popup' */
    $data['node-dataset-field_temporal_coverage']['widget']['weight'] = 11; /* WAS: 15 */
  }
}
