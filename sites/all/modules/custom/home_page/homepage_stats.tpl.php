<?php
    $cached_dataset_count = cache_get('homepage_datasets_count', 'cache');
    $cached_publications_count = cache_get('homepage_publications_count', 'cache');

    if ($cached_dataset_count) {
      $datasets_count = $cached_dataset_count->data;
    } else {
		$datasets_count = _ckan_tweaks_count_ckan_entities() - _ckan_tweaks_count_ckan_entities(CKAN_SEARCH_CRIT_PUBLICATION_DATASET_TYPE);
      cache_set('homepage_datasets_count', $datasets_count, 'cache', time(), 60*60*6);
    }

    if ($cached_publications_count) {
      $publications_count = $cached_publications_count->data;
    } else {
      $publications_count = _ckan_tweaks_count_ckan_entities(CKAN_SEARCH_CRIT_PUBLICATION_DATASET_TYPE);
      cache_set('homepage_publications_count', $publications_count, 'cache', time() + 60*60*6);
    }
?>

<div>
	<div id="homepage-stats-block">
		<div class="homepage-stat-item">
			<a href="<?= _ckan_tweaks_search_page() ?>">
				<img class="homepage-stat-icon" src="/sites/all/themes/spc/img/spc_new/datasets_icon.png" alt="">
				<div class="homepage-stat-info">
					<div class="homepage-stat-count"><?= $datasets_count ?></div>
					<div class="homepage-stat-type"><?php print t('Datasets'); ?></div>
				</div>
			</a>
		</div>
		<div class="homepage-stat-item">
			<a href="/stories/by-topic/<?= $node->nid ?>">
				<img class="homepage-stat-icon" src="/sites/all/themes/spc/img/spc_new/stories_icon.png" alt="">
				<div class="homepage-stat-info">
					<div class="homepage-stat-count"><?= views_embed_view('articles_by_topic','block_1', $node->nid, $node->title); ?></div>
					<div class="homepage-stat-type"><?php print t('Stories'); ?></div>
				</div>
			</a>			
		</div>
		<div class="homepage-stat-item">
			<a href="<?= _ckan_tweaks_search_page(CKAN_SEARCH_CRIT_PUBLICATION_DATASET_TYPE) ?>">
				<img class="homepage-stat-icon" src="/sites/all/themes/spc/img/spc_new/publications_icon.png" alt="">
				<div class="homepage-stat-info">
					<div class="homepage-stat-count"><?= $publications_count ?></div>
					<div class="homepage-stat-type"><?php print t('Publications'); ?></div>
				</div>
			</a>			
		</div>
	</div>
</div>