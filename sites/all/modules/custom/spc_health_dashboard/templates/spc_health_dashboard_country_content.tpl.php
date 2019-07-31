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
        <?php if (!empty($data['chart-pdf-export'])): ?>
          <div class="chart-pdf-export">
              <a target="_blank"href="<?php print $data['chart-pdf-export']; ?>"></a>
            <div class="chart-pdf-text">
              <p><strong><?php print t('Download pdf file'); ?></strong></p>
              <p><?php print t('Summary of status of indicators across the categories (%)'); ?></p>
            </div>
          </div>
        <?php endif; ?>
    </div>    
</div>

<div class="health-country-categories">
  <h4 class="block-title"><?php print t('NCD Response Measures');?></h4>

  <?php foreach ($data['categories'] as $key => $category): ?>
  <div class="block-indicator-group">
    <?php if ($category['#wrapper']) $category['#title'] .= ' - ' . $category['#wrapper']; ?>
    <h4 class="toggle-lbl category-title <?php print $key; ?>"><?php print $category['#title']; ?></h4>
    
    <div class="toggle">
      <span class="arrow"></span>
    </div>
    
    <div class="helth-indicators">
      <div class="row"> 
          <div class="col-sm-2 code">
            <h6><?php print t('Code'); ?></h6>  
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p><?php print $indicator['code']; ?></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>
          <div class="col-sm-5 title">
            <h6><?php print t('Description'); ?></h6>    
            <?php foreach($data['indicators'] as $indicator): ?>
                <?php if ($key == $indicator['indicator-category']): ?>
                  <p><?php print $indicator['title']; ?></p>
                <?php endif; ?> 
            <?php endforeach;?>
          </div>
          <div class="scroll-wrapp">
            <div class="scroll-row">
              <div class="col-sm-3 strength">
                <h6><?php print t('Status and strength'); ?></h6>    
                <?php foreach($data['indicators'] as $id => $indicator): ?>
                    <?php if ($key == $indicator['indicator-category']): ?>
                      <p class="status-strength <?php print $indicator['value'] ?>"
                         data-value="<?php print $indicator['value']; ?>"
                         data-category="<?php print $indicator['indicator-category']; ?>"
                         data-indicator="<?php print $id; ?>"></p>
                    <?php endif; ?> 
                <?php endforeach;?>
              </div>
              <div class="col-sm-2 who">
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
    </div>
    
  </div>
  <?php endforeach; ?>
  
  <div class="indicator-popup">
      <div class="country-detales col-sm-5">
          <?php $src = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/flags/' . $data['country_id'] . '.svg'?>
          <img class="country-flag" src="<?php print $src; ?>" alt="<?php print $data['country']; ?>">
          <h4><?php print $data['country']; ?></h4>
          <div class="content clearfix">
              <p class="indicator-title"></p>
              <div class="col-sm-4">
                <p id="indicator-value"></p>
              </div>
              <div class="col-sm-8">
                <p id="indicator-text" class="text"></p>
              </div>
          </div>
          <?php $map = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/maps/' . $data['country_id'] . '.svg';?>
          <div id="map" class="map <?php print $data['country_id']; ?>" style="background-image: url(<?php print $map; ?>)"></div>
      </div>
      <div class="description-detales col-sm-7">
        <h4><?php print t('Description'); ?></h4>
          <div class="content detales">
              
              <div id="not-present" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength not-present"></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              
              <div id="under-development" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength under-development"></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              
              <div id="present" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength present"></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              
              <div id="low" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength low"></p>
                  </div>  
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              
              <div id="medium" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength medium"></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              
              <div id="high" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength high"></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
              <div id="not-applicable" class="clearfix">
                  <div class="col-sm-3">
                    <p class="status-strength not-applicable"><?php print t('N/A'); ?></p>
                  </div>
                  <div class="col-sm-9">
                    <p class="text"></p>
                  </div>
              </div>
          </div>        
      </div>
  </div>
  
</div>
