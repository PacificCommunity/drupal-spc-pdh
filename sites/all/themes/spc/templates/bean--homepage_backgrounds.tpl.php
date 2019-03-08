<?php
	$country_data_img = !empty($content['field_country_data_background']) ? $content['field_country_data_background'][0]['#item']['uri'] : '';
	$dashboards_img = !empty($content['field_dashboards_background']) ? $content['field_dashboards_background'][0]['#item']['uri'] : '';
	$datasets_img = !empty($content['field_datasets_background']) ? $content['field_datasets_background'][0]['#item']['uri'] : '';
?>
<style>
	#member-countries-block {
		background-image: linear-gradient(rgba(176, 183, 187, 0.1), rgba(176, 183, 187, 0.1)), url(<?php print file_create_url($country_data_img); ?>);
	}
	#mini-panel-datasets_on_home_page {
		background-image: linear-gradient(rgba(176, 183, 187, 0.1), rgba(176, 183, 187, 0.1)), url(<?php print file_create_url($datasets_img); ?>);
	}
</style>
