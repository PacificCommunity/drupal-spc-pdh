
<div class='<?php print $classes;?> clearfix'>
    <div class='row'>
        <?php $thematic_groups_home = $content['field_thematic_groups_home']['#object']->field_thematic_groups_home['und'];
        foreach ($thematic_groups_home as $key => $value) {
            $entity = entity_uri('node', $value['entity']);
            $entity_path_alias = drupal_get_path_alias($entity['path']);  
            if (!empty($value['entity']->field_icon)) {
                $icon_uri = $value['entity']->field_icon['und'][0]['uri'];
                $icon_url = parse_url(file_create_url($icon_uri));
                $img_path = $icon_url['path'];
            }       
        ?>
            <div class='col-md-2'>
                <a href='<?php print('/'.$entity_path_alias); ?>'>
                    <div class='thumbnail'>
                        <?php if (!empty($value['entity']->field_icon))
                            print('<img src='.$img_path.'>'); ?>
                        <p class='group-title'><?php print($value['entity']->title); ?></p>
                    </div>
                </a>
            </div>
        <?php } ?>
    </div>
</div>
