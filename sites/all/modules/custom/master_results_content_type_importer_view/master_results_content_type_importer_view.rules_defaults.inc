<?php

/**
 * @file
 * master_results_content_type_importer_view.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function master_results_content_type_importer_view_default_rules_configuration() {
  $items = array();
  $items['rules_show_results_list_instead_of_individual_node'] = entity_import('rules_config', '{ "rules_show_results_list_instead_of_individual_node" : {
      "LABEL" : "Show results list instead of individual node",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--master_results" : { "bundle" : "master_results" } },
      "DO" : [ { "redirect" : { "url" : "results-explorer" } } ]
    }
  }');
  return $items;
}
