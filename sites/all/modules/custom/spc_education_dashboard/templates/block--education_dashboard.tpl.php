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
          
          <div class="chart col-sm-5">
              <div class="chart-<?php print $item['id']; ?>"></div>
              <?php if ($item['id'] == 4 ): ?>
              <div id="chart4yearNumeracy"></div>
              <?php endif; ?>
          </div>
          
          <div class="description col-sm-7">
              
            <?php if ($item['id'] == 4 ): ?>  
            <div class="switchers clearfix">
                <div class="switch-wrapper horizontal">
                    <div class="switcher">
                        <a href="" id="literacy" class="checked"><?php print t('Literacy'); ?></a>
                    </div>
                    
                </div>
                <div class="switch-wrapper horizontal">
                    <div class="switcher">
                        <a href="" id="numeracy" class="" ><?php print t('Numeracy'); ?></a>
                    </div>
                </div> 
                <div class="switch-wrapper vertical">
                  <div class="labels">  
                      <p class="checked"><?php print t('Year four students'); ?></p>
                      <p><?php print t('Year six students'); ?></p>
                  </div>    
                  <div class="switcher">
                    <input class="form-check-input slider" type="checkbox" id="years" value="four">
                  </div>
                </div>
            </div> 
            <?php endif; ?> 
              
            <div class="definition ">
              <h5><?php print t('Definition'); ?></h5>
                  <div class="toggle">
                      <span class="arrow down"></span>
                  </div>
              <p class="active"><?php print $item['definition']; ?></p>
            </div>
            <div class="rationale">
              <h5><?php print t('Threshold'); ?></h5>
                  <div class="toggle">
                      <span class="arrow"></span>
                  </div>
              <p class="hidden"><?php print $item['threshold']['value']; ?></p>
              <p class="hidden"><?php print $item['threshold']['description']; ?></p>
            </div> 
            <div class="rationale">
              <h5><?php print t('Rationale'); ?></h5>
              <div class="toggle">
                  <span class="arrow"></span>
              </div>
              <p class="hidden"><?php print $item['rationale']; ?></p>
            </div>              
          </div>
          
      </div>
      <a href="#" class="education-pdf"><?php print t('Export PDF'); ?></a>  
    </div>
    <?php endforeach; ?>
    
</section>