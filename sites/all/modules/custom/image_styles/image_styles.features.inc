<?php
/**
 * @file
 * image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: home_page_articles.
  $styles['home_page_articles'] = array(
    'label' => 'Home Page Articles (600x300)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: publication_preview__200x280_.
  $styles['publication_preview__200x280_'] = array(
    'label' => 'Publication preview (200x280)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 280,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
