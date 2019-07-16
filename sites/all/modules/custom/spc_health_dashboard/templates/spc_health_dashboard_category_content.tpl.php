<div class="row">
    
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
            <?php foreach ($country['indicators'] as $indicator): ?>
              <?php if ($indicator['indicator-category'] == $data['current_category']['id']): ?>
                <div class="status-strength <?php print $indicator['value']?>"></div>
              <?php endif; ?>
            <?php endforeach; ?>
        </div>   
      </div>        
      <?php endforeach;?>
  </div>

  <div class="category-detales <?php print $category_detales_class; ?>">
    <h4><?php print t('Summary of findings for Pacific NCD dashboard leadership and governance indicators'); ?></h4>
  </div>
</div>

<div class="categories-switcher">
    <p class="prev"></p>
    <?php foreach ($data['categories_list'] as $category_key => $category): ?>
      <?php $current = ''?>
      <?php if($category_key == $data['current_category']['id']): ?>
        <?php $current = 'current'?>
      <?php endif; ?>
      <div class="category-item <?php print $current ?>">
          <a href="/health-dashboard/<?php print $category_key; ?>"><?php print $category['#title'] ?></a>
      </div>    
    <?php endforeach; ?>
    <p class="next"></p>
</div>