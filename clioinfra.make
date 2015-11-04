core = 7.x
api = 2


; Core

projects[drupal][type] = core
; the latest release
projects[drupal][version] = 7.39

; Clio custom modules

projects[clio][type] = module
projects[clio][subdir] = custom
projects[clio][version] = 4.x
projects[clio][download][type] = git
projects[clio][download][url] = git://github.com/IISH/drupal-module-clioinfra.git
projects[clio][download][branch] = test

; Clio required modules

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.9
projects[entity][subdir] = contrib
projects[entity][version] = 1.6
projects[features][subdir] = contrib
projects[features][version] = 2.6
projects[feeds][subdir] = contrib 
projects[feeds][version] = 2.x-dev
projects[feeds_tamper][subdir] = contrib 
projects[feeds_tamper][version] = 1.1
projects[feeds_ex][subdir] = contrib 
projects[feeds_ex][version] = 1.0-beta2
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3
projects[jquery_update][subdir] = contrib 
projects[jquery_update][version] = 3.0-alpha2
projects[libraries][subdir] = contrib 
projects[libraries][version] = 2.2
projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0
projects[uuid][subdir] = contrib 
projects[uuid][version] = 1.0-alpha6
projects[uuid_features][subdir] = contrib 
projects[uuid_features][version] = 1.0-alpha4
projects[views][subdir] = contrib
projects[views][version] = 3.11

; Clio site

projects[backup_migrate][subdir] = contrib 
projects[backup_migrate][version] = 3.1
projects[features_extra][subdir] = contrib 
projects[features_extra][version] = 1.0-beta1
projects[fontyourface][subdir] = contrib 
projects[fontyourface][version] = 2.8
projects[google_analytics][subdir] = contrib 
projects[google_analytics][version] = 1.4
projects[login_destination][subdir] = contrib 
projects[login_destination][version] = 1.1
projects[menu_block][subdir] = contrib 
projects[menu_block][version] = 2.4
projects[menu_trail_by_path][subdir] = contrib 
projects[menu_trail_by_path][version] = 2.0
projects[pathauto][subdir] = contrib 
projects[pathauto][version] = 1.2
projects[token][subdir] = contrib
projects[token][version] = 1.6
projects[transliteration][subdir] = contrib 
projects[transliteration][version] = 3.2
projects[views_slideshow][subdir] = contrib 
projects[views_slideshow][version] = 3.1
projects[wysiwyg][subdir] = contrib 
projects[wysiwyg][version] = 2.2

; Clio site content

projects[clio_site][type] = module
projects[clio_site][subdir] = features
projects[clio_site][version] = 1.4
projects[clio_site][download][type] = git
projects[clio_site][download][url] = git://github.com/IISH/drupal-feature-clioinfra.git
projects[clio_site][download][branch] = master

; Themes

projects[zen][version] = 5.5

projects[clioinfra][type] = "theme"
projects[clioinfra][download][type] = "git"
projects[clioinfra][download][url] = "git://github.com/IISH/drupal-theme-clioinfra.git"
projects[clioinfra][download][branch] = "master"

; Libraries

libraries[ckeditor][type] = libraries
libraries[ckeditor][download][type] = git
libraries[ckeditor][download][url] = https://github.com/ckeditor/ckeditor-releases.git
libraries[ckeditor][download][branch] = "4.5.x"
libraries[ckeditor][directory_name] = ckeditor

libraries[d3][type] = libraries
libraries[d3][download][type] = git
libraries[d3][download][url] = https://github.com/mbostock/d3.git
libraries[d3][directory_name] = d3

libraries[d3.geo.projection][type] = libraries
libraries[d3.geo.projection][download][type] = git
libraries[d3.geo.projection][download][url] = https://github.com/d3/d3-geo-projection.git
libraries[d3.geo.projection][directory_name] = d3.geo.projection

libraries[d3.svg.legend][type] = libraries
libraries[d3.svg.legend][download][type] = git
libraries[d3.svg.legend][download][url] = https://github.com/emeeks/d3-svg-legend.git
libraries[d3.svg.legend][directory_name] = d3.svg.legend

libraries[d3.tip][type] = libraries
libraries[d3.tip][download][type] = git
libraries[d3.tip][download][url] = https://github.com/Caged/d3-tip.git
libraries[d3.tip][directory_name] = d3.tip

libraries[jquery.cycle][type] = libraries
libraries[jquery.cycle][download][type] = git
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle.git
libraries[jquery.cycle][directory_name] = jquery.cycle

libraries[jquery.typeahead][type] = libraries
libraries[jquery.typeahead][download][type] = git
libraries[jquery.typeahead][download][url] = https://github.com/running-coder/jquery-typeahead.git
libraries[jquery.typeahead][directory_name] = jquery.typeahead

libraries[jsonpath][type] = libraries
libraries[jsonpath][download][type] = file
libraries[jsonpaths][download][url] = https://jsonpath.googlecode.com/svn/trunk/src/php/jsonpath.php
libraries[jsonpath][directory_name] = jsonpath

libraries[multiselect.js][type] = libraries
libraries[multiselect.js][download][type] = git
libraries[multiselect.js][download][url] = https://github.com/lou/multi-select.git
libraries[multiselect.js][directory_name] = multiselect.js

libraries[quicksearch][type] = libraries
libraries[quicksearch][download][type] = git
libraries[quicksearch][download][url] = https://github.com/riklomas/quicksearch.git
libraries[quicksearch][directory_name] = quicksearch

libraries[topojson][type] = libraries
libraries[topojson][download][type] = git
libraries[topojson][download][url] = https://github.com/mbostock/topojson.git
libraries[topojson][directory_name] = topojson

