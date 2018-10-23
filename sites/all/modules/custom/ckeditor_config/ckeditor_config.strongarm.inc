<?php
/**
 * @file
 * ckeditor_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ckeditor_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_dirperm';
  $strongarm->value = '0777';
  $export['elfinder_settings_filesystem_dirperm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_fileperm';
  $strongarm->value = '0666';
  $export['elfinder_settings_filesystem_fileperm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_fileurl';
  $strongarm->value = 'true';
  $export['elfinder_settings_filesystem_fileurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_mimedetect';
  $strongarm->value = 'auto';
  $export['elfinder_settings_filesystem_mimedetect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_root';
  $strongarm->value = 'custom';
  $export['elfinder_settings_filesystem_root'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_root_custom';
  $strongarm->value = '%files/content_files';
  $export['elfinder_settings_filesystem_root_custom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_filesystem_url_custom';
  $strongarm->value = '/%files/content_files';
  $export['elfinder_settings_filesystem_url_custom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_misc_rememberlastdir';
  $strongarm->value = 'true';
  $export['elfinder_settings_misc_rememberlastdir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_misc_usesystemjquery';
  $strongarm->value = 'true';
  $export['elfinder_settings_misc_usesystemjquery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_thumbnail_dirname';
  $strongarm->value = 'tmb';
  $export['elfinder_settings_thumbnail_dirname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_thumbnail_imglib';
  $strongarm->value = 'auto';
  $export['elfinder_settings_thumbnail_imglib'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elfinder_settings_thumbnail_size';
  $strongarm->value = '48';
  $export['elfinder_settings_thumbnail_size'] = $strongarm;

  return $export;
}
