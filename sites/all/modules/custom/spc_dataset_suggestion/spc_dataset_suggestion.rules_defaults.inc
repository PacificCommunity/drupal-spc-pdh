<?php

/**
 * @file
 * spc_dataset_suggestion.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function spc_dataset_suggestion_default_rules_configuration() {
  $items = array();
  $items['rules_show_suggestions_list_instead_of_individual_node'] = entity_import('rules_config', '{ "rules_show_suggestions_list_instead_of_individual_node" : {
      "LABEL" : "Show suggestions list instead of individual node",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--dataset_suggestion" : { "bundle" : "dataset_suggestion" } },
      "DO" : [ { "redirect" : { "url" : "dataset-suggestions" } } ]
    }
  }');
  return $items;
}
