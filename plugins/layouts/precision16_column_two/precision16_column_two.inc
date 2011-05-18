<?php

$plugin = array(
  'title' => t('Precision two columns'),
  'theme' => 'precision16_column_two',
  'icon' => 'precision16-column-two.png',
  'category' => 'precision16',
  'regions' => array(
    'header_alpha' => t('Header alpha'),
    'main' => t('Main'),
    'aside_beta' => t('Aside beta'),
    'footer_alpha' => t('Footer alpha'),
  ),
);

/**
 * Implementation of theme_preprocess_precision16_column_two().
 */
function precision16_preprocess_precision16_column_two(&$vars) {
  precision16_check_layout_variables($vars);
}
