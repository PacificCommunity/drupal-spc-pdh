<?php $current_indicator = $data['current_indicator']; ?>

<div class="row indicator-content">
  <h4><?php print $data['indicator_detales']['code'] . '. ' . $data['indicator_detales']['title']; ?></h4>
    
  <div class="category-detales <?php print @$category_detales_class; ?>">
    <h4><?php print t('Summary of findings '. $data['indicator_detales']['title']); ?></h4>
    
    <div class="wrapper">
      <div class="summary-indicators ">
          <div class="indicator-name">
              <?php print t('indicator'); ?>
          </div>

          <div class="country-indicators">
              <div class="indicator-title">
                  <a data-name="<?php print @$indicator_key; ?>" href="/health-dashboard/<?php print @$indicator['indicator-category']; ?>/<?php print @$indicator_key; ?>">
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
      <div class="country-item clearfix"
           data-country="<?php print $country['id']; ?>"
           data-name="<?php print $country['title']; ?>"
           data-lat="<?php print $country['map-coordinates']['lat']; ?>"
           data-lng="<?php print $country['map-coordinates']['lng']; ?>"
           data-value="<?php print $country['indicators'][$current_indicator]['value']; ?>">
        <div class="country-flag">
              <?php $map = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/flags/' . $country['id'] . '.svg';?>
            <img id="<?php print $country['id']; ?>" src="<?php print $map; ?>">       
        </div>

        <div class="country-name">
            <a data-country-id="<?php print $country['id']; ?>" 
               href="/health-dashboard/country/<?php print $country['id']; ?>"
               class="country-on-map">
                <?php print $country['title']; ?>
            </a>
        </div>

        <div class="country-indicators helth-indicators">
            <?php foreach ($country['indicators'] as $ind_key => $indicator): ?>
              <?php if ($indicator['indicator-category'] == $data['current_category'] && $ind_key == $data['current_indicator']): ?>
                <div class="status-strength <?php print $indicator['value']?>" 
                     data-value="<?php print $indicator['value']?>"
                     data-category="<?php print @$data['current_category']['id']; ?>"
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
    <div id="pacific-map"></div>
    <script>
      function initMap() {

        const map = new google.maps.Map(document.getElementById('pacific-map'), {
          disableDefaultUI: true
        });

        const iconBase = '<?php print $src = '/' . drupal_get_path('module', 'spc_health_dashboard') . '/img/markers/'?>';
        const lebleDefault = {
          color: "#fff",
          fontWeight: "bold",
          fontSize: "0px"
        }
        
        let countriesData = []; 
        const countryItems = document.querySelectorAll('.country-item');
        
        for (let i = 0; i < countryItems.length; i++){
          
          let countryId = countryItems[i].dataset.country;
          let lat = countryItems[i].dataset.lat;
          let lng = countryItems[i].dataset.lng;
          
          countriesData[countryId] = {};
          countriesData[countryId]['lat'] = countryItems[i].dataset.lat;
          countriesData[countryId]['lng'] = countryItems[i].dataset.lng;
          countriesData[countryId]['name'] = countryItems[i].dataset.name;
          countriesData[countryId]['value'] = countryItems[i].dataset.value;
          countriesData[countryId]['position'] = new google.maps.LatLng(lat, lng);
          countriesData[countryId]['icon'] = iconBase + countryItems[i].dataset.value + '.png';
          
          countriesData[countryId]['label'] = {
              text: countryItems[i].dataset.name,
              color: lebleDefault.color,
              fontWeight: lebleDefault.fontWeight,
              fontSize: lebleDefault.fontSize
          }
        }
        
        let bounds = new google.maps.LatLngBounds();

        let markers = {};
        
        // Create markers.
        for (let key in countriesData) {
          markers[key] = new google.maps.Marker({
            position: countriesData[key].position,
            icon: countriesData[key].icon,
            map: map,
            label: countriesData[key].label,
            value: countriesData[key].value
          });
          
          bounds.extend(markers[key].position);
          
          markers[key].addListener('mouseover', function() {
                let marker = this;
                marker.setIcon( iconBase + marker.value + '-stroke.png');
                        
                let label = this.getLabel();
                label.fontSize="10px";
                this.setLabel(label);
          });

          markers[key].addListener('mouseout', function() {
                let marker = this;
                marker.setIcon( iconBase + marker.value + '.png');
            
                let label = this.getLabel();
                label.fontSize="0px";
                this.setLabel(label);
          });
        };
        
        map.fitBounds(bounds);

        for (var i = 0; i < countryItems.length; i++) {
          let countryId = countryItems[i].dataset.country;
          
          countryItems[i].addEventListener('mouseover', function(event) {
            if (markers[countryId] != 'undefined'){
              
              let marker = markers[countryId];
              marker.setIcon( iconBase + marker.value + '-stroke.png');
              
              let label = marker.getLabel();
              label.fontSize="10px";
              marker.setLabel(label);                
            }

          });
        }     
        
        for (var i = 0; i < countryItems.length; i++) {
          let countryId = countryItems[i].dataset.country;
          
          countryItems[i].addEventListener('mouseout', function(event) {
            if (markers[countryId] != 'undefined'){
              
              let marker = markers[countryId];
              marker.setIcon( iconBase + marker.value + '.png');
              
              let label = marker.getLabel();
              label.fontSize="0px";
              marker.setLabel(label);                
            }

          });
        }
        
      }
    </script>
    <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDEy9EQCIbFOhOfh-PPqxesjbjirYC6WZ0&callback=initMap" async defer></script>
      
  </div>
</div>

<div class="categories-switcher indicator">
    <p class="prev"><span><?php print t('Previous indicator'); ?></span></p>
    <div class="list">
    <?php foreach ($data['indicators_list'] as $indicator_key => $indicator): ?>
      <?php $current = ''?>
      <?php if($indicator['indicator-category'] == $data['current_category']): ?>
        <?php if ($indicator_key == $data['current_indicator']): ?>
          <?php $current = 'current'; ?>
        <?php endif; ?>
          <div class="category-item <?php print $current ?>">
              <a href="/health-dashboard/<?php print $data['current_category']; ?>/<?php print $indicator_key; ?>">
                <?php print $indicator['code'] ?>
              </a>
          </div>   
      <?php endif; ?>
    <?php endforeach; ?>
    </div>    
    <p class="next"><span><?php print t('Next indicator'); ?></span></p>
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