<?php

/**
 * @file
 * dotstat_charts.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dotstat_charts_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_conf'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_conf'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => array(
      0 => array(
        'value' => '{
  title: \'Education Level (SDG 4.5.1)\',
  subtitle: \'\',
  type: \'column\',
  yAxisLabel: \'Index\',
  tooltip: {
    headerFormat: \'\',
    pointFormat: \'<em>{point.label}</em><br />Education Level ({point.year}): <b>{point.y}</b>\'
  },
  showTable: false
}',
      ),
    ),
    'deleted' => 0,
    'description' => 'HighCharts Configuration (JSON Object)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_conf',
    'label' => 'DotStat chart conf',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_json'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_json'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_json',
    'label' => 'DotStat chart JSON',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_link'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_link'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '.Stat Data URL to data structure definition',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_link',
    'label' => 'DotStat chart link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_allowed_values' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 80,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_parser'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_parser'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => array(
      0 => array(
        'value' => '{
  "name": "dim[2].id",
  "label": "dim[2].name",
  "year": "dim[12].name",
  "y": "val[0]"
}',
      ),
    ),
    'deleted' => 0,
    'description' => 'HighCharts Parser configuration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_parser',
    'label' => 'DotStat chart parser',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_query'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_query'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => array(
      0 => array(
        'value' => 'https://stats.spc.int/SeptemberDisseminateNSIService/Rest/data/SPC,DF_SDG,1.0/.SE_TOT_GPI......ISCED11_10..../?startPeriod=2007&endPeriod=2018&dimensionAtObservation=AllDimensions',
      ),
    ),
    'deleted' => 0,
    'description' => 'URL to call .stat\'s API, requesting for JSON data',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_query',
    'label' => 'DotStat chart query',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bean-dotstat_chart_block-field_dotstat_chart_structure'.
  $field_instances['bean-dotstat_chart_block-field_dotstat_chart_structure'] = array(
    'bundle' => 'dotstat_chart_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '.Stat Data URL to data structure definition',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_dotstat_chart_structure',
    'label' => 'DotStat chart structure',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_allowed_values' => '',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 80,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('.Stat Data URL to data structure definition');
  t('DotStat chart JSON');
  t('DotStat chart conf');
  t('DotStat chart link');
  t('DotStat chart parser');
  t('DotStat chart query');
  t('DotStat chart structure');
  t('HighCharts Configuration (JSON Object)');
  t('HighCharts Parser configuration');
  t('URL to call .stat\'s API, requesting for JSON data');

  return $field_instances;
}
