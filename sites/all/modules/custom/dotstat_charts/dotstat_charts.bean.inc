<?php

/**
 * @file
 * dotstat_charts.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function dotstat_charts_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'dotstat_chart_block';
  $bean_type->label = 'DotStat Chart Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['dotstat_chart_block'] = $bean_type;

  return $export;
}
