<div class="health-home-description">
  <?php if (!empty($data['background'])): ?>  
    <h4 class="title-text"><?php print t('Background'); ?> </h4>
    <p><?php print $data['background']; ?></p>
  <?php endif; ?>  
  </br>
  <?php if (!empty($data['methods'])): ?>
    <h4 class="title-text"><?php print t('Methods'); ?> </h4>
    <p><?php print $data['methods']; ?></p>
  <?php endif; ?>
</div>

<div class="health-home-chart">
    <h4><?php print $data['chart']['name'] ?></h4>
    <div class="col-sm-9">
      <div id="stacked-chart-global" class="stacked-chart-global"></div>
    </div> 
    <div class="col-sm-3">
        <div class="chart-global-legend">
          <div class="legend present"><span><?php print t('Present'); ?></span></div>
          <div class="legend development"><span><?php print t('Under Development'); ?></span></div>
          <div class="legend not-present"><span><?php print t('Not Present'); ?></span></div>
        </div>
    </div>    
</div>

<div class="health-dashboard-categories" style="display: none;">
    <h4><?php echo t('NCD Response Measures') ?> </h4>
    <ul class="nav__list">
        <?php foreach ($data['categories'] as $key => $item): ?>
        <li class="<?php echo $key ?>">
            <input id="group-<?php echo $key ?>" type="checkbox" hidden />
            <label for="group-<?php echo $key ?>"><?php echo $item['#title'] ?></label>
            <ul class="group-list">
              <?php foreach ($item['#indicators'] as $key2 => $item2): ?>
                <?php if (isset($item2['#indicators'])): ?>
                  <li>
                      <input id="sub-group-<?php echo $key2 ?>" type="checkbox" hidden />
                      <label for="sub-group-<?php echo $key2 ?>" class="indicator"><?php echo $item2['#title'] ?><span class="fa fa-angle-down"></span></label>
                        <ul class="sub-group-list">
                        <?php foreach ($item2['#indicators'] as $key3 => $item3): ?>
                            <li><a href="#"><?php echo $item3 ?></a>
                            </li>
                        <?php endforeach; ?>
                      </ul>
                  </li>
                <?php else: ?>
                  <li>
                      <input id="sub-group-<?php echo $key2 ?>" type="checkbox" hidden />
                      <label for="sub-group-<?php echo $key2 ?>"><?php echo $item2 ?></label>
                  </li>
                <?php endif; ?>
              <?php endforeach; ?>
            </ul>
        </li>
        <?php endforeach; ?>
    </ul>
</div>

<div class="health-dashboard-countries">
    <h4><?php echo t('Pacific island countries') ?></h4>
  <?php foreach ($data['countries'] as $key => $item): ?>
    <?php echo $key == 0 ? '' : '<div class="delimiter">&gt;</div>' ?>
      <a class="one-country <?php echo $key ?>" href="<?php echo HEALTH_DASHBOARD_URL . '/country/' . $key ?>" title="<?php echo $item['#title'] ?>">
          <img src="/<?php echo $data['flag_base_path'] . '/' . $key . '.svg' ?>" alt="<?php echo $item['#title'] ?>"><br>
          <span>
              <?php if ($item['#abbr']): ?>
                <?php echo $item['#abbr'] ?>
              <?php else: ?>
                <?php echo $item['#title'] ?>
              <?php endif ?>
          </span>
      </a>
  <?php endforeach; ?>
</div>
