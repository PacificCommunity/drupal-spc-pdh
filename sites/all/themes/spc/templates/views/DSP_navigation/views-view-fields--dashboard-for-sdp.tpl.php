<?php
  foreach ($fields as $id => $field) {
    $node = node_load($field->content);
    $indicators = !empty($node->field_indicators) ? $node->field_indicators['und'] : false;
    break;
  };

  $icon_uri = $node->field_icon_logo ? $node->field_icon_logo['und'][0]['uri'] : '';
?>
<button type="button" id="goals-navigation" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
  <img class="goals-logo" src="<?php !empty($icon_uri) ? print(file_create_url($icon_uri)) : '/sites/all/themes/spc/img/spc/SDG_logo.png'; ?>">
    <i class="fa fa-caret-down" aria-hidden="true"></i>
    <i class="fa fa-caret-up" aria-hidden="true"></i>
</button>
<ul class="dropdown-menu" aria-labelledby="goals-navigation">
  <?php
    foreach ($indicators as $id => $ind) {
      $nid = $ind['target_id'];
      $node = node_load($nid);
      $path = 'node/' . (int)$nid;
      $alias = drupal_get_path_alias($path); 
      print('<li><a href="/'.$alias.'">'.$node->title.'</a></li>');
    };
    ?>
</ul>
