<div class="health-country-chart">
    <h4><?php print $data['title'];?></h4>
    <div class="col-sm-9">
      <div id="stacked-chart-global" class="stacked-chart-global"></div>
    </div> 
    <div class="col-sm-3">
        <div class="chart-global-legend">
          <div class="legend present"><span><?php print t('Present'); ?></span></div>
          <div class="legend development"><span><?php print t('Under Development'); ?></span></div>
          <div class="legend not-present"><span><?php print t('Not Present'); ?></span></div>
        </div>
    </div>    
</div>
