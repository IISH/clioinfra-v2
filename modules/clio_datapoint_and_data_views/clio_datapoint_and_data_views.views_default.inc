<?php
/**
 * @file
 * clio_datapoint_and_data_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function clio_datapoint_and_data_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Ok';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'datapoint' => 'datapoint',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_datapoint_year) */
  $handler->display->display_options['filters']['field_datapoint_year_value']['id'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['table'] = 'field_data_field_datapoint_year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['field'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator_id'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['label'] = 'Time period';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['label'] = 'Year (field_datapoint_year)';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['identifier'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Indicator (field_datapoint_indicator) */
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['id'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['table'] = 'field_data_field_datapoint_indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['field'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator_id'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['label'] = 'Indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['identifier'] = 'indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['vocabulary'] = 'indicators';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Country (field_datapoint_country) */
  $handler->display->display_options['filters']['field_datapoint_country_tid']['id'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['table'] = 'field_data_field_datapoint_country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['field'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator_id'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'datasets2';

  /* Display: Page Country */
  $handler = $view->new_display('page', 'Page Country', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Country (field_datapoint_country) */
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['id'] = 'field_datapoint_country_tid';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['table'] = 'field_data_field_datapoint_country';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['field'] = 'field_datapoint_country_tid';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['title'] = 'Search datasets of %1';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_datapoint_country_tid']['validate_options']['vocabularies'] = array(
    'countries' => 'countries',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'datapoint' => 'datapoint',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_datapoint_year) */
  $handler->display->display_options['filters']['field_datapoint_year_value']['id'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['table'] = 'field_data_field_datapoint_year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['field'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator_id'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['label'] = 'Year (field_datapoint_year)';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['identifier'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Indicator (field_datapoint_indicator) */
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['id'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['table'] = 'field_data_field_datapoint_indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['field'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator_id'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['label'] = 'Indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['identifier'] = 'indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['vocabulary'] = 'indicators';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'datasets2/country';

  /* Display: Page Indicator */
  $handler = $view->new_display('page', 'Page Indicator', 'page_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Indicator (field_datapoint_indicator) */
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['id'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['table'] = 'field_data_field_datapoint_indicator';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['field'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['title'] = 'Search datasets of %1';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_datapoint_indicator_tid']['validate_options']['vocabularies'] = array(
    'indicators' => 'indicators',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'datapoint' => 'datapoint',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_datapoint_year) */
  $handler->display->display_options['filters']['field_datapoint_year_value']['id'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['table'] = 'field_data_field_datapoint_year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['field'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator_id'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['label'] = 'Year (field_datapoint_year)';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['identifier'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Country (field_datapoint_country) */
  $handler->display->display_options['filters']['field_datapoint_country_tid']['id'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['table'] = 'field_data_field_datapoint_country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['field'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator_id'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'datasets2/indicator';

  /* Display: Page Topic */
  $handler = $view->new_display('page', 'Page Topic', 'page_3');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'datapoint' => 'datapoint',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_datapoint_year) */
  $handler->display->display_options['filters']['field_datapoint_year_value']['id'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['table'] = 'field_data_field_datapoint_year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['field'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator_id'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['label'] = 'Year (field_datapoint_year)';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['identifier'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Indicator (field_datapoint_indicator) */
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['id'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['table'] = 'field_data_field_datapoint_indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['field'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator_id'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['label'] = 'Indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['identifier'] = 'indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['vocabulary'] = 'indicators';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Country (field_datapoint_country) */
  $handler->display->display_options['filters']['field_datapoint_country_tid']['id'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['table'] = 'field_data_field_datapoint_country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['field'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator_id'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'datasets2/topic';

  /* Display: Page Combined */
  $handler = $view->new_display('page', 'Page Combined', 'page_4');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'post_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Ok';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_datapoint_year_value' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_datapoint_country_tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_datapoint_indicator_tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['form_method'] = 'post';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<script type="text/javascript">
jQuery(document).ready(function($){
  $(\'ul.bef-tree\').tristate();
}); 
</script>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'datapoint' => 'datapoint',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Year (field_datapoint_year) */
  $handler->display->display_options['filters']['field_datapoint_year_value']['id'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['table'] = 'field_data_field_datapoint_year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['field'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator_id'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['label'] = 'Time period';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['operator'] = 'field_datapoint_year_value_op';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['field_datapoint_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['label'] = 'Year (field_datapoint_year)';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['identifier'] = 'field_datapoint_year_value';
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_datapoint_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Country (field_datapoint_country) */
  $handler->display->display_options['filters']['field_datapoint_country_tid']['id'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['table'] = 'field_data_field_datapoint_country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['field'] = 'field_datapoint_country_tid';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator_id'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['operator'] = 'field_datapoint_country_tid_op';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_datapoint_country_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Indicator (field_datapoint_indicator) */
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['id'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['table'] = 'field_data_field_datapoint_indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['field'] = 'field_datapoint_indicator_tid';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator_id'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['label'] = 'Indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['operator'] = 'field_datapoint_indicator_tid_op';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['identifier'] = 'indicator';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['vocabulary'] = 'indicators';
  $handler->display->display_options['filters']['field_datapoint_indicator_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'datasets2/combined';
  $export['data'] = $view;

  return $export;
}
