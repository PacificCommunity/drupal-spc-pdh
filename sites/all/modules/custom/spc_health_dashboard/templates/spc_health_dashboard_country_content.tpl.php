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
    <?php if ($category['#wrapper']) $category['#title'] .= ' - ' . $category['#wrapper']; ?>
    <h4 class="category-title <?php print $key; ?>"><?php print $category['#title']; ?></h4>
    
    <div class="toggle">
      <span class="arrow"></span>
    </div>
    
    <div class="helth-indicators">
      <div class="row"> 
          <div class="col-sm-2">
            <h6><?php print t('Code'); ?></h6>  
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p><?php print $indicator['code']; ?></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>
          <div class="col-sm-5">
            <h6><?php print t('Description'); ?></h6>    
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p><?php print $indicator['title']; ?></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>
          <div class="col-sm-3">
            <h6><?php print t('Status and strength'); ?></h6>    
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p class="status-strength <?php print $indicator['value'] ?>"></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>
          <div class="col-sm-2">
            <h6><?php print t('WHO Equivalent indicator #'); ?></h6>    
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p><?php print $indicator['who']; ?></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>          
     </div>       
    </div>
    
  </div>
  <?php endforeach; ?>
  
</div>
