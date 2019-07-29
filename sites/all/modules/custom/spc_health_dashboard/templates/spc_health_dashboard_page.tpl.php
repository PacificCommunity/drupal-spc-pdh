<div class="bean-banner-with-title">
    <div class="content">
        <div style="" class="banner-with-title health-dashboard-header">
            <div class="left-label"><?php print t('<strong>NCD</strong> Dashboard'); ?></div>
            <div class="breadcrumbs"><?php print $breadcrumbs; ?></div>
            <div class="title">
                <h1><?php print $title; ?> </h1>
            </div>
            <div class="search"><?php print $search; ?></div>
        </div>
    </div>
</div>
<div role="main" id="main-content" class="health-dashboard-content">
    <div class="container">
      <?php print $content; ?>
    </div>
</div>