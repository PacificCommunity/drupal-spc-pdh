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
            
            function addColorsToData(data, threshold){
                const thdGreen = threshold.dots.green;
                const thdOrange = threshold.dots.orange;
                const thdRed = threshold.dots.red;

                switch (threshold.type){
                    case 'normal':
                        data.map(function(item, i, arr){
                            if (item.percentage >= thdGreen){
                                item.color = green;
                            } else if (item.percentage < thdGreen && item.percentage >= thdOrange){
                                item.color = orange;
                            } else if (item.percentage < thdOrange){
                                item.color = red;
                            }
                        }); 
                    break;
                    case 'revers':
                        data.map(function(item, i, arr){
                            if (item.percentage <= thdGreen){
                                item.color = green;
                            } else if (item.percentage > thdGreen && item.percentage <= thdOrange){
                                item.color = orange;
                            } else if (item.percentage > thdOrange){
                                item.color = red;
                            }
                        }); 
                    break;
                    case 'advanced':
                        const overlap = threshold.dots.overlap
                        data.map(function(item, i, arr){
                            if (item.percentage >= thdGreen && item.percentage <= overlap){
                                item.color = green;
                            } else if ((item.percentage < thdGreen && item.percentage >= thdOrange) || item.percentage > overlap ){
                                item.color = orange;
                            } else if (item.percentage < thdOrange){
                                item.color = red;
                            }
                        });
                    break; 
                }
                
                return data;
            }
            
            function setThreshold(svg, threshold, x, y, width, height, symbol){
                
                const thdGreen = threshold.dots.green;
                const thdOrange = threshold.dots.orange;
                const thdRed = threshold.dots.red;
                
                svgSetLine(svg, 30, y(thdGreen), width, y(thdGreen)+1, green);
                svgSetText(svg, -5, y(thdGreen)+4, thdGreen+symbol, green);

                svgSetLine(svg, 30, y(thdOrange), width, y(thdOrange)+1, orange);
                svgSetText(svg, -5, y(thdOrange)+4, thdOrange+symbol, orange);
                
                svgSetText(svg, 0, height, '0', grey);                
            }
            
            function setNegativeThreshold(svg, threshold, x, y, width, height, symbol){
                svgSetLine(svg, 30, 185, 580, 186, green);
                svgSetText(svg, -5, 189, '1%', green);
                
                svgSetLine(svg, 30, 200, 580, 201, grey);
                svgSetText(svg, -5, 204, '0', grey);
                
                svgSetLine(svg, 30, 215, 580, 216, orange);
                svgSetText(svg, -5, 219, '-1%', orange);
            }
            
            function setCartExtremum(svg, data, threshold, x, y, width, height){
                //todo set cart extremum function
            }
            
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
                        .enter()
                        .append("rect")
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
                    .attr("font-size", "12px")
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
                const chart1Thd = settings.spc_education_dashboard.threshold1;
                let chart1data = settings.spc_education_dashboard.chart1[0].data;

                chart1data = addColorsToData(chart1data, chart1Thd);
                
                let height = 300;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart1data, x, y);
                setThreshold(svg, chart1Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);

                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart1data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);

                svgSetText(svg, -10, 20, '18%', green);
                svgSetText(svg, -10, 230, '3.8%', red);
            }
            
            //Out of School Children chart
            if ($('.chart-2').length){
                const id = '2';
                const chart2Thd = settings.spc_education_dashboard.threshold2;
                let chart2data = settings.spc_education_dashboard.chart2[0].data;

                chart2data = addColorsToData(chart2data, chart2Thd);
                
                let height = 450;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart2data, x, y);
                setThreshold(svg, chart2Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart2data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
            }
            
            //Over age students chart
            if ($('.chart-3').length){
                const id = '3';
                let chart3data = settings.spc_education_dashboard.chart3[0].data;
                const chart3Thd = settings.spc_education_dashboard.threshold3;
                
                chart3data = addColorsToData(chart3data, chart3Thd);
                
                let height = 450;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);

                setSvgDomains(chart3data, x, y);
                setThreshold(svg, chart3Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                
                appendTolltip(id);
            
                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart3data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
            }
       
            //Learning outcomes
            if ($('.chart-4').length){
                const id = '4';
                let year = 4;
                let option = 'literacy';

                let chart4yearLiteracy = settings.spc_education_dashboard.chart4[0].data;
                let chart4yearNumeracy = settings.spc_education_dashboard.chart4[1].data;
                let chart6yearLiteracy = settings.spc_education_dashboard.chart4[2].data;
                let chart6yearNumeracy = settings.spc_education_dashboard.chart4[3].data;

                chart4yearLiteracy.sort(barSort);
                chart4yearNumeracy.sort(barSort);
                chart6yearLiteracy.sort(barSort);
                chart6yearNumeracy.sort(barSort);
                
                const chart4Thd = settings.spc_education_dashboard.threshold4;
                
                chart4yearLiteracy = addColorsToData(chart4yearLiteracy, chart4Thd);
                chart4yearNumeracy = addColorsToData(chart4yearNumeracy, chart4Thd);
                chart6yearLiteracy = addColorsToData(chart6yearLiteracy, chart4Thd);
                chart6yearNumeracy = addColorsToData(chart6yearNumeracy, chart4Thd);
                
                let height = 400;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);

                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart4yearLiteracy, x, y);
                setNegativeThreshold(svg, chart4Thd, x, y, width, height, '%');
                
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
                    setNegativeThreshold(svg, chart4Thd, x, y, width, height, '%');

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);
                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
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
                    setNegativeThreshold(svg, chart4Thd, x, y, width, height, '%');

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);
                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                });            
            }
            
            //Net enrolment rate
            if ($('.chart-5').length){
                const id = '5';
                let chart5ece = settings.spc_education_dashboard.chart5[0].data;
                let chart5primary = settings.spc_education_dashboard.chart5[1].data;
                let chart5secondary = settings.spc_education_dashboard.chart5[2].data;
                const chart5Thd = settings.spc_education_dashboard.threshold5;
                
                chart5ece.sort(barSort);
                chart5primary.sort(barSort);
                chart5secondary.sort(barSort);

                chart5ece = addColorsToData(chart5ece, chart5Thd);
                chart5primary = addColorsToData(chart5primary, chart5Thd);
                chart5secondary = addColorsToData(chart5secondary, chart5Thd);

                let height = 450;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart5ece, x, y);
                setThreshold(svg, chart5Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                appendTolltip(id);
            
                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart5ece,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);

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
                    setThreshold(svg, chart5Thd, x, y, width, height, '%');

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);
                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                });    
            }
            
            //Gross enrolment ratio
            if ($('.chart-6').length){
                const id = '6';
                let chart6ece = settings.spc_education_dashboard.chart6[0].data;
                let chart6primary = settings.spc_education_dashboard.chart6[1].data;
                let chart6secondary = settings.spc_education_dashboard.chart6[2].data;
                let chart6Thd = settings.spc_education_dashboard.threshold6;
                
                chart6ece.sort(barSort);
                chart6primary.sort(barSort);
                chart6secondary.sort(barSort);

                chart6ece = addColorsToData(chart6ece, chart6Thd);
                chart6primary = addColorsToData(chart6primary, chart6Thd);
                chart6secondary = addColorsToData(chart6secondary, chart6Thd);

                let height = 450;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart6ece, x, y);
                setThreshold(svg, chart6Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                appendTolltip(id);
            
                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart6ece,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
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
                    setThreshold(svg, chart6Thd, x, y, width, height, '%'); 

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);
                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);                 
                });    
            } 
            
            //Primary completion rate
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
                svgSetText(svg, -30, 183, '85%', orange);
                
                svgSetText(svg, -20, height, '0', grey);
            }
            
            //Progression to secondary school
            if ($('.chart-8').length){
                const data = settings.spc_education_dashboard.chart8[0].data;
                const id = '8';
                
                const threshold = {
                    "green": 85,
                    "orange": 70,
                    "red": 70
                }
                
                let height = 300;
                let width = 500;
                
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

                svgSetLine(svg, 0, 120, 480, 121, green);
                svgSetText(svg, -30, 120, '100%', green);
                
                svgSetLine(svg, 0, 180, 480, 181, orange);
                svgSetText(svg, -30, 183, '80%', orange);
                
                svgSetText(svg, -20, height, '0', grey);
            }
            
            //Transition rate
            if ($('.chart-9').length){
                const id = '9';
                let chart9data = settings.spc_education_dashboard.chart9[0].data;
                const chart9Thd = settings.spc_education_dashboard.threshold9;
                
                chart9data.sort(barSort);
                chart9data = addColorsToData(chart9data, chart9Thd);
                
                let height = 300;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart9data, x, y);
                setThreshold(svg, chart9Thd, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                appendTolltip(id);

                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart9data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
            }
            
            // Lower secondary completion rate
            if ($('.chart-10').length){
                const data = settings.spc_education_dashboard.chart10[0].data;
                const id = '10';
                
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

                svgSetLine(svg, 0, 110, 780, 111, green);
                svgSetText(svg, -30, 114, '85%', green);
                
                svgSetLine(svg, 0, 180, 780, 181, orange);
                svgSetText(svg, -30, 183, '70%', orange);
                
                svgSetText(svg, -20, height, '0', grey);
            }

            //Pupil-teacher ratio (PTR)
            if ($('.chart-11').length){
                const id = '11';
                let chart11ece = settings.spc_education_dashboard.chart11[0].data;
                let chart11primary = settings.spc_education_dashboard.chart11[1].data;
                let chart11secondary = settings.spc_education_dashboard.chart11[2].data;
                
                chart11ece.sort(barSort);
                chart11primary.sort(barSort);
                chart11secondary.sort(barSort);
                
                const threshold11Ece = settings.spc_education_dashboard.threshold11.ece;
                const threshold11Primary = settings.spc_education_dashboard.threshold11.primary;
                const threshold11Secondary = settings.spc_education_dashboard.threshold11.secondary;

                chart11ece = addColorsToData(chart11ece, threshold11Ece);
                chart11primary = addColorsToData(chart11primary, threshold11Primary);
                chart11secondary = addColorsToData(chart11secondary, threshold11Secondary);

                let height = 450;
                let width = 600;
                
                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart11ece, x, y);
                setThreshold(svg, threshold11Ece, x, y, width, height, '');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                appendTolltip(id);
            
                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage); }
                const tipY = function(d){ return y(d.percentage)-30; }
                
                setCartBars(svg, chart11ece,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                
                $('.sw-11 a').on('click', function(e){
                    e.preventDefault();
                    let newData = [];
                    let newThreshold = [];
                    
                    $(this).closest('.switchers').find('.switcher a').removeClass('checked');
                    $(this).toggleClass('checked');

                    if($(this).attr('id') == 'secondary'){
                        newData = chart11secondary;
                        newThreshold = threshold11Secondary;
                    }
                    else if ($(this).attr('id') == 'primary'){
                        newData = chart11primary;
                        newThreshold = threshold11Primary;
                    }
                    else if ($(this).attr('id') == 'ece'){
                        newData = chart11ece;
                        newThreshold = threshold11Ece;
                    }
                    
                    d3.select(".chart-" + id + " svg").remove();
                    svg = setChartSvg('.chart-' + id, width, height);
                    setSvgDomains(newData, x, y);
                    setThreshold(svg, newThreshold, x, y, width, height, '');

                    tooltext = setToolText(svg, "tooltip-" + id);
                    tooltip = setToolBox(svg);
                    appendTolltip(id);
                    
                    setCartBars(svg, newData,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
                });    
            }            
            
            //Safe drinking water
            if ($('.chart-12').length){
                const id = '12';
                let chart12data = settings.spc_education_dashboard.chart12[0].data;
                const threshold12 = settings.spc_education_dashboard.threshold12;
                
                chart12data.sort(barSort);
                chart12data = addColorsToData(chart12data, threshold12);
                
                let height = 300;
                let width = 600;

                let x = setX(width);
                let y = setY(height);
                
                let svg = setChartSvg('.chart-' + id, width, height);
                setSvgDomains(chart12data, x, y);
                setThreshold(svg, threshold12, x, y, width, height, '%');
                
                let tooltext = setToolText(svg, "tooltip-" + id);
                let tooltip = setToolBox(svg);
                appendTolltip(id);

                const attrX = function(d) { return x(d.country)+20; }
                const attrY = function(d) { return y(d.percentage); }
                const attrH = function(d){ return y(0) - y(d.percentage);}
                const tipY = function(d){ return y(d.percentage)-30;}
                
                setCartBars(svg, chart12data,  x, y, width, height, tooltip, tooltext, attrX, attrY, attrH, tipY);
            }
            
        //end context
        }
    };
}(jQuery));