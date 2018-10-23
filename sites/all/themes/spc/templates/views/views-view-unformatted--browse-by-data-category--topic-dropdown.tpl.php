<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php
	$current_node = menu_get_object();
    $cur_icon_uri = $current_node->field_icon[LANGUAGE_NONE][0]['uri'] ?? null;
    $cur_icon_url = parse_url(file_create_url($cur_icon_uri));
    $fa_icon = $current_node->field_fa_icon[LANGUAGE_NONE][0]['value'] ?? null;
?>

<div class="thematic-heading-block container">
	<div class="dropdown">
	  <button type="button" id="thematic_dropdown" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
      <?php if ($fa_icon): ?>
      <i class="thematic-fa-icon text-primary fa <?=$fa_icon?>"></i>
      <?php else: ?>
      <img src="<?=$cur_icon_url['path']?>">
      <?php endif; ?>
      <?= $current_node->title ?>
	    <i class="fa fa-caret-down" aria-hidden="true"></i>

	    </button>
	    <ul class="dropdown-menu" aria-labelledby="thematic_dropdown">
	    <?php foreach ($rows as $id => $row) { ?>
	    	<li>
	    	<?php print $row; ?>
	    	</li>
	    <?php }; ?>
	    </ul>
	</div>
</div>
