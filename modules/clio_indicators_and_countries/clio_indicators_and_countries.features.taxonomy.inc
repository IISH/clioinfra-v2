<?php
/**
 * @file
 * clio_indicators_and_countries.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function clio_indicators_and_countries_taxonomy_default_vocabularies() {
  return array(
    'countries' => array(
      'name' => 'Countries',
      'machine_name' => 'countries',
      'description' => 'Countries.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'indicators' => array(
      'name' => 'Indicators',
      'machine_name' => 'indicators',
      'description' => 'Indicators.',
      'hierarchy' => 2,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
