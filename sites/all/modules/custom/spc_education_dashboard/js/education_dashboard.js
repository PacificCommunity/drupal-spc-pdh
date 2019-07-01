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
               let active = $(this).siblings('p').hasClass('hidden');
                
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
            
            function appendTolltip(id){
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".tooltip-" + id));
            }
            
            function setX(width){
                return d3
                    .scale
                    .ordinal()
                    .rangeRoundBands([0, width], .1);
            }
            
            function setXg(){
                 return d3
                    .scale
                    .ordinal();
            }

            function setY(height){
                return d3
                    .scale
                    .linear()
                    .range([height, 0]);
            }
            
            function setChartSvg(chart, width, height, className){
                return d3
                    .select(chart)
                    .append("svg")
                    .attr('class', className)
                    .attr("viewBox", [0, 0, width, height])
                    .append("g");
            }
            
            function setSvgDomains(data, x, y){
                x.domain(data.map(function(d) { return d.country; }));
                y.domain([0, d3.max(data, function(d) { return d.percentage; })]);
            }
            
            function setCartBars(svg, data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, typY){
                svg.selectAll(".bar")
                    .data(data)
                    .enter()
                    .append("rect")
                    .transition()
                    .duration(500)
                    .attr("x", attrX)
                    .attr("y", attrY)
                    .attr("height", attrH)
                    .attr("width", 20)
                    .attr("class", "bar")
                    .attr("country", data => data.country)
                    .attr("percentage", data => data.percentage)
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
                        .attr("country", data => data.country)
                        .attr("percentage", data => data.percentage)
                        .attr("x", attrX)
                        .attr("y", attrY)
                        .attr("height", attrH)
                        .attr("width", 20)
                        .attr("rx", 10)
                        .attr("ry", 10)
                        .attr("fill", data => data.color)
                        .style("opacity", 1)
                        .on('mouseover', function(d){
                            tooltip.style("opacity", 1)
                                    .attr("x", x(d.country)+10)
                                    .attr("y", typY(d))
                                    .attr("fill", d.color);

                            tooltext.style("opacity", 1)      
                                    .text(Number((d.percentage).toFixed(1)))  
                                    .attr("x", x(d.country)+30)
                                    .attr("y", typY(d)+25);

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
            
            function barSort(data, delta){
                if (data.percentage === delta.percentage) {
                    return 0;
                } else {
                    return (data.percentage < delta.percentage) ? -1 : 1;
                }
            }
            
            function setGenderChartDomains(data, categoriesNames, rateNames, x0, x1, y){
                x0.domain(categoriesNames);
                x1.domain(rateNames).rangeRoundBands([0, x0.rangeBand()]);
                y.domain([0, d3.max(data, function(country) { return d3.max(country.values, function(d) { return d.value; }); })]);
            }
            
            function setGenderChartSvg(id, width, height, margin){
                return d3
                    .select('.chart-' + id)
                    .append("svg")
                    .attr("viewBox", [0, 0, width + margin.left + margin.right, height + margin.top + margin.bottom])
                    .append("g")
                    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");   
            }
            
            function setSvgGenderBarData(svg, data, x0, x1, y, width, height, tooltip, tooltext, boyWrap){
                var slice = svg.selectAll(".slice")
                    .data(data)
                    .enter()
                    .append("g")
                    .attr("class", "group")
                    .attr("x", function(d){return x0(d.country)})
                    .attr("transform",function(d) {return "translate(" + x0(d.country) + ",0)"; });

                slice.selectAll("rect")
                    .data(function(d) { return d.values; })
                    .enter()
                    .append("rect")
                    .attr("width", 20)
                    .attr("x", function(d) { return x1(d.rate); })
                    .style("fill", function(d) {if (d.rate == 'M'){return setFill(d.value);}return '#fff';})
                    .style("stroke-width", 3)
                    .style("stroke",function(d) {return setFill(d.value);})
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("y", function(d) { return y(0); })
                    .attr("height", function(d) { return height - y(0); })
                    .on("mouseover", function(d) {
                        let xGroup = 0;
                        d3.select(this)
                            .attr("Xgroup", function(){
                                xGroup = $(this).closest('.group').attr('x');
                                return xGroup;
                            });
                            
                        tooltip.style("opacity", 1)
                            .attr("x", setXdelta(xGroup, d.rate)+40)
                            .attr("y", y(d.value)-10)
                            .style("stroke-width", 3)
                            .style("stroke", setFill(d.value))
                            .attr("fill", setTipFill(d));
                       
                        tooltext.style("opacity", 1)
                            .text(Number((d.value).toFixed(1)))  
                            .attr("x", setXdelta(xGroup, d.rate)+60)
                            .attr("y", y(d.value)+25)
                            .attr("fill", setTipTextFill(d));
                    
                        boyWrap.style("opacity", 1)
                            .attr("x", setXdelta(xGroup, d.rate)+55)
                            .attr("y", y(d.value)-5)
                            .attr("xlink:href", showGender(d))
                    
                    })
                    .on("mouseout", function(d) {
                        tooltip.style("opacity", 0);
                        tooltext.style("opacity", 0);
                        boyWrap.style("opacity", 0);
                    });

                slice.selectAll("rect")
                    .transition()
                    .delay(function (d) {return Math.random()*1000;})
                    .duration(1000)
                    .attr("y", function(d) { return y(d.value); })
                    .attr("height", function(d) { return height - y(d.value); });
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

                setSvgDomains(data, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);

                const attrX = function(d) { 
                    return x(d.country)+20; 
                }
                
                const attrY = function(d) { 
                    return y(d.percentage); 
                }
                
                const attrH = function(d){
                    return y(0) - y(d.percentage);
                }
                
                const tipY = function(d){
                    return y(d.percentage)-30; 
                }
                
                setCartBars(svg, data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
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

                setSvgDomains(chart2data, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { 
                    return x(d.country)+20; 
                }
                
                const attrY = function(d) { 
                    return y(d.percentage); 
                }
                
                const attrH = function(d){
                    return y(0) - y(d.percentage);
                }
                
                const tipY = function(d){
                    return y(d.percentage)-30; 
                }
                
                setCartBars(svg, chart2data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
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

                setSvgDomains(chart3data, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { 
                    return x(d.country)+20; 
                }
                
                const attrY = function(d) { 
                    return y(d.percentage); 
                }
                
                const attrH = function(d){
                    return y(0) - y(d.percentage);
                }
                
                const tipY = function(d){
                    return y(d.percentage)-30; 
                }
                
                setCartBars(svg, chart3data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
                svgSetLine(svg, 40, 430, 580, 431, green);
                svgSetText(svg, 0, 433, '4%', green);
                
                svgSetLine(svg, 40, 410, 580, 411, orange);
                svgSetText(svg, 0, 413, '6%', orange);
                
                svgSetText(svg, 0, height, '0', grey);
            }
       
            //Learning outcomes
            if ($('.chart-4').length){
                const id = '4';
                
                let year = 4;
                let option = 'literacy';

                const chart4yearLiteracy = settings.spc_education_dashboard.chart4[0].data;
                const chart4yearNumeracy = settings.spc_education_dashboard.chart4[1].data;
                const chart6yearLiteracy = settings.spc_education_dashboard.chart4[2].data;
                const chart6yearNumeracy = settings.spc_education_dashboard.chart4[3].data;

                chart4yearLiteracy.sort(barSort);
                chart4yearNumeracy.sort(barSort);
                chart6yearLiteracy.sort(barSort);
                chart6yearNumeracy.sort(barSort);
                
                let height = 400;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);

                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart4yearLiteracy, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
                
                let attrX = function(chart4yearLiteracy) { 
                    return x(chart4yearLiteracy.country)+20; 
                }
                
                let attrY = function(chart4yearLiteracy) { 
                    let pos = 200;
                    if (chart4yearLiteracy.percentage > 0){
                        pos = y(chart4yearLiteracy.percentage)/2;
                    }
                    return pos; 
                }
                
                let attrH = function(chart4yearLiteracy){
                    if (chart4yearLiteracy.percentage < 0){
                        return (y(0) - y((chart4yearLiteracy.percentage)*-1))/2;
                    }
                    return (y(0) - y(chart4yearLiteracy.percentage))/2;
                }
                
                let tipY = function(chart4yearLiteracy){
                    let pos = 200;
                    if (chart4yearLiteracy.percentage > 0){
                        pos = y(chart4yearLiteracy.percentage)/2;
                    }
                    return pos-30; 
                }
                
                setCartBars(svg, chart4yearLiteracy,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
                svgSetLine(svg, 40, 185, 580, 186, green);
                svgSetText(svg, 0, 189, '1%', green);
                
                svgSetLine(svg, 40, 200, 580, 201, grey);
                svgSetText(svg, 0, 204, '0', grey);
                
                svgSetLine(svg, 40, 215, 580, 216, orange);
                svgSetText(svg, 0, 219, '-1%', orange);

                //enable switcher    
                $.switcher('input.slider');
                
                $('.ui-switcher').on('click', function(e){
                    e.preventDefault();
                    let newData = [];                    
                    
                    $(this).closest('.switch-wrapper').find('.labels span').toggleClass('checked');

                    if($(this).attr('aria-checked') == 'true'){
                        year = 6;
                        if(option == 'literacy'){
                            newData = chart6yearLiteracy;
                        } else {
                            newData = chart6yearNumeracy;
                        }                       
                    } else {
                        year = 4;
                        if(option == 'literacy'){
                            newData = chart4yearLiteracy;
                        } else {
                            newData = chart4yearNumeracy;
                        }
                    }

                    
                    d3.select(".chart-" + id + " svg").remove();

                    svg = setChartSvg('.chart-' + id, width, height);
                    setSvgDomains(newData, x, y);

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);

                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                    
                    svgSetLine(svg, 40, 185, 580, 186, green);
                    svgSetText(svg, 0, 189, '1%', green);

                    svgSetLine(svg, 40, 200, 580, 201, grey);
                    svgSetText(svg, 0, 204, '0', grey);

                    svgSetLine(svg, 40, 215, 580, 216, orange);
                    svgSetText(svg, 0, 219, '-1%', orange);
                });

                $('.sw-4 a').on('click', function(e){
                    e.preventDefault();
                    
                    let newData = [];

                    $(this).closest('.switchers').find('.switcher a').removeClass('checked');
                    $(this).toggleClass('checked');
                    
                    if ($(this).attr('id') == 'numeracy'){
                        option = 'numeracy';
                        
                        if(year == 6){
                            newData = chart6yearNumeracy;;
                        } else {
                            newData = chart4yearNumeracy;
                        }                       
                    } else {
                        option = 'literacy';
                        if(year == 4){
                            newData = chart4yearLiteracy;
                        } else {
                            newData = chart6yearLiteracy;
                        }
                    }
                    
                    d3.select(".chart-" + id + " svg").remove();

                    svg = setChartSvg('.chart-' + id, width, height);
                    setSvgDomains(newData, x, y);

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);

                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                    
                    svgSetLine(svg, 40, 185, 580, 186, green);
                    svgSetText(svg, 0, 189, '1%', green);

                    svgSetLine(svg, 40, 200, 580, 201, grey);
                    svgSetText(svg, 0, 204, '0', grey);

                    svgSetLine(svg, 40, 215, 580, 216, orange);
                    svgSetText(svg, 0, 219, '-1%', orange);
                    
                });            
            }
            
            //Net enrolment rate
            if ($('.chart-5').length){
                const chart5ece = settings.spc_education_dashboard.chart5[0].data;
                const chart5primary = settings.spc_education_dashboard.chart5[1].data;
                const chart5secondary = settings.spc_education_dashboard.chart5[2].data;
                
                chart5ece.sort(barSort);
                chart5primary.sort(barSort);
                chart5secondary.sort(barSort);
                
                const id = '5';
                
                let height = 450;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart5ece, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { 
                    return x(d.country)+20; 
                }
                
                const attrY = function(d) { 
                    return y(d.percentage); 
                }
                
                const attrH = function(d){
                    return y(0) - y(d.percentage);
                }
                
                const tipY = function(d){
                    return y(d.percentage)-30; 
                }
                
                setCartBars(svg, chart5ece,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
                svgSetLine(svg, 40, 0, 580, 1, green);
                svgSetText(svg, 0, 0, '100%', green);
                
                svgSetLine(svg, 40, 350, 580, 351, orange);
                svgSetText(svg, 0, 353, '20%', orange);
                
                svgSetText(svg, 0, height, '0', grey);
                
                $('.sw-5 a').on('click', function(e){
                    e.preventDefault();
                    
                    let newData = [];

                    $(this).closest('.switchers').find('.switcher a').removeClass('checked');
                    $(this).toggleClass('checked');
                    
                    
                    if($(this).attr('id') == 'secondary'){
                        newData = chart5secondary;
                    }
                    else if ($(this).attr('id') == 'primary'){
                        newData = chart5primary;
                    }
                    else if ($(this).attr('id') == 'ece'){
                        newData = chart5ece;
                    }
                    
                    d3.select(".chart-" + id + " svg").remove();

                    svg = setChartSvg('.chart-' + id, width, height);
                    setSvgDomains(newData, x, y);

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);

                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);

                    svgSetLine(svg, 40, 0, 580, 1, green);
                    svgSetText(svg, 0, 0, '100%', green);

                    svgSetText(svg, 0, height, '0', grey);                     
                });    
            }
            
            //Gross enrolment ratio
            if ($('.chart-6').length){
                const chart6ece = settings.spc_education_dashboard.chart6[0].data;
                const chart6primary = settings.spc_education_dashboard.chart6[1].data;
                const chart6secondary = settings.spc_education_dashboard.chart6[2].data;
                
                chart6ece.sort(barSort);
                chart6primary.sort(barSort);
                chart6secondary.sort(barSort);
                
                const id = '6';
                
                let height = 450;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart6ece, x, y);
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { 
                    return x(d.country)+20; 
                }
                
                const attrY = function(d) { 
                    return y(d.percentage); 
                }
                
                const attrH = function(d){
                    return y(0) - y(d.percentage);
                }
                
                const tipY = function(d){
                    return y(d.percentage)-30; 
                }
                
                setCartBars(svg, chart6ece,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
                svgSetLine(svg, 40, 80, 580, 81, green);
                svgSetText(svg, 0, 80, '100%', green);
                
                svgSetLine(svg, 40, 180, 580, 181, orange);
                svgSetText(svg, 0, 183, '90%', orange);
                
                svgSetText(svg, 0, height, '0', grey);
                
                $('.sw-6 a').on('click', function(e){
                    e.preventDefault();
                    
                    let newData = [];
                    
                    $(this).closest('.switchers').find('.switcher a').removeClass('checked');
                    $(this).toggleClass('checked');
                    
                    
                    if($(this).attr('id') == 'secondary'){
                        newData = chart6secondary;
                    }
                    else if ($(this).attr('id') == 'primary'){
                        newData = chart6primary;
                    }
                    else if ($(this).attr('id') == 'ece'){
                        newData = chart6ece;
                    }
                    
                    d3.select(".chart-" + id + " svg").remove();

                    svg = setChartSvg('.chart-' + id, width, height);
                    setSvgDomains(newData, x, y);

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);

                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);

                    svgSetLine(svg, 40, 0, 580, 1, green);
                    svgSetText(svg, 0, 0, '100%', green);

                    svgSetText(svg, 0, height, '0', grey);                    
                    
                });    
            } 
            
            //Gross enrolment ratio
            if ($('.chart-7').length){
                const data = settings.spc_education_dashboard.chart7[0].data;
                const id = '7';
                
                const threshold = {
                    "green": 85,
                    "orange": 70,
                    "red": 70
                }
                
                let height = 400;
                let width = 800;
                
                const margin = {
                    top: 20, 
                    right: 20, 
                    bottom: 30, 
                    left: 40
                };
                
                let x0 = setX(width);
                let x1 = setXg();
                let y = setY(height);
                
                let svg = setGenderChartSvg(id, width, height, margin);

                var categoriesNames = data.map(function(d) { return d.country; });
                var rateNames = data[0].values.map(function(d) { return d.rate; });
                
                setGenderChartDomains(data, categoriesNames, rateNames, x0, x1, y); 
                
                svg.select('.y').transition().duration(500).delay(1300).style('opacity','1');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                
                let tooltip = svg
                    .append("rect")   
                    .attr("class", "tipbox-" + id)
                    .attr("width", 40)
                    .attr("height", 40)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .style("opacity", 0);
                
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".tipbox-" + id));
                
                let boyWrap = svg.append("image")
                    .style("opacity", 0)
                    .attr("class", "gimage-" + id)
                    .attr("width", 12)
                    .attr("height", 16);
            
                document
                    .querySelector(".chart-" + id + " svg")
                    .appendChild(document.querySelector(".gimage-" + id));
            
                function setFill(proc) {
                    let fill = green;
                    if(proc < threshold.green){
                        fill = orange;
                    } else if (proc < threshold.orange){
                        fill = red;
                    }
                    return fill;
                }
                
                function setTipFill(data) {
                    let fill = "#fff";
                    if (data.rate == "M"){
                        if(data.value < threshold.green){
                            fill = orange;
                        } else if (data.value < threshold.orange){
                            fill = red;
                        } else {
                            fill = green
                        } 
                    }

                    return fill;
                }
                
                function setTipTextFill(data) {
                    let fill = "#fff";
                    if (data.rate == "F"){
                        if(data.value < threshold.green){
                            fill = orange;
                        } else if (data.value < threshold.orange){
                            fill = red;
                        } else {
                            fill = green
                        } 
                    }

                    return fill;
                }                
                
                function setXdelta(xGroup, rate){
                    if (rate == "M"){
                        return xGroup -9;
                    } else {
                        return parseInt(xGroup, 10) +23;
                    }
                }

                function showGender(data){
                    let path = "sites/all/modules/custom/spc_education_dashboard/img/";
                     if (data.rate == "M"){
                         path =  path + "boys.png";
                     } else {
                        if(data.value < threshold.green){
                            path =  path + "girls_orange.png";
                        } else if (data.value < threshold.orange){
                            path =  path + "girls_red.png";
                        } else {
                            path =  path + "girls_green.png";
                        }
                     }
                    return path; 
                }

                appendTolltip(id);
                
                setSvgGenderBarData(svg, data, x0, x1, y, width, height, tooltip, tooltext, boyWrap);

                svgSetLine(svg, 0, 120, 780, 121, green);
                svgSetText(svg, -30, 120, '100%', green);
                
                svgSetLine(svg, 0, 180, 780, 181, orange);
                svgSetText(svg, -30, 183, '80%', orange);
                
                svgSetText(svg, -20, height, '0', grey);
                
            }    
            
            
        //end context
        }
    };
}(jQuery));