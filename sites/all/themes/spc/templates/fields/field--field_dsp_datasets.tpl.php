<?php if ($element['datasets_info']): ?>
  <ul class="dsp-datasets">
    <?php foreach ($element['datasets_info'] as $dataset) { ?>
      <li class="dataset-preview">
        <p class="dataset-title">
          <?php 
            $ckan_url = variable_get('govcms_ckan_endpoint_url', ''); 
            $dataset_url = $ckan_url.'/dataset/'.$dataset->name;
          ?>
          <a href="<?= $dataset_url ?>">
            <?= $dataset->title; ?>
          </a>
        </p>
        <p class="dataset-date">Last Updated on: <span><?= date_format(date_create($dataset->metadata_modified), 'F j, Y'); ?></span></p>
        <div class="dataset-formats">File Format: 
          <?php foreach ($dataset->resources as $res) { ?>
            <span>
              <?php if ($res->format) {
                print(strtoupper($res->format));
              } else {
                print('DATA');
              } ?>
            </span>
          <?php } ?>
        </div>
      </li>
    <?php } ?>
  </ul>
<?php endif; ?>
