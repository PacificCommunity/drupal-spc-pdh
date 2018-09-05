<?php
	$country_data_img = !empty($content['field_country_data_background']) ? $content['field_country_data_background'][0]['#item']['uri'] : '';
	$dashboards_img = !empty($content['field_dashboards_background']) ? $content['field_dashboards_background'][0]['#item']['uri'] : '';
	$datasets_img = !empty($content['field_datasets_background']) ? $content['field_datasets_background'][0]['#item']['uri'] : '';
?>
<style>
	.dashboards-home {
		background-image: url(<?php print file_create_url($dashboards_img); ?>);
	}
	#member-countries-block {
		background-image: url(<?php print file_create_url($country_data_img); ?>);
	}
	#mini-panel-datasets_on_home_page {
		background-image: url(<?php print file_create_url($datasets_img); ?>);
	}
</style>
