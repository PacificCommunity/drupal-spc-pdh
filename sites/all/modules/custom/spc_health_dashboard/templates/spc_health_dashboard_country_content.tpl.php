<div class="health-country-chart clearfix">
    <h4 class="block-title"><?php print $data['title'];?></h4>
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
<div class="health-country-categories">
  <h4 class="block-title"><?php print t('NCD Response Measures');?></h4>
  
  
  <?php foreach ($data['categories'] as $key => $category): ?>
  <div class="block-indicator-group">
    <h4><?php print $category['#title']; ?></h4>
    
    <div class="toggle">
      <span class="arrow down"></span>
    </div>
    
    <div class="helth-indicators">
          <?php foreach($data['indicators'] as $indicator): ?>
              <?php if ($key == $indicator['indicator-category']): ?>
                <p><?php print $indicator['title']; ?></p>
                <p><?php print $indicator['value']; ?></p>
              <?php endif; ?> 
          <?php endforeach;?> 
    </div>
    
  </div>
  <?php endforeach; ?>
  
</div>
