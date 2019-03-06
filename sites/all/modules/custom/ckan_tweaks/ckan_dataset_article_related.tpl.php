<div class="dataset-item">
	<div class="dataset-org">
			<a href="<?= $dataset['organization_url'] ?>">
				<img class="media-object" src="<?= $dataset['image_url'] ?>" alt="..." title="<?= $dataset['organization'] ?>">
			</a>
	</div>		
	<div class="dataset-title">
		<a href="<?= $dataset['ckan_url'] ?>">
			<?= $dataset['title'] ?>
		</a>
	</div>
	<div class="dataset-date"><span><?php print t('Release Date'); ?>:</span> <span class="dataset-date-green"><?= $dataset['release_date'] ?></span></div>
	<div class="dataset-formats">
		<span><?php print t('File Format'); ?>:</span>
		<?php $resources_formats = array();
		foreach ($dataset['resources'] as $res) { ?>
			<?php if ($res->format) {
				array_push($resources_formats, strtoupper($res->format));
			} else {
				array_push($resources_formats, 'DATA');
			} ?>
		<?php } ?>
		<?php foreach (array_unique($resources_formats) as $res) { ?>
			<a href="<?= $dataset['ckan_url'] ?>">
				<div class="res-formats res-format-<?= $res; ?>"></div>
			</a>
		<?php } ?>
	</div>
</div>
