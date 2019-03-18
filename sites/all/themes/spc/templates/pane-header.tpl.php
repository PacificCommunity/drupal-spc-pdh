<?php
/**
 * @file
 *
 * Theme implementation to display the header block on a Drupal page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $front_page
 * - $logo
 * - $site_name
 * - $site_slogan
 *
 * Additional items can be added via theme_preprocess_pane_header(). See
 * template_preprocess_pane_header() for examples.
 */
?>
<header id="header">
  <div class="container-fluid">
    <div class="row">
      <div class="col-md-3 col-sm-3 col-xs-5" id="logo-title">
        <?php if (!empty($logo)): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
      </div>
      <div class="col-md-9 col-sm-9 col-xs-7">
        <?= create_main_menu(); ?>
        <?= create_mobile_menu(); ?>
      </div>
    </div>
  </div>
</header>
