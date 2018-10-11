<div class="<?php print $classes; ?>" <?php  print $id; ?>>
  <div class="container">
	  <?php if ($admin_links): ?>
	    <?php print $admin_links; ?>
	  <?php endif; ?>
	  <?php if ($title): ?>
	    <h2 class="pane-title"><?php print $title; ?></h2>
	  <?php endif; ?>
	  <div class="data-insights-promoted-group">
   		<?php print render($content); ?>
   	</div>
   </div>
</div>
