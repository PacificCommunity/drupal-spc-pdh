<?php
// plugin settings
$plugin = array(
  'title' => t('Access Denied'),
  'render callback' => 'access_denied_page_render',
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
function access_denied_page_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  drupal_set_title(variable_get('page_403_title', 'Access Denied'));

  $block->content = '
    <h1>' . variable_get('page_403_title', 'Access Denied') . '</h1>
    <div class="error-pages-page-content">'
     . variable_get('page_403_body', '<p>You are not authorised to access this page.</p>') . '
    </div>';

  return $block;
}