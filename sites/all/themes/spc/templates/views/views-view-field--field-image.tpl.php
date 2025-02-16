<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php 
    $entity = $row->_field_data['nid']['entity'];
    $uri = $entity->field_image['und'][0]['uri'];

    $nid = $row->nid;
    $path = drupal_get_path_alias('node/'.$nid); 
    
    if (!empty($stile_name = $field->view->result[0]->field_field_image[0]['rendered']['#image_style'])) {
        $img_src = image_style_url($stile_name, $uri);
    } else {
      $img_src = file_create_url($uri);
    }

?>
<div class="field field-type-image">
    <a href="/<?php print $path; ?>">
        <img typeof="foaf:Image"  data-src="<?php print $img_src; ?>" src="/sites/all/themes/spc/img/loader.gif" class="lazy-load"  width="320" height="224" alt="">
    </a>
</div>
