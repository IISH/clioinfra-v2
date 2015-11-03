core = 7.x
api = 2


; Core

projects[drupal][type] = core
; the latest release
projects[drupal][version] = 7.38

; Clio custom modules

projects[clio][type] = module
projects[clio][subdir] = custom
projects[clio][version] = 4.x
projects[clio][download][type] = git
projects[clio][download][url] = git://github.com/IISH/drupal-module-clioinfra.git
projects[clio][download][branch] = test

; Clio required modules

projects[uuid_features][subdir] = contrib 
projects[uuid_features][version] = 1.0-alpha4
projects[feeds][subdir] = contrib 
projects[feeds][version] = 2.x-dev
projects[feeds_tamper][subdir] = contrib 
projects[feeds_tamper][version] = 1.1
projects[feeds_ex][subdir] = contrib 
projects[feeds_ex][version] = 1.0-beta2
projects[libraries][subdir] = contrib 
projects[libraries][version] = 2.2
projects[jquery_update][subdir] = contrib 
projects[jquery_update][version] = 3.0-alpha2

; Clio site

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

libraries[multiselect.js][type] = libraries
libraries[multiselect.js][download][type] = git
libraries[multiselect.js][download][url] = https://github.com/lou/multi-select.git
libraries[multiselect.js][directory_name] = multiselect.js

libraries[quicksearch][type] = libraries
libraries[quicksearch][download][type] = git
libraries[quicksearch][download][url] = https://github.com/riklomas/quicksearch.git
libraries[quicksearch][directory_name] = quicksearch

libraries[jquery.typeahead][type] = libraries
libraries[jquery.typeahead][download][type] = git
libraries[jquery.typeahead][download][url] = https://github.com/running-coder/jquery-typeahead.git
libraries[jquery.typeahead][directory_name] = jquery.typeahead

libraries[d3][type] = libraries
libraries[d3][download][type] = git
libraries[d3][download][url] = https://github.com/mbostock/d3.git
libraries[d3][directory_name] = d3

libraries[topojson][type] = libraries
libraries[topojson][download][type] = git
libraries[topojson][download][url] = https://github.com/mbostock/topojson.git
libraries[topojson][directory_name] = topojson

libraries[d3.tip][type] = libraries
libraries[d3.tip][download][type] = git
libraries[d3.tip][download][url] = https://github.com/Caged/d3-tip.git
libraries[d3.tip][directory_name] = d3.tip

libraries[d3.geo.projection][type] = libraries
libraries[d3.geo.projection][download][type] = git
libraries[d3.geo.projection][download][url] = https://github.com/d3/d3-geo-projection.git
libraries[d3.geo.projection][directory_name] = d3.geo.projection

libraries[d3.svg.legend][type] = libraries
libraries[d3.svg.legend][download][type] = git
libraries[d3.svg.legend][download][url] = https://github.com/emeeks/d3-svg-legend.git
libraries[d3.svg.legend][directory_name] = d3.svg.legend

libraries[jquery.cycle][type] = libraries
libraries[jquery.cycle][download][type] = git
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle.git
libraries[jquery.cycle][directory_name] = jquery.cycle

libraries[ckeditor][type] = libraries
libraries[ckeditor][download][type] = git
libraries[ckeditor][download][url] = https://github.com/ckeditor/ckeditor-releases.git
libraries[ckeditor][download][branch] = "4.5.x"
libraries[ckeditor][directory_name] = ckeditor

