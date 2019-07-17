<div class="row category-content">
    
    <h2><?php print $data['category_data']['name'];?></h2>
    
    <div class="category-description">
        <?php $src = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/categories/' . $data['current_category']['id'] . '.png'?>
        <img class="category-img" src="<?php print $src; ?>" alt="<?php print $data['country']; ?>">
        
        <div class="text">
          <?php $description = $data['category_data']['description']; ?>  
          <span class="less"><?php print substr($description, 0, 300); ?></span>
          <span class="dots"><?php print t('...'); ?></span>
          <span class="more"><?php print substr($description, 301, strlen($description)); ?></span>
          <p class="more-less show-more"><?php print t('Read more'); ?></p>
        </div>
    </div>
    
   <?php 
    $indicators_count = count($data['current_category']['#indicators']); 
    if ($indicators_count <= 3){
      $category_countries_class = 'col-sm-6';
      $category_detales_class = 'col-sm-6';
    } else {
      $category_countries_class = 'col-sm-12';
      $category_detales_class = 'col-sm-12';
    }
   
   ?> 
  <h4><?php print t('PICT ratings for Pacific NCD Dashboard '. $data['current_category']['#title'] . ' indicators'); ?></h4>
  <div class="category-countries <?php print $category_countries_class; ?>">
      <h4><?php print t('PICT ratings for Pacific NCD Dashboard '. $data['current_category']['#title'] . ' indicators'); ?></h4>

      <div class="category-header clearfix">
          <div class="countries-names">
              <?php print t('indicator'); ?>
          </div>

          <div class="country-indicators">
          <?php foreach ($data['indicator_detales'] as $indicator_key => $indicator): ?>
            <?php if ($indicator['indicator-category'] == $data['current_category']['id']): ?>
              <div class="indicator-title">
                  <a data-name="<?php print $indicator_key; ?>" href="/health-dashboard/<?php print $indicator['indicator-category']; ?>/<?php print $indicator_key; ?>">
                  <?php print $indicator['code'] .'. '. $indicator['title']; ?>
                </a>
              </div>
            <?php endif; ?>
          <?php endforeach; ?>
          </div>    
      </div>

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
              <?php if ($indicator['indicator-category'] == $data['current_category']['id']): ?>
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

  <div class="category-detales <?php print $category_detales_class; ?>">
    <h4><?php print t('Summary of findings for Pacific NCD dashboard '. $data['current_category']['#title'] . ' indicators'); ?></h4>
    
    <div class="wrapper">
      <div class="summary-indicators ">
          <div class="indicator-name">
              <?php print t('indicator'); ?>
          </div>

          <div class="country-indicators">
          <?php foreach ($data['indicator_detales'] as $indicator_key => $indicator): ?>
            <?php if ($indicator['indicator-category'] == $data['current_category']['id']): ?>
              <div class="indicator-title">
                  <a data-name="<?php print $indicator_key; ?>" href="/health-dashboard/<?php print $indicator['indicator-category']; ?>/<?php print $indicator_key; ?>">
                  <?php print $indicator['code'] .'. '. $indicator['title']; ?>
                </a>
              </div>
            <?php endif; ?>
          <?php endforeach; ?>
          </div> 
      </div> 
        
      <div class="category-data">
          <div class="not-present values">
          <h4><?php print t('Not Present'); ?></h4>  
          
          <?php foreach ($data['category_data']['indicators'] as $ikey => $idata): ?>
            <?php if(!empty($idata['not-present'])):?>
              <div class="<?php print $ikey; ?>-value indicator">
                  <p class="number value"><?php print $idata['not-present']['number']; ?></p>
                  <p class="percentage value"><?php print $idata['not-present']['percentage']; ?>%</p>
              </div>
            <?php endif; ?>
          <?php endforeach; ?>
          </div>
          
          <div class="under-development values">
          <h4><?php print t('Under Development'); ?></h4>    
          <?php foreach ($data['category_data']['indicators'] as $ikey => $idata): ?>
            <?php if(!empty($idata['under-development'])):?>
              <div class="<?php print $ikey; ?>-value indicator">
                  <p class="number value"><?php print $idata['under-development']['number']; ?></p>
                  <p class="percentage value"><?php print $idata['under-development']['percentage']; ?>%</p>
              </div>
            <?php endif; ?> 
          <?php endforeach; ?>
          </div>
          
          <div class="present values">
          <h4><?php print t('Present'); ?></h4>    
          <?php foreach ($data['category_data']['indicators'] as $ikey => $idata): ?>
            <?php if(!empty($idata['under-development'])):?>
              <div class="<?php print $ikey; ?>-value indicator">
                  <p class="number value"><?php print $idata['present']['number']; ?></p>
                  <p class="percentage value"><?php print $idata['present']['percentage']; ?>%</p>
              </div>
            <?php endif; ?>
          <?php endforeach; ?>
          </div>    
      </div>
    </div>
        
  </div>
</div>

<div class="categories-switcher">
    <p class="prev"></p>
    <div class="list">
    <?php foreach ($data['categories_list'] as $category_key => $category): ?>
      <?php $current = ''?>
      <?php if($category_key == $data['current_category']['id']): ?>
        <?php $current = 'current'?>
      <?php endif; ?>
      <div class="category-item <?php print $current ?>">
          <a href="/health-dashboard/<?php print $category_key; ?>"><?php print $category['#title'] ?></a>
      </div>    
    <?php endforeach; ?>
    </div>    
    <p class="next"></p>
</div>

<div class="indicator-popup">
    <div class="country-detales col-sm-5">
        <img class="country-flag" src="" alt="">
        <h4></h4>
        <div class="content clearfix">
            <p class="indicator-title"></p>
            <div class="col-sm-4">
              <p id="indicator-value"></p>
            </div>
            <div class="col-sm-8">
              <p id="indicator-text" class="text"></p>
            </div>
        </div>
        <div id="map" class="map"></div>
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