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

<?php if (!empty($content['header']) || !empty($content['main']) || !empty($content['aside_alpha'])): ?>
  <div class="page-main-wrapper grid-16 alpha">
<?php endif; ?>

  <?php if (!empty($content['header'])): ?>
    <div class="page-header grid-16 alpha omega">
      <div class="page-header-inner">
        <?php print $content['header']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="page-main grid-8 alpha">
      <div class="page-main-inner">
        <?php print $content['main']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['aside_alpha'])): ?>
    <div class="page-aside-alpha grid-4">
      <div class="page-aside-alpha-inner">
        <?php print $content['aside_alpha']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['aside_beta'])): ?>
    <div class="page-aside-beta grid-4 omega">
      <div class="page-aside-beta-inner">
        <?php print $content['aside_beta']; ?>
      </div>
    </div>
  <?php endif; ?>

<?php if (!empty($content['header']) || !empty($content['main']) || !empty($content['aside_alpha'])): ?>
  </div>
<?php endif; ?>

<?php if (!empty($css_id)): ?>
  </div>
<?php endif; ?>
