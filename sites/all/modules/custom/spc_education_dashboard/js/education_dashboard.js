(function ($) {
    Drupal.behaviors.educationDashboard = {
      attach: function (context, settings) {

          const availableTags = [];
          let availableItems = {};
          
          $('.title-text').each(function(){
              availableTags.push($(this).text());
              availableItems[$(this).attr('id')] = $(this).text()
          });
          
          function getKeyByValue(object, value) {
            return Object.keys(object).find(key => object[key] === value);
          }

          $('#education-dashboard-search').autocomplete({
            source: availableTags,
            select: function( event, ui ) {
                
                let itemValue = ui.item.value;
                
                let itemKey = getKeyByValue(availableItems, itemValue)
                
                $([document.documentElement, document.body]).animate({
                    scrollTop: $("#" + itemKey).offset().top
                }, 100);
            }
          });

      }
    };
}(jQuery));