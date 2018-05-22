<div class="col-md-3">
    <div class="panel panel-primary ">
	<div class="panel-title dataset-title">
	    <a href="<?= $dataset['ckan_url'] ?>">
		<?= $dataset['title'] ?>
	    </a>

	</div>
	<div class="panel-body">
	    <div class="media">
		<div class="media-left">
		    <div class="col-xs-6 col-md-12">
			<img width="100%" class="media-object" src="<?= $dataset['image_url'] ?>" alt="...">
		    </div>
		</div>
		<div class="col-md-12">
		    <?= $dataset['description'] ?>
		</div>
	    </div>

	</div>
    </div>
</div>
