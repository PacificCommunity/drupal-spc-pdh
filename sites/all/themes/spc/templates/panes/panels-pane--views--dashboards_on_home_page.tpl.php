<?php if( theme_get_setting('mothership_poorthemers_helper') ){ ?>
<!-- TPL: panels-pane.tpl (panels-pane-<?php print $pane->type ?> -- <?php print $pane->subtype ?>)  -->
<?php } ?>

<div class="<?php print $classes; ?>" <?php // print $id; ?>>
  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>
  <div class="container-fluid">
    <?php if ($title): ?>
      <h2 class="pane-title"><?php print $title; ?></h2>
    <?php endif; ?>
  	<div class="pane-subtitle"><?php print t('Check out our dashboard on following'); ?></div>
    <?php print render($content); ?>
  </div>
<?php if( theme_get_setting('mothership_poorthemers_helper') ){ ?>
<!-- /tpl panels-pane.tpl (panels-pane-<?php print $pane->type ?>-<?php print $pane->subtype ?>)  -->
<?php } ?>
</div>
