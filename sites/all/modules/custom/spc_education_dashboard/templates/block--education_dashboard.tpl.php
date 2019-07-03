<?php
/**
 * @file
 *
 * Theme to display the Education dashboard block on a Drupal page.
 *
 */
?>

<div class="bean-banner-with-title contextual-links-region clearfix">
  <div class="content">
    <div style="background-image: url('/sites/default/files/styles/dashboard_banner/public/all_stories_bg_0.png');" class="banner-with-title">
        <div class="ed-lable">
            <span><b><?php print t('Pacific'); ?></b>&nbsp;<?php print t('education'); ?></span>
        </div>  
      <div class="field field-type-text-long">
          <h1><?php print t('The status of education</br>in the'); ?>&nbsp;<strong><?php print t('Pacific region'); ?></strong></h1>
      </div>
      <div id="spc-home-banner-search">
        <form action="/" method="post" id="ckan-search-form" accept-charset="UTF-8">
          <div>
           <input placeholder="Search" type="text" id="education-dashboard-search" name="term" value="" size="30" maxlength="128" required="">
          </div>
        </form>          
      </div>
    </div> 
  </div>
</div>

<section class="education-block-content"> 
    <?php foreach ($items as $item): ?>
    <div class="panel-pane education-block-pane" data-id="<?php print $item['id']; ?>">
      <div class="title">  
        <h4 id="<?php print $item['id']; ?>" class="title-text"><?php print $item['name']; ?></h4>
        <p class="subtitle"><?php print $item['title']; ?></p>
      </div>
      <div class="info clearfix">
          <?php $ch_cols = (count($item['charts'][0]['data']) >= 10 && $item['type'] == "gender")? 7 : 5; ?>
          <div class="chart col-sm-<?php print $ch_cols; ?>">
              <?php if ($item['type'] == "gender"): ?>
              <div class="gender-wrapp">
                <div class="male"><?php print t('Boys'); ?></div>
                <div class="female"><?php print t('Girls'); ?></div>
              </div>
              <?php endif; ?>
              <div class="chart-<?php print $item['id']; ?>"></div>
          </div>
          
          <?php $ds_cols =  (count($item['charts'][0]['data']) >= 10 && $item['type'] == "gender")? 5 : 7; ?>
          <div class="description col-sm-<?php print $ds_cols; ?>">
              
            <?php if (!empty($item['switchers'])): ?> 
            <div class="switchers clearfix">
                
                <?php if (!empty($item['switchers']['horizontal'])): ?> 
                  <?php foreach ($item['switchers']['horizontal'] as $key => $switcher): ?>
                    <div class="switch-wrapper horizontal">
                        <div class="switcher sw-<?php print $item['id']; ?>">
                            <?php $class = ($switcher['default'])? 'checked': ''; ?>
                            <a href="" key="<?php print $key; ?>" id="<?php print $switcher['id']; ?>" class="<?php print $class; ?>"><?php print $switcher['name']; ?></a>
                        </div>
                    </div>
                  <?php endforeach; ?>
                <?php endif?>
                
                <?php if (!empty($item['switchers']['vertical'])): ?> 
                <div class="switch-wrapper vertical swch-<?php print $item['id']; ?>">
                  <div class="labels">  
                      <span class="checked"><?php print $item['switchers']['vertical'][0]['name']; ?></span>
                      <span><?php print $item['switchers']['vertical'][1]['name']; ?></span>
                  </div>    
                  <div class="switcher">
                    <input class="form-check-input slider" type="checkbox" id="years" value="four">
                  </div>
                </div>
                <?php endif; ?>

            </div> 
            <?php endif; ?> 
              
            <?php if (!empty($item['definition'])): ?>  
            <div class="definition ">
              <h5><?php print t('Definition'); ?></h5>
                  <div class="toggle">
                      <span class="arrow down"></span>
                  </div>
              <p class="active"><?php print $item['definition']; ?></p>
            </div>
            <?php endif; ?>  
              
            <?php if (!empty($item['threshold']['description']) || !empty($item['threshold']['value'])): ?>  
            <div class="rationale">
              <h5><?php print t('Threshold'); ?></h5>
                  <div class="toggle">
                      <span class="arrow"></span>
                  </div>
              <p class="hidden"><?php print $item['threshold']['value']; ?></p>
              <p class="hidden"><?php print $item['threshold']['description']; ?></p>
            </div> 
            <?php endif; ?>  
              
            <?php if (!empty($item['rationale'])): ?>  
            <div class="rationale">
              <h5><?php print t('Rationale'); ?></h5>
              <div class="toggle">
                  <span class="arrow"></span>
              </div>
              <p class="hidden"><?php print $item['rationale']; ?></p>
            </div>
            <?php endif; ?>  
              
          </div>
          
      </div>
      <a href="#" class="education-pdf"><?php print t('Export PDF'); ?></a>  
    </div>
    <?php endforeach; ?>
    
</section>