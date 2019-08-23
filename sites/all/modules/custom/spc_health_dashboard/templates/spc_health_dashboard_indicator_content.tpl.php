<?php $current_indicator = $data['current_indicator']; ?>

<div class="row indicator-content">
  <h4><?php print $data['indicator_detales']['code'] . '. ' . $data['indicator_detales']['title']; ?></h4>
  
  <?php $description = @$data['indicator_detales']['indicator-description']; ?> 
  <?php if (!empty(@$description)): ?>
    <div class="category-description">
        <div class="text">
          <?php $limit = 300; ?>
          <span class="less"><?php print substr($description, 0, $limit); ?></span>
          <?php if (strlen($description) > $limit): ?>
            <span class="dots"><?php print t('...'); ?></span>
          <?php endif; ?>
          <span class="more"><?php print substr($description, $limit+1, strlen($description)); ?></span>
          <?php if (strlen($description) > $limit): ?>
            <p class="more-less show-more"><?php print t('Read more'); ?></p>
          <?php endif; ?>
        </div>
    </div>
  <?php endif; ?>
  
  <div class="category-detales <?php print @$category_detales_class; ?>">
    <h4><?php print t('Summary of findings '. $data['indicator_detales']['title']); ?></h4>
    
    <div class="wrapper">
      <div class="summary-indicators ">
          <div class="indicator-name">
              <?php print t('Indicator'); ?>
          </div>

          <div class="country-indicators">
              <div class="indicator-title">
                  <a data-name="<?php print @$indicator_key; ?>" href="<?php echo HEALTH_DASHBOARD_URL; ?>/<?php print @$indicator['indicator-category']; ?>/<?php print @$indicator_key; ?>">
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
               href="<?php echo HEALTH_DASHBOARD_URL; ?>/country/<?php print $country['id']; ?>"
               class="country-on-map">
                <?php print $country['title']; ?>
            </a>
        </div>

        <div class="country-indicators helth-indicators">
            <?php foreach ($country['indicators'] as $ind_key => $indicator): ?>
              <?php if ($indicator['indicator-category'] == $data['current_category'] && $ind_key == $data['current_indicator']): ?>
                <div id ="country-<?php print $country['id']; ?>-id"
                     class="status-strength <?php print $indicator['value']?>" 
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
          disableDefaultUI: true,
          styles: [
            {elementType: 'geometry', stylers: [{color: '#ffffff'}]},
            {elementType: 'labels.text.stroke', stylers: [{color: '#ffffff'}]},
            {elementType: 'labels.text.fill', stylers: [{color: '#000000'}]},
            {
              featureType: 'administrative',
              elementType: 'geometry.fill',
              stylers: [{color: '#000000'}]
            },
            {
              featureType: 'administrative.province',
              elementType: 'geometry.stroke',
              stylers: [{color: '#000000'}]
            },
            {
              featureType: 'administrative.locality',
              elementType: 'labels.text.fill',
              stylers: [{color: '#000000'}]
            },            
            {
              featureType: 'road',
              elementType: 'geometry',
              stylers: [{color: '#38414e'}]
            },
            {
              featureType: 'road',
              elementType: 'geometry.stroke',
              stylers: [{color: '#212a37'}]
            },
            {
              featureType: 'road',
              elementType: 'labels.text.fill',
              stylers: [{color: '#9ca5b3'}]
            },
            {
              featureType: 'road.highway',
              elementType: 'geometry',
              stylers: [{color: '#746855'}]
            },
            {
              featureType: 'road.highway',
              elementType: 'geometry.stroke',
              stylers: [{color: '#1f2835'}]
            },
            {
              featureType: 'road.highway',
              elementType: 'labels.text.fill',
              stylers: [{color: '#f3d19c'}]
            },
            {
              featureType: 'transit',
              elementType: 'geometry',
              stylers: [{color: '#000000'}]
            },
            {
              featureType: 'transit.station',
              elementType: 'labels.text.fill',
              stylers: [{color: '#000000'}]
            },
            {
              featureType: 'water',
              elementType: 'geometry',
              stylers: [{color: '#33c5ec'}]
            },
            {
              featureType: 'water',
              elementType: 'labels.text.fill',
              stylers: [{color: '#515c6d'}]
            },
            {
              featureType: 'water',
              elementType: 'labels.text.stroke',
              stylers: [{color: '#17263c'}]
            }
          ]
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
          countriesData[countryId]['position'] = new google.maps.LatLng(lat+10, lng+10);
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
            icon: { 
              url: countriesData[key].icon,
              scaledSize: new google.maps.Size(60, 60),
              anchor: new google.maps.Point(30, 30),
            },
            map: map,
            label: countriesData[key].label,
            value: countriesData[key].value,
            cid: key
          });
          
          bounds.extend(markers[key].position);
          
          markers[key].addListener('mouseover', function() {
                let marker = this;
                marker.setIcon({
                  url: iconBase + marker.value + '-stroke.png',
                  scaledSize: new google.maps.Size(60, 60),
                  anchor: new google.maps.Point(30, 30),
                });
                        
                let label = this.getLabel();
                label.fontSize="10px";
                this.setLabel(label);
                
                marker.setZIndex(1000);
          });
          
          markers[key].addListener('mouseout', function() {
                let marker = this;
                
                marker.setIcon({
                  url: iconBase + marker.value + '.png',
                  scaledSize: new google.maps.Size(60, 60),
                  anchor: new google.maps.Point(30, 30),
                });
            
                let label = this.getLabel();
                label.fontSize="0px";
                this.setLabel(label);
                
                marker.setZIndex(0);
          });
          
          markers[key].addListener('click', function() {
                let marker = this;

                let countryIndicator = document.querySelector('#country-' + marker.cid + '-id');
                countryIndicator.click();
                
                if (marker.icon.url.indexOf('stroke') == -1){
                    marker.setIcon({
                      url: iconBase + marker.value + '-stroke.png',
                      scaledSize: new google.maps.Size(60, 60),
                      anchor: new google.maps.Point(30, 30),
                    });
                    
                    let label = this.getLabel();
                    label.fontSize="10px";
                    this.setLabel(label);
                } else {
                    marker.setIcon({
                      url: iconBase + marker.value + '.png',
                      scaledSize: new google.maps.Size(60, 60),
                      anchor: new google.maps.Point(30, 30),                  
                    });

                    let label = this.getLabel();
                    label.fontSize="0px";
                    this.setLabel(label);
                }
          });
        };
        
        map.fitBounds(bounds);

        for (var i = 0; i < countryItems.length; i++) {
          let countryId = countryItems[i].dataset.country;
          
          countryItems[i].addEventListener('mouseover', function(event) {
            if (markers[countryId] != 'undefined'){
              
              let marker = markers[countryId];
              marker.setIcon({
                  url: iconBase + marker.value + '-stroke.png',
                  scaledSize: new google.maps.Size(60, 60),
                  anchor: new google.maps.Point(30, 30),
                });
              
              let label = marker.getLabel();
              label.fontSize="10px";
              marker.setLabel(label);
              marker.setZIndex(1000);
            }

          });
        }     
        
        for (var i = 0; i < countryItems.length; i++) {
          let countryId = countryItems[i].dataset.country;
          
          countryItems[i].addEventListener('mouseout', function(event) {
            if (markers[countryId] != 'undefined'){
              
              let marker = markers[countryId];
              marker.setIcon({
                  url: iconBase + marker.value + '.png',
                  scaledSize: new google.maps.Size(60, 60),
                  anchor: new google.maps.Point(30, 30),                  
                });
              
              let label = marker.getLabel();
              label.fontSize="0px";
              marker.setLabel(label);
              marker.setZIndex(0);
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
              <a href="<?php echo HEALTH_DASHBOARD_URL; ?>/<?php print $data['current_category']; ?>/<?php print $indicator_key; ?>">
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