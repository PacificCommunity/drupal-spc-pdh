<?php

/**
 * @file
 * Master results view template to display a list of rows for accordion.
 *
 * @ingroup views_templates
 */
?>
<div class="master-results-accordion">
<?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>
