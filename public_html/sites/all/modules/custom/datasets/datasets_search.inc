<?php

/**
 * @file
 * Search dataset files.
 *
 */

/**
 * Search dataset files by country
 */



function datasets_search_country() {
  global $user, $uri, $scriptdir;
  $username = $user->name;
  $output = `$scriptdir/backend/visual.cgi -user '$username' -uri '$uri'`;
  $output = 'dfafdafda';
  return $output;
}

function datasets_search_topic($form_state) {
  global $user, $uri, $scriptdir;
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Search by topic'),
  );
  $output = `$scriptdir/backend/visual.cgi --user=\"$user->name\" --uri=\"$uri\"`;
  $form['dataset'] = array(
    '#markup' => $output,
  );
  return $form;
}

function datasets_search_indicator($form_state) {
  global $user, $uri, $scriptdir;
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Search by indicator'),
  );
  $output = `$scriptdir/charts/charts.cgi --uri=\"$uri\"`;
  $form['dataset'] = array(
    '#markup' => $output,
  );
  return $form;
}

function datasets_search_combined($form_state) {
  global $user, $uri, $scriptdir;
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Combined search'),
  );
  $output = `$scriptdir/visualize/customdatasets.cgi --user=\"$user->name\" --uri=\"$uri\"`;
  $form['dataset'] = array(
    '#markup' => $output,
  );
  return $form;
}

