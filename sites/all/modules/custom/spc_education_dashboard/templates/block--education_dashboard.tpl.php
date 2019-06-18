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
      <div class="field field-type-text-long">
          <h1><?php print t('The status of education</br>in the '); ?>&nbsp;<strong><?php print t('Pacific region'); ?></strong></h1>
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

<?php         
    $items_data = array(
      [
        'title' => 'Title One',
        'id'    => 1
      ],
      [
        'title' => 'Title Two',
        'id'    => 2
      ],
      [
        'title' => 'Title Three',
        'id'    => 3
      ],
      [
        'title' => 'Title Four',
        'id'    => 4
      ],
      [
        'title' => 'Title Five',
        'id'    => 5
      ],
    ); 
?>

<section class="education-block-content"> 
   <?php //for ($i = 1; $i <= $items; $i++ ): ?>
    <?php foreach ($items_data as $item): ?>
    <div class="panel-pane education-block-pane">
      <div class="title">  
        <h4 id="<?php print $item['id']; ?>" class="title-text"><?php print $item['title']; ?></h4>
        <p><?php print t('Percentage of GDP spent on education. Range is from 3.8% to 18%. 7 of 10 countries spent more than 6%'); ?></p>
      </div>
      <div class="info clearfix">
          <div class="chart col-sm-6">

          </div>
          <div class="description col-sm-6">
            <p><?php print t('Total general (local, regional and central) government expenditure on education (current, capital, and transfers), expressed as a percentage of GDP. It includes expenditure funded by transfers from international sources to government'); ?></p>
          </div>
      </div>
      <a href="#" class="education-pdf"><?php print t('Export PDF'); ?></a>  
    </div>
    <?php endforeach; ?>
    <?php //endfor; ?>
    
</section>