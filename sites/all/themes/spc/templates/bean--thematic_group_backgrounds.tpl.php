<?php
	$datasets_img = !empty($content['field_datasets_background']) ? $content['field_datasets_background'][0]['#item']['uri'] : '';
?>
<style>
	#thematic-group-popular-datasets {
		background-image: linear-gradient(rgba(176, 183, 187, 0.1), rgba(176, 183, 187, 0.1)), url(<?php print file_create_url($datasets_img); ?>);
	}
</style>
