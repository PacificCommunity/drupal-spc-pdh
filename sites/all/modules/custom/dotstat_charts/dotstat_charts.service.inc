<?php

class DotStatRenderer {
  private $bean = null;
  public function __construct(string $delta) {
    $this->bean = bean_load($delta);
  }

  private function fieldValue(string ...$fields): array {

    return array_map(
      function($field) {
        return $this->bean->$field[LANGUAGE_NONE][0]['value'] ?? null;
      },
      $fields
    );
  }

  private function getData() {
    list($q, $parser) = $this->fieldValue(
      'field_dotstat_chart_query', 'field_dotstat_chart_parser'
    );
    $cid = 'dotstat_chart_data_' . $this->bean->bid . '_' . md5($q);
    if ($cached = cache_get($cid, 'cache_block')) {
      $data = $cached->data;
    } else {
      $data = DotStatRequest::getParsedResults($q, $parser);
      cache_set($cid, $data, 'cache_block', CACHE_TEMPORARY);
    }

    return $data;
  }

  public function render() {
    if (!$this->bean) {
      return;
    }
    $path = drupal_get_path('module', 'dotstat_charts');
    drupal_add_js($path . '/js/highcharts.js');
    drupal_add_js($path . '/js/exporting.js');
    drupal_add_js($path . '/js/export-data.js');
    drupal_add_js($path . '/js/statchart.js');
    drupal_add_css($path . '/css/style.css');

    $data = $this->getData();
    list($parser, $conf, $link) = $this->fieldValue(
      'field_dotstat_chart_parser',
      'field_dotstat_chart_conf',
      'field_dotstat_chart_link'
    );
    $dtitle = $this->bean->title;

    // generate unique DIV ID attribute
    $did = 'dotstat-'.md5($dtitle);

    // JS variable unique name (DotStatChart object)
    $xid = str_replace('-','_', $did);

    // instanciate JS DotStatChart object
    // get parser settings
    $parser = trim($parser);

    // wait for every external JS to be loaded (Jquery and Highchart) before rendering
    $script = "window.addEventListener('load', function() {\n"
            . "var $xid = new DotStatChart(\"$did\", \"$dtitle\", \"".$link."\", $conf);\n"
            . "{$xid}.gen({$data});\n"
            . "});";
    return '<div id="'.$did.'" hidden>'
                      // add animated loader (SVG)
                      .'<div class="highcharts-chart">'
                      .'<svg viewBox="0 0 135 140" xmlns="http://www.w3.org/2000/svg" class="highcharts-loader"><rect x="0" y="5" width="15" height="140" rx="6"><animate attributeName="height" begin="0s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="30" y="50" width="15" height="100" rx="6"><animate attributeName="height" begin="0.25s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.25s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="60" y="25" width="15" height="120" rx="6"><animate attributeName="height" begin="0.5s" dur="1s" values="90;80;70;60;45;30;140;120;120;110;100" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.5s" dur="1s" values="55;65;75;85;100;115;5;25;25;35;45" calcMode="linear" repeatCount="indefinite" /></rect><rect x="90" y="30" width="15" height="120" rx="6"><animate attributeName="height" begin="0.25s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.25s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="120" y="70" width="15" height="80" rx="6"><animate attributeName="height" begin="0.5s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.5s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect></svg>'
                      .'</div>'
                      // close DIV
                      .'</div>'."\n"
                      // insert Javascript inline (@todo should go to the end of <body>, after JS includes)
                      .'<script>'.$script.'</script>';
  }
}

class DotStatRequest {

  /**
   * get JSON back from .stat API query
   */
  public static function queryRaw($url) {
    try {
      $response = drupal_http_request($url, [
        'headers' => [
          'Accept' => 'text/json',
          // 'If-Modified-Since' => gmdate(DATE_RFC1123, $last_fetched),
        ],
      ]);
      return $response->data;
    }
    catch (Exception $e) {
      watchdog_exception('dotstat_stat', $e);
    }
  }

  /**
   * Internal row parser
   *
   * This is called by getParsedResults method, for each row found in results.
   *
   * Each row is parsed following the $conf parameter, which tells what and where to find data.
   * * `dim[X].Y` gets the Y value in $obs corresponding to $key X position
   * * `val[Z]` gets the value from $arv at Z position
   *
   * For instance, if $conf contains :
   * ```php
   * [
   *   "name": "dim[2].id",
   *   "label": "dim[2].name",
   *   "y": "val[0]"
   * ]
   * ```
   *
   * Returns an array containing the requested data, eg.
   * ```php
   * [
   *   name: 1,
   *   label: 'Column 1',
   *   y: 97
   * ]
   * ```
   *
   * @param string $key key from .stat eg. 0:0:1:0:3:0
   * @param array $arv array of values from .stat
   * @param array $conf array of key => parse definition
   * @param array $obs array of observations definitions provided by .stat
   *
   * @return array Parsed values extracted from $arv and $obs, following $conf definition
   */
  protected static function parseRow($key, $arv, $conf, $obs) {
    $data = [];
    foreach ($conf as $k => $p) {
      $val = null;
      if (preg_match('/^(dim|val)\[(\d+)\](\.(.+))?$/', $p, $red)) {
        switch ($red[1]) {
          case 'dim':
            // gets data from dimensions structure, indexed from observations' key at certain position
            // dim[position].property eg. dim[3].name
            $i = $red[2];
            $n = explode(':',$key)[$i];
            $p = $red[4];
            $val = $obs[$i]['values'][$n][$p];
            break;
          case 'val':
            // gets data from array of observations's value
            // val[position] eg. val[0]
            $i = $red[2];
            $val = $arv[$i];
            break;
        }

      }
      $data[$k] = $val;
    }
    return $data;
  }

  /**
   * Returns parsed JSON results from .stat
   * This is called by DotStatChart block on submit
   *
   * @param string $url .stat API query URL
   * @param string $params parser method parameters
   *
   * @return array Returns array of "JS objects" containing data to visualize
   */
  public static function getParsedResults($url, $params) {
    $raw = json_decode(self::queryRaw($url), true);
    $conf = json_decode($params, true);
    $data = [];
    foreach ($raw['dataSets'][0]['observations'] as $key => $arv) {
      $data[] = self::parseRow($key, $arv, $conf, $raw['structure']['dimensions']['observation']);
    }
    return json_encode($data);
  }

}
