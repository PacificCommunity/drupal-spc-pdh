<div class="dataset-preview">
	<p class="dataset-title">
		<a href="<?= $dataset['ckan_url'] ?>">
			<?= $dataset['title'] ?>
		</a>
	</p>
	<div class="dataset-groups">
		<p><img width="100%" class="media-object" src="<?= $dataset['image_url'] ?>" alt="..."> <?= $dataset['organization'] ?></p>
	</div>
	<p class="dataset-date">Release Date: <span><?= $dataset['release_date'] ?></span></p>
	<div class="dataset-formats">File Format: 
		<?php foreach ($dataset['resources'] as $res) { ?>
			<span>
				<?php if ($res->format) {
					print(strtoupper($res->format));
				} else {
					print('DATA');
				} ?>
			</span>
		<?php } ?>
	</div>
</div>
