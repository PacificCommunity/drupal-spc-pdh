(function ($) {
    var titles = $('.thematic-group-articles .thematic-group-article-item h4 a')
    if (titles) {
        titles.each(function(){
            var title = this.innerText;
            if (title.length > 40) {
                var shortTitle = $.trim(title).substring(0, 40).split(' ').slice(0, -1).join(' ') + '...';
                this.innerText = shortTitle;
            }
        })
    }

    $('body>div.panel-display').addClass('ma5-page');
        
  /**
   * Element equalheights
   *
   */
  Drupal.behaviors.columnEqualHeights = {
    attach: function (context) {
      $('.view-content').each(function() {
        $(this).children('.eq-col').find('.node-article').matchHeight({
          byRow: true
        });
      });
    }
  };

})(jQuery);

jQuery( document ).ready(function() {
    var block_height = jQuery('.data-insights-list-item .node-data-insights').height();
    jQuery.each(jQuery('.data-insights-list-item'), function(index, value){
        var title_height = jQuery(this).find('.node-data-insights .insight-title').outerHeight(true);
        var preview_height = block_height - title_height;
        var preview = jQuery(this).find('.node-data-insights .insights-list-preview');
        if(jQuery(preview).find('iframe').parents('p').length > 0){
            jQuery(jQuery(preview).find('iframe').parents('p')).height(preview_height);

        }
        jQuery(preview).height(preview_height);
    });
});