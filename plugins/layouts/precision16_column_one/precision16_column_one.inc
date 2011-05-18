<?php

$plugin = array(
  'title' => t('Precision one column'),
  'theme' => 'precision16_column_one',
  'icon' => 'precision16-column-one.png',
  'category' => 'precision16',
  'regions' => array(
    'main' => t('Main'),
  ),
);

/**
 * Implementation of theme_preprocess_precision16_column_one().
 */
function precision16_preprocess_precision16_column_one(&$vars) {
  precision16_check_layout_variables($vars);
}
