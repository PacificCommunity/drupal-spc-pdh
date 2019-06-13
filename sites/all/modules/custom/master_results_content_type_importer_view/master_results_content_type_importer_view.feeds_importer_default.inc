<?php

/**
 * @file
 * master_results_content_type_importer_view.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function master_results_content_type_importer_view_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_to_master_results';
  $feeds_importer->config = array(
    'name' => 'CSV to master results',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_master_results_plan_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => '1',
            'target' => 'field_master_results_kpi',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => '2',
            'target' => 'field_master_result_type_result',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          3 => array(
            'source' => '3',
            'target' => 'field_master_result_country',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          4 => array(
            'source' => '4',
            'target' => 'field_master_results_sdg',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          5 => array(
            'source' => '5',
            'target' => 'field_master_results_contribut',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => '6',
            'target' => 'field_master_results_division',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => '7',
            'target' => 'field_master_results_dev_obj',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          8 => array(
            'source' => '8',
            'target' => 'field_master_results_link',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => '9',
            'target' => 'field_master_results_link_fr',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => '10',
            'target' => 'field_master_results_year',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          11 => array(
            'source' => '7',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'master_results',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_to_master_results'] = $feeds_importer;

  return $export;
}
