<?php

/**
 * @file
 * This layout is designed to be the site template layout when using
 * the Panels Everywhere module.
 */
?>
<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="page-wrapper">

  <?php if (!empty($content['branding'])): ?>
    <div class="page-branding-wrapper">
      <div class="region container-16 clear-block">
        <div class="page-branding grid-16">
          <div class="page-branding-inner clear-block">
            <?php print $content['branding']; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['nav'])): ?>
    <div class="page-nav-wrapper">
      <div class="region container-16 clear-block">
        <div class="page-nav grid-16">
          <div class="page-nav-inner clear-block">
            <?php print $content['nav']; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="page-body-wrapper">
      <div class="region container-16 clear-block">
        <div class="page-body grid-16">
          <div class="page-body-inner clear-block">
            <?php print $content['main']; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer'])): ?>
    <div class="page-closure-wrapper">
      <div class="region container-16 clear-block">
        <div class="page-closure grid-16">
          <div class="page-closure-inner clear-block">
            <?php print $content['footer']; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

</div>
