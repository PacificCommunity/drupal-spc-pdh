<?php
/**
 * 404 settings form
 *
 * @param $form
 * @param $form_state
 */
function error_pages_404_admin_form ($form, &$form_state) {
  $form['page_404_title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#description' => t('404 page title'),
    '#default_value' => variable_get('page_404_title', 'Page not found')
  );

  $form['page_404_body'] = array(
    '#title' => t('Body'),
    '#type' => 'text_format',
    '#description' => t('404 page body'),
    '#default_value' => variable_get('page_404_body', '<p>The page you are looking for might have been removed, had its name changed or is temporarily unavailable.</p>')
  );

  return system_settings_form($form);
}

/**
 * 404 settings form
 *
 * @param $form
 * @param $form_state
 */
function error_pages_403_admin_form ($form, &$form_state) {
  $form['page_403_title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#description' => t('403 page title'),
    '#default_value' => variable_get('page_403_title', 'Page not found')
  );

  $form['page_403_body'] = array(
    '#title' => t('Body'),
    '#type' => 'text_format',
    '#description' => t('403 page body'),
    '#default_value' => variable_get('page_403_body', '<p>You are not authorised to access this page.</p>')
  );

  return system_settings_form($form);
}

