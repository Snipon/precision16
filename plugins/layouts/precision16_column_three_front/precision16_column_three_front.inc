<?php

$plugin = array(
  'title' => t('Precision16 three columns front page'),
  'theme' => 'precision16_column_three_front',
  'icon' => 'precision16-column-three-front.png',
  'category' => 'precision16',
  'panels' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'aside_alpha' => t('Aside alpha'),
    'aside_beta' => t('Aside beta'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_three_front().
 */
function precision16_preprocess_precision16_column_three_front(&$vars) {
  precision16_check_layout_variables($vars);
}
