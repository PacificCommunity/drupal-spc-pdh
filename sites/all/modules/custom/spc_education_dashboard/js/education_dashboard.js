(function ($) {
    Drupal.behaviors.educationDashboard = {
        attach: function (context, settings) {
        //start context
        
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
  
            //GPD expenditure chart
            if ($('.chart-1').length){
                const data = settings.spc_education_dashboard.chart1[0].data;
                
                
                
                const height = 300;
                const width = 600;
                
                const margin = ({top: 20, right: 0, bottom: 30, left: 40});
                
                let x = d3.scaleBand()
                    .domain(data.map(d => d.country))
                    .range([margin.left, width - margin.right])
                    .padding(0.1);
                    
                let y = d3.scaleLinear()
                    .domain([0, d3.max(data, d => d.percentage)]).nice()
                    .range([height - margin.bottom, margin.top]);
            
                const svg = d3                    
                    .select(".chart-1")
                    .append('svg')
                    .attr("viewBox", [0, 0, width, height]);

                svg.append("g")
                    .attr("fill", "steelblue")
                    .selectAll("rect")
                    .data(data)
                    .join("rect")
                    .attr("x", data => x(data.country))
                    .attr("y", data => y(data.percentage))
                    .attr("height", d => y(0) - y(d.percentage))
                    .attr("width", 20)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", data => data.color);
            }
            
            //Out of School Children chart
            if ($('.chart-2').length){

            }
            
            
        //end context
        }
    };
}(jQuery));