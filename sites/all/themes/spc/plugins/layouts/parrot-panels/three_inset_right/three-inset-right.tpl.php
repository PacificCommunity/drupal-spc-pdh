<?php
/**
 * @file
 * Implementation of a panels grid ready layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout.
 * - $css_id: unique id if present.
 */

?>
<div class="panel-display parrot-panels three-inset-right clearfix" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>
  <div class="container">
    <div id="three-inset-right-wrapper" class="fullwidth">
      <div id="three-inset-right-left-wrapper" class="clearfix">
        <div class="region three-inset-right-sidebar">
          <div class="region-inner clearfix">
            <?php print $content['three_inset_right_sidebar']; ?>
          </div>
        </div>
      </div>

      <div id="three-inset-right-right-wrapper" class="clearfix">

        <?php if ($content['three_inset_right_top']): ?>
          <div class="region three-inset-right-top region-conditional-stack">
            <div class="region-inner clearfix">
              <?php print $content['three_inset_right_top']; ?>
            </div>
          </div>
        <?php endif; ?>

        <div class="region three-inset-right-middle">
          <div class="region-inner clearfix">
            <?php print $content['three_inset_right_middle']; ?>
          </div>
        </div>

        <div class="region three-inset-right-inset">
          <div class="region-inner clearfix">
            <?php print $content['three_inset_right_inset']; ?>
          </div>
        </div>

        <?php if ($content['three_inset_right_bottom']): ?>
          <div class="region three-inset-right-bottom region-conditional-stack">
            <div class="region-inner clearfix">
              <?php print $content['three_inset_right_bottom']; ?>
            </div>
          </div>
        <?php endif; ?>

      </div>
    </div>
  </div>
</div>
