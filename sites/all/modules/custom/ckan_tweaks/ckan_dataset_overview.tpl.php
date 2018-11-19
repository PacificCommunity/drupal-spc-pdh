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
			<?php foreach ($dataset['resources'] as $res) { ?>
				<a href="<?= $dataset['ckan_url'] ?>">
					<span>
						<?php if ($res->format) {
							print(strtoupper($res->format));
						} else {
							print('DATA');
						} ?>
					</span>
				</a>
			<?php } ?>
		</div>
	</div>
</div>
