<?php //print_r($search); ?>
<div id="spc-home-banner-search">
  <form action="/" method="post" id="ckan-search-form" class="health-dashboard-search-form" accept-charset="UTF-8">
    <div>
      <input placeholder="Search" type="text" id="health-dashboard-search" name="term" size="30" maxlength="128">
      <div class="search-sugestion">
        <div class="sug-wrapper">
            
          <div class="no-results">
              <p><?php print t('No results were found.'); ?></p>
          </div>  
            
          <div class="sug-block sug-categories">
            <p class="lable"><?php print t('Categories'); ?></p>  
            <ul class="sug-list"></ul>
          </div> 

          <div class="sug-block item sug-indicators">
            <p class="lable"><?php print t('Indicators'); ?></p>  
            <ul class="sug-list"></ul>
          </div> 

          <div class="sug-block sug-countries">
            <p class="lable"><?php print t('Countries'); ?></p>  
            <ul class="sug-list"></ul>
          </div>
            
        </div>
      </div>
    </div>
  </form>          
</div>