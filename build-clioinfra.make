core = 7.x
api = 2


; Core

projects[drupal][type] = core
projects[drupal][version] = 7.26

; Clio custom modules

projects[clio_base][subdir] = custom
projects[clio_base][download][type] = git
projects[clio_base][download][version] = 1.x
projects[clio_base][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clio_base][download][branch] = master
projects[clio_base][download][subtree] = modules/clio_base
projects[clio_base][type] = module

projects[clio_convert][subdir] = custom
projects[clio_convert][download][type] = git
projects[clio_convert][download][version] = 1.x
projects[clio_convert][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clio_convert][download][branch] = master
projects[clio_convert][download][subtree] = modules/clio_convert
projects[clio_convert][type] = module

projects[clio_search][subdir] = custom
projects[clio_search][download][type] = git
projects[clio_search][download][version] = 1.x
projects[clio_search][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clio_search][download][branch] = master
projects[clio_search][download][subtree] = modules/clio_search
projects[clio_search][type] = module

projects[clio_statplanet][subdir] = custom
projects[clio_statplanet][download][type] = git
projects[clio_statplanet][download][version] = 1.x
projects[clio_statplanet][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clio_statplanet][download][branch] = master
projects[clio_statplanet][download][subtree] = modules/clio_statplanet
projects[clio_statplanet][type] = module

; Clio required modules

projects[better_exposed_filters][subdir] = contrib 
projects[better_exposed_filters][version] = 3.0-beta4
projects[dkan_dataset][subdir] = contrib 
projects[dkan_dataset][version] = 1.0-rc1
projects[dkan_datastore][subdir] = contrib 
projects[dkan_datastore][version] = 1.0-beta1
projects[phpexcel][subdir] = contrib 
projects[phpexcel][version] = 3.7
projects[swfembed][subdir] = contrib 
projects[swfembed][version] = 1.4
projects[term_reference_tree][subdir] = contrib 
projects[term_reference_tree][version] = 1.10
projects[uuid_features][subdir] = contrib 
projects[uuid_features][version] = 1.0-alpha4
projects[views_expost][subdir] = contrib 
projects[views_expost][version] = 1.1
projects[views_tree][subdir] = contrib 
projects[views_tree][version] = 2.0

; Clio site

projects[ctools_automodal][subdir] = contrib 
projects[ctools_automodal][version] = 1.1
projects[features_extra][subdir] = contrib 
projects[features_extra][version] = 1.0-beta1
projects[fontyourface][subdir] = contrib 
projects[fontyourface][version] = 2.8
projects[google_analytics][subdir] = contrib 
projects[google_analytics][version] = 1.4
projects[login_destination][subdir] = contrib 
projects[login_destination][version] = 1.1
projects[menu_block][subdir] = contrib 
projects[menu_block][version] = 2.3
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

; Themes

projects[zen][version] = 5.1

projects[clioinfra][download][type] = git
projects[clioinfra][download][version] = 1.x
projects[clioinfra][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clioinfra][download][branch] = master
projects[clioinfra][download][subtree] = themes/clioinfra
projects[clioinfra][type] = theme


; Libraries

libraries[phpexcel][type] = libraries
libraries[phpexcel][download][type] = file
libraries[phpexcel][download][url] = http://download-codeplex.sec.s-msft.com/Download/Release?ProjectName=phpexcel&DownloadId=809026&FileTime=130382506283700000&Build=20885
libraries[phpexcel][directory_name] = PHPExcel

libraries[pclzip][type] = libraries
libraries[pclzip][download][type] = file
libraries[pclzip][download][url] = http://www.phpconcept.net/download.php?file=pclzip-2-8-2.zip
libraries[pclzip][directory_name] = pclzip

libraries[jquery.cycle][type] = libraries
libraries[jquery.cycle][download][type] = git
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle.git
libraries[jquery.cycle][directory_name] = jquery.cycle


