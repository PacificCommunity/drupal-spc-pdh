<?php $current_indicator = $data['current_indicator']; ?>

<div class="row indicator-content">
  <h4><?php print $data['indicator_detales']['code'] . '. ' . $data['indicator_detales']['title']; ?></h4>
    
  <div class="category-detales <?php print $category_detales_class; ?>">
    <h4><?php print t('Summary of findings '. $data['indicator_data']['title']); ?></h4>
    
    <div class="wrapper">
      <div class="summary-indicators ">
          <div class="indicator-name">
              <?php print t('indicator'); ?>
          </div>

          <div class="country-indicators">
              <div class="indicator-title">
                  <a data-name="<?php print $indicator_key; ?>" href="/health-dashboard/<?php print $indicator['indicator-category']; ?>/<?php print $indicator_key; ?>">
                  <?php print $data['indicator_detales']['code'] .'. '. $data['indicator_detales']['title']; ?>
                </a>
              </div>
          </div> 
      </div> 
        
      <div class="category-data">
          <div class="not-present values">
          <h4><?php print t('Not Present'); ?></h4>  
              <div class="<?php print $current_indicator; ?>-value indicator">
                  <p class="number value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['not-present']['number']; ?>
                  </p>
                  <p class="percentage value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['not-present']['percentage']; ?>%
                  </p>
              </div>
          </div>
          
          <div class="under-development values">
          <h4><?php print t('Under Development'); ?></h4>    
              <div class="<?php print $current_indicator; ?>-value indicator">
                  <p class="number value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['under-development']['number']; ?>
                  </p>
                  <p class="percentage value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['under-development']['percentage']; ?>%
                  </p>
              </div>
          </div>
          
          <div class="present values">
          <h4><?php print t('Present'); ?></h4>    
              <div class="<?php print $current_indicator; ?>-value indicator">
                  <p class="number value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['present']['number']; ?>
                  </p>
                  <p class="percentage value">
                    <?php print $data['category_data']['indicators'][$current_indicator]['present']['percentage']; ?>%
                  </p>
              </div>
          </div>    
      </div>
    </div>
  </div>

  <div class="category-countries col-sm-3">
      
      <?php foreach ($data['countries-data'] as $country): ?>
      <div class="country-item clearfix">
        <div class="country-flag">
              <?php $map = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/flags/' . $country['id'] . '.svg';?>
            <img id="<?php print $country['id']; ?>" src="<?php print $map; ?>">       
        </div>

        <div class="country-name">
            <a href="/health-dashboard/country/<?php print $country['id']; ?>"><?php print $country['title']; ?></a>
        </div>

        <div class="country-indicators helth-indicators">
            <?php foreach ($country['indicators'] as $ind_key => $indicator): ?>
              <?php if ($indicator['indicator-category'] == $data['current_category'] && $ind_key == $data['current_indicator']): ?>
                <div class="status-strength <?php print $indicator['value']?>" 
                     data-value="<?php print $indicator['value']?>"
                     data-category="<?php print $data['current_category']['id']; ?>"
                     data-indicator="<?php print $ind_key; ?>"
                     data-country-title="<?php print $country['title']; ?>"
                     data-country="<?php print $country['id']; ?>"></div>
              <?php endif; ?>
            <?php endforeach; ?>
        </div>   
      </div>        
      <?php endforeach;?>
  </div>
    
  <div class="pacific-map col-sm-9">
    <?php $src = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/pacific-map.png'?>
      <img src="<?php print $src; ?>" alt="pacific-map">
  </div>
</div>