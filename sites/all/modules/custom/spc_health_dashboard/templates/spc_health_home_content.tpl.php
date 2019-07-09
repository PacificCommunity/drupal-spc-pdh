<div class="health-home-description">
  <?php if (!empty($data['background'])): ?>  
    <h4 class="title-text"><?php print t('Background'); ?> </h4>
    <p><?php print $data['background']; ?></p>
  <?php endif; ?>  
  </br>
  <?php if (!empty($data['methods'])): ?>
    <h4 class="title-text"><?php print t('Methods'); ?> </h4>
    <p><?php print $data['methods']; ?></p>
  <?php endif; ?>
</div>

<div class="health-home-chart">
    <h4><?php print $data['chart']['name'] ?></h4>
    <div class="col-sm-9">
      <div id="stacked-chart-global" class="stacked-chart-global"></div>
    </div> 
    <div class="col-sm-3">
        <div class="chart-global-legend">
          <div class="legend present"><?php print t('Present'); ?></div>
          <div class="legend development"><?php print t('Development'); ?></div>
          <div class="legend not-present"><?php print t('Not Present'); ?></div>
        </div>
    </div>    
</div>    
