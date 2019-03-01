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
      $('.articles-list').each(function() {
        $(this).find('.eq-col').find('.node-article').matchHeight({
          byRow: true
        });
      });
    }
  };

  /**
   * Element niceSelect
   *
   */
  Drupal.behaviors.niceSelect = {
    attach: function (context) {
      $('.node-type-thematic-group #ckan-search-form select').niceSelect();
    }
  };

  var dataset_titles = $('.dataset-preview .dataset-title a');
  dataset_titles.each((ind, tiitle) => {
    $(tiitle).dotdotdot({
      height: 50
    });
  })


$( document ).ready(function() {

  var block_height = $('.data-insights-list-item .node-data-insights').height();
  $.each($('.data-insights-list-item'), function(index, value){
      var title_height = $(this).find('.node-data-insights .insight-title').outerHeight(true);
      var preview_height = block_height - title_height;
      var preview = $(this).find('.node-data-insights .insights-list-preview');
      if($(preview).find('iframe').parents('p').length > 0){
          $($(preview).find('iframe').parents('p')).height(preview_height);

      }
      $(preview).height(preview_height);
  });

  $('.list-tweets').slick({
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


  $('.data-insights-promoted-group').slick({
    slidesToShow: 3,
    centerMode: true,
    variableWidth: true,
    dots: true,
    responsive: [
      {
        breakpoint: 768,
        settings: {
          arrows: false
        }
      }
    ]
  });

  var slides_num = $('.slick-dots li').length;
  if ($('.data-insights-promoted-group').length > 0 && slides_num > 0) {
    var slide = $('.slick-dots .slick-active button').text();
    $('.data-insights-promoted-group').append(`<div class="slide-number"><strong>${slide}</strong> of <strong>${slides_num}</strong></div>`);
    $('.slick-arrow').on('click', function(){
      slide = $('.slick-dots .slick-active button').text();
      $('.slide-number').html(`<strong>${slide}</strong> of <strong>${slides_num}</strong>`);
    });
  };

  
  $('.ckan-dataset-tab-container .carusel-of-items').slick({
    dots: false,
    infinite: true,
    speed: 600,
    arrows: false,
    slidesToShow: 1,
    slidesToScroll: 1,
    centerMode: true,
  });

  $('#nav-popular-datasets-tab').on('click', function(){
    var slide_center = $('#nav-popular-datasets .ckan-dataset-tab-container .carusel-of-items').find('.slick-center').first();
    if (slide_center.length == 1 && slide_center.width() < 0) {
      $('#nav-popular-datasets .ckan-dataset-tab-container .carusel-of-items').slick('refresh');
    } 
  })
});

$('.stories-list').slick({
  slidesToShow: 3,
  dots: true,
});

})(jQuery);
