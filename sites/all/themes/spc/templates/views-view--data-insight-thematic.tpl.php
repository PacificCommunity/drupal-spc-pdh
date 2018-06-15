<?php 
    $current_node = menu_get_object();
    $insight_id = $current_node->field_data_insight_thematic['und'][0]['target_id'];

    if ($insight_id) {
        $insight = node_load($insight_id);
    } else {
        $insight_id = $view->result[0]->nid;
        $insight = node_load($insight_id);
    }
?>
<div id='thematic_insight'>
    <div class='data-insights-promoted-item'>
        <h2><a href='../<?= drupal_get_path_alias('node/'.$insight_id) ?>'><?= $insight->title; ?></a></h2>
        <div class='insight-body'><?= $insight->field_data_insights_preview['und'][0]['value']; ?></div>
        <div class='release-date'>Release Date: <span><?= gmdate('F j, Y', $insight->created); ?></span></div>
    </div>
</div>
