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
            
            const red = '#D84774';
            const orange = '#F79663';
            const green = '#00ACB3';

            //GPD expenditure chart
            if ($('.chart-1').length){
                const data = settings.spc_education_dashboard.chart1[0].data;
                
                let height = 300;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});

                let x = d3.scaleBand()
                    .domain(data.map(d => d.country))
                    .range([margin.left, width - margin.right])
                    .padding(0.1);
                    
                let y = d3.scaleLinear()
                    .domain([0, d3.max(data, d => d.percentage)]).nice()
                    .range([height - margin.bottom, margin.top]);
            
                let yAxis = g => g
                    .attr("transform", `translate(${margin.left},0)`)
                    .call(d3.axisLeft(y))
                    .call(g => g.select(".domain").remove());
            
                const svg = d3                    
                    .select(".chart-1")
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height]);
            
                //svg.append("g").call(yAxis);

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
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 59)
                    .attr("x2", 580)
                    .attr("y2", 60)
                    .attr("stroke", green)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 189)
                    .attr("x2", 580)
                    .attr("y2", 190)
                    .attr("stroke", orange)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 63)
                    .text("15%")
                    .attr("fill", green);
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 20)
                    .text("18%")
                    .attr("fill", green);
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 193)
                    .text("6%")
                    .attr("fill", orange);
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 230)
                    .text("3.8%")
                    .attr("fill", red);
            
            }
            
            //Out of School Children chart
            if ($('.chart-2').length){
                const chart2data = settings.spc_education_dashboard.chart2[0].data;
                
                let height = 450;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});

                let x = d3.scaleBand()
                    .domain(chart2data.map(d => d.country))
                    .range([margin.left, width - margin.right])
                    .padding(0.1);
                    
                let y = d3.scaleLinear()
                    .domain([0, d3.max(chart2data, d => d.percentage)]).nice()
                    .range([height - margin.bottom, margin.top]);
            
                let yAxis = g => g
                    .attr("transform", `translate(${margin.left},0)`)
                    .call(d3.axisLeft(y))
                    .call(g => g.select(".domain").remove());

                const svg = d3                    
                    .select(".chart-2")
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height]);
            
                //svg.append("g").call(yAxis);

                svg.append("g")
                    .attr("fill", "steelblue")
                    .selectAll("rect")
                    .data(chart2data)
                    .join("rect")
                    .attr("x", chart2data => x(chart2data.country))
                    .attr("y", chart2data => y(chart2data.percentage))
                    .attr("height", d => y(0) - y(d.percentage))
                    .attr("width", 20)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", chart2data => chart2data.color);
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 400)
                    .attr("x2", 580)
                    .attr("y2", 401)
                    .attr("stroke", green)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 375)
                    .attr("x2", 580)
                    .attr("y2", 376)
                    .attr("stroke", orange)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 378)
                    .text("4%")
                    .attr("fill", orange);
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 403)
                    .text("2%")
                    .attr("fill", green);

            }
            
            //Over age students chart
            if ($('.chart-3').length){
                const chart3data = settings.spc_education_dashboard.chart3[0].data;
                
                let height = 450;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});

                let x = d3.scaleBand()
                    .domain(chart3data.map(d => d.country))
                    .range([margin.left, width - margin.right])
                    .padding(0.1);
                    
                let y = d3.scaleLinear()
                    .domain([0, d3.max(chart3data, d => d.percentage)]).nice()
                    .range([height - margin.bottom, margin.top]);
            
                let yAxis = g => g
                    .attr("transform", `translate(${margin.left},0)`)
                    .call(d3.axisLeft(y))
                    .call(g => g.select(".domain").remove());

                const svg = d3                    
                    .select(".chart-3")
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height]);
            
                //svg.append("g").call(yAxis);
                
                svg.append("g")
                    .attr("fill", "steelblue")
                    .selectAll("rect")
                    .data(chart3data)
                    .join("rect")
                    .attr("x", chart3data => x(chart3data.country))
                    .attr("y", chart3data => y(chart3data.percentage))
                    .attr("height", d => y(0) - y(d.percentage))
                    .attr("width", 20)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", chart3data => chart3data.color);
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 400)
                    .attr("x2", 580)
                    .attr("y2", 401)
                    .attr("stroke", green)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 403)
                    .text("4%")
                    .attr("fill", green);
            }
            
            //Over age students chart
            if ($('.chart-4').length){
                const chart4data = settings.spc_education_dashboard.chart4[0].data;
                
                console.log(chart4data);
                
                let height = 400;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});

                let x = d3.scaleBand()
                    .domain(chart4data.map(d => d.country))
                    .range([margin.left, width - margin.right])
                    .padding(0.1);
                    
                let y = d3.scaleLinear()
                    .domain([0, d3.max(chart4data, d => d.percentage)]).nice()
                    .range([height - margin.bottom, margin.top]);
            
                let yAxis = g => g
                    .attr("transform", `translate(${margin.left},0)`)
                    .call(d3.axisLeft(y))
                    .call(g => g.select(".domain").remove());

                const svg = d3                    
                    .select(".chart-4")
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height]);
            
               // svg.append("g").call(yAxis);

                svg.append("g")
                    .attr("fill", "steelblue")
                    .selectAll("rect")
                    .data(chart4data)
                    .join("rect")
                    .attr("x", chart4data => x(chart4data.country))
                    .attr("y", function(chart4data){
                        let pos = 200;
                        if (chart4data.base == 1){
                            pos = y(chart4data.percentage)/2;
                        }
                        return pos;
                    })
                    .attr("height", d => (y(0) - y(d.percentage))/2)
                    .attr("width", 20)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", chart4data => chart4data.color);
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 194)
                    .attr("x2", 580)
                    .attr("y2", 195)
                    .attr("stroke", "#ccc")
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 198)
                    .text("0")
                    .attr("fill", "#ccc");
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 165)
                    .attr("x2", 580)
                    .attr("y2", 166)
                    .attr("stroke", green)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 169)
                    .text("1%")
                    .attr("fill", green);
            
                svg.append("line")
                    .attr("x1", 40)
                    .attr("y1", 220)
                    .attr("x2", 580)
                    .attr("y2", 221)
                    .attr("stroke", orange)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", 224)
                    .text("-1%")
                    .attr("fill", orange);
            
            }
            
            
        //end context
        }
    };
}(jQuery));