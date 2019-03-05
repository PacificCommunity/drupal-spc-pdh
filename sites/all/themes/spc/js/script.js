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

  var wrapper_loader ="<div class='loading-more-element'>" 
  var the_loader = "<div class='lds-spinner'><div></div><div></div><div></div><div></div><div></div><div></div><div></div><div></div><div></div><div></div><div></div><div></div></div>";
  var full_loading = wrapper_loader + the_loader + "<div class='load-more'> Load more</div></div>"
  $('.view-data-insights-list-page').append(full_loading)
  $(window).on('scroll', function (){
    var loader_btn = $('.loading-more-element').offset().top + 100
    var scrolloffset = window.pageYOffset
    var scouterHeight = window.outerHeight
    if ((scrolloffset + scouterHeight) > loader_btn) {
      $('.pager-show-more .pager-show-more-next a').click()
    } 
  })

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

  if ($('.data-insights-promoted-group').length > 0 && $('.data-insights-promoted-group .slick-dots li').length > 0) {
    let slides_num_di = $('.data-insights-promoted-group .slick-dots li').length;
    let slide = $('.data-insights-promoted-group .slick-dots .slick-active button').text();
    $('.data-insights-promoted-group').append(`<div class="slide-number"><strong>${slide}</strong> of <strong>${slides_num_di}</strong></div>`);
    $('.data-insights-promoted-group .slick-arrow').on('click', function(){
      slide = $('.data-insights-promoted-group .slick-dots .slick-active button').text();
      $('.data-insights-promoted-group .slide-number').html(`<strong>${slide}</strong> of <strong>${slides_num_di}</strong>`);
    });
  };

  
  $('.latest-stories-homepage .field-item').each(function(i) {
    let title_block = $(this).find('.views-field-title');
    if (title_block.length > 0) {
      let num = i + 1;
      title_block.prepend(`<div class="slide-num">${num <= 9 ? '0'+num : num}</div>`)
    }
  })

  $('.stories-list').slick({
    slidesToShow: 3,
      dots: true,
      responsive: [
        {
          breakpoint: 768,
          settings: {
            slidesToShow: 1,
            arrows: false
          }
        }
      ]
  });
  
  if ($('.latest-stories-homepage').length > 0 && $('.latest-stories-homepage .slick-dots li').length > 0) {
    let slides_num_stories = $('.latest-stories-homepage .slick-dots li').length;
    let slide = $('.latest-stories-homepage .slick-dots .slick-active button').text();
    $('.latest-stories-homepage').append(`<div class="slide-number"><strong>${slide}</strong> of <strong>${slides_num_stories}</strong></div>`);
    $('.latest-stories-homepage .slick-arrow').on('click', function(){
      slide = $('.latest-stories-homepage .slick-dots .slick-active button').text();
      $('.latest-stories-homepage .slide-number').html(`<strong>${slide}</strong> of <strong>${slides_num_stories}</strong>`);
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

})(jQuery);
