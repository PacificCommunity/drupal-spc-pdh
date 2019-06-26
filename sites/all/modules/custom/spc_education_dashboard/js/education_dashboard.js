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
            
            
            /*
             * Charts configurations and global functions
             */
            
            const red = '#D84774';
            const orange = '#F79663';
            const green = '#00ACB3';
            const grey = '#ccc';
            
            const margin = ({top: 20, right: 0, bottom: 30, left: 40});
            
            function setToolText(svg, className){
                return svg
                    .append("text")
                    .attr("class", className)
                    .attr("width", 30)
                    .attr("height", 30)
                    .attr("fill", "#fff")
                    .attr("text-anchor", "middle")
                    .style("opacity", 0);
            }
            
            function setToolBox(svg){
                return svg
                    .append("rect")   
                    .attr("class", "tipbox")
                    .attr("width", 40)
                    .attr("height", 40)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .style("opacity", 0);
            }
            
            function setX(width){
                return d3
                    .scale
                    .ordinal()
                    .rangeRoundBands([0, width], .1);
            }

            function setY(height){
                return d3
                    .scale
                    .linear()
                    .range([height, 0]);
            }
            
            function setChartSvg(chart, width, height){
                return d3
                    .select(chart)
                    .append("svg")
                    .attr("viewBox", [0, 0, width, height])
                    .append("g");
            }
            
            function setCartBars(svg, data,  x, y, width, height, tooltip, tooltext){
                svg.selectAll(".bar")
                    .data(data)
                    .enter()
                    .append("rect")
                    .transition()
                    .duration(500)
                    .attr("x", function(d) { return x(d.country)+20; })
                    .attr("y", function(d) { return y(d.percentage); })
                    .attr("height", function(d) { return height - y(d.percentage); })
                    .attr("width", 20)
                    .attr("class", "bar")
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", data => data.color)
                    .style("opacity", 1)
                    .delay(function(data,i){ return(i*100)});
        
                setTimeout(function(){
                    svg.selectAll(".bar").remove();
                    svg.selectAll(".bar")
                        .data(data)
                        .enter().append("rect")
                        .attr("class", "bar")
                        .attr("x", function(d) { return x(d.country)+20; })
                        .attr("y", function(d) { return y(d.percentage); })
                        .attr("height", function(d) { return height - y(d.percentage); })
                        .attr("width", 20)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .attr("fill", data => data.color)
                        .style("opacity", 1)
                        .on('mouseover', function(d){
                            tooltip.style("opacity", 1)
                                    .attr("x", x(d.country)+10)
                                    .attr("y", y(d.percentage)-30)
                                    .attr("fill", d.color);

                            tooltext.style("opacity", 1)      
                                    .text(Number((d.percentage).toFixed(1)))  
                                    .attr("x", x(d.country)+30)
                                    .attr("y", y(d.percentage)-7);                            

                        })
                        .on('mouseout', function(d){
                            tooltip.style("opacity", 0);
                            tooltext.style("opacity", 0);
                        });                    
                }, 2000) 
            }
            
            function svgSetLine(svg, x1, y1, x2, y2, stroke){
                svg.append("line")
                    .attr("x1", x1)
                    .attr("y1", y1)
                    .attr("x2", x2)
                    .attr("y2", y2)
                    .attr("stroke", stroke)
                    .attr("stroke-width", 1)
                    .attr("stroke-dasharray", "10");
            }
            
            function svgSetText(svg, x, y, text, fill){
                svg.append("text")
                    .attr("x", x)
                    .attr("y", y)
                    .text(text)
                    .attr("fill", fill);
            }

            //GPD expenditure chart
            if ($('.chart-1').length){
                const id = '1';
                const data = settings.spc_education_dashboard.chart1[0].data;
                
                let height = 300;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                x.domain(data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(data, function(d) { return d.percentage; })]);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
         
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".tooltip-" + id));
            
                setCartBars(svg, data,  x, y, width, height, tooltip, tooltext);
                
                svgSetLine(svg, 40, 59, 580, 60, green);
                svgSetLine(svg, 40, 189, 580, 190, orange);
                
                svgSetText(svg, 0, 20, '18%', green);
                svgSetText(svg, 0, 63, '15%', green);
                svgSetText(svg, 0, 193, '6%', orange);
                svgSetText(svg, 0, 230, '3.8%', red);
                svgSetText(svg, 0, height, '0', grey);
            }
            
            //Out of School Children chart
            if ($('.chart-2').length){
                const id = '2';
                const chart2data = settings.spc_education_dashboard.chart2[0].data;
                
                let height = 450;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                x.domain(chart2data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(chart2data, function(d) { return d.percentage; })]);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".tooltip-" + id));
            
                setCartBars(svg, chart2data,  x, y, width, height, tooltip, tooltext);
                
                svgSetLine(svg, 40, 395, 580, 396, orange);
                svgSetText(svg, 0, 398, '4%', orange);
                
                svgSetLine(svg, 40, 420, 580, 421, green);
                svgSetText(svg, 0, 423, '2%', green);
                
                svgSetText(svg, 0, height, '0', grey);
            }
            
            //Over age students chart
            if ($('.chart-3').length){
                const id = '3';
                const chart3data = settings.spc_education_dashboard.chart3[0].data;
                
                let height = 450;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                x.domain(chart3data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(chart3data, function(d) { return d.percentage; })]);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".tooltip-" + id));
            
                setCartBars(svg, chart3data,  x, y, width, height, tooltip, tooltext);
                
                svgSetLine(svg, 40, 420, 580, 421, green);
                svgSetText(svg, 0, 423, '4%', green);
                
                svgSetText(svg, 0, height, '0', grey);
            }
       
            //Over age students chart
            if ($('.chart-4').length){
                const id = '4';
                const chart4yearLiteracy = settings.spc_education_dashboard.chart4[0].data;
                const chart4yearNumeracy = settings.spc_education_dashboard.chart4[1].data;
                const chart6yearLiteracy = settings.spc_education_dashboard.chart4[2].data;
                const chart6yearNumeracy = settings.spc_education_dashboard.chart4[3].data;

                let height = 400;
                let width = 600;
                
                let x = d3.scale.ordinal()
                    .rangeRoundBands([0, width], .1);

                let y = d3.scale.linear()
                    .range([height, 0]);

                let tip = d3.tip()
                    .attr('class', 'd3-tip')
                    .offset([-230, 0])
                    .html(function(d) {
                      return "<div style='background:" + d.color + "'>" + Number((d.percentage).toFixed(1)) + "</div>";
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
                        .attr("x", function(d) { return x(d.country)+20; })
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
                        .attr("x", function(d) { return x(d.country)+20; })
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