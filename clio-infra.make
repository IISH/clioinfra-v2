core = 7.x
api = 2

; CORE

projects[drupal][type] = core
projects[drupal][version] = 7.26

; CLIO

projects[clio_convert][subdir] = custom
projects[clio_convert][download][type] = git
projects[clio_convert][download][version] = 1.x
projects[clio_convert][download][url] = https://github.com/IISH/clioinfra-v2/tree/master/sites/all/modules/custom/clio_convert
projects[clio_convert][type] = "module"

; DKAN
projects[dkan_dataset][subdir] = dkan
projects[dkan_dataset][download][type] = git
projects[dkan_dataset][download][version] = 1.x
projects[dkan_dataset][download][url] = http://git.drupal.org/project/dkan_dataset.git
projects[dkan_dataset][type] = "module"
; requires autocomplete_deluxe, beautytips, chosen, ctools, date, date_popup, double_field, entity, entityreference, eva,
; features, field_group, field_group_table, jquery_update, libraries, link, link_iframe_formatter, multistep, og, og_extras,
; rdfx, ref_field_sync, restws, select_or_other, strongarm, token, uuid, views, views_datasource

projects[dkan_datastore][subdir] = dkan
projects[dkan_datastore][download][type] = git
projects[dkan_datastore][download][version] = 1.x
projects[dkan_datastore][download][url] = http://git.drupal.org/project/dkan_datastore.git
projects[dkan_datastore][type] = "module"
; requires ctools, data, feeds, feeds_field_fetcher, feeds_flatstore_processor, schema


; Contrib Modules

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.3
projects[diff][subdir] = contrib
projects[date][subdir] = contrib
projects[double_field][subdir] = contrib
projects[double_field][version] = 2.3
projects[entity][subdir] = contrib
projects[entity][version] = 1.2
projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.1
projects[eva][subdir] = contrib
projects[eva][version] = 1.2
projects[field_group][subdir] = contrib
projects[field_group][version] = 1.1
projects[field_group][patch][2042681] = http://drupal.org/files/field-group-show-ajax-2042681-6.patch
projects[filefield_sources][subdir] = contrib
projects[filefield_sources][version] = 1.8
projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.3
projects[libraries][subdir] = contrib
projects[libraries][version] = 2.1
projects[link][subdir] = contrib
projects[link][version] = 1.1
projects[link_iframe_formatter][subdir] = contrib
projects[multistep][subdir] = contrib
projects[multistep][version] = 1.x

projects[phpexcel][subdir] = contrib
projects[phpexcel][version] = 3.7

projects[ref_field][subdir] = contrib
projects[ref_field][version] = 2.x
projects[ref_field][patch][1670356] = http://drupal.org/files/removed_notice-1670356-1.patch
projects[remote_file_source][subdir] = contrib
projects[remote_stream_wrapper][subdir] = contrib
projects[restws][subdir] = contrib
projects[select_or_other][subdir] = contrib
projects[select_or_other][version] = 2.20
projects[token][subdir] = contrib
projects[views][subdir] = contrib
projects[views_datasource][subdir] = contrib
projects[views_datasource][download][type] = git
projects[views_datasource][download][url] = "http://git.drupal.org/project/views_datasource.git"
projects[views_datasource][download][branch] = "7.x-1.x"
projects[views_datasource][type] = "module"
projects[views_bulk_operations][subdir] = contrib

projects[entity_rdf][subdir] = contrib
projects[rdfx][subdir] = contrib
projects[rdfx][version] = 2.x
projects[rdfx][patch][1271498] = http://drupal.org/files/issues/1271498_3_rdfui_form_values.patch

projects[field_group_table][subdir] = contrib
projects[field_group_table][download][type] = git
projects[field_group_table][download][url] = "https://github.com/nuams/field_group_table.git"
projects[field_group_table][type] = "module"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.x"
projects[feeds][download][type] = "git"
projects[feeds][download][url] = "http://git.drupal.org/project/feeds.git"
projects[feeds][download][revision] = 1383713
projects[feeds][download][branch] = 7.x-2.x
projects[feeds][type] = "module"
projects[feeds][patch][1428272] = http://drupal.org/files/feeds-encoding_support_CSV-1428272-52.patch
projects[feeds][patch][1127696] = http://drupal.org/files/feeds-1127696-multiple-importers-per-content-type-59.patch

projects[feeds_field_fetcher][subdir] = contrib
projects[feeds_field_fetcher][download][type] = git
projects[feeds_field_fetcher][download][url] = "http://git.drupal.org/project/feeds_field_fetcher.git"
projects[feeds_field_fetcher][download][branch] = master
projects[feeds_field_fetcher][type] = "module"

projects[feeds_flatstore_processor][subdir] = contrib
projects[feeds_flatstore_processor][download][type] = git
projects[feeds_flatstore_processor][download][url] = "http://git.drupal.org/sandbox/acouch/1952754.git"
projects[feeds_flatstore_processor][download][branch] = master
projects[feeds_flatstore_processor][type] = "module"

projects[schema][subdir] = contrib
projects[schema][patch][1237974] = http://drupal.org/files/schema-support-custom-types-1237974-48.patch
projects[services][subdir] = contrib
projects[data][subdir] = contrib
projects[data][version] = 1.x
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 1.x

projects[pathauto][subdir] = contrib
projects[r4032login][subdir] = contrib
projects[rules][subdir] = contrib
projects[rules][version] = 2.3

; Themes

projects[zen][version] = 5.1

projects[clio][download][type] = git
projects[clio][download][url] = https://github.com/IISH/clioinfra-v2/tree/master/sites/all/themes/clio
projects[clio][download][branch] = master
projects[clio][type] = theme

; Libraries

libraries[arc][type] = libraries
libraries[arc][download][type] = git
libraries[arc][download][url] = "https://github.com/semsol/arc2.git"
libraries[arc][download][revision] = "44c396ab54178086c09499a1704e31a977b836d2"

libraries[spyc][download][type] = "get"
libraries[spyc][download][url] = "https://raw.github.com/mustangostang/spyc/79f61969f63ee77e0d9460bc254a27a671b445f3/spyc.php"
libraries[spyc][filename] = "../spyc.php"
libraries[spyc][directory_name] = "lib"
libraries[spyc][destination] = "modules/contrib/services/servers/rest_server"

