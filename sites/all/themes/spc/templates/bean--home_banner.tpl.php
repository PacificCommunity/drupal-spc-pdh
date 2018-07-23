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
      $banner_image = $node->field_banner_image_thematic['und'][0]['uri']; ?>
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
        if($cached = cache_get('topic_count', 'cache'))  {
          $topic_count = $cached->data;
        }
        if(empty($topic_count) && $topic_count != '0') {
          $topic_count = !empty($node->field_ckan_thematic_group_id) ? _ckan_tweaks_count_datasets_for_thematic_area($node->field_ckan_thematic_group_id['und'][0]['safe_value']) : '0';
          cache_set('topic_count', $topic_count, 'cache', time() + 60*60*6);
        }
        $publications_count = !empty($node->field_publications) ? $node->field_publications['und'][0]['value'] : '0';
      ?>
      <div class="banner-links hidden-xs">
        <div class="col-md-4 col-sm-4 link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/dataset_icon.png">
          </div>
          <span><?= $topic_count ?></span><br> Datasets
        </div>
        <div class="col-md-4 col-sm-4 link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/article_icon.png">
          </div>
          <span><?= views_embed_view('articles_by_topic','block_1', $node->nid, $node->title); ?></span><br> Articles
        </div>
        <div class="col-md-4 col-sm-4 link-block">
          <div class="icon-wrapper">
            <img src="/sites/all/themes/spc/img/spc/publication_icon.png">
          </div>
          <span><?= $publications_count ?></span><br> Publications
        </div>
      </div>
    <?php endif; ?>
</div>
