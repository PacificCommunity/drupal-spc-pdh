<?php
/**
 * @file
 *
 * Theme to display the Education dashboard block on a Drupal page.
 *
 */
?>

<div class="ed-dashboard-link-container container" style="margin-bottom: 50px;" >
    <div about="/content/17-goals-transform-pacific" typeof="sioc:Item foaf:Document" class="ds-1col node node-dashboards node-promoted contextual-links-region view-mode-dashboard_highlight clearfix">
 
        <div class="group-content">
            <div class="group-content-left">
                <?php print t('The <strong> status of education </strong> in the Pacific region'); ?>
            </div>
            <div class="group-content-right">
                <div class="dashboard-description">
                    <?php print t('An overview, based on available comparable data, of the current status on education in the Pacific to provide an evidence base around key education indicators.'); ?>
                </div>
                <div class="field field-type-ds">
                    <a href="<?php echo EDUCATION_DASHBOARD_URL; ?>" class="banner-button btn"><?php print t('View DASHBOARD'); ?></a>        
                </div>
            </div>

        </div>
        <div class="group-chart">
            <div class="chart-static lazy-load" data-background="/sites/all/themes/spc/img/sprite/spc_sprite.png" data-sx="-2156px" data-sy="-780px"></div>
        </div>
        
    </div>        
</div>
