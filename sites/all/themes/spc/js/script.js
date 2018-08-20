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

  jQuery('.list-tweets').slick({
    // dots: true,
    infinite: false,
    speed: 600,
    slidesToShow: 4,
    slidesToScroll: 4,
    responsive: [
      {
        breakpoint: 1025,
        settings: {
          arrows: false,
          slidesToShow: 3,
          slidesToScroll: 3,
          autoplay: true,
          autoplaySpeed: 5000,
          infinite: true,
        }
      },
      {
        breakpoint: 992,
        settings: {
          arrows: false,
          slidesToShow: 2,
          slidesToScroll: 2,
          autoplay: true,
          autoplaySpeed: 5000,
          infinite: true,
        }
      },
      {
        breakpoint: 480,
        settings: {
          arrows: false,
          slidesToShow: 1,
          slidesToScroll: 1,
          autoplay: true,
          autoplaySpeed: 5000,
          infinite: true,
        }
      }
    ]
  });
  console.log($('body'));
});