<div class='<?php print $classes;?> clearfix'>
    <?php 
    $thematic_groups_home = $content['field_thematic_groups_home']['#object']->field_thematic_groups_home['und'];
    $current_node = menu_get_object();
    if ($content['field_thematic_groups_home']['#object']->delta == 'thematic-page-heading'): 
        $cur_icon_uri = $current_node->field_icon['und'][0]['uri'];
        $cur_icon_url = parse_url(file_create_url($cur_icon_uri)); ?>
        <div class="dropdown">
            <button type="button" id="thematic_dropdown" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
                <?php print('<img src='.$cur_icon_url['path'].'>'); 
                print($current_node->title); ?>
                <i class="fa fa-caret-down" aria-hidden="true"></i>
            </button>
            <ul class="dropdown-menu" aria-labelledby="thematic_dropdown">
            <?php foreach ($thematic_groups_home as $key => $value) {
                $entity = entity_uri('node', $value['entity']);
                $entity_path_alias = drupal_get_path_alias($entity['path']); ?>
                <li>
                    <a href='<?php print('/'.$entity_path_alias); ?>'>
                        <?php print($value['entity']->title); ?>
                    </a>
                </li>
            <?php }; ?>
            </ul>
        </div>
    <?php else: 
    foreach ($thematic_groups_home as $key => $value) {
        $entity = entity_uri('node', $value['entity']);
        $entity_path_alias = drupal_get_path_alias($entity['path']);  
        if (!empty($value['entity']->field_icon)) {
            $icon_uri = $value['entity']->field_icon['und'][0]['uri'];
            $icon_url = parse_url(file_create_url($icon_uri));
            $img_path = $icon_url['path'];
        } ?>
        <div class='col-md-2'>
            <a href='<?php print('/'.$entity_path_alias); ?>'>
                <div class='thumbnail'>
                    <?php if (!empty($value['entity']->field_icon))
                        print('<img src='.$img_path.'>'); ?>
                    <p class='group-title'><?php print($value['entity']->title); ?></p>
                </div>
            </a>
        </div>
    <?php }; endif;?>
</div>
