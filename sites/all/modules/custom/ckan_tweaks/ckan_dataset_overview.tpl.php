<div class="dataset-preview">
	<div class="dataset-preview-inner">
		<p class="dataset-title">
			<a href="<?= $dataset['ckan_url'] ?>">
				<?= $dataset['title'] ?>
			</a>
		</p>
		<div class="dataset-groups">
			<p>
				<a href="<?= $dataset['organization_url'] ?>">
					<img width="100%" class="media-object" src="<?= $dataset['image_url'] ?>" alt="..." title="<?= $dataset['organization'] ?>">
				</a>
			</p>
		</div>
		<p class="dataset-date"><label><?php print t('Release Date'); ?>:</label> <span><?= $dataset['release_date'] ?></span></p>
		<div class="dataset-formats"><label><?php print t('File Format'); ?>:</label>
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
					<span><?= $res; ?></span>
				</a>
			<?php } ?>
		</div>
	</div>
</div>
