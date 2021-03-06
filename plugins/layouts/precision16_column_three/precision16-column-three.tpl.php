<?php

/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>
<?php if (!empty($css_id)): ?>
  <div id="<?php print $css_id; ?>" class="clear-block">
<?php endif; ?>

<?php if (!empty($content['header_alpha'])): ?>
  <div class="page-header-alpha grid-16 alpha omega">
    <div class="sub-region page-header-alpha-inner">
      <?php print $content['header_alpha']; ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($content['header_beta']) || !empty($content['main']) || !empty($content['aside_alpha']) || !empty($content['footer_alpha']) || !empty($content['footer_beta'])): ?>
  <div class="page-main-wrapper grid-12 alpha">
<?php endif; ?>

  <?php if (!empty($content['header_beta'])): ?>
    <div class="page-header-beta grid-12 alpha omega">
      <div class="sub-region page-header-beta-inner">
        <?php print $content['header_beta']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="page-main grid-8 alpha">
      <div class="sub-region page-main-inner">
        <?php print $content['main']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['aside_alpha'])): ?>
    <div class="page-aside-alpha grid-4 omega">
      <div class="sub-region page-aside-alpha-inner">
        <?php print $content['aside_alpha']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer_alpha'])): ?>
    <div class="page-footer-alpha grid-12 alpha omega">
      <div class="sub-region page-footer-alpha-inner">
        <?php print $content['footer_alpha']; ?>
      </div>
    </div>
  <?php endif; ?>

<?php if (!empty($content['header_beta']) || !empty($content['main']) || !empty($content['aside_alpha'])): ?>
  </div>
<?php endif; ?>

<?php if (!empty($content['aside_beta'])): ?>
  <div class="page-aside-beta grid-4 omega">
    <div class="sub-region page-aside-beta-inner">
      <?php print $content['aside_beta']; ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($content['footer_beta'])): ?>
  <div class="page-footer-beta grid-16 alpha omega">
    <div class="sub-region page-footer-beta-inner">
      <?php print $content['footer_beta']; ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($css_id)): ?>
  </div>
<?php endif; ?>
