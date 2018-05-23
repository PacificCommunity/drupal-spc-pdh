<?php
// plugin settings
$plugin = array(
  'title' => t('Page not found'),
  'render callback' => 'page_not_found_page_render',
  'category' => 'Error Pages',
);

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 * @return stdClass
 */
function page_not_found_page_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  drupal_set_title(variable_get('page_404_title', 'Page not found'));

  $block->content = '
    <h1>' . variable_get('page_404_title', 'Page not found') . '</h1>
    <div class="error-pages-page-content">'
     . variable_get('page_404_body', '<p>The page you are looking for might have been removed, had its name changed or is temporarily unavailable.</p>') . '
    </div>';

  return $block;
}