function DotStatChart(id, title, link, opts) {

  this.id = id;
  this.title = title;
  this.sublink = link;

  var btns = ['viewFullscreen','printChart','showDatTable','separator','downloadPNG','downloadPDF','downloadSVG'];
  if (link) {
    btns = ['viewFullscreen','printChart','sourceLink','showDatTable','separator','downloadCVS','downloadPNG','downloadPDF','downloadSVG'];
  }

  // default options
  this.options = {
    title: '',
    subtitle: '',
    type: 'column',
    yAxisLabel: 'Index',
    tooltip: false,
    buttons: btns,
    showTable: false,
    debug: false,
    loader: '<svg viewBox="0 0 135 140" xmlns="http://www.w3.org/2000/svg" class="highcharts-loader"><rect x="0" y="5" width="15" height="140" rx="6"><animate attributeName="height" begin="0s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="30" y="50" width="15" height="100" rx="6"><animate attributeName="height" begin="0.25s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.25s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="60" y="25" width="15" height="120" rx="6"><animate attributeName="height" begin="0.5s" dur="1s" values="90;80;70;60;45;30;140;120;120;110;100" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.5s" dur="1s" values="55;65;75;85;100;115;5;25;25;35;45" calcMode="linear" repeatCount="indefinite" /></rect><rect x="90" y="30" width="15" height="120" rx="6"><animate attributeName="height" begin="0.25s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.25s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect><rect x="120" y="70" width="15" height="80" rx="6"><animate attributeName="height" begin="0.5s" dur="1s" values="120;110;100;90;80;70;60;50;40;140;120" calcMode="linear" repeatCount="indefinite" /><animate attributeName="y" begin="0.5s" dur="1s" values="25;35;45;55;65;75;85;95;105;5;25" calcMode="linear" repeatCount="indefinite" /></rect></svg>'
  };

  // set options from passed argument
  for (var key in this.options) {
    if (opts.hasOwnProperty(key)) {
      this[key] = opts[key];
    } else if (!this[key]) {
      this[key] = this.options[key];
    }
  }

  // @todo check options are valid

  this.initHtml = function() {
    var $d = jQuery('#'+this.id);
    if (!$d[0]) {
      alert('ERR: Target div #'+this.id+' not found');
      return false;
    }
    var tabs = this.showTable || this.debug;
    var html = '';
    if (tabs) {
      html += '<div class="sdd-chart-panel">'
        + '<ul class="nav nav-tabs" id="dotstat-sdg451-tabs" role="tablist">'
        + '<li class="nav-item">'
        + '<a class="nav-link active" data-toggle="tab" href="#'+this.id+'-chart" role="tab" aria-controls="home" aria-selected="true">Chart</a>'
        + '</li>';
      if (this.showTable) {
        html += '<li class="nav-item"><a class="nav-link" data-toggle="tab" href="#'+this.id+'-data-table" role="tab" aria-controls="profile" aria-selected="false">Data Table</a></li>';
      }
      if (this.debug) {
        html += '<li class="nav-item"><a class="nav-link" data-toggle="tab" href="#'+this.id+'-jsondata" role="tab" aria-controls="contact" aria-selected="false">JSON</a></li>';
      }
      html += '</ul>'
        + '<div class="tab-content" id="'+this.id+'-content">'
        + '<div id="'+this.id+'-chart" class="highcharts-chart tab-pane fade show active">'
    } else {
      html += '<div id="'+this.id+'-chart" class="highcharts-chart">';
    }
    html += this.loader
      +'</div>';

    if (this.showTable) {
      html += '<div id="'+this.id+'-data-table" class="highcharts-data-table tab-pane fade">Loading...</div>';
    }
    if (this.debug) {
      html += '<div id="'+this.id+'-jsondata" class="highcharts-jsondata tab-pane fade">...</div>';
    }
    if (tabs) {
      html += '</div></div>';
    }
    if (this.buttons.indexOf('showDatTable') !== -1) {
      html += '<div class="modal fade" id="'+this.id+'-modal"><div class="modal-dialog modal-lg" role="document"><div class="modal-content">'
      +'<div class="modal-header"><div class="modal-title" id="dotstat-sdg451-modal-title">Data Table</div><button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button></div><div class="modal-body highcharts-data-table"></div></div></div></div>';
    }
    $d.html(html);
    $d.attr('hidden', false);
    return true;
  };

  this.parseDotStat = function(data) {
    alert('ERR: Parser method not defined');
    return false;
  };

  // generate chart
  this.render = function() {

    var obj = this;

    obj.dbg('Rendering...');

    this.chart = Highcharts.chart(this.id+'-chart', {
      // credits: { enabled: false },
      exporting: {
        menuItemDefinitions: {
          showDatTable: {
            text: 'Show Data Table',
            onclick: function() {
              jQuery('#'+obj.id+'-modal .modal-body').html(this.getTable());
              jQuery('#'+obj.id+'-modal').modal();
            }
          },
          sourceLink: {
            text: 'View in .stat',
            onclick: function() {
              window.open(obj.sublink.replace(/&amp;/g, "&"), '_blank');
            }
          }
        },
        buttons: {
          contextButton: {
            menuItems: this.buttons
          }
        }
      },
      chart: {
        type: this.type
          // styledMode : true
      },
      title: {
          text: this.title
      },
      subtitle: {
          // text: this.subtitle?this.subtitle:('Source: <a href="'+this.sublink.replace(/&amp;/g, "&")+'" target="_blank">SPC Statistics for Development Division</a>')
          text: this.subtitle?this.subtitle:('Source: SPC Statistics for Development Division')
      },
      xAxis: {
          type: 'category',
          labels: {
              rotation: -45,
              style: {
                  fontSize: '13px',
                  fontFamily: 'Verdana, sans-serif'
              }
          }
      },
      yAxis: {
          min: 0,
          title: {
              text: this.yAxisLabel
          }
      },
      legend: {
          enabled: false
      },
      tooltip: this.tooltip,
      series: [{
        data: this.jsdata
      }]
    }, function() {
      if (obj.showTable ) {
        jQuery('#'+obj.id+'-data-table').html(this.getTable());
      }
    });

  };

  // launch
  this.go = function(data) {
    if (this.initHtml()) {
      if (this.debug) {
        jQuery('#'+this.id+'-jsondata').html(JSON.stringify(data)); //.beautifyJSON();
      }
      this.parseDotStat(data);
      this.render();
    }
  };

  // new launch (no data parsing needed)
  this.gen = function(data) {
    if (this.initHtml()) {
      if (this.debug) {
        jQuery('#'+this.id+'-jsondata').html(JSON.stringify(data)); // .beautifyJSON();
      }
      this.jsdata = data;
      this.render();
    }
  };

  // debug ?
  this.dbg = function(s) {
    if (this.debug) { console.log(s); }
  }

  return this;

}
