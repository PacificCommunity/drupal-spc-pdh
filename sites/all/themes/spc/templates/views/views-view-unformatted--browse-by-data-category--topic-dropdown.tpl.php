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
    $cur_icon_uri = $current_node->field_icon['und'][0]['uri'];
    $cur_icon_url = parse_url(file_create_url($cur_icon_uri));
?>

<div class="thematic-heading-block">
	<div class="dropdown">
	    <button type="button" id="thematic_dropdown" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
            <?php print('<img src='.$cur_icon_url['path'].'>'); 
            print($current_node->title); ?>
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