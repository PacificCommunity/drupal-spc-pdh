<div class="<?php print $classes; ?>" <?php  print $id; ?>>
	<?php if ($admin_links): ?>
		<?php print $admin_links; ?>
	<?php endif; ?>
	<?php if ($title): ?>
		<h2 class="pane-title"><?php print $title; ?></h2>
	<?php endif; ?>
	<div>
		<?php print render($content); ?>
	</div>
</div>
