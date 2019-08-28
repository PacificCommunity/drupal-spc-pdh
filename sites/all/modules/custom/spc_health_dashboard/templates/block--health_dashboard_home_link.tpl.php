<?php
/**
 * @file
 *
 * Theme to display the Education dashboard block on a Drupal page.
 *
 */
?>

<div class="hl-dashboard-link container">
    <div about="/content/17-goals-transform-pacific" typeof="sioc:Item foaf:Document" style="" class="node-dashboards node-promoted view-mode-dashboard_highlight clearfix">

        <div class="group-chart" style="z-index: 2;">
            <div class="chart-static lazy-load" data-background="/sites/all/themes/spc/img/sprite/spc_sprite.png" data-sx="-2845px" data-sy="-1376px" style="margin-left: 0; margin-right: -90px;"></div>
        </div>        
        
        <div class="group-content" style="z-index: 1;">
            <div class="group-content-left">
                <?php print t('<strong>MANA</strong> Dashboard'); ?>
            </div>
            <div class="group-content-right" style="flex: 1 1 75%;">
                <div class="dashboard-description">
                    <?php print t('The Pacific Monitoring Alliance for NCD Action (MANA) dashboard will enable PICTs to monitor <strong>status and progress of NCD policy and legislation</strong> against the <strong>Pacific NCD Roadmap</strong>, the <strong>Health Islands Monitoring Frameworks</strong> as well as the <strong>Sustainable Development Goals</strong>'); ?>
                </div>
                <div class="field field-type-ds">
                    <a href="<?php echo HEALTH_DASHBOARD_URL; ?>" class="banner-button btn"><?php print t('View DASHBOARD'); ?></a>
                </div>
            </div>

        </div>

    </div>        
</div>
