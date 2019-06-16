<?php

/**
 * @file
 * master_results_content_type_importer_view.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function master_results_content_type_importer_view_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 2018,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '6ac9706d-0953-4f80-ad78-5416c5e82706',
    'vocabulary_machine_name' => 'year',
  );
  return $terms;
}
