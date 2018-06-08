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

  // Exported image style: home_banner_full_width.
  $styles['home_banner_full_width'] = array(
    'label' => 'Home banner full width',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1800,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_page_articles.
  $styles['home_page_articles'] = array(
    'label' => 'Home Page Articles (275x275)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 275,
          'height' => 275,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: icon__25x25_.
  $styles['icon__25x25_'] = array(
    'label' => 'Icon (25x25)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 25,
          'height' => 25,
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

  // Exported image style: similar_posts.
  $styles['similar_posts'] = array(
    'label' => 'Similar Posts (165x165)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 165,
          'height' => 165,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
