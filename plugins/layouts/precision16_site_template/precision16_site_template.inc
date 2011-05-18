<?php

$plugin = array(
  'title' => t('Precision site template'),
  'theme' => 'precision16_site_template',
  'icon' => 'precision16-site-template.png',
  'category' => 'precision16',
  'regions' => array(
    'branding' => t('Branding'),
    'nav' => t('Navigation'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);

/**
 * Preprocess the site template layout.
 */
function precision16_preprocess_precision16_site_template(&$vars) {
  precision16_check_layout_variables($vars);
}
