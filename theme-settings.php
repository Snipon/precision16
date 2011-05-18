<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function precision16_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['precision16_show_overlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show grid overlay'),
    '#default_value' =>  theme_get_setting('precision16_show_overlay'),
    '#description' => t('Shows the precision grid debug overlay.'),
  );
}
