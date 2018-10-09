<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php $color = $node->field_dsp_color ? '#'.$node->field_dsp_color['und'][0]['jquery_colorpicker'] : '#fff'; ?>
  <style>
    .node-dsp.view-mode-full h1 {
      color: <?= $color ?>;
    }
    .target-title {
      color: <?= $color ?>;
    }
    .target-definition {
      background-color: <?= $color ?>;
    }
  </style>

  <div class="container">
    <?php if (isset($title_suffix['contextual_links'])): ?>
      <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>
    
    <?php print $ds_content; ?>
  </div>
  
</<?php print $ds_content_wrapper ?>>
