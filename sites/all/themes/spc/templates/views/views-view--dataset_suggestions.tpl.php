<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<div class="bean-banner-with-title">
    <div class="content">
        <div style="" class="banner-with-title dataset-suggestion-header">
            <div class="breadcrumb-box container">
              <div class="breadcrumb">
                  <span class="inline odd first"><a href="/"><?php print t('Home'); ?></a></span> 
                  <span class="delimiter">&gt;</span> 
                  <span class="inline even last"><?php print t('Dataset Suggestions'); ?></span>
              </div>
            </div>
            <div class="title">
                <h1><?php print t('Dataset <strong>suggestions</strong>'); ?></h1>
            </div>
        </div>
    </div>
</div>
<div class="container">
  <?php print theme('status_messages'); ?>  
  <div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
      
    <?php if ($header): ?>
      <div class="view-header clearfix">
        <?php print $header; ?>
      <div class="datasets-sorting">
        <label>Order by</label>
        <a id="sorting-select" href="#">
            <span></span>
            <i class="fa fa-chevron-down"></i></a>
        <ul>
            <li><a data-order="value" data-sort="desc" href="/dataset-suggestions?order=value&sort=desc">Most popular first</a></li>
            <li><a data-order="value" data-sort="asc" href="/dataset-suggestions?order=value&sort=asc">Least popular first</a></li>
            <li><a data-order="created" data-sort="desc" href="/dataset-suggestions?order=created&sort=desc">Latest first</a></li>
            <li><a data-order="created" data-sort="asc" href="/dataset-suggestions?order=created&sort=asc">Oldest first</a></li>
        </ul>
      </div>
      </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
      <div class="view-filters">
        <?php print $exposed; ?>
      </div>
    <?php endif; ?>
      
    <a class="action-add" href="/dataset-suggestions/add"><?php print t('Suggest a Dataset'); ?></a>

    <?php if ($attachment_before): ?>
      <div class="attachment attachment-before">
        <?php print $attachment_before; ?>
      </div>
    <?php endif; ?>

    <?php if ($rows): ?>
      <div class="view-content clearfix">
        <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>

    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
      <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
      <div class="view-footer">
        <?php print $footer; ?>
      </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
      <div class="feed-icon">
        <?php print $feed_icon; ?>
      </div>
    <?php endif; ?>

  </div><?php /* class view */ ?>
</div><?php /* class container */ ?>
