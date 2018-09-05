<div class="goals-navigation">
  <div class="dropdown">
    <?php if ($rows): ?>
      <button type="button" id="goals-navigation" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
        <img class="goals-logo" src="/sites/all/themes/spc/img/spc/SDG_logo.png" width="109" height="60">
          <i class="fa fa-caret-down" aria-hidden="true"></i>
          <i class="fa fa-caret-up" aria-hidden="true"></i>
      </button>
      <ul class="dropdown-menu" aria-labelledby="goals-navigation">
        <?php print $rows; ?>
      </ul>
    <?php else: ?>
      <img class="goals-logo" src="/sites/all/themes/spc/img/spc/SDG_logo.png" width="109" height="60">
    <?php endif; ?>
  </div>
</div>
