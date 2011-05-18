<?php

/**
 * Implementation of theme_panels_default_style_render_region().
 */
function precision16_panels_default_style_render_region($vars) {
  return implode($vars['panes']);
}

/**
 * Generic function that modifies some variables in all precision16 layouts.
 */
function precision16_check_layout_variables(&$vars) {
  $vars['css_id'] = strtr($vars['css_id'], '_', '-');
}

/**
 * Implementation of template_process_html().
 */
function precision16_process_html(&$variables, $hook) {
  // Check if overlay is activated.
  if (theme_get_setting('precision16_show_overlay')) {
    // Extract and put back the body classes.
    $variables['classes_array'][] = 'show-grid';
    $variables['classes'] = implode(' ', $variables['classes_array']);
    // Add the overlay css to the page.
    $styles = (drupal_add_css(drupal_get_path('theme', 'precision16') . '/debug/debug.css'));
    $variables['css'] = $styles;
    $variables['styles'] = drupal_get_css($variables['css']);
  }
}
