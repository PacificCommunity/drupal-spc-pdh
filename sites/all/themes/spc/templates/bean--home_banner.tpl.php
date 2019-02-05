<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
    $thematic_landing_banner = $content['field_thematic_banner']['#items'][0]['value'];
    $thematic_landing_img = $content['field_banner_image'][0]['#item']['uri'];
    if ($thematic_landing_banner == 0):
      ?>
      <div class="banner-image" style="background-image: url(<?php print file_create_url($thematic_landing_img); ?>)"></div>
      <div class="content"<?php print $content_attributes; ?>>
        <div class="spc-home-banner-block-main">
          <div class="spc-home-banner-block">
            <div class="banner-title">
              <?php
                print render($content['field_banner_title']);
                print render($content['field_banner_sub_title']);
              ?>
            </div>
            <div id="spc-home-banner-search">
              <?php
              if (!empty($content['search_block'])):
                print render($content['search_block']);
              endif; ?>
            </div>
          </div>
        </div>
      </div>
    <?php elseif ($thematic_landing_banner == 1):
      $node = menu_get_object();
      $banner_image = $node->field_banner_image_thematic[LANGUAGE_NONE][0]['uri'] ?? null; ?>
      <div class="banner-image" style="background-image: url(<?php if ($banner_image): print(file_create_url($banner_image)); else: print(file_create_url($thematic_landing_img)); endif; ?>)"></div>
      <div class="content"<?php print $content_attributes; ?>
        <div class="spc-home-banner-block-main">
          <div class="spc-home-banner-block">
            <div class="banner-title">
              <?php
                print render($content['field_banner_title']);
                print render($content['field_banner_sub_title']);
              ?>
            </div>
            <div id="spc-home-banner-search">
              <?php
              if (!empty($content['search_block'])):
                print render($content['search_block']);
              endif; ?>
            </div>
          </div>
        </div>
      </div>
      <?php
        $cached_dataset_count = cache_get('datasets_count'.$node->nid, 'cache');
        $cached_publications_count = cache_get('publications_count'.$node->nid, 'cache');

        $thematic_id = $node->field_ckan_thematic_group_id[LANGUAGE_NONE][0]['safe_value'] ?? null;

        if ($cached_dataset_count) {
          $datasets_count = $cached_dataset_count->data;
        } else {
          $datasets_count = $thematic_id ? (_ckan_tweaks_count_datasets_for_thematic_area($thematic_id) - _ckan_tweaks_count_publications_for_thematic_area($thematic_id)) : '0';
          cache_set('datasets_count'.$node->nid, $datasets_count, 'cache', time(), 60*60*6);
        }

        if ($cached_publications_count) {
          $publications_count = $cached_publications_count->data;
        } else {
          $publications_count = $thematic_id ? _ckan_tweaks_count_publications_for_thematic_area($thematic_id) : '0';
          cache_set('publications_count'.$node->nid, $publications_count, 'cache', time() + 60*60*6);
        }
      ?>
      <div class="banner-links hidden-xs">
        <div class="link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/dataset_icon.png">
          </div>
          <a href="<?= _ckan_tweaks_search_page_by_topic($thematic_id) ?>">
            <span class="count"><?= $datasets_count ?></span>
            <?php print t('Datasets'); ?>
          </a>
        </div>
        <div class="link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/article_icon.png">
          </div>
          <a href="/stories/by-topic/<?= $node->nid ?>">
            <span class="count"><?= views_embed_view('articles_by_topic','block_1', $node->nid, $node->title); ?></span>
            <?php print t('Stories'); ?>
          </a>
        </div>
        <div class="link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/publication_icon.png">
          </div>
          <a href="<?= _ckan_tweaks_search_page_by_topic($thematic_id, CKAN_SEARCH_CRIT_PUBLICATION_DATASET_TYPE) ?>">
            <span class="count"><?= $publications_count ?></span>
            <?php print t('Publications'); ?>
          </a>
        </div>
      </div>
    <?php endif; ?>
</div>
