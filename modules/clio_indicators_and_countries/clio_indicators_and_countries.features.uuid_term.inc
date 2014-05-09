<?php
/**
 * @file
 * clio_indicators_and_countries.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function clio_indicators_and_countries_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Bulgaria',
    'description' => 'Bulgaria',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '00507f23-b1c8-4e17-a4e2-f765c5e3384b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 100,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BGR',
          'format' => 'plain_text',
          'safe_value' => 'BGR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bulgaria',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Netherlands',
    'description' => 'Netherlands',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '0213dbcb-3375-493a-8fc6-6a69d993c9d7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 528,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NLD',
          'format' => 'plain_text',
          'safe_value' => 'NLD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/netherlands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Liberia',
    'description' => 'Liberia',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '02687f22-661b-4830-bcf6-b18026126aa1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 430,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LBR',
          'format' => 'plain_text',
          'safe_value' => 'LBR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/liberia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Lao People\'s Democratic Republic',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '032600d9-9c61-49f7-b0b9-9c0982282f19',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 418,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LAO',
          'format' => NULL,
          'safe_value' => 'LAO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/lao-peoples-democratic-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Armed Conflicts (International)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '03b41832-15c9-4d0b-908f-b6b2bc3ebb92',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/armed-conflicts-international',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'ca1ce3c7-b769-4630-956c-14c85950f263',
    ),
  );
  $terms[] = array(
    'name' => 'Timor-Leste',
    'description' => 'Timor-Leste',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '0473ac13-8f09-4b42-b3f0-7e79a91cbf03',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 626,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TLS',
          'format' => 'plain_text',
          'safe_value' => 'TLS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/timor-leste',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'China, Macao Special Administrative Region',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '04ffd851-ee9c-4ef6-befb-f2ee07dc6b48',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 446,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MAC',
          'format' => NULL,
          'safe_value' => 'MAC',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/china-macao-special-administrative-region',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Democratic Republic of the Congo',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '05f02717-ce93-4727-844c-8bfacc2b7e5c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 180,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'COD',
          'format' => NULL,
          'safe_value' => 'COD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/democratic-republic-congo',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Uruguay',
    'description' => 'Uruguay',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '06489366-bad1-4e48-a50e-1ce685b26cc0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 858,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'URY',
          'format' => 'plain_text',
          'safe_value' => 'URY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/uruguay',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Caribbean',
    'description' => 'Caribbean',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0672dc20-031b-485e-8a15-762774bc6453',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 29,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/caribbean',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '2fb3f46c-6a56-43eb-8b17-ac72debd1b5b',
    ),
  );
  $terms[] = array(
    'name' => 'Israel',
    'description' => 'Israel',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '07917afc-87b2-476a-b4f4-513c7b329a9b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 376,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ISR',
          'format' => 'plain_text',
          'safe_value' => 'ISR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/israel',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Tonga',
    'description' => 'Tonga',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '07da2779-8d64-42ec-b929-2e958b264d46',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 776,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TON',
          'format' => 'plain_text',
          'safe_value' => 'TON',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tonga',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Czechoslovakia (until 1993)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '082148c1-15cc-4c9c-be0c-2a1524b14220',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 200,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/czechoslovakia-until-1993',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Algeria',
    'description' => 'Algeria',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '085a51ce-1a55-4d64-96dd-4d2704d56aa4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 12,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DZA',
          'format' => 'plain_text',
          'safe_value' => 'DZA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/algeria',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Kenya',
    'description' => 'Kenya',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '09b27b28-4155-46f7-8eb9-8801f0881460',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 404,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KEN',
          'format' => 'plain_text',
          'safe_value' => 'KEN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kenya',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Luxembourg',
    'description' => 'Luxembourg',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '0a5683d8-ce6b-4599-80d7-27832b6810d1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 442,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LUX',
          'format' => 'plain_text',
          'safe_value' => 'LUX',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/luxembourg',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Grenada',
    'description' => 'Grenada',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '0abdd62c-3e19-4456-99b4-beeee676ac64',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 308,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GRD',
          'format' => 'plain_text',
          'safe_value' => 'GRD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/grenada',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Mexico',
    'description' => 'Mexico',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '0b39e7c7-7c99-4e81-9d72-c0c96ae9f24d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 484,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MEX',
          'format' => 'plain_text',
          'safe_value' => 'MEX',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mexico',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Cook Islands',
    'description' => 'Cook Islands',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '0bfe8bc0-2a06-41ea-a16b-8e5a51885294',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 184,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'COK',
          'format' => 'plain_text',
          'safe_value' => 'COK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cook-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Ecuador',
    'description' => 'Ecuador',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '0dc744f4-e6c1-40d4-a7d4-03e7c840291a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 218,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ECU',
          'format' => 'plain_text',
          'safe_value' => 'ECU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ecuador',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Madagascar',
    'description' => 'Madagascar',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '0e993994-374a-4dfc-b855-49bcc40b2985',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 450,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MDG',
          'format' => 'plain_text',
          'safe_value' => 'MDG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/madagascar',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Curaçao',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '0ec11f32-ac3e-4184-a072-0275aa3bfebc',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 531,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CUW',
          'format' => NULL,
          'safe_value' => 'CUW',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/curaçao',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Western Europe',
    'description' => 'Western Europe',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 155,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/western-europe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '166e96aa-bcf6-4dfe-92d6-24a42d9e334f',
    ),
  );
  $terms[] = array(
    'name' => 'Australia and New Zealand',
    'description' => 'Australia and New Zealand',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '129199ba-f4e9-43eb-891b-5581a5baf206',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 53,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/australia-and-new-zealand',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e142c681-c49e-41dd-8ace-8016247c8cbf',
    ),
  );
  $terms[] = array(
    'name' => 'Federal Republic of Germany (until 1990)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '12b57d25-fd74-4067-a648-18cf7d889166',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 280,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/federal-republic-germany-until-1990',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Samoa',
    'description' => 'Samoa',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '156754ec-4332-4c1f-b6f8-8f7def6adc48',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 882,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'WSM',
          'format' => 'plain_text',
          'safe_value' => 'WSM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/samoa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Europe',
    'description' => 'Europe',
    'format' => 'plain_text',
    'weight' => 253,
    'uuid' => '166e96aa-bcf6-4dfe-92d6-24a42d9e334f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 150,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/europe',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Congo',
    'description' => 'Congo',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '16b54515-0c3b-4b38-9e2e-9171df33b9dd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 178,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'COG',
          'format' => 'plain_text',
          'safe_value' => 'COG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/congo',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Honduras',
    'description' => 'Honduras',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '17d9f241-e465-46fe-94ba-06304fd9a5f0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 340,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'HND',
          'format' => 'plain_text',
          'safe_value' => 'HND',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/honduras',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Maldives',
    'description' => 'Maldives',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '1819b759-3612-4442-9fef-4071259ed722',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 462,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MDV',
          'format' => 'plain_text',
          'safe_value' => 'MDV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/maldives',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Pigs per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '1898d2d6-ff66-43b3-ab2c-ba045f66da8e',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/pigs-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Kiribati',
    'description' => 'Kiribati',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '18bf5117-5bf7-4d9a-bc9c-eecd80302f19',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 296,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KIR',
          'format' => 'plain_text',
          'safe_value' => 'KIR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kiribati',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Gambia',
    'description' => 'Gambia',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '1bee85b3-524b-4e7d-9660-454e0482d6b6',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 270,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GMB',
          'format' => 'plain_text',
          'safe_value' => 'GMB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/gambia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Total Number of Pigs',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => '1bef61e4-ab06-40e7-a5a7-31f19cf18b90',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-number-pigs',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Oman',
    'description' => 'Oman',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '1c4ee8e3-ff48-4699-a935-fbf78f92b56d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 512,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'OMN',
          'format' => 'plain_text',
          'safe_value' => 'OMN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/oman',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Trinidad and Tobago',
    'description' => 'Trinidad and Tobago',
    'format' => 'plain_text',
    'weight' => 26,
    'uuid' => '1c64a585-e005-4a70-8f5a-64f44482402c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 780,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TTO',
          'format' => 'plain_text',
          'safe_value' => 'TTO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/trinidad-and-tobago',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Guam',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1c70d31b-8ecc-40b8-8d5b-2ccc397ae5ec',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 316,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GUM',
          'format' => NULL,
          'safe_value' => 'GUM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guam',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Romania',
    'description' => 'Romania',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '1d3c4ad7-af4f-44a2-b873-28b8dc1a5f36',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 642,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ROU',
          'format' => 'plain_text',
          'safe_value' => 'ROU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/romania',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'South-Eastern Asia',
    'description' => 'South-Eastern Asia',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 35,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/south-eastern-asia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    ),
  );
  $terms[] = array(
    'name' => 'SO2 Emissions per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '1e1e55ab-1a83-4576-8291-0037bc29c61a',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/so2-emissions-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Rwanda',
    'description' => 'Rwanda',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '1e98f332-d673-4de0-8855-d748fcc69b58',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 646,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'RWA',
          'format' => 'plain_text',
          'safe_value' => 'RWA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/rwanda',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Uzbekistan',
    'description' => 'Uzbekistan',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '1f31ee27-1cf9-4f5d-87ca-9550282bd7f1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 860,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'UZB',
          'format' => 'plain_text',
          'safe_value' => 'UZB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/uzbekistan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '52c127f7-e79c-428a-bb82-3082a2629c85',
    ),
  );
  $terms[] = array(
    'name' => 'South Africa',
    'description' => 'South Africa',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '20333486-3b0b-4013-a8e8-b10bb2cf5255',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 710,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ZAF',
          'format' => 'plain_text',
          'safe_value' => 'ZAF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/south-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    ),
  );
  $terms[] = array(
    'name' => 'Equatorial Guinea',
    'description' => 'Equatorial Guinea',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '2232b978-012f-4fc3-a28a-d743c0f521ae',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 226,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GNQ',
          'format' => 'plain_text',
          'safe_value' => 'GNQ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/equatorial-guinea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Georgia',
    'description' => 'Georgia',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '22926b76-434a-42e5-b57d-1f0db65f7a08',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 268,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GEO',
          'format' => 'plain_text',
          'safe_value' => 'GEO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/georgia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Poland',
    'description' => 'Poland',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '2355c835-9bf3-41a2-8336-e628e1593899',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 616,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'POL',
          'format' => 'plain_text',
          'safe_value' => 'POL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/poland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Total Number of Sheep',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => '235a1a01-c6c4-4273-a203-c4c7a3533b67',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-number-sheep',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Niger',
    'description' => 'Niger',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '240d1efb-a186-4d24-98e8-58c45b9fae8d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 562,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NER',
          'format' => 'plain_text',
          'safe_value' => 'NER',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/niger',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'United States of America',
    'description' => 'United States of America',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '244155ab-31b9-427a-ab9d-419c1d1fe2a9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 840,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'USA',
          'format' => 'plain_text',
          'safe_value' => 'USA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/united-states-america',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    ),
  );
  $terms[] = array(
    'name' => 'Wallis and Futuna Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '24fef82c-38fd-4d44-8fd4-7a681303676d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 876,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'WLF',
          'format' => NULL,
          'safe_value' => 'WLF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/wallis-and-futuna-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Argentina',
    'description' => 'Argentina',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '25103487-6281-45e5-8f74-955120108671',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 32,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ARG',
          'format' => 'plain_text',
          'safe_value' => 'ARG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/argentina',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Western Africa',
    'description' => 'Western Africa',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 11,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/western-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    ),
  );
  $terms[] = array(
    'name' => 'Tuvalu',
    'description' => 'Tuvalu',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '28bf68c9-e994-47a6-ac08-33154039aaa1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 798,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TUV',
          'format' => 'plain_text',
          'safe_value' => 'TUV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tuvalu',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Kyrgyzstan',
    'description' => 'Kyrgyzstan',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '28fe8f90-b891-486e-b407-744231a860bd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 417,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KGZ',
          'format' => 'plain_text',
          'safe_value' => 'KGZ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kyrgyzstan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '52c127f7-e79c-428a-bb82-3082a2629c85',
    ),
  );
  $terms[] = array(
    'name' => 'United Kingdom of Great Britain and Northern Ireland',
    'description' => 'United Kingdom of Great Britain and Northern Ireland',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => '29d368f3-bd7b-4619-91dd-bfb2f11fbaf4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 826,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GBR',
          'format' => 'plain_text',
          'safe_value' => 'GBR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/united-kingdom-great-britain-and-northern-ireland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'New Zealand',
    'description' => 'New Zealand',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2b069d9f-456c-42aa-be65-cf1d9a7ddf8a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 554,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NZL',
          'format' => 'plain_text',
          'safe_value' => 'NZL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/new-zealand',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '129199ba-f4e9-43eb-891b-5581a5baf206',
    ),
  );
  $terms[] = array(
    'name' => 'Cameroon',
    'description' => 'Cameroon',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2d2d383d-e8b8-4f09-a499-3b4eee131490',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 120,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CMR',
          'format' => 'plain_text',
          'safe_value' => 'CMR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cameroon',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Sweden',
    'description' => 'Sweden',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => '2d63e209-181b-43e8-bb9e-3e4b84eee76d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 752,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SWE',
          'format' => 'plain_text',
          'safe_value' => 'SWE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sweden',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Latin America and the Caribbean',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2fb3f46c-6a56-43eb-8b17-ac72debd1b5b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 419,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/latin-america-and-caribbean',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a1230c66-4709-4e48-acd0-ad499d3d3061',
    ),
  );
  $terms[] = array(
    'name' => 'Sark',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '2fb90103-bc10-4239-b067-90e651b11504',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 680,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sark',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Panama',
    'description' => 'Panama',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '308cb72d-6a8e-4980-b4e8-180522040f8d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 591,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PAN',
          'format' => 'plain_text',
          'safe_value' => 'PAN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/panama',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Monaco',
    'description' => 'Monaco',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '31278784-60b3-44fa-99b8-5a1afb972854',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 492,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MCO',
          'format' => 'plain_text',
          'safe_value' => 'MCO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/monaco',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Niue',
    'description' => 'Niue',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '314d6c9d-74f8-41d6-9c89-0c1cac459a28',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 570,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NIU',
          'format' => 'plain_text',
          'safe_value' => 'NIU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/niue',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'San Marino',
    'description' => 'San Marino',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '32820712-a78e-4584-963e-9dc27cce3a50',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 674,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SMR',
          'format' => 'plain_text',
          'safe_value' => 'SMR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/san-marino',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Hungary',
    'description' => 'Hungary',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '3288ce66-880b-4281-b4bc-1d14ad5d36a2',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 348,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'HUN',
          'format' => 'plain_text',
          'safe_value' => 'HUN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/hungary',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Pacific Islands (Trust Territory) (1947-1986)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '36cca487-c13f-4e61-a8ee-d72cad8ccd36',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 582,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/pacific-islands-trust-territory-1947-1986',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Polynesia',
    'description' => 'Polynesia',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 61,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/polynesia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e142c681-c49e-41dd-8ace-8016247c8cbf',
    ),
  );
  $terms[] = array(
    'name' => 'Slovenia',
    'description' => 'Slovenia',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => '375fe619-edde-4fdd-b4a7-ea14b10562a9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 705,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SVN',
          'format' => 'plain_text',
          'safe_value' => 'SVN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/slovenia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Vanuatu',
    'description' => 'Vanuatu',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '379a4f78-eae6-4ee9-80b1-eef0ffd3d4f3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 548,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VUT',
          'format' => 'plain_text',
          'safe_value' => 'VUT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/vanuatu',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    ),
  );
  $terms[] = array(
    'name' => 'Southern Asia',
    'description' => 'Southern Asia',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 34,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/southern-asia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    ),
  );
  $terms[] = array(
    'name' => 'Southern Europe',
    'description' => 'Southern Europe',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 39,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/southern-europe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '166e96aa-bcf6-4dfe-92d6-24a42d9e334f',
    ),
  );
  $terms[] = array(
    'name' => 'United States Virgin Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 28,
    'uuid' => '38b50129-76bb-42af-b21e-1fda8c7ef392',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 850,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VIR',
          'format' => NULL,
          'safe_value' => 'VIR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/united-states-virgin-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Socialist Federal Republic of Yugoslavia (until 1992)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => '3948c1b3-0b79-43f8-956d-feb1796e7c4f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 890,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/socialist-federal-republic-yugoslavia-until-1992',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Peru',
    'description' => 'Peru',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '395c658f-3fd9-4cd3-a8f5-446bc0f7e72c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 604,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PER',
          'format' => 'plain_text',
          'safe_value' => 'PER',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/peru',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Dominican Republic',
    'description' => 'Dominican Republic',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '39ba91f8-501b-4ccc-b494-ad514f56f20d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 214,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DOM',
          'format' => 'plain_text',
          'safe_value' => 'DOM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/dominican-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Infant Mortality',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '3a251cea-106f-4696-af89-85f0a894857d',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/infant-mortality',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd55d22b8-b5b7-4c82-851e-1b08dd1ce941',
    ),
  );
  $terms[] = array(
    'name' => 'Qatar',
    'description' => 'Qatar',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '3c81e642-5569-4515-8041-662e324f0a4e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 634,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'QAT',
          'format' => 'plain_text',
          'safe_value' => 'QAT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/qatar',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Paraguay',
    'description' => 'Paraguay',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '3ce544d6-ebf8-4de9-9be9-26bcaae7924f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 600,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PRY',
          'format' => 'plain_text',
          'safe_value' => 'PRY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/paraguay',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Ethiopia (until 1993)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '3d58ff0f-4cb5-4bce-b79c-9649535a8c41',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 230,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ethiopia-until-1993',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Mongolia',
    'description' => 'Mongolia',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '3df24cbc-2cac-4cc2-865f-37d63aae4683',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 496,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MNG',
          'format' => 'plain_text',
          'safe_value' => 'MNG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mongolia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Malawi',
    'description' => 'Malawi',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '3e97675f-fa81-4297-8231-c29308438faa',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 454,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MWI',
          'format' => 'plain_text',
          'safe_value' => 'MWI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/malawi',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Guatemala',
    'description' => 'Guatemala',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '3f3bf733-2539-422b-ad52-18f1e864d3e2',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 320,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GTM',
          'format' => 'plain_text',
          'safe_value' => 'GTM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guatemala',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Portugal',
    'description' => 'Portugal',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '407bb0c6-41d6-4193-a562-f2d97e450f39',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 620,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PRT',
          'format' => 'plain_text',
          'safe_value' => 'PRT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/portugal',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Melanesia',
    'description' => 'Melanesia',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 54,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/melanesia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e142c681-c49e-41dd-8ace-8016247c8cbf',
    ),
  );
  $terms[] = array(
    'name' => 'Geography, Environment, and Sustainability',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '42226113-307f-448b-9095-f365e7ed4b01',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/geography-environment-and-sustainability',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Zimbabwe',
    'description' => 'Zimbabwe',
    'format' => 'plain_text',
    'weight' => 19,
    'uuid' => '427b0059-8221-45eb-8f05-a88ccc973d43',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 716,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ZWE',
          'format' => 'plain_text',
          'safe_value' => 'ZWE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/zimbabwe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Total Cattle',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '429abef0-a958-4697-bbe8-ff39390e695d',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-cattle',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'China',
    'description' => 'China',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '449b2829-f258-47cf-97e8-0e4da21a7442',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 156,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CHN',
          'format' => 'plain_text',
          'safe_value' => 'CHN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/china',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Chile',
    'description' => 'Chile',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '454394af-2c71-4821-9a48-99071380c28a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 152,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CHL',
          'format' => 'plain_text',
          'safe_value' => 'CHL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/chile',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Micronesia (Federated States of)',
    'description' => 'Micronesia (Federated States of)',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '45531a1e-495f-4d3b-a134-cdd08ff2011b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 583,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FSM',
          'format' => 'plain_text',
          'safe_value' => 'FSM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/micronesia-federated-states',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Denmark',
    'description' => 'Denmark',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '4570d7a2-3c6d-4844-95f1-a89167f6465d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 208,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DNK',
          'format' => 'plain_text',
          'safe_value' => 'DNK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/denmark',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Lesotho',
    'description' => 'Lesotho',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4605fd84-ea0c-4d48-baeb-423c67c5e972',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 426,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LSO',
          'format' => 'plain_text',
          'safe_value' => 'LSO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/lesotho',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    ),
  );
  $terms[] = array(
    'name' => 'Occupied Palestinian Territory',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '47397f4d-50ea-44db-8542-fa274ab0a857',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 275,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PSE',
          'format' => NULL,
          'safe_value' => 'PSE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/occupied-palestinian-territory',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Philippines',
    'description' => 'Philippines',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '479d7f54-77ba-4609-bf5f-3dea01d46762',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 608,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PHL',
          'format' => 'plain_text',
          'safe_value' => 'PHL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/philippines',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Canada',
    'description' => 'Canada',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '481d2ee6-7ab7-4615-b1c7-4bb499f9ea98',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 124,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CAN',
          'format' => 'plain_text',
          'safe_value' => 'CAN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/canada',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    ),
  );
  $terms[] = array(
    'name' => 'Female Life Expectancy at Birth',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '484c41de-04fe-4eba-9274-5a797b7dccb9',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/female-life-expectancy-birth',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
    ),
  );
  $terms[] = array(
    'name' => 'Estonia',
    'description' => 'Estonia',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '48dbf7dc-4665-46d3-8afb-031da9fc2d20',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 233,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'EST',
          'format' => 'plain_text',
          'safe_value' => 'EST',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/estonia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Tibet',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '48e1af94-ca49-45b0-ab2a-792fc94e4dc3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 9003,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tibet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'French Polynesia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '498ff808-15f6-4392-946f-fd7abf1641dc',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 258,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PYF',
          'format' => NULL,
          'safe_value' => 'PYF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/french-polynesia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Total Urban Population',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => '4bf712d2-13b5-499b-80b4-f86c0c0af718',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-urban-population',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
      1 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Bermuda',
    'description' => 'Bermuda',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4bfe833a-17b8-4be3-bcd8-13d8c0a92c0d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 60,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BMU',
          'format' => 'plain_text',
          'safe_value' => 'BMU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bermuda',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    ),
  );
  $terms[] = array(
    'name' => 'Namibia',
    'description' => 'Namibia',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '4c8bb8a7-1209-4579-b39c-b7ae6594a5de',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 516,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NAM',
          'format' => 'plain_text',
          'safe_value' => 'NAM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/namibia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    ),
  );
  $terms[] = array(
    'name' => 'Suriname',
    'description' => 'Suriname',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '4d78e7f1-8ce1-4728-b5ee-c0d1aa1b484a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 740,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SUR',
          'format' => 'plain_text',
          'safe_value' => 'SUR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/suriname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Tokelau',
    'description' => 'Tokelau',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '4dc55703-7b38-4ab3-8c12-058932ed1889',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 772,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TKL',
          'format' => 'plain_text',
          'safe_value' => 'TKL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tokelau',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Yemen (until 1990)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 18,
    'uuid' => '4dde54e3-e50c-4dc7-a21f-147b898c2d9c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 886,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/yemen-until-1990',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Cattle per Capita',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4ea063f4-7178-479c-bd11-331068a13bc9',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/cattle-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd55d22b8-b5b7-4c82-851e-1b08dd1ce941',
      1 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Sudan (North)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '4ed18747-b2ac-4f18-9b7a-c16ab4e812a4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 729,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SDN',
          'format' => NULL,
          'safe_value' => 'SDN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sudan-north',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Cote d\'Ivoire',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '4f9e4b6d-ac88-4b1d-8c82-c0d4eb98e567',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 384,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CIV',
          'format' => NULL,
          'safe_value' => 'CIV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cote-divoire',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Solomon Islands',
    'description' => 'Solomon Islands',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '504cf069-920d-4d4d-a787-6c5a0d05390d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 90,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SLB',
          'format' => 'plain_text',
          'safe_value' => 'SLB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/solomon-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    ),
  );
  $terms[] = array(
    'name' => 'Finland',
    'description' => 'Finland',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '50acd5ac-d0de-4c33-bf94-e609404769b9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 246,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FIN',
          'format' => 'plain_text',
          'safe_value' => 'FIN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/finland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Kosovo',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '51aff354-01a4-418e-899f-e482064bb58e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 9001,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kosovo',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Total CO2 Emissions',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => '51d8a89c-8475-4d1b-bbe9-63aa2bb9c0cc',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-co2-emissions',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Guinea-Bissau',
    'description' => 'Guinea-Bissau',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '52501bb6-3df4-424a-9695-f880de376c0f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 624,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GNB',
          'format' => 'plain_text',
          'safe_value' => 'GNB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guinea-bissau',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Central Asia',
    'description' => 'Central Asia',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '52c127f7-e79c-428a-bb82-3082a2629c85',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 143,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/central-asia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    ),
  );
  $terms[] = array(
    'name' => 'Croatia',
    'description' => 'Croatia',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '5469c512-c49e-400c-a0c7-085f8f01fbb0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 191,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'HRV',
          'format' => 'plain_text',
          'safe_value' => 'HRV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/croatia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Total Population',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => '56302841-1459-422f-87bf-91b41ac2a85a',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-population',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
      1 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Brunei Darussalam',
    'description' => 'Brunei Darussalam',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '563b2a80-5d49-4733-9a68-03559f75ec54',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 96,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BRN',
          'format' => 'plain_text',
          'safe_value' => 'BRN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/brunei-darussalam',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Bangladesh',
    'description' => 'Bangladesh',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '57168313-1225-4c14-b788-46a5a923c05a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 50,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BGD',
          'format' => 'plain_text',
          'safe_value' => 'BGD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bangladesh',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Lithuania',
    'description' => 'Lithuania',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '579d2eba-a98d-4e2f-96c2-74e0f9c65104',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 440,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LTU',
          'format' => 'plain_text',
          'safe_value' => 'LTU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/lithuania',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Serbia',
    'description' => 'Serbia',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '58fe1259-89ca-472b-a53c-7b46cfe67030',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 688,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SRB',
          'format' => 'plain_text',
          'safe_value' => 'SRB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/serbia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Sierra Leone',
    'description' => 'Sierra Leone',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => '5931d053-9570-463f-b6f0-354df5c00486',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 694,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SLE',
          'format' => 'plain_text',
          'safe_value' => 'SLE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sierra-leone',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Turks and Caicos Islands',
    'description' => 'Turks and Caicos Islands',
    'format' => 'plain_text',
    'weight' => 27,
    'uuid' => '5a390a42-8dda-425a-a3c5-c691e0aa6df3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 796,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TCA',
          'format' => 'plain_text',
          'safe_value' => 'TCA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/turks-and-caicos-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Jordan',
    'description' => 'Jordan',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '5a60abb3-6fab-43de-8c85-cf55809aafa9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 400,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'JOR',
          'format' => 'plain_text',
          'safe_value' => 'JOR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/jordan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Jersey',
    'description' => 'Jersey',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '5bd7711a-7e1c-4d7c-a441-afc04dfb0c7c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 832,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'JEY',
          'format' => 'plain_text',
          'safe_value' => 'JEY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/jersey',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Ukraine',
    'description' => 'Ukraine',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '5bef5093-1278-4614-adf0-2ec4bb7df9ab',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 804,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'UKR',
          'format' => 'plain_text',
          'safe_value' => 'UKR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ukraine',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Egypt',
    'description' => 'Egypt',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5bfd11a8-0da0-4ea5-bb8f-e0d5433340dd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 818,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'EGY',
          'format' => 'plain_text',
          'safe_value' => 'EGY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/egypt',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Northern America',
    'description' => 'Northern America',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 21,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/northern-america',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a1230c66-4709-4e48-acd0-ad499d3d3061',
    ),
  );
  $terms[] = array(
    'name' => 'Andorra',
    'description' => 'Andorra',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5d1af60e-0bdb-4337-a47a-ea122298552a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 20,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AND',
          'format' => 'plain_text',
          'safe_value' => 'AND',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/andorra',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Belarus',
    'description' => 'Belarus',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5d3ebd12-50cf-4c4b-831a-e4ad73251c6d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 112,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BLR',
          'format' => 'plain_text',
          'safe_value' => 'BLR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/belarus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Norway',
    'description' => 'Norway',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '5da753f7-69ad-44e8-b971-62d44d7cb679',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 578,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NOR',
          'format' => 'plain_text',
          'safe_value' => 'NOR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/norway',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Spain',
    'description' => 'Spain',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => '5df1fc34-f7ff-48bc-98eb-bdf90e8b963f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 724,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ESP',
          'format' => 'plain_text',
          'safe_value' => 'ESP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/spain',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Tunisia',
    'description' => 'Tunisia',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '5dfae8e9-34a9-4782-9874-4b558f7e08fd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 788,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TUN',
          'format' => 'plain_text',
          'safe_value' => 'TUN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tunisia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Saint Martin (French part)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 23,
    'uuid' => '5e0840f4-b19d-4ed8-aff2-98800feee231',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 663,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MAF',
          'format' => NULL,
          'safe_value' => 'MAF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-martin-french-part',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Taiwan',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '5e2340ba-88aa-438a-9282-4a738337b5e4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 9002,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/taiwan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'British Virgin Islands',
    'description' => 'British Virgin Islands',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '5e23b0ed-a508-4621-9787-dce41a573d61',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 92,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VGB',
          'format' => 'plain_text',
          'safe_value' => 'VGB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/british-virgin-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Senegal',
    'description' => 'Senegal',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '5f12cbf4-8c41-4035-becf-c988153385fd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 686,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SEN',
          'format' => 'plain_text',
          'safe_value' => 'SEN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/senegal',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Total Cropland',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '5f9b854c-1c98-4967-89f4-ba88f95cf9a2',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-cropland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Saint Lucia',
    'description' => 'Saint Lucia',
    'format' => 'plain_text',
    'weight' => 22,
    'uuid' => '600b228d-9b76-4e05-8f6c-1337e184a6ca',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 662,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LCA',
          'format' => 'plain_text',
          'safe_value' => 'LCA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-lucia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Togo',
    'description' => 'Togo',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => '604b6f2b-8549-4aa5-945f-e79f96217564',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 768,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TGO',
          'format' => 'plain_text',
          'safe_value' => 'TGO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/togo',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Libya',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '6297165a-0fc5-426d-9291-be6064ba109c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 434,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LBY',
          'format' => NULL,
          'safe_value' => 'LBY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/libya',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Guyana',
    'description' => 'Guyana',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '6552c379-5164-4202-919a-779062a6e50c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 328,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GUY',
          'format' => 'plain_text',
          'safe_value' => 'GUY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guyana',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Exchange Rates to US Dollar',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '68132cb3-1151-4806-9a6c-e8feade5650e',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/exchange-rates-us-dollar',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd04082fa-fc11-4af3-b45f-e029f3aa1e7a',
    ),
  );
  $terms[] = array(
    'name' => 'Fiji',
    'description' => 'Fiji',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '684d2b5e-72c6-4f8f-a3a3-e3c472435207',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 242,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FJI',
          'format' => 'plain_text',
          'safe_value' => 'FJI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/fiji',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    ),
  );
  $terms[] = array(
    'name' => 'Long-Term Government Bond Yield',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '6886fed9-53a4-4acf-831e-a5e0fc1f7d02',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/long-term-government-bond-yield',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd04082fa-fc11-4af3-b45f-e029f3aa1e7a',
    ),
  );
  $terms[] = array(
    'name' => 'Nepal',
    'description' => 'Nepal',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '696ca151-e44a-40ba-9d2b-c16bd72bd856',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 524,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NPL',
          'format' => 'plain_text',
          'safe_value' => 'NPL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/nepal',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Eritrea',
    'description' => 'Eritrea',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '69920fd0-28f5-45f4-858c-a5b8be81f203',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 232,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ERI',
          'format' => 'plain_text',
          'safe_value' => 'ERI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/eritrea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Swaziland',
    'description' => 'Swaziland',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '6ad6c85f-2451-42e7-ab1e-737102cf75e7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 748,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SWZ',
          'format' => 'plain_text',
          'safe_value' => 'SWZ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/swaziland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    ),
  );
  $terms[] = array(
    'name' => 'Nigeria',
    'description' => 'Nigeria',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => '6c6bf374-64f5-4efa-9ea7-5e04abf84392',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 566,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NGA',
          'format' => 'plain_text',
          'safe_value' => 'NGA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/nigeria',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Botswana',
    'description' => 'Botswana',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6e0d8f95-b6eb-400c-bb62-15a48b06e890',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 72,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BWA',
          'format' => 'plain_text',
          'safe_value' => 'BWA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/botswana',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    ),
  );
  $terms[] = array(
    'name' => 'Latvia',
    'description' => 'Latvia',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '6e1fa2a3-80e8-4a6c-9daf-78e466754ab1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 428,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LVA',
          'format' => 'plain_text',
          'safe_value' => 'LVA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/latvia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'German Democratic Republic (until 1990)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '6edfe944-fe19-413d-b93d-15b673fef089',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 278,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/german-democratic-republic-until-1990',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Ghana',
    'description' => 'Ghana',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '70aeb23f-918b-41dc-98b3-75d0ec718ab0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 288,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GHA',
          'format' => 'plain_text',
          'safe_value' => 'GHA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ghana',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Costa Rica',
    'description' => 'Costa Rica',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '728a7bc9-69d0-4194-9941-33cd1e962195',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 188,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CRI',
          'format' => 'plain_text',
          'safe_value' => 'CRI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/costa-rica',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Iraq',
    'description' => 'Iraq',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '73e82ad6-cde3-4275-ab7a-e24c29e03cef',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 368,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IRQ',
          'format' => 'plain_text',
          'safe_value' => 'IRQ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/iraq',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Guernsey',
    'description' => 'Guernsey',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '77adcce1-1098-468e-b089-dc6c2d4cd01a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 831,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GGY',
          'format' => 'plain_text',
          'safe_value' => 'GGY',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guernsey',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Cayman Islands',
    'description' => 'Cayman Islands',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '78e3af74-44f2-4a69-aba4-52c90636892c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 136,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CYM',
          'format' => 'plain_text',
          'safe_value' => 'CYM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cayman-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Eastern Asia',
    'description' => 'Eastern Asia',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 30,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/eastern-asia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    ),
  );
  $terms[] = array(
    'name' => 'Faeroe Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '79ef8620-c43f-496e-b4fa-f021bf03fa6f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 234,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FRO',
          'format' => NULL,
          'safe_value' => 'FRO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/faeroe-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Turkmenistan',
    'description' => 'Turkmenistan',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '7a561b55-70e5-48b2-a366-baf0a926c8d1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 795,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TKM',
          'format' => 'plain_text',
          'safe_value' => 'TKM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/turkmenistan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '52c127f7-e79c-428a-bb82-3082a2629c85',
    ),
  );
  $terms[] = array(
    'name' => 'Eastern Africa',
    'description' => 'Eastern Africa',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '7bee44e5-2a84-446d-84cc-7079108912a5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 14,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/eastern-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    ),
  );
  $terms[] = array(
    'name' => 'France',
    'description' => 'France',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '7c41da03-d898-4aa3-8fb0-1c58cd4feea4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 250,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FRA',
          'format' => 'plain_text',
          'safe_value' => 'FRA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/france',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Malta',
    'description' => 'Malta',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '7f437baf-31e8-4ca1-ba1e-0623b80d788c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 470,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MLT',
          'format' => 'plain_text',
          'safe_value' => 'MLT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/malta',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Azerbaijan',
    'description' => 'Azerbaijan',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '7f9195a7-2a13-4fa1-a47d-187cb1f62e97',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 31,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AZE',
          'format' => 'plain_text',
          'safe_value' => 'AZE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/azerbaijan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'China, Hong Kong Special Administrative Region',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '80061b73-d096-40a5-a6bd-8dcb0d78e66d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 344,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'HKG',
          'format' => NULL,
          'safe_value' => 'HKG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/china-hong-kong-special-administrative-region',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'New Caledonia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '80e01028-982c-4705-a44a-5ab88fb1364c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 540,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NCL',
          'format' => NULL,
          'safe_value' => 'NCL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/new-caledonia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    ),
  );
  $terms[] = array(
    'name' => 'Greece',
    'description' => 'Greece',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '81ddf442-32ca-4a96-af1e-fa827506bbd4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 300,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GRC',
          'format' => 'plain_text',
          'safe_value' => 'GRC',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/greece',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Czech Republic',
    'description' => 'Czech Republic',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '8231f6e2-bfdd-4ffd-a8d2-27c6bf9cb1c8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 203,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CZE',
          'format' => 'plain_text',
          'safe_value' => 'CZE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/czech-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Saudi Arabia',
    'description' => 'Saudi Arabia',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '82652536-60e2-47d8-8b5f-3561887ade91',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 682,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SAU',
          'format' => 'plain_text',
          'safe_value' => 'SAU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saudi-arabia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'South Sudan',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '82ea86a0-2e61-46cd-9c6d-62acf16df2b9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 728,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SSD',
          'format' => NULL,
          'safe_value' => 'SSD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/south-sudan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Northern Europe',
    'description' => 'Northern Europe',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 154,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/northern-europe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '166e96aa-bcf6-4dfe-92d6-24a42d9e334f',
    ),
  );
  $terms[] = array(
    'name' => 'Sao Tome and Principe',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '85917110-903b-4cbe-bfff-7580bafe2463',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 678,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'STP',
          'format' => NULL,
          'safe_value' => 'STP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sao-tome-and-principe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Albania',
    'description' => 'Albania',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '85baf35d-847f-4c31-86d1-229e32dfa53a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 8,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ALB',
          'format' => 'plain_text',
          'safe_value' => 'ALB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/albania',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Cape Verde',
    'description' => 'Cape Verde',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '860d1c97-9b17-4b2b-bfc9-9d060ef1a74d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 132,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CPV',
          'format' => 'plain_text',
          'safe_value' => 'CPV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cape-verde',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Africa',
    'description' => 'Africa',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 2,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/africa',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Norfolk Island',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '88bff46e-7eef-417f-b98a-d744f78fed2e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 574,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NFK',
          'format' => NULL,
          'safe_value' => 'NFK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/norfolk-island',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '129199ba-f4e9-43eb-891b-5581a5baf206',
    ),
  );
  $terms[] = array(
    'name' => 'Serbia and Montenegro (until 2006)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '8970acca-81eb-40ff-8779-86a8f7a078d5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 891,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/serbia-and-montenegro-until-2006',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Falkland Islands (Malvinas)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '8a1fafdc-8889-43d7-a7eb-cb40d66520ca',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 238,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FLK',
          'format' => NULL,
          'safe_value' => 'FLK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/falkland-islands-malvinas',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Uganda',
    'description' => 'Uganda',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => '8bc1560e-f2b9-4fa7-9c02-c828ba381e92',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 800,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'UGA',
          'format' => 'plain_text',
          'safe_value' => 'UGA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/uganda',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Bahamas',
    'description' => 'Bahamas',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '8d2bd41a-c57c-4330-9faa-4e1a3bee955b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 44,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BHS',
          'format' => 'plain_text',
          'safe_value' => 'BHS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bahamas',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Republic of Korea',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '8d86c487-4ce5-4c4d-8e1d-35156afd624b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 410,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KOR',
          'format' => NULL,
          'safe_value' => 'KOR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/republic-korea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Thailand',
    'description' => 'Thailand',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '8e20ac8e-190a-4a6c-ba97-0967d95d20fb',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 764,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'THA',
          'format' => 'plain_text',
          'safe_value' => 'THA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/thailand',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Venezuela (Bolivarian Republic of)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '906848de-9634-4ebf-a31e-b3b8688466a5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 862,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VEN',
          'format' => NULL,
          'safe_value' => 'VEN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/venezuela-bolivarian-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Greenland',
    'description' => 'Greenland',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '90a58f61-7e55-4ccb-94fd-b4f99c914e2f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 304,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GRL',
          'format' => 'plain_text',
          'safe_value' => 'GRL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/greenland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    ),
  );
  $terms[] = array(
    'name' => 'Gabon',
    'description' => 'Gabon',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '90b6c0df-011b-47a7-b740-29482ef67808',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 266,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GAB',
          'format' => 'plain_text',
          'safe_value' => 'GAB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/gabon',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Cyprus',
    'description' => 'Cyprus',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '90eba5d5-c346-4261-88d9-fb04ca2d0cdd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 196,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CYP',
          'format' => 'plain_text',
          'safe_value' => 'CYP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cyprus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Mayotte',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '91477858-2370-4904-81e1-587c9da0a49a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 175,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MYT',
          'format' => NULL,
          'safe_value' => 'MYT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mayotte',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Slovakia',
    'description' => 'Slovakia',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '91f98791-b014-480a-aefb-e368232f632d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 703,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SVK',
          'format' => 'plain_text',
          'safe_value' => 'SVK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/slovakia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Marshall Islands',
    'description' => 'Marshall Islands',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '92f55772-2981-4c82-982d-a058709329a7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 584,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MHL',
          'format' => 'plain_text',
          'safe_value' => 'MHL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/marshall-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Netherlands Antilles (until 2010)',
    'description' => '',
    'format' => 'html',
    'weight' => 18,
    'uuid' => '92fe49fe-d7ad-4804-8f6c-663fff211f2e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 530,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/netherlands-antilles-until-2010',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Guadeloupe',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '9441eb6d-b363-4b14-991c-5e8f7e44abf6',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 312,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GLP',
          'format' => NULL,
          'safe_value' => 'GLP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guadeloupe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Seychelles',
    'description' => 'Seychelles',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '94535c76-16e5-4f6f-987a-cdfa960977ce',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 690,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SYC',
          'format' => 'plain_text',
          'safe_value' => 'SYC',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/seychelles',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Colombia',
    'description' => 'Colombia',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '94f7ab81-1199-404b-b67b-3da123c6df75',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 170,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'COL',
          'format' => 'plain_text',
          'safe_value' => 'COL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/colombia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Japan',
    'description' => 'Japan',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '9530ca15-3df7-4f1d-8aee-f3ed3c3ce840',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 392,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'JPN',
          'format' => 'plain_text',
          'safe_value' => 'JPN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/japan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Saint-Barthélemy',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 20,
    'uuid' => '953e2ae8-a1c8-4d98-b946-4f7a2ce1da74',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 652,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BLM',
          'format' => NULL,
          'safe_value' => 'BLM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-barthélemy',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Liechtenstein',
    'description' => 'Liechtenstein',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '97cac626-bbec-490a-9262-d123831ba269',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 438,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LIE',
          'format' => 'plain_text',
          'safe_value' => 'LIE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/liechtenstein',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Sudan (until 2011)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '98da5777-f5e7-4605-80f3-17a66f7541d8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 736,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sudan-until-2011',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Gibraltar',
    'description' => 'Gibraltar',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '9921b101-e371-4f34-9a6f-124b04eb0989',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 292,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GIB',
          'format' => 'plain_text',
          'safe_value' => 'GIB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/gibraltar',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Åland Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9953e9c2-d35c-4423-a1d8-f35e7342ada0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 248,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ALA',
          'format' => NULL,
          'safe_value' => 'ALA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/åland-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Polity2 Index',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '99792d63-23f3-42e9-b2a4-65bc09817a37',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/polity2-index',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'ca1ce3c7-b769-4630-956c-14c85950f263',
    ),
  );
  $terms[] = array(
    'name' => 'Zambia',
    'description' => 'Zambia',
    'format' => 'plain_text',
    'weight' => 18,
    'uuid' => '99d97d52-ff79-47a3-a448-a9cbd9d3d802',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 894,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ZMB',
          'format' => 'plain_text',
          'safe_value' => 'ZMB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/zambia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Total SO2 Emissions',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 16,
    'uuid' => '9ac34a39-2031-48ce-b305-a807035b2b91',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-so2-emissions',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Lebanon',
    'description' => 'Lebanon',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '9d5cd6db-5ab8-495a-ae05-a03fc06bdc05',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 422,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LBN',
          'format' => 'plain_text',
          'safe_value' => 'LBN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/lebanon',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Saint Helena',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '9f7cb74c-8581-4cf2-a19e-527734103e3b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 654,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SHN',
          'format' => NULL,
          'safe_value' => 'SHN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-helena',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Belize',
    'description' => 'Belize',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9fb1ed5b-20eb-47ab-b33e-244cfd895bc7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 84,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BLZ',
          'format' => 'plain_text',
          'safe_value' => 'BLZ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/belize',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Afghanistan',
    'description' => 'Afghanistan',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a01f97fb-007f-4463-8c4e-881f2fea4968',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 4,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AFG',
          'format' => 'plain_text',
          'safe_value' => 'AFG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/afghanistan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Pakistan',
    'description' => 'Pakistan',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'a114b64f-876f-4f53-a12c-5a886fed217e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 586,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PAK',
          'format' => 'plain_text',
          'safe_value' => 'PAK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/pakistan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Americas',
    'description' => 'Americas',
    'format' => 'plain_text',
    'weight' => 251,
    'uuid' => 'a1230c66-4709-4e48-acd0-ad499d3d3061',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 19,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/americas',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Angola',
    'description' => 'Angola',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a2452a6a-26d7-4e74-bd20-332bf1987f9a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 24,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AGO',
          'format' => 'plain_text',
          'safe_value' => 'AGO',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/angola',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Jamaica',
    'description' => 'Jamaica',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => 'a2a1526a-15d7-4536-a6e8-df31326f9e41',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 388,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'JAM',
          'format' => 'plain_text',
          'safe_value' => 'JAM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/jamaica',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Republic of Moldova',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'a3701bfc-c60b-4d74-b7f6-cf3c7c8c4103',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 498,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MDA',
          'format' => NULL,
          'safe_value' => 'MDA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/republic-moldova',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'United Arab Emirates',
    'description' => 'United Arab Emirates',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => 'a3d08cc7-5339-45a2-85b5-305524ba960e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 784,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ARE',
          'format' => 'plain_text',
          'safe_value' => 'ARE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/united-arab-emirates',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Germany',
    'description' => 'Germany',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'a43bd81d-b67c-49ba-9fad-8528d08e7256',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 276,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DEU',
          'format' => 'plain_text',
          'safe_value' => 'DEU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/germany',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Sint Maarten (Dutch part)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 25,
    'uuid' => 'a470c196-23f8-4c54-8bd2-d0426e308575',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 534,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SXM',
          'format' => NULL,
          'safe_value' => 'SXM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sint-maarten-dutch-part',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'India',
    'description' => 'India',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'a4ae4466-bf05-43cb-aad4-c8b47489c861',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 356,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IND',
          'format' => 'plain_text',
          'safe_value' => 'IND',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/india',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Brazil',
    'description' => 'Brazil',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a5a32b74-ac81-496d-a4ef-ae3007af9dbb',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 76,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BRA',
          'format' => 'plain_text',
          'safe_value' => 'BRA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/brazil',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Syrian Arab Republic',
    'description' => 'Syrian Arab Republic',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => 'a5bcb759-1c7a-45c3-81f8-113f75d6c59a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 760,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SYR',
          'format' => 'plain_text',
          'safe_value' => 'SYR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/syrian-arab-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Bosnia and Herzegovina',
    'description' => 'Bosnia and Herzegovina',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a5cabcd2-7493-48d4-94fc-684fa45595db',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 70,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BIH',
          'format' => 'plain_text',
          'safe_value' => 'BIH',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bosnia-and-herzegovina',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Papua New Guinea',
    'description' => 'Papua New Guinea',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a5eedf99-b9b3-42ca-957e-a1f2ce4169eb',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 598,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PNG',
          'format' => 'plain_text',
          'safe_value' => 'PNG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/papua-new-guinea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '407d59d0-a383-4d4b-8cad-9e2637edc416',
    ),
  );
  $terms[] = array(
    'name' => 'Micronesia',
    'description' => 'Micronesia',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 57,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/micronesia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'e142c681-c49e-41dd-8ace-8016247c8cbf',
    ),
  );
  $terms[] = array(
    'name' => 'Morocco',
    'description' => 'Morocco',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'a7aad71f-5e1b-4033-a92a-38c8ad6047ad',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 504,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MAR',
          'format' => 'plain_text',
          'safe_value' => 'MAR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/morocco',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Iran (Islamic Republic of)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'a7abd806-590b-4600-8986-30e2b6bc2cb4',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 364,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IRN',
          'format' => NULL,
          'safe_value' => 'IRN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/iran-islamic-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Central America',
    'description' => 'Central America',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 13,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/central-america',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '2fb3f46c-6a56-43eb-8b17-ac72debd1b5b',
    ),
  );
  $terms[] = array(
    'name' => 'Saint Kitts and Nevis',
    'description' => 'Saint Kitts and Nevis',
    'format' => 'plain_text',
    'weight' => 21,
    'uuid' => 'aa0e7a85-f487-4659-9df6-20b096f4a653',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 659,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KNA',
          'format' => 'plain_text',
          'safe_value' => 'KNA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-kitts-and-nevis',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Bahrain',
    'description' => 'Bahrain',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'aa45c8e7-7ef8-4aae-b7f3-0653dbcba520',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 48,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BHR',
          'format' => 'plain_text',
          'safe_value' => 'BHR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bahrain',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Singapore',
    'description' => 'Singapore',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'ac1e0be0-089a-4771-a723-906461ac199d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 702,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SGP',
          'format' => 'plain_text',
          'safe_value' => 'SGP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/singapore',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Svalbard and Jan Mayen Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => 'ac7848d9-3cd4-4710-beec-59962b5f801b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 744,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SJM',
          'format' => NULL,
          'safe_value' => 'SJM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/svalbard-and-jan-mayen-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'El Salvador',
    'description' => 'El Salvador',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'acfedf02-6b16-464b-a3c4-8324c065de46',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 222,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SLV',
          'format' => 'plain_text',
          'safe_value' => 'SLV',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/el-salvador',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Life Expectancy at Birth (Total)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'ad440f95-8fc0-4df6-b31f-bc5973f93ce0',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/life-expectancy-birth-total',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
    ),
  );
  $terms[] = array(
    'name' => 'Kuwait',
    'description' => 'Kuwait',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'ae7bfb28-4330-482a-a34a-f2f85af9aec6',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 414,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KWT',
          'format' => 'plain_text',
          'safe_value' => 'KWT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kuwait',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Viet Nam',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'aee7a984-8d3e-4da4-bf1a-b3018c62e39d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 704,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VNM',
          'format' => NULL,
          'safe_value' => 'VNM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/viet-nam',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Total Gross Central Government Debt as a Percentage of GDP',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'b08eb97e-0b08-4557-9572-d75910290c62',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-gross-central-government-debt-percentage-gdp',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd04082fa-fc11-4af3-b45f-e029f3aa1e7a',
    ),
  );
  $terms[] = array(
    'name' => 'Pasture per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'b0938a91-f89e-4010-8a64-5ae5229627a3',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/pasture-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Burundi',
    'description' => 'Burundi',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b0ed569b-b6f1-4c97-ada1-da14b9975f43',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 108,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BDI',
          'format' => 'plain_text',
          'safe_value' => 'BDI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/burundi',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Yemen',
    'description' => 'Yemen',
    'format' => 'plain_text',
    'weight' => 19,
    'uuid' => 'b1fab740-3705-447b-97a4-55fd9771c64d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 887,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'YEM',
          'format' => 'plain_text',
          'safe_value' => 'YEM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/yemen',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Montenegro',
    'description' => 'Montenegro',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'b27108bd-a733-47a5-9704-f7b979e2d2ac',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 499,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MNE',
          'format' => 'plain_text',
          'safe_value' => 'MNE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/montenegro',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Kazakhstan',
    'description' => 'Kazakhstan',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b3317fb0-4d0b-4bdf-92f8-068617aa9a15',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 398,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KAZ',
          'format' => 'plain_text',
          'safe_value' => 'KAZ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/kazakhstan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '52c127f7-e79c-428a-bb82-3082a2629c85',
    ),
  );
  $terms[] = array(
    'name' => 'Anguilla',
    'description' => 'Anguilla',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b4015dc0-1dcd-4abd-b515-20eba00ce3e8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 660,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AIA',
          'format' => 'plain_text',
          'safe_value' => 'AIA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/anguilla',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Western Sahara',
    'description' => 'Western Sahara',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'b5851253-f8d8-4efa-a077-47ac9871ed5d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 732,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ESH',
          'format' => 'plain_text',
          'safe_value' => 'ESH',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/western-sahara',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    ),
  );
  $terms[] = array(
    'name' => 'Mauritius',
    'description' => 'Mauritius',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'b5f00102-129e-499a-b5c7-c5d922783cd0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 480,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MUS',
          'format' => 'plain_text',
          'safe_value' => 'MUS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mauritius',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'USSR (until 1991)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'b77c8727-d728-482f-ae40-a6387e7974e3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 810,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ussr-until-1991',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Bhutan',
    'description' => 'Bhutan',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'b787c7db-3b25-4d28-8bef-1382963a6ef3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 64,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BTN',
          'format' => 'plain_text',
          'safe_value' => 'BTN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bhutan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Northern Africa',
    'description' => 'Northern Africa',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b7da9ece-6eca-4c99-a301-46bb55b1e5b5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 15,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/northern-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    ),
  );
  $terms[] = array(
    'name' => 'Isle of Man',
    'description' => 'Isle of Man',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'b7dae948-cfbc-4a11-aab6-2da96f560ce8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 833,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IMN',
          'format' => 'plain_text',
          'safe_value' => 'IMN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/isle-man',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Mauritania',
    'description' => 'Mauritania',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'b7ff7a33-410e-4fee-b5d0-193ae0c87e97',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 478,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MRT',
          'format' => 'plain_text',
          'safe_value' => 'MRT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mauritania',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Western Asia',
    'description' => 'Western Asia',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 145,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/western-asia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    ),
  );
  $terms[] = array(
    'name' => 'National Accounts',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => 'b9ccd609-4114-4cbd-ab11-d9bc1a59331e',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/national-accounts',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ireland',
    'description' => 'Ireland',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'ba70bd22-e829-40d5-aaa1-8424bf3e6190',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 372,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IRL',
          'format' => 'plain_text',
          'safe_value' => 'IRL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ireland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Bolivia (Plurinational State of)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'bbdd5552-7c7a-4f95-a86e-90b06ce8fa4d',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 68,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BOL',
          'format' => NULL,
          'safe_value' => 'BOL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bolivia-plurinational-state',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Male Life Expectancy at Birth',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'bc39af45-2143-4d17-abb6-edaeb499ae7a',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/male-life-expectancy-birth',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
    ),
  );
  $terms[] = array(
    'name' => 'American Samoa',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc7d7d27-721d-4c26-a56e-7418821861cd',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 16,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ASM',
          'format' => NULL,
          'safe_value' => 'ASM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/american-samoa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Mali',
    'description' => 'Mali',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'be38e696-12f6-47e5-a967-e9cb5d9505c9',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 466,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MLI',
          'format' => 'plain_text',
          'safe_value' => 'MLI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mali',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Djibouti',
    'description' => 'Djibouti',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'bee5c025-f1b0-44b0-b525-7e868757b0b5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 262,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DJI',
          'format' => 'plain_text',
          'safe_value' => 'DJI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/djibouti',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Educational Inequality Gini Coefficient',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'c03d2993-864c-4b5a-936a-6c22fd656bb8',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/educational-inequality-gini-coefficient',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'c9e47e9a-91ec-4ea9-9aea-98a1fe3d79a2',
    ),
  );
  $terms[] = array(
    'name' => 'Martinique',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => 'c0f5cf0c-cf29-436c-bc75-c71d836b7cf1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 474,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MTQ ',
          'format' => NULL,
          'safe_value' => 'MTQ ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/martinique',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Sri Lanka',
    'description' => 'Sri Lanka',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'c1d7bcac-412c-4097-a241-495aa57fecca',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 144,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'LKA',
          'format' => 'plain_text',
          'safe_value' => 'LKA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/sri-lanka',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37c6db86-5c86-4d61-ae00-b02aa9e251c5',
    ),
  );
  $terms[] = array(
    'name' => 'Armenia',
    'description' => 'Armenia',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c3349335-2c7f-485f-bf53-80b25bf694c5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 51,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ARM',
          'format' => 'plain_text',
          'safe_value' => 'ARM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/armenia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Cuba',
    'description' => 'Cuba',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'c36cdce9-1d9b-4c53-a190-151556ade323',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 192,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CUB',
          'format' => 'plain_text',
          'safe_value' => 'CUB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cuba',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Russian Federation',
    'description' => 'Russian Federation',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'c393a594-8e3f-4d19-9219-7f0f8a5667fb',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 643,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'RUS',
          'format' => 'plain_text',
          'safe_value' => 'RUS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/russian-federation',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    ),
  );
  $terms[] = array(
    'name' => 'Inflation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c4f50a10-2e4e-400f-a8a8-271de156b702',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/inflation',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'db20f7d3-b275-4b8d-913d-099b30a8ae85',
    ),
  );
  $terms[] = array(
    'name' => 'Guinea',
    'description' => 'Guinea',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'c5545906-3918-447e-8952-6f5f92e03b9f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 324,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GIN',
          'format' => 'plain_text',
          'safe_value' => 'GIN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/guinea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Burkina Faso',
    'description' => 'Burkina Faso',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'c632dce2-1a9d-4450-ae79-7a1faab9929f',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 854,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BFA',
          'format' => 'plain_text',
          'safe_value' => 'BFA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/burkina-faso',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Armed Conflicts (Internal)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c779a13f-b200-4136-a7e7-e9dad4fdaa61',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/armed-conflicts-internal',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'ca1ce3c7-b769-4630-956c-14c85950f263',
    ),
  );
  $terms[] = array(
    'name' => 'Switzerland',
    'description' => 'Switzerland',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'c7824e45-03c1-4dde-b678-8ce8c1279526',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 756,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CHE',
          'format' => 'plain_text',
          'safe_value' => 'CHE',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/switzerland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Sheep per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => 'c7bb73a7-6008-48cd-979b-57089f2b3121',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/sheep-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Human Capital',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'c9e47e9a-91ec-4ea9-9aea-98a1fe3d79a2',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/human-capital',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Institutions',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => 'ca1ce3c7-b769-4630-956c-14c85950f263',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/institutions',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Austria',
    'description' => 'Austria',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ca7aa210-0e21-45a9-8179-5ff8f7c5ed50',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 40,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AUT',
          'format' => 'plain_text',
          'safe_value' => 'AUT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/austria',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'Indonesia',
    'description' => 'Indonesia',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'ca7de4a3-1a12-4a34-a190-d98c56f5eba0',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 360,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'IDN',
          'format' => 'plain_text',
          'safe_value' => 'IDN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/indonesia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Average Years of Education',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cae4b5c0-a52e-4195-984a-32da8bdc9209',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/average-years-education',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'c9e47e9a-91ec-4ea9-9aea-98a1fe3d79a2',
    ),
  );
  $terms[] = array(
    'name' => 'Tajikistan',
    'description' => 'Tajikistan',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'cb323d35-0a87-496f-95d5-5c2f9228faf5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 762,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TJK',
          'format' => 'plain_text',
          'safe_value' => 'TJK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/tajikistan',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '52c127f7-e79c-428a-bb82-3082a2629c85',
    ),
  );
  $terms[] = array(
    'name' => 'Eastern Europe',
    'description' => 'Eastern Europe',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'cce97118-9554-4b55-9e13-ec2cd60b92f8',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 151,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/eastern-europe',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '166e96aa-bcf6-4dfe-92d6-24a42d9e334f',
    ),
  );
  $terms[] = array(
    'name' => 'Cropland per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'cfd3651f-c9ab-4ba2-a4db-204f1e19d3d9',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/cropland-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Finance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'd04082fa-fc11-4af3-b45f-e029f3aa1e7a',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/finance',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Barbados',
    'description' => 'Barbados',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'd0c19978-46ff-457d-b2c5-89105f66d5f7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 52,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BRB',
          'format' => 'plain_text',
          'safe_value' => 'BRB',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/barbados',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Demography',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'd144e915-85fa-4c7b-b85e-32998b5042b1',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/demography',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mozambique',
    'description' => 'Mozambique',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => 'd216dbaf-2a67-4897-9fcb-3d08d7c4a165',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 508,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MOZ',
          'format' => 'plain_text',
          'safe_value' => 'MOZ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/mozambique',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Biological Standards of Living',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'd55d22b8-b5b7-4c82-851e-1b08dd1ce941',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/biological-standards-living',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Turkey',
    'description' => 'Turkey',
    'format' => 'plain_text',
    'weight' => 16,
    'uuid' => 'd617e0d2-5375-484b-a2d7-e2e32c7a0c85',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 792,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TUR',
          'format' => 'plain_text',
          'safe_value' => 'TUR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/turkey',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Dominica',
    'description' => 'Dominica',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => 'd651f327-1a36-4daa-8200-56e1f5d62e9b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 212,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'DMA',
          'format' => 'plain_text',
          'safe_value' => 'DMA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/dominica',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Chad',
    'description' => 'Chad',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'd6c057ff-abd6-4ff1-8efc-45838b8abeee',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 148,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TCD',
          'format' => 'plain_text',
          'safe_value' => 'TCD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/chad',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'Total Pasture',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 14,
    'uuid' => 'd6ded972-7d1c-44a0-8e8d-d863cffd21ee',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-pasture',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Northern Mariana Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'd6f6886b-f4ea-4b92-b61a-f424277c5c83',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 580,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MNP',
          'format' => NULL,
          'safe_value' => 'MNP',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/northern-mariana-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'Bonaire, Saint Eustatius and Saba',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'd827e3c0-5268-4b78-ad82-c2a14ec0323b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 535,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BES',
          'format' => NULL,
          'safe_value' => 'BES',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/bonaire-saint-eustatius-and-saba',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Holy See',
    'description' => 'Holy See',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'd8797515-fd2d-48d9-8b40-383f2f709c93',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 336,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VAT',
          'format' => 'plain_text',
          'safe_value' => 'VAT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/holy-see',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'Haiti',
    'description' => 'Haiti',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => 'd8d53458-6b92-456c-b0b2-28a98bc89a2b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 332,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'HTI',
          'format' => 'plain_text',
          'safe_value' => 'HTI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/haiti',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Democratic Yemen (until 1990)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'd9714a3b-833c-424b-97fe-57c3f89131a1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 720,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/democratic-yemen-until-1990',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b8bdeedd-9c8d-4e0e-a626-376554215de8',
    ),
  );
  $terms[] = array(
    'name' => 'Central African Republic',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'd9715d92-7de3-4f28-8bc4-4a18b2ba7777',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 140,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'CAF',
          'format' => NULL,
          'safe_value' => 'CAF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/central-african-republic',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    ),
  );
  $terms[] = array(
    'name' => 'GDP per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd984a8cd-8b88-460c-8027-50c36fc2b7a9',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/gdp-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'b9ccd609-4114-4cbd-ab11-d9bc1a59331e',
    ),
  );
  $terms[] = array(
    'name' => 'Cambodia',
    'description' => 'Cambodia',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd9e758a7-61ed-4d4d-935c-ad85cf9683a5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 116,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'KHM',
          'format' => 'plain_text',
          'safe_value' => 'KHM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/cambodia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Benin',
    'description' => 'Benin',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'da280f4c-992f-4680-bdfe-1757de65d345',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 204,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BEN',
          'format' => 'plain_text',
          'safe_value' => 'BEN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/benin',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '26bdac36-27ac-4933-a51c-fa8bf567373c',
    ),
  );
  $terms[] = array(
    'name' => 'Prices and Wages',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 15,
    'uuid' => 'db20f7d3-b275-4b8d-913d-099b30a8ae85',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/prices-and-wages',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Saint Pierre and Miquelon',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'e1072ad7-fb07-4da3-9bda-3d9dc5047be6',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 666,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SPM ',
          'format' => NULL,
          'safe_value' => 'SPM ',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-pierre-and-miquelon',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5c1b466c-e870-4c1d-8b30-e8ee03993cfe',
    ),
  );
  $terms[] = array(
    'name' => 'Oceania',
    'description' => 'Oceania',
    'format' => 'plain_text',
    'weight' => 254,
    'uuid' => 'e142c681-c49e-41dd-8ace-8016247c8cbf',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 9,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/oceania',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Myanmar',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'e2c1e020-9f00-4209-a5b2-61c64458e03e',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 104,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MMR',
          'format' => NULL,
          'safe_value' => 'MMR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/myanmar',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Height',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'e2de437a-508c-4348-85dd-77188678f9ed',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/height',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'd55d22b8-b5b7-4c82-851e-1b08dd1ce941',
    ),
  );
  $terms[] = array(
    'name' => 'Southern Africa',
    'description' => 'Southern Africa',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'e36e0b20-27f1-420a-baf3-a82a05910a00',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 18,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/southern-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    ),
  );
  $terms[] = array(
    'name' => 'Antigua and Barbuda',
    'description' => 'Antigua and Barbuda',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'e515cb97-aad7-4206-b890-8826faa4ec5c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 28,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ATG',
          'format' => 'plain_text',
          'safe_value' => 'ATG',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/antigua-and-barbuda',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Aruba',
    'description' => 'Aruba',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'e5895f19-5ab2-4264-84ad-93a62ccd3512',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 533,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ABW',
          'format' => 'plain_text',
          'safe_value' => 'ABW',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/aruba',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Goats per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'e64745f6-17cc-4188-9915-fe9f7b1b7078',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/goats-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Channel Islands',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'e85eb6d4-21b7-45fd-ab96-c2e5b6f96635',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 830,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/channel-islands',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'CO2 Emissions per Capita',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'eb79fec6-c537-4958-ab1f-6ba55ffa098b',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/co2-emissions-capita',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Total Number of Goats',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => 'ed48cf6e-4127-46a5-86d6-68cabb800e3d',
    'vocabulary_machine_name' => 'indicators',
    'url_alias' => array(
      0 => array(
        'alias' => 'indicators/total-number-goats',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '42226113-307f-448b-9095-f365e7ed4b01',
    ),
  );
  $terms[] = array(
    'name' => 'Belgium',
    'description' => 'Belgium',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'ef962d8e-af31-494a-888e-d6bf74959f54',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 56,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'BEL',
          'format' => 'plain_text',
          'safe_value' => 'BEL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/belgium',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1127bc1b-9a0a-46c1-90f1-9e18309af553',
    ),
  );
  $terms[] = array(
    'name' => 'The former Yugoslav Republic of Macedonia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 18,
    'uuid' => 'f094b70a-b80c-49d4-b5af-4b243a488141',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 807,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MKD',
          'format' => NULL,
          'safe_value' => 'MKD',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/former-yugoslav-republic-macedonia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'United Republic of Tanzania',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => 'f10d0bd6-4234-4b81-9644-bef128a31c27',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 834,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'TZA',
          'format' => NULL,
          'safe_value' => 'TZA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/united-republic-tanzania',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Asia',
    'description' => 'Asia',
    'format' => 'plain_text',
    'weight' => 252,
    'uuid' => 'f148823e-438e-453f-a2e5-5b26ccd67e4a',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 142,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/asia',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Pitcairn',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'f24c07ec-dbc1-4a3f-8616-d308ae7221ed',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 612,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PCN',
          'format' => NULL,
          'safe_value' => 'PCN',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/pitcairn',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '36f9d386-4dec-4658-97f8-daf5695fca7e',
    ),
  );
  $terms[] = array(
    'name' => 'Ethiopia (from 1993)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'f3a16269-86dd-4b06-b73e-f82bd6a7ef15',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 231,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ETH',
          'format' => NULL,
          'safe_value' => 'ETH',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/ethiopia-1993',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Comoros',
    'description' => 'Comoros',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'f3dccfc7-1258-45ca-97c1-c3c2d831a3e5',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 174,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'COM',
          'format' => 'plain_text',
          'safe_value' => 'COM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/comoros',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Somalia',
    'description' => 'Somalia',
    'format' => 'plain_text',
    'weight' => 15,
    'uuid' => 'f414bdd1-fa4d-4a4f-a56f-a3946a1bc3c7',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 706,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'SOM',
          'format' => 'plain_text',
          'safe_value' => 'SOM',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/somalia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Australia',
    'description' => 'Australia',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f65aae5f-496e-4bf8-b2e3-2e5c1c77fed1',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 36,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'AUS',
          'format' => 'plain_text',
          'safe_value' => 'AUS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/australia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '129199ba-f4e9-43eb-891b-5581a5baf206',
    ),
  );
  $terms[] = array(
    'name' => 'Nicaragua',
    'description' => 'Nicaragua',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'f67a6647-6849-4b6e-9c3e-43862b99f1ee',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 558,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NIC',
          'format' => 'plain_text',
          'safe_value' => 'NIC',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/nicaragua',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a980a142-49f1-4a5a-8d40-c8bb80afde3e',
    ),
  );
  $terms[] = array(
    'name' => 'Middle Africa',
    'description' => 'Middle Africa',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'f69003a4-92ff-4c67-b275-f854bc831e95',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 17,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/middle-africa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '888f400f-a30c-43cc-892e-8a4e3fc7ca8e',
    ),
  );
  $terms[] = array(
    'name' => 'Indonesia (until 1999)',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'f6f78fab-7eba-4d02-af92-3af7c3b53cc2',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 9004,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/indonesia-until-1999',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Montserrat',
    'description' => 'Montserrat',
    'format' => 'plain_text',
    'weight' => 17,
    'uuid' => 'f85b7394-d969-4507-86df-bf9b707aa4e6',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 500,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MSR',
          'format' => 'plain_text',
          'safe_value' => 'MSR',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/montserrat',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Saint Vincent and the Grenadines',
    'description' => 'Saint Vincent and the Grenadines',
    'format' => 'plain_text',
    'weight' => 24,
    'uuid' => 'f9b76f46-63ab-4381-98c6-a3700277894c',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 670,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'VCT',
          'format' => 'plain_text',
          'safe_value' => 'VCT',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/saint-vincent-and-grenadines',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Malaysia',
    'description' => 'Malaysia',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'fb21ea7f-24df-43a2-8db0-0c7cdb1794f3',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 458,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'MYS',
          'format' => 'plain_text',
          'safe_value' => 'MYS',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/malaysia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1d5d6157-0f11-4cdb-bc0a-10eef13dc13e',
    ),
  );
  $terms[] = array(
    'name' => 'Puerto Rico',
    'description' => 'Puerto Rico',
    'format' => 'plain_text',
    'weight' => 19,
    'uuid' => 'fbaa1653-7192-4533-8ddb-b22204317b36',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 630,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PRI',
          'format' => 'plain_text',
          'safe_value' => 'PRI',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/puerto-rico',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0672dc20-031b-485e-8a15-762774bc6453',
    ),
  );
  $terms[] = array(
    'name' => 'Iceland',
    'description' => 'Iceland',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'fc00eada-824c-4b33-91a1-2e008b185c5b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 352,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ISL',
          'format' => 'plain_text',
          'safe_value' => 'ISL',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/iceland',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '837a1bfa-c4b6-4344-adb8-084f97415e61',
    ),
  );
  $terms[] = array(
    'name' => 'Italy',
    'description' => 'Italy',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'fc77cdae-9818-4680-a858-51849c8d590b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 380,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'ITA',
          'format' => 'plain_text',
          'safe_value' => 'ITA',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/italy',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '37d564ff-7e51-456b-ae25-3b4558b56e43',
    ),
  );
  $terms[] = array(
    'name' => 'South America',
    'description' => 'South America',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_country_code' => array(),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/south-america',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '2fb3f46c-6a56-43eb-8b17-ac72debd1b5b',
    ),
  );
  $terms[] = array(
    'name' => 'Palau',
    'description' => 'Palau',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'fcdf8bf2-9ee3-4873-9f49-0625948f8906',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 585,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PLW',
          'format' => 'plain_text',
          'safe_value' => 'PLW',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/palau',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  $terms[] = array(
    'name' => 'French Guiana',
    'description' => 'French Guiana',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'fce1f4e5-b92f-4fcf-87d0-f43c3abcac0b',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 254,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'GUF',
          'format' => 'plain_text',
          'safe_value' => 'GUF',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/french-guiana',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'fcb85f77-21a8-4f57-bf47-673051fa9309',
    ),
  );
  $terms[] = array(
    'name' => 'Democratic People\'s Republic of Korea',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'fd111446-8998-4a27-bbf5-16c9a983e370',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 408,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'PRK',
          'format' => NULL,
          'safe_value' => 'PRK',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/democratic-peoples-republic-korea',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '792c6f58-987d-4a82-9f78-0d5b5d853c75',
    ),
  );
  $terms[] = array(
    'name' => 'Réunion',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => 'febdfb21-68ef-4788-9958-2282aea5e003',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 638,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'REU',
          'format' => NULL,
          'safe_value' => 'REU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/réunion',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '7bee44e5-2a84-446d-84cc-7079108912a5',
    ),
  );
  $terms[] = array(
    'name' => 'Nauru',
    'description' => 'Nauru',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'ff0208c4-c9b7-4612-b815-82ae57895cac',
    'vocabulary_machine_name' => 'countries',
    'field_country_id' => array(
      'und' => array(
        0 => array(
          'value' => 520,
        ),
      ),
    ),
    'field_country_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NRU',
          'format' => 'plain_text',
          'safe_value' => 'NRU',
        ),
      ),
    ),
    'field_country_status' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'countries/nauru',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'a70bdf91-6aeb-45bb-b11d-996df07e8442',
    ),
  );
  return $terms;
}
