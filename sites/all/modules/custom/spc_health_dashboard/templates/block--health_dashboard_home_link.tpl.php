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
            <div class="chart-static" style="margin-left: 0; margin-right: -90px; background: url(/sites/all/modules/custom/spc_health_dashboard/img/health-home.svg) 50% 50% no-repeat"></div>
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
                    <a href="/health-dashboard" class="banner-button btn"><?php print t('View DASHBOARD'); ?></a>
                </div>
            </div>

        </div>

    </div>        
</div>
