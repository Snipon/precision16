<?php

$plugin = array(
  'title' => t('Precision naked'),
  'theme' => 'precision16_naked',
  'icon' => 'precision16-naked.png',
  'category' => 'precision16',
  'regions' => array(
    'main' => t('Main'),
  ),
);

/**
 * Implementation of theme_preprocess_precision16_naked().
 */
function precision16_preprocess_precision16_naked(&$vars) {
  precision16_check_layout_variables($vars);
}
