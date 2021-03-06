<?php

$plugin = array(
  'title' => t('precision16 grid'),
  'description' => t('Wraps panels or panes in a grid.'),
  'render panel' => 'precision16_grid_render_panel',
  'render pane' => 'precision16_grid_render_pane',
  'settings form' => 'precision16_grid_settings_form',
  'pane settings form' => 'precision16_grid_settings_form',
  'hook theme' => array(
    'precision16_grid' => array(
      'arguments' => array('content' => NULL, 'attributes' => array()),
    ),
  ),
);

/**
 * Theme function for a grid.
 */
function theme_precision16_grid($content, $attributes) {
  if (!empty($content)) {
    return '<div ' . drupal_attributes($attributes) . '>' . $content . '</div>';
  }
}

/**
 * Theme function for the panel style.
 */
function theme_precision16_grid_render_panel($display, $panel_id, $panes, $settings) {
  $output = '';
  foreach ($panes as $pane_id => $pane) {
    $output .= panels_render_pane($pane, $display->content[$pane_id], $display);
  }
  $attributes = precision16_grid_parse_settings($settings);
  return theme('precision16_grid', $output, $attributes);
}

/**
 * Theme function for the pane style.
 *
 * To save some markup, we merge our settings into the pane CSS settings.
 */
function theme_precision16_grid_render_pane($content, $pane, $display) {
  $attributes = precision16_grid_parse_settings($pane->style['settings']);
  foreach ($attributes as $attribute => $value) {
    if (empty($content->{"css_$attribute"})) {
      $content->{"css_$attribute"} = $value;
    }
    else {
      $content->{"css_$attribute"} .= ' ' . $value;
    }
  }
  return theme('panels_pane', $content, $pane, $display);
}

/**
 * Helper function for parsing an settings array.
 */
function precision16_grid_parse_settings($settings) {
  $attributes = array();
  $classes = array();
  $id = '';

  foreach ($settings as $key => $value) {
    if (!empty($value)) {
      if ($key == 'id') {
        $id = $value;
      }
      elseif ($key == 'class') {
        $classes[] = $value;
      }
      elseif (in_array($key, array('grid', 'prefix', 'suffix', 'pad', 'push', 'pull'))) {
        $classes[] = $key . '-' . $value;
      }
      elseif (in_array($key, array('alpha', 'omega'))) {
        $classes[] = $key;
      }
      else {
        $classes[] = 'grid-' . $key;
      }
    }
  }
  $classes = implode(' ', $classes);

  if (!empty($id)) {
    $attributes['id'] = $id;
  }
  if (!empty($classes)) {
    $attributes['class'] = $classes;
  }
  return $attributes;
}

/**
 * Helper function for options.
 */
function precision16_grid_get_options($key) {
  if (!in_array($key, array('grid', 'prefix', 'suffix', 'pad', 'push', 'pull'))) {
    return array();
  }
  $options = array('' => t('None'));
  for ($i = 1; $i <= 16; $i++) {
    $options[$i] = format_plural($i, '1 grid', '@num grids', array('@num' => $i));
  }
  return $options;
}

/**
 * Helper function for the setting forms.
 */
function precision16_grid_settings_form($settings) {
  $form = array();

  $form['id'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS id'),
    '#description' => t('Enter a string to be used as the id attribute.'),
    '#default_value' => isset($settings['id']) ? $settings['id'] : '',
  );

  $form['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS classes'),
    '#description' => t('Enter a string to be used as the class attribute. Additional classes will be added from the settings below.'),
    '#default_value' => isset($settings['class']) ? $settings['class'] : '',
  );

  $form['grid'] = array(
    '#type' => 'select',
    '#title' => t('Width'),
    '#description' => t('Choose the width for this element (measured in grids).'),
    '#options' => precision16_grid_get_options('grid'),
    '#default_value' => isset($settings['grid']) ? $settings['grid'] : '',
  );

  $form['prefix'] = array(
    '#type' => 'select',
    '#title' => t('Prefix'),
    '#description' => t('Choose how much to prefix this element (measured in grids).'),
    '#options' => precision16_grid_get_options('prefix'),
    '#default_value' => isset($settings['prefix']) ? $settings['prefix'] : '',
  );

  $form['suffix'] = array(
    '#type' => 'select',
    '#title' => t('Suffix'),
    '#description' => t('Choose how much to suffix this element (measured in grids).'),
    '#options' => precision16_grid_get_options('suffix'),
    '#default_value' => isset($settings['suffix']) ? $settings['suffix'] : '',
  );

  $form['pad'] = array(
    '#type' => 'select',
    '#title' => t('Padding'),
    '#description' => t('Choose how much to pad this element (measured in grids).'),
    '#options' => precision16_grid_get_options('pad'),
    '#default_value' => isset($settings['pad']) ? $settings['pad'] : '',
  );

  $form['push'] = array(
    '#type' => 'select',
    '#title' => t('Push'),
    '#description' => t('Choose how much to push this element (measured in grids).'),
    '#options' => precision16_grid_get_options('push'),
    '#default_value' => isset($settings['push']) ? $settings['push'] : '',
  );

  $form['pull'] = array(
    '#type' => 'select',
    '#title' => t('Pull'),
    '#description' => t('Choose how much to pull this element (measured in grids).'),
    '#options' => precision16_grid_get_options('pull'),
    '#default_value' => isset($settings['pull']) ? $settings['pull'] : '',
  );

  $form['alpha'] = array(
    '#type' => 'checkbox',
    '#title' => t('Alpha'),
    '#description' => t('Check if this is the first child element of another.'),
    '#default_value' => isset($settings['alpha']) ? $settings['alpha'] : FALSE,
  );

  $form['omega'] = array(
    '#type' => 'checkbox',
    '#title' => t('Omega'),
    '#description' => t('Check if this is the last child element of another.'),
    '#default_value' => isset($settings['omega']) ? $settings['omega'] : FALSE,
  );

  return $form;
}
