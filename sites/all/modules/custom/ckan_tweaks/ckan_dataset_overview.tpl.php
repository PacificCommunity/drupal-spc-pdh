<!-- <div>Icons made by <a href="https://www.flaticon.com/packs/files-8" title="Dimitry Miroliubov">Dimitry Miroliubov</a> from <a href="https://www.flaticon.com/" 		    title="Flaticon">www.flaticon.com</a> is licensed by <a href="http://creativecommons.org/licenses/by/3.0/" 		    title="Creative Commons BY 3.0" target="_blank">CC 3.0 BY</a></div> -->
<div id="ckan-dataset-tabs-block">
	<div class="container ckan-dataset-tabs-content">
		<div class="ckan-dataset-tabs-heading">
			<h2>Popular Datasets</h2>
			<div class="ckan-dataset-tabs-intro"><?php print t('Discover our popular datasets'); ?></div>
		</div>
		<div class="ckan-dataset-tabs-items" id="pills-tabContent">
			<div class="ckan-dataset-tabs-item">
				<div class="ckan-dataset-tab-container">
					<div class="list-of-items">
						<?php foreach ($datasets as $item) { ?>
							<div class="tab-data">
								<div class="dataset-org">
									<a href="<?= $item['organization_url'] ?>">
										<img class="media-object" src="<?= $item['image_url'] ?>" alt="..." title="<?= $item['organization'] ?>">
									</a>
								</div>
								<div class="dataset-title">
									<a href="<?= $item['ckan_url'] ?>"><?= $item['title'] ?></a>
								</div>
								<div class="dataset-date"><span><?php print t('Release date'); ?>:</span> <span class="dataset-date-green"><?= $item['release_date'] ?></span></div>						
								
								<div class="dataset-formats"><span><?php print t('File Format'); ?>:</span>
									<?php $resources_formats = array();
									foreach ($item['resources'] as $res) { ?>
										<?php if ($res->format) {
											array_push($resources_formats, strtolower($res->format));
										} else {
											array_push($resources_formats, 'data');
										} ?>
									<?php } ?>
									<?php foreach (array_slice(array_unique($resources_formats), 0, 3) as $res) { ?>
										<a href="<?= $item['ckan_url'] ?>">
											<div class="res-formats res-format-<?= strtolower($res); ?>"></div>
										</a>
									<?php } ?>
								</div>
							</div>
						<?php } ?>
					</div>
					<div class="carusel-of-items">
						<?php foreach ($datasets as $item) { ?>
							<div class="tab-data">
								<div class="dataset-org">
									<a href="<?= $item['organization_url'] ?>">
										<img class="media-object" src="<?= $item['image_url'] ?>" alt="..." title="<?= $item['organization'] ?>">
									</a>
								</div>
								<div class="dataset-title">
									<a href="<?= $item['ckan_url'] ?>"><?= $item['title'] ?></a>
								</div>
								<div class="dataset-date"><span><?php print t('Release date'); ?>:</span> <span class="dataset-date-green"><?= $item['release_date'] ?></span></div>						
								
								<div class="dataset-formats"><span><?php print t('File Format'); ?>:</span>
									<?php $resources_formats = array();
									foreach ($item['resources'] as $res) { ?>
										<?php if ($res->format) {
											array_push($resources_formats, strtolower($res->format));
										} else {
											array_push($resources_formats, 'data');
										} ?>
									<?php } ?>
									<?php foreach (array_slice(array_unique($resources_formats), 0, 3) as $res) { ?>
										<a href="<?= $item['ckan_url'] ?>">
											<div class="res-formats res-format-<?= strtolower($res); ?>"></div>
										</a>
									<?php } ?>
								</div>
							</div>
						<?php } ?>						
					</div>
				</div>
			</div>
		</div>
		<div class="ckan-dataset-tabs-view-all">
			<?php
				global $base_url;
				$url = $base_url . '/data';
			?>
			<a href="<?= $url; ?>" target="__blank">
				View all
			</a>
		</div>
	</div>	
</div> 
