<?php
/**
 * @file
 * articles_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function articles_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_first_column|node|article|article_view_on_homepage';
  $field_group->group_name = 'group_article_first_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'article_view_on_homepage';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-article-first-column field-group-div group-article-item',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_article_first_column|node|article|article_view_on_homepage'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_second_column|node|article|article_view_on_homepage';
  $field_group->group_name = 'group_article_second_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'article_view_on_homepage';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'node_link',
      2 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-article-second-column field-group-div group-article-item',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_article_second_column|node|article|article_view_on_homepage'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tg_article_items|node|article|thematic_group_artiacle';
  $field_group->group_name = 'group_tg_article_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'thematic_group_artiacle';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-tg-article-items field-group-fieldset',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_tg_article_items|node|article|thematic_group_artiacle'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_block|node|article|default';
  $field_group->group_name = 'group_title_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title block',
    'weight' => '0',
    'children' => array(
      0 => 'field_thematic_group',
      1 => 'title',
      2 => 'author',
      3 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Title block',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-title-block field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_title_block|node|article|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Title block');

  return $field_groups;
}
