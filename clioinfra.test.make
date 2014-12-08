core = 7.x
api = 2


; Core

projects[drupal][type] = core
projects[drupal][version] = 7.x

; Clio custom modules

projects[clio][type] = module
projects[clio][subdir] = custom
projects[clio][version] = 1.x
projects[clio][download][type] = git
projects[clio][download][url] = git://github.com/IISH/clioinfra-v2.git
projects[clio][download][branch] = test

; Clio dev modules
;
;projects[xhprof][subdir] = dev
;
; Clio required modules

projects[better_exposed_filters][subdir] = contrib 
projects[better_exposed_filters][version] = 3.0-beta4
projects[dkan_dataset][subdir] = contrib 
projects[dkan_dataset][version] = 1.5
projects[dkan_datastore][subdir] = contrib 
projects[dkan_datastore][version] = 1.5
projects[phpexcel][subdir] = contrib 
projects[phpexcel][version] = 3.7
projects[phpexcel][patch][2243117] = https://drupal.org/files/issues/phpexcel-2243117.patch
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

projects[print][subdir] = contrib
projects[print][version] = 2.0

projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-rc2

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

; Clio site content

projects[clio_site][type] = module
projects[clio_site][subdir] = features
projects[clio_site][version] = 1.x
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

;libraries[phpexcel][type] = libraries
;libraries[phpexcel][download][type] = file
;libraries[phpexcel][download][url] = http://download-codeplex.sec.s-msft.com/Download/Release?ProjectName=phpexcel&DownloadId=809026&FileTime=130382506283700000&Build=20885
;libraries[phpexcel][directory_name] = PHPExcel

libraries[phpexcel][type] = libraries
libraries[phpexcel][download][type] = "git"
libraries[phpexcel][download][url] = "git@atlassian-bamboo-be0.socialhistoryservices.org:phpexcel.git"
libraries[phpexcel][download][branch] = "1.8.3"
libraries[phpexcel][directory_name] = PHPExcel

;libraries[pclzip][type] = libraries
;libraries[pclzip][download][type] = file
;libraries[pclzip][download][url] = http://www.phpconcept.net/download.php?file=pclzip-2-8-2.zip
;libraries[pclzip][directory_name] = pclzip

libraries[jquery.cycle][type] = libraries
libraries[jquery.cycle][download][type] = git
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle.git
libraries[jquery.cycle][directory_name] = jquery.cycle

libraries[ckeditor][type] = libraries
libraries[ckeditor][download][type] = git
libraries[ckeditor][download][url] = https://github.com/ckeditor/ckeditor-releases.git
libraries[ckeditor][download][branch] = "4.4.x"
libraries[ckeditor][directory_name] = ckeditor

libraries[tcpdf][type] = libraries
libraries[tcpdf][download][type] = "git"
libraries[tcpdf][download][url] = "git@atlassian-bamboo-be0.socialhistoryservices.org:tcpdf.git"
libraries[tcpdf][download][branch] = "6.1.0"
libraries[tcpdf][directory_name] = tcpdf

; overwrite

projects[schema][subdir] = contrib


