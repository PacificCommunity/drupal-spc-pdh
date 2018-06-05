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
    print render($content['field_banner_image']);
  ?>
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
            if ($thematic_landing_banner == 0):
              print render($content['search_block']); 
            else:
              print render($content['search_block']); 
            endif;
          endif; ?>
        </div>
      </div>
      <?php if ($thematic_landing_banner == 1): ?>
          <div class="banner-links">
            <div class="col-md-4 link-block">
              <div class="icon-wrapper">
                <img src="/sites/all/themes/spc/img/spc/dataset_icon.png">
              </div>
              <span>326</span><br> Datasets
            </div>
            <div class="col-md-4 link-block">
              <div class="icon-wrapper">
                <img src="/sites/all/themes/spc/img/spc/article_icon.png">
              </div>
              <span>326</span><br> Articles
            </div>
            <div class="col-md-4 link-block">
              <div class="icon-wrapper">
                <img src="/sites/all/themes/spc/img/spc/publication_icon.png">
              </div>
              <span>326</span><br> Publications
            </div>
          </div>
        <?php endif; ?>
    </div>
  </div>
</div>
