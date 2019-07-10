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
    <ul class="nav__list">
        <li>
            <input id="group-1" type="checkbox" hidden />
            <label for="group-1"> First level</label><span class="fa fa-angle-down"></span>
            <ul class="group-list">
                <li><a href="#">1st level item</a></li>
                <li>
                    <input id="sub-group-1" type="checkbox" hidden />
                    <label for="sub-group-1"><span class="fa fa-angle-right"></span> Second level</label>
                    <ul class="sub-group-list">
                        <li><a href="#">2nd level nav item</a></li>
                        <li><a href="#">2nd level nav item</a></li>
                        <li><a href="#">2nd level nav item</a></li>
                        <li>
                            <input id="sub-sub-group-1" type="checkbox" hidden />
                            <label for="sub-sub-group-1"><span class="fa fa-angle-right"></span> Third level</label>
                            <ul class="sub-sub-group-list">
                                <li><a href="#">3rd level nav item</a></li>
                                <li><a href="#">3rd level nav item</a></li>
                                <li><a href="#">3rd level nav item</a></li>
                            </ul>
                        </li>
                    </ul>
                </li>
            </ul>
        </li>
        <li>
            <input id="group-2" type="checkbox" hidden />
            <label for="group-2">First level</label><span class="fa fa-angle-down"></span>
            <ul class="group-list">
                <li>
                <li><a href="#">1st level item</a></li>
                <li><a href="#">1st level item</a></li>
                <input id="sub-group-2" type="checkbox" hidden />
                <label for="sub-group-2"><span class="fa fa-angle-right"></span> Second level</label>
                <ul class="sub-group-list">
                    <li><a href="#">2nd level nav item</a></li>
                    <li><a href="#">2nd level nav item</a></li>
                    <li>
                        <input id="sub-sub-group-2" type="checkbox" hidden />
                        <label for="sub-sub-group-2"><span class="fa fa-angle-right"></span> Third level</label>
                        <ul class="sub-sub-group-list">
                            <li><a href="#">3rd level nav item</a></li>
                        </ul>
                    </li>
                </ul>
                </li>
            </ul>
        </li>
        <li>
            <input id="group-3" type="checkbox" hidden />
            <label for="group-3"><span class="fa fa-angle-right"></span> First level</label>
            <ul class="group-list">
                <li>
                <li><a href="#">1st level item</a></li>
                <li><a href="#">1st level item</a></li>
                <input id="sub-group-3" type="checkbox" hidden />
                <label for="sub-group-3"><span class="fa fa-angle-right"></span> Second level</label>
                <ul class="sub-group-list">
                    <li><a href="#">2nd level nav item</a></li>
                    <li><a href="#">2nd level nav item</a></li>
                    <li><a href="#">2nd level nav item</a></li>
                    <li>
                        <input id="sub-sub-group-3" type="checkbox" hidden />
                        <label for="sub-sub-group-3"><span class="fa fa-angle-right"></span> Third level</label>
                        <ul class="sub-sub-group-list">
                            <li><a href="#">3rd level nav item</a></li>
                            <li><a href="#">3rd level nav item</a></li>
                            <li><a href="#">3rd level nav item</a></li>
                        </ul>
                    </li>
                </ul>
                </li>
            </ul>
        </li>
        <li>
            <input id="group-4" type="checkbox" hidden />
            <label for="group-4"><span class="fa fa-angle-right"></span> First level</label>
            <ul class="group-list">
                <li>
                <li><a href="#">1st level item</a></li>
                <input id="sub-group-4" type="checkbox" hidden />
                <label for="sub-group-4"><span class="fa fa-angle-right"></span> Second level</label>
                <ul class="sub-group-list">
                    <li><a href="#">2nd level nav item</a></li>
                    <li><a href="#">2nd level nav item</a></li>
                </ul>
                </li>
            </ul>
        </li>
    </ul>
</div>
