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
            
            //chart block description toggle
            $('.toggle').on('click', function(){
               var active = $(this).siblings('p').hasClass('hidden');
                
               $(this).closest('.description').find('p').addClass('hidden'); 
               $(this).closest('.description').find('.arrow').removeClass('down'); 

                if (active){
                    $(this).siblings('p').removeClass('hidden');
                    $(this).find('.arrow').toggleClass('down');
                }
            });
            
            const red = '#D84774';
            const orange = '#F79663';
            const green = '#00ACB3';

            //GPD expenditure chart
            if ($('.chart-1').length){
                const data = settings.spc_education_dashboard.chart1[0].data;
                
                const height = 300;
                const width = 600;
                const margin = ({top: 20, right: 0, bottom: 30, left: 40});

                const x = d3.scale.ordinal()
                    .rangeRoundBands([0, width], .1);

                const y = d3.scale.linear()
                    .range([height, 0]);

                const tip = d3.tip()
                    .attr('class', 'd3-tip')
                    .offset([-margin.top, 0])
                    .html(function(d) {
                      return "<div style='background:" + d.color + "'>" + d.percentage + "</div>";
                    });

                const svg = d3.select(".chart-1").append("svg")
                    .attr("viewBox", [0, 0, width, height])
                    .append("g");

                svg.call(tip);

                x.domain(data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(data, function(d) { return d.percentage; })]);

                svg.selectAll(".bar")
                        .data(data)
                        .enter()
                        .append("rect")
                        .transition()
                        .duration(500)
                        .attr("x", function(d) { return x(d.country); })
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("width", 20)
                        .attr("class", "bar")
                        .attr("fill", data => data.color)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .delay(function(data,i){ return(i*100)})
              
                if ($(".chart-1 svg").length){
                    setTimeout(function(){
                        svg.selectAll(".bar").remove();

                        svg.selectAll(".bar")
                            .data(data)
                            .enter().append("rect")
                            .attr("class", "bar")
                            .attr("x", function(d) { return x(d.country); })
                            .attr("width", x.rangeBand())
                            .attr("y", function(d) { return y(d.percentage); })
                            .attr("height", function(d) { return height - y(d.percentage); })
                            .attr("fill", data => data.color)
                            .attr("width", 20)
                            .attr("rx", 10)
                            .attr("ry", 10)
                            .on('mouseover', tip.show)
                            .on('mouseout', tip.hide) 
                    }, 2000)
                }  
                
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
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", height)
                    .text("0")
                    .attr("fill", "#ccc");
            
            }
            
            //Out of School Children chart
            if ($('.chart-2').length){
                const chart2data = settings.spc_education_dashboard.chart2[0].data;
                
                let height = 450;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});

                let x = d3.scale.ordinal()
                    .rangeRoundBands([0, width], .1);

                let y = d3.scale.linear()
                    .range([height, 0]);

                let tip = d3.tip()
                    .attr('class', 'd3-tip')
                    .offset([-100, 0])
                    .html(function(d) {
                      return "<div style='background:" + d.color + "'>" + d.percentage + "</div>";
                    });

                let svg = d3.select(".chart-2").append("svg")
                    .attr("viewBox", [0, 0, width, height])
                    .append("g");

                svg.call(tip);

                x.domain(chart2data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(chart2data, function(d) { return d.percentage; })]);

                svg.selectAll(".bar")
                        .data(chart2data)
                        .enter()
                        .append("rect")
                        .transition()
                        .duration(500)
                        .attr("x", function(d) { return x(d.country); })
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("width", 20)
                        .attr("class", "bar")
                        .attr("fill", chart2data => chart2data.color)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .delay(function(chart2data,i){ return(i*100)})
              
                setTimeout(function(){
                    svg.selectAll(".bar").remove();

                    svg.selectAll(".bar")
                        .data(chart2data)
                        .enter().append("rect")
                        .attr("class", "bar")
                        .attr("x", function(d) { return x(d.country); })
                        .attr("width", x.rangeBand())
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("fill", chart2data => chart2data.color)
                        .attr("width", 20)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .on('mouseover', tip.show)
                        .on('mouseout', tip.hide) 
                }, 2000)
            
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
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", height)
                    .text("0")
                    .attr("fill", "#ccc");

            }
            
            //Over age students chart
            if ($('.chart-3').length){
                const chart3data = settings.spc_education_dashboard.chart3[0].data;
                
                let height = 450;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});
                
                let x = d3.scale.ordinal()
                    .rangeRoundBands([0, width], .1);

                let y = d3.scale.linear()
                    .range([height, 0]);

                let tip = d3.tip()
                    .attr('class', 'd3-tip')
                    .offset([-180, 0])
                    .html(function(d) {
                      return "<div style='background:" + d.color + "'>" + d.percentage + "</div>";
                    });

                let svg = d3.select(".chart-3").append("svg")
                    .attr("viewBox", [0, 0, width, height])
                    .append("g");

                svg.call(tip);

                x.domain(chart3data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(chart3data, function(d) { return d.percentage; })]);

                svg.selectAll(".bar")
                        .data(chart3data)
                        .enter()
                        .append("rect")
                        .transition()
                        .duration(500)
                        .attr("x", function(d) { return x(d.country); })
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("width", 20)
                        .attr("class", "bar")
                        .attr("fill", chart3data => chart3data.color)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .delay(function(chart3data,i){ return(i*100)})
              
                setTimeout(function(){
                    svg.selectAll(".bar").remove();

                    svg.selectAll(".bar")
                        .data(chart3data)
                        .enter().append("rect")
                        .attr("class", "bar")
                        .attr("x", function(d) { return x(d.country); })
                        .attr("width", x.rangeBand())
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("fill", chart3data => chart3data.color)
                        .attr("width", 20)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .on('mouseover', tip.show)
                        .on('mouseout', tip.hide) 
                }, 2000)
                
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
            
                svg.append("text")
                    .attr("x", 0)
                    .attr("y", height)
                    .text("0")
                    .attr("fill", "#ccc");
            }
       
            //Over age students chart
            if ($('.chart-4').length){

                const chart4yearLiteracy = settings.spc_education_dashboard.chart4[0].data;
                const chart4yearNumeracy = settings.spc_education_dashboard.chart4[1].data;
                const chart6yearLiteracy = settings.spc_education_dashboard.chart4[2].data;
                const chart6yearNumeracy = settings.spc_education_dashboard.chart4[3].data;

                let height = 400;
                let width = 600;
                let margin = ({top: 20, right: 0, bottom: 30, left: 40});
                
                let x = d3.scale.ordinal()
                    .rangeRoundBands([0, width], .1);

                let y = d3.scale.linear()
                    .range([height, 0]);

                let tip = d3.tip()
                    .attr('class', 'd3-tip')
                    .offset([-230, 0])
                    .html(function(d) {
                      return "<div style='background:" + d.color + "'>" + d.percentage + "</div>";
                    });

                let svg = d3.select(".chart-4").append("svg")
                    .attr("viewBox", [0, 0, width, height])
                    .append("g")

                svg.call(tip);

                x.domain(chart4yearLiteracy.map(function(d) { return d.country; }));
                y.domain([0, d3.max(chart4yearLiteracy, function(d) { return d.percentage; })]);

                svg.selectAll(".bar")
                        .data(chart4yearLiteracy)
                        .enter()
                        .append("rect")
                        .transition()
                        .duration(500)
                        .attr("x", function(d) { return x(d.country); })
                        .attr("y", function(chart4yearLiteracy){
                                let pos = 200;
                                if (chart4yearLiteracy.base == 1){
                                    pos = y(chart4yearLiteracy.percentage)/2;
                                }
                                return pos;
                            })
                        .attr("height", d => (y(0) - y(d.percentage))/2)
                        .attr("width", 20)
                        .attr("class", "bar")
                        .attr("fill", chart4yearLiteracy => chart4yearLiteracy.color)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .delay(function(chart4yearLiteracy,i){ return(i*100)})
              

                setTimeout(function(){
                    svg.selectAll(".bar").remove();

                    svg.selectAll(".bar")
                        .data(chart4yearLiteracy)
                        .enter().append("rect")
                        .attr("class", "bar")
                        .attr("x", function(d) { return x(d.country); })
                        .attr("width", x.rangeBand())
                        .attr("y", function(chart4yearLiteracy){
                            let pos = 200;
                            if (chart4yearLiteracy.base == 1){
                                pos = y(chart4yearLiteracy.percentage)/2;
                            }
                            return pos;
                        })
                        .attr("height", d => (y(0) - y(d.percentage))/2)
                        .attr("fill", chart4yearLiteracy => chart4yearLiteracy.color)
                        .attr("width", 20)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .on('mouseover', tip.show)
                        .on('mouseout', tip.hide) 
                }, 2000)
               
           
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
                    
                //enable switcher    
                $.switcher('input.slider');
                
                $('.ui-switcher').on('click', function(){
                    
                    var newData = [];                    
                    
                    $(this).closest('.switch-wrapper').find('.labels p').toggleClass('checked');
                    svg.selectAll("rect").remove();
                    
                    if ($(this).attr('aria-checked') == 'true' ){
                        newData = chart4yearNumeracy;
                    } else {
                        newData = chart4yearLiteracy;
                    }

                    svg.selectAll(".bar")
                            .data(newData)
                            .enter()
                            .append("rect")
                            .transition()
                            .duration(500)
                            .attr("x", function(d) { return x(d.country); })
                            .attr("y", function(newData){
                                    let pos = 200;
                                    if (newData.base == 1){
                                        pos = y(newData.percentage)/2;
                                    }
                                    return pos;
                                })
                            .attr("height", d => (y(0) - y(d.percentage))/2)
                            .attr("width", 20)
                            .attr("class", "bar")
                            .attr("fill", newData => newData.color)
                            .attr("rx", 10)
                            .attr("ry", 10)
                            .delay(function(newData,i){ return(i*100)})

                    setTimeout(function(){
                        svg.selectAll(".bar").remove();

                        svg.selectAll(".bar")
                            .data(newData)
                            .enter().append("rect")
                            .attr("class", "bar")
                            .attr("x", function(d) { return x(d.country); })
                            .attr("width", x.rangeBand())
                            .attr("y", function(newData){
                                let pos = 200;
                                if (newData.base == 1){
                                    pos = y(newData.percentage)/2;
                                }
                                return pos;
                            })
                            .attr("height", d => (y(0) - y(d.percentage))/2)
                            .attr("fill", newData => newData.color)
                            .attr("width", 20)
                            .attr("rx", 10)
                            .attr("ry", 10)
                            .on('mouseover', tip.show)
                            .on('mouseout', tip.hide) 
                    }, 2000)
                });

                $('.switcher a').on('click', function(e){
                    e.preventDefault();
                    $(this).closest('.switchers').find('.switcher a').removeClass('checked');
                    $(this).toggleClass('checked');
                    
                    var newData = [];
                    
                    if ($(this).attr('id') == 'numeracy'){
                        newData = chart6yearNumeracy;
                    } else {
                        newData = chart6yearLiteracy;
                    }
                    
                    svg.selectAll("rect").remove();
                    
                    svg.selectAll(".bar")
                            .data(newData)
                            .enter()
                            .append("rect")
                            .transition()
                            .duration(500)
                            .attr("x", function(d) { return x(d.country); })
                            .attr("y", function(newData){
                                    let pos = 200;
                                    if (newData.base == 1){
                                        pos = y(newData.percentage)/2;
                                    }
                                    return pos;
                                })
                            .attr("height", d => (y(0) - y(d.percentage))/2)
                            .attr("width", 20)
                            .attr("class", "bar")
                            .attr("fill", newData => newData.color)
                            .attr("rx", 10)
                            .attr("ry", 10)
                            .delay(function(newData,i){ return(i*100)})

                    setTimeout(function(){
                        svg.selectAll(".bar").remove();

                        svg.selectAll(".bar")
                            .data(newData)
                            .enter().append("rect")
                            .attr("class", "bar")
                            .attr("x", function(d) { return x(d.country); })
                            .attr("width", x.rangeBand())
                            .attr("y", function(newData){
                                let pos = 200;
                                if (newData.base == 1){
                                    pos = y(newData.percentage)/2;
                                }
                                return pos;
                            })
                            .attr("height", d => (y(0) - y(d.percentage))/2)
                            .attr("fill", newData => newData.color)
                            .attr("width", 20)
                            .attr("rx", 10)
                            .attr("ry", 10)
                            .on('mouseover', tip.show)
                            .on('mouseout', tip.hide) 
                    }, 2000)
                    
                });            
            
            }
            
            
        //end context
        }
    };
}(jQuery));