<div class="health-home-description">
  <?php if (!empty($data['background'])): ?> 
    <div>
      <h4 class="title-text"><?php print t('Background'); ?> </h4>
      <?php $background = $data['background']; ?> 
      <?php $limit = 300; ?>
      <span class="less"><?php print substr($background, 0, $limit); ?></span>
      <?php if (strlen($background) > $limit): ?>
        <span class="dots"><?php print t('...'); ?></span>
      <?php endif; ?>
      <span class="more"><?php print substr($background, $limit+1, strlen($background)); ?></span>
      <?php if (strlen($background) > $limit): ?>
        <p class="more-less show-more"><?php print t('Read more'); ?></p>
      <?php endif; ?>
    </div>  
  <?php endif; ?>

  <?php if (!empty($data['methods'])): ?>
    <div>
      <h4 class="title-text"><?php print t(''); ?> </h4>
      <?php $methods = $data['methods']; ?> 
      <?php $limit = 300; ?>
      <span class="less"><?php print substr($methods, 0, $limit); ?></span>
      <?php if (strlen($methods) > $limit): ?>
        <span class="dots"><?php print t('...'); ?></span>
      <?php endif; ?>
      <span class="more"><?php print substr($methods, $limit+1, strlen($methods)); ?></span>
      <?php if (strlen($methods) > $limit): ?>
        <p class="more-less show-more"><?php print t('Read more'); ?></p>
      <?php endif; ?>
    </div>  
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
        <div class="chart-pdf-export">
            <a target="_blank"href="<?php print $data['chart-pdf-export']; ?>"></a>
          <div class="chart-pdf-text">
            <p><strong><?php print t('Download pdf file'); ?></strong></p>
            <p><?php print t('Summary of status of indicators across the categories (%) across the 21 PICTs'); ?></p>
          </div>
        </div>
    </div>    
</div>

<div class="health-dashboard-categories">
    <h4><?php echo t('NCD Response Areas') ?> </h4>
    <ul class="nav__list">
        <?php foreach ($data['categories'] as $key => $item): ?>
        <li class="<?php echo $key ?>">
            <input id="group-<?php echo $key ?>" type="checkbox" hidden />
            <label for="group-<?php echo $key ?>" class="first-level">
                <?php if ($key != 'wrapper'): ?>
                <a href="<?php echo HEALTH_DASHBOARD_URL . '/' . $key ?>">
                  <?php echo $item['#title'] ?>
                </a>
                <?php else: ?>
                    <?php echo $item['#title'] ?>
                <?php endif; ?>
                <span class="category-toggle">
                    <span class="fa fa-angle-down"></span>
                </span>
            </label>
            <ul class="group-list">
              <?php foreach ($item['#indicators'] as $key2 => $item2): ?>
                <?php if (isset($item2['#indicators'])): ?>
                  <li>
                      <input id="sub-group-<?php echo $key2 ?>" type="checkbox" hidden />
                      <label for="sub-group-<?php echo $key2 ?>" class="indicator">
                        <a class="subcategory" href="<?php echo HEALTH_DASHBOARD_URL . '/' . $key2 ?>">
                            <?php echo $item2['#title'] ?>
                        </a>
                        <span class="fa fa-angle-down"></span>
                      </label>
                        <ul class="sub-group-list">
                        <?php foreach ($item2['#indicators'] as $key3 => $item3): ?>
                            <li>
                              <a href="<?php echo HEALTH_DASHBOARD_URL . '/' . $key2 . '/' . $key3 ?>">
                                <?php echo $item3['code'] . '. ' . $item3['title'] ?>
                              </a>
                            </li>
                        <?php endforeach; ?>
                      </ul>
                  </li>
                <?php else: ?>
                  <li>
                      <input id="sub-group-<?php echo $key2 ?>" type="checkbox" hidden />
                      <label for="sub-group-<?php echo $key2 ?>">
                        <a href="<?php echo HEALTH_DASHBOARD_URL . '/' . $key . '/' . $key2 ?>">
                            <?php echo $item2['code'] .'. '. $item2['title'] ?>
                        </a>
                      </label>
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
