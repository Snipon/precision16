<?php

$plugin = array(
  'title' => t('Precision16 three columns'),
  'theme' => 'precision16_column_three',
  'icon' => 'precision16-column-three.png',
  'category' => 'precision16',
  'panels' => array(
    'header_alpha' => t('Header alpha'),
    'header_beta' => t('Header beta'),
    'main' => t('Main'),
    'aside_alpha' => t('Aside alpha'),
    'aside_beta' => t('Aside beta'),
    'footer_alpha' => t('Footer alpha'),
    'footer_beta' => t('Footer beta'),
  ),
);

/**
 * Implementation of theme_preprocess_precision16_column_three().
 */
function precision16_preprocess_precision16_column_three(&$vars) {
  precision16_check_layout_variables($vars);
}
