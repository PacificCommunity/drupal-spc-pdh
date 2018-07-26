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
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-sm-7 col-xs-9" id="logo-title">
        <?php if (!empty($logo)): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <div id="main-menu">
    <button class="header-menu-btn ma5-toggle-menu" type="button">
      <input type="checkbox">
      <span></span>
      <span></span>
      <span></span>
    </button>
    <nav class="ma5-menu-mobile">
      <?= create_main_menu(); ?>
    </nav>
  </div>
</header>
