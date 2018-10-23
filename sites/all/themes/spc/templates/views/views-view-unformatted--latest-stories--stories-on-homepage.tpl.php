<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="container">
	<h2>Latest Stories</h2>
	<div>
		<div class="stories-list field-items">
			<?php foreach ($rows as $id => $row): ?>
			<div <?php if ($classes_array[$id]): ?> class="<?php print $classes_array[$id]; ?>"<?php endif; ?>>
				<?php print $row; ?>
			</div>
			<?php endforeach; ?>
		</div>
	</div>
	<p><a href="/blog" class="view-all-link">View All</a></p>	
</div>

