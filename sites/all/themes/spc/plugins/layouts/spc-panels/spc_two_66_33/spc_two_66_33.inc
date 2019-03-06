<?php

$plugin = array(
  'title' => t('SPC Two column 66/33'),
  'icon' => 'spc_two_66_33.png',
  'category' => t('SPC Panels'),
  'theme' => 'spc_two_66_33',
  'css' => 'spc_two_66_33.admin.css',
  'regions' => array(
    'two_66_33_top'    => t('Top (conditional)'),
    'two_66_33_first'  => t('Left'),
    'two_66_33_second' => t('Right'),
    'two_66_33_bottom' => t('Bottom (conditional)'),
  ),
);
