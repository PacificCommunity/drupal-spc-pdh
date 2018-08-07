<?php
  foreach ($fields as $id => $field) {
    $node = node_load($field->content);
    $indicators = !empty($node->field_indicators) ? $node->field_indicators['und'] : false;
    break;
  };

  foreach ($indicators as $id => $ind) {
    $nid = $ind['target_id'];
    $node = node_load($nid);
    $path = 'node/' . (int)$nid;
    $alias = drupal_get_path_alias($path); 
    print('<li><a href="/'.$alias.'">'.$node->title.'</a></li>');
    
  };
?>
