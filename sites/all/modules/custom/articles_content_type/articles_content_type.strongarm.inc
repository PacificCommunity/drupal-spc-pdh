<?php
/**
 * @file
 * articles_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function articles_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_field_group';
  $strongarm->value = array(
    'group_article_item|node|article|thematic_group_artiacle' => TRUE,
    'group_tg_article_items|node|article|thematic_group_artiacle' => FALSE,
    'group_article_first_column|node|article|article_view_on_homepage' => FALSE,
    'group_article_second_column|node|article|article_view_on_homepage' => FALSE,
    'group_title_block|node|article|default' => FALSE,
    'group_thematic_groups|node|article|default' => FALSE,
    'group_with_icon|node|thematic_group|group_with_icon' => FALSE,
    'group_countries_wrapper|node|page|default' => FALSE,
  );
  $export['default_field_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__article_on_home_page';
  $strongarm->value = array(
    'view_modes' => array(
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-9',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__article_on_home_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'thematic_group_artiacle' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'article_view_on_homepage' => array(
        'custom_settings' => TRUE,
      ),
      'thematic_group_article' => array(
        'custom_settings' => TRUE,
      ),
      'related_articles_and_publication' => array(
        'custom_settings' => TRUE,
      ),
      'similar_posts' => array(
        'custom_settings' => TRUE,
      ),
      'group_with_icon' => array(
        'custom_settings' => FALSE,
      ),
      'data_insights_individual_page' => array(
        'custom_settings' => FALSE,
      ),
      'data_insights_list_page' => array(
        'custom_settings' => FALSE,
      ),
      'data_insights_on_topic_page' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_article_pattern';
  $strongarm->value = '';
  $export['pathauto_node_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_tags_pattern'] = $strongarm;

  return $export;
}
