<div class="bean-banner-with-title">
    <div class="content">
        <div style="" class="banner-with-title dataset-suggestion-header">
            <div class="title">
                <h1><?php print $title; ?></h1>
            </div>
        </div>
    </div>
</div>
<div role="main" id="main-content" class="dataset-suggestion-content">
    <div class="container">
      <div class="row">
          <div class="col-sm-8 suggestion-form">
            <?php print $content['messages']; ?>
            <?php print $content['form']; ?>            
          </div>
          <div class="col-sm-4 suggestion-tip">
            <h4><?php print $content['tip']['title']; ?></h4>  
            <p>
              <?php print $content['tip']['text']; ?>
            </p>
          </div>
      </div>      
    </div>
</div>