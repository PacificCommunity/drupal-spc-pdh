<div class="-indicator-countries">
    <h4><?php print t('PICT ratings for Pacific NCD Dashboard leadership and governance indicators'); ?></h4>
    <?php foreach ($data['countries-data'] as $country): ?>
    <div class="country-flag">
          <?php $map = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/flags/' . $country['id'] . '.svg';?>
        <img id="<?php print $country['id']; ?>" src="<?php print $map; ?>">       
    </div>    
    <div class="country-name">
      <?php print $country['title']; ?>
    </div>
    <div class="country-indicators">
        <?php foreach ($country['indicators'] as $key => $indicator): ?>
          <?php if ($key == $data['current_indicator']): ?>
            <div><?php print $indicator['value']?></div>
          <?php endif; ?>
        <?php endforeach; ?>
    </div>    
    <?php endforeach;?>
</div>