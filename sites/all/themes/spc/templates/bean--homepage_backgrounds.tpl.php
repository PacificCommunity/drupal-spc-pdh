<?php
	$data_insights_img = !empty($content['field_data_insights_background']) ? $content['field_data_insights_background'][0]['#item']['uri'] : '';
	$country_data_img = !empty($content['field_country_data_background']) ? $content['field_country_data_background'][0]['#item']['uri'] : '';
	$latest_stories_img = !empty($content['field_latest_stories_background']) ? $content['field_latest_stories_background'][0]['#item']['uri'] : '';
?>
<style>
	#mini-panel-data_insights {
	background-image: linear-gradient(to right, rgba(0, 0, 0, 0.6), rgba(0, 0, 0, 0.2)), url(<?php print file_create_url($data_insights_img); ?>);
	}
	#member-countries-block {
	background-image: linear-gradient(to right, rgba(0, 0, 0, 0.6), rgba(0, 0, 0, 0.2)), url(<?php print file_create_url($country_data_img); ?>);		
	}
	.latest-stories-homepage {
	background-image: linear-gradient(to right, rgba(0, 0, 0, 0.6), rgba(0, 0, 0, 0.2)), url(<?php print file_create_url($latest_stories_img); ?>);
	}
</style>