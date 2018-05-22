<?php

function ckan_menu_sync_settings_form($form, &$form_state) {
  $form['ckan_menu_sync_menus'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Menus',
    '#required' => TRUE,
    '#description' => t('Selected menus will be synchronized with CKAN.'),
    '#options' => menu_get_menus(),
    '#default_value' => variable_get('ckan_menu_sync_menus', array('main-menu')),
  );

  return system_settings_form($form);
}