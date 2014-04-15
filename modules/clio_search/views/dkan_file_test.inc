$view = new view();
$view->name = 'dkan_file_test';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'feeds_datastore_dkan_file_16';
$view->human_name = 'DKAN file test';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'DKAN file test';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'indicator' => 'indicator',
  'countrycode' => 'countrycode',
  'indicator_1' => 'indicator_1',
  'unit' => 'unit',
  'value' => 'value',
  'year' => 'year',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'indicator' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'countrycode' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'indicator_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'unit' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'year' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: dkan_file16: Indicator */
$handler->display->display_options['fields']['indicator']['id'] = 'indicator';
$handler->display->display_options['fields']['indicator']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['fields']['indicator']['field'] = 'indicator';
/* Field: dkan_file16: Countrycode */
$handler->display->display_options['fields']['countrycode']['id'] = 'countrycode';
$handler->display->display_options['fields']['countrycode']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['fields']['countrycode']['field'] = 'countrycode';
/* Field: dkan_file16: Unit */
$handler->display->display_options['fields']['unit']['id'] = 'unit';
$handler->display->display_options['fields']['unit']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['fields']['unit']['field'] = 'unit';
/* Field: dkan_file16: Year */
$handler->display->display_options['fields']['year']['id'] = 'year';
$handler->display->display_options['fields']['year']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['fields']['year']['field'] = 'year';
$handler->display->display_options['fields']['year']['separator'] = '';
/* Field: dkan_file16: Value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['fields']['value']['field'] = 'value';
/* Contextual filter: dkan_file16: Countrytid */
$handler->display->display_options['arguments']['countrytid']['id'] = 'countrytid';
$handler->display->display_options['arguments']['countrytid']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['arguments']['countrytid']['field'] = 'countrytid';
$handler->display->display_options['arguments']['countrytid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['countrytid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['countrytid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['countrytid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['countrytid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['countrytid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['countrytid']['validate_options']['type'] = 'tids';
$handler->display->display_options['arguments']['countrytid']['break_phrase'] = TRUE;
/* Contextual filter: dkan_file16: Indicatortid */
$handler->display->display_options['arguments']['indicatortid']['id'] = 'indicatortid';
$handler->display->display_options['arguments']['indicatortid']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['arguments']['indicatortid']['field'] = 'indicatortid';
$handler->display->display_options['arguments']['indicatortid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['indicatortid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['indicatortid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['indicatortid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['indicatortid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['indicatortid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['indicatortid']['validate_options']['vocabularies'] = array(
  'indicators' => 'indicators',
);
$handler->display->display_options['arguments']['indicatortid']['validate_options']['type'] = 'tids';
$handler->display->display_options['arguments']['indicatortid']['break_phrase'] = TRUE;
/* Contextual filter: dkan_file16: Year */
$handler->display->display_options['arguments']['year']['id'] = 'year';
$handler->display->display_options['arguments']['year']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['arguments']['year']['field'] = 'year';
$handler->display->display_options['arguments']['year']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['year']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['year']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['year']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['year']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['year']['break_phrase'] = TRUE;
/* Filter criterion: dkan_file16: Countrytid */
$handler->display->display_options['filters']['countrytid']['id'] = 'countrytid';
$handler->display->display_options['filters']['countrytid']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['filters']['countrytid']['field'] = 'countrytid';
$handler->display->display_options['filters']['countrytid']['exposed'] = TRUE;
$handler->display->display_options['filters']['countrytid']['expose']['operator_id'] = 'countrytid_op';
$handler->display->display_options['filters']['countrytid']['expose']['label'] = 'Countrytid';
$handler->display->display_options['filters']['countrytid']['expose']['operator'] = 'countrytid_op';
$handler->display->display_options['filters']['countrytid']['expose']['identifier'] = 'countrytid';
$handler->display->display_options['filters']['countrytid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['countrytid']['group_info']['label'] = 'Countrytid';
$handler->display->display_options['filters']['countrytid']['group_info']['identifier'] = 'countrytid';
$handler->display->display_options['filters']['countrytid']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['countrytid']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
/* Filter criterion: dkan_file16: Indicatortid */
$handler->display->display_options['filters']['indicatortid']['id'] = 'indicatortid';
$handler->display->display_options['filters']['indicatortid']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['filters']['indicatortid']['field'] = 'indicatortid';
$handler->display->display_options['filters']['indicatortid']['exposed'] = TRUE;
$handler->display->display_options['filters']['indicatortid']['expose']['operator_id'] = 'indicatortid_op';
$handler->display->display_options['filters']['indicatortid']['expose']['label'] = 'Indicatortid';
$handler->display->display_options['filters']['indicatortid']['expose']['operator'] = 'indicatortid_op';
$handler->display->display_options['filters']['indicatortid']['expose']['identifier'] = 'indicatortid';
$handler->display->display_options['filters']['indicatortid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: dkan_file16: Year */
$handler->display->display_options['filters']['year']['id'] = 'year';
$handler->display->display_options['filters']['year']['table'] = 'feeds_datastore_dkan_file_16';
$handler->display->display_options['filters']['year']['field'] = 'year';
$handler->display->display_options['filters']['year']['exposed'] = TRUE;
$handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
$handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
$handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
$handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
$handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'dkan-file-test';

