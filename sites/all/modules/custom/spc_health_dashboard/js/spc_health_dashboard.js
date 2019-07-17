(function ($) {
    Drupal.behaviors.spcHealthDashboard = {
        attach: function (context, settings) {
        //start context
        
        if ($('.stacked-chart-global').length){
 
            const data = settings.spc_health_chart.summary_chart;

            if(data[0].indicator == 'Leadership and governance'){
                data[0].indicator = 'Leadership';
            }

            let dataset = d3.layout.stack()(["present", "under-development", "not-present"].map(function(item) {
              return data.map(function(d) {
                return {x: d.indicator, y: +d[item]};
              });
            }));

            function setToolText(svg, className){
                return svg
                    .append("text")
                    .attr("class", className)
                    .attr("width", 30)
                    .attr("height", 30)
                    .attr("fill", "#000")
                    .attr("text-anchor", "start")
                    .style("opacity", 0);
            }

            function setToolBox(svg){
                return svg
                    .append("rect")   
                    .attr("class", "tipbox")
                    .attr("height", 40)
                    .attr("rx", 10)
                    .attr("ry", 10)
                    .attr("fill", "#fff")
                    .attr("filter", "url(#dropshadow)")
                    .style("opacity", 0);
            }
        
            const width = 900,
                  height = 400;

            // Set x, y and colors
            let x = d3.scale.ordinal()
              .domain(dataset[0].map(function(d) { return d.x; }))
              .rangeRoundBands([10, width-10], 0.02);

            let y = d3.scale.linear()
              .domain([0, d3.max(dataset, function(d) {  return d3.max(d, function(d) { return d.y0 + d.y; });  })])
              .range([height, 0]);

            const colors = ["#cfff6fb3", "#ffc00080", "#ff000080" ];
            const border = ['#CFFF6F',  '#FFC000', '#FF0000' ];
            const range = ["Present", "Under Development", "Not Present"];
            const rangeWidth = [95, 170, 120];

            let svg = d3.select(".stacked-chart-global")
              .append("svg")
              .attr("viewBox", [0, 0, width, height])
              .append("g"); 

            let defs = svg.append("defs");

            let filter = defs.append("filter")
                .attr("id", "dropshadow")

            filter.append("feGaussianBlur")
                .attr("in", "SourceAlpha")
                .attr("stdDeviation", 4)
                .attr("result", "blur");

            filter.append("feOffset")
                .attr("in", "blur")
                .attr("dx", 2)
                .attr("dy", 2)
                .attr("result", "offsetBlur");

            let feMerge = filter.append("feMerge");

            feMerge.append("feMergeNode")
                .attr("in", "offsetBlur")
            feMerge.append("feMergeNode")
                .attr("in", "SourceGraphic");  

            let tooltext = setToolText(svg, "tooltip");
            let tooltip = setToolBox(svg);

            document
                .querySelector(".stacked-chart-global svg")
                .appendChild(document.querySelector(".tipbox"));

            document
                .querySelector(".stacked-chart-global svg")
                .appendChild(document.querySelector(".tooltip"));     

            // Define and draw axes
            let yAxis = d3.svg.axis()
              .scale(y)
              .orient("left")
              .ticks(5)
              .tickSize(-width, 0, 0)
              .tickFormat( function(d) { return d } );

            let xAxis = d3.svg.axis()
              .scale(x)
              .orient("bottom");

            svg.append("g")
              .attr("class", "y axis")
              .call(yAxis);

            svg.append("g")
              .attr("class", "x axis")
              .attr("transform", "translate(0," + height + ")")
              .style("font-size", '11')
              .call(xAxis);

            svg.selectAll(".x .domain").style("opacity", 0);

            // Create groups for each series, rects for each segment 
            let groups = svg.selectAll("g.cost")
                .data(dataset)
                .enter()
                .append("g")
                .attr("class", "cost")
                .attr('range', function(d, i) { return range[i]; })
                .attr('range-width', function(d, i) { return rangeWidth[i]; })
                .attr('stroke', function(d, i) { return border[i]; })
                .attr('def-fill', function(d, i) { return colors[i]; })
                .style("stroke-width", 1)
                .style("fill", function(d, i) { return colors[i]; });

            groups.selectAll("rect")
                .data(function(d) { return d; })
                .enter()
                .append("rect")
                .attr("rx", 5)
                .attr("ry", 5)
                .attr('value', function(d) { return d.y; })
                .attr("x", function(d) { return x(d.x)+40; })
                .attr("y", function(d) { return y(d.y0 + d.y); })
                .attr("height", function(d) { return (y(d.y0) - y(d.y0 + d.y))-5 ; })
                .attr("width", 30)
                .on('mouseover', function(d){
                    let hovRange = d3.select(this.parentNode).attr('range');
                    let hovRangeWidth = d3.select(this.parentNode).attr('range-width');
                    let hovFill = d3.select(this.parentNode).attr('stroke');
                    d3.select(this).attr('fill', hovFill);

                    tooltip.style("opacity", 1)
                        .attr("x", x(d.x)+75)
                        .attr("y", y(d.y0 + d.y))
                        .attr("width", hovRangeWidth);

                    tooltext.style("opacity", 1)      
                        .text(hovRange + ' ' + Math.round(d.y) + '%')  
                        .attr("x", x(d.x)+85)
                        .attr("y", y(d.y0 + d.y)+23);

                })
                .on('mouseout', function(d){
                    let defFill = d3.select(this.parentNode).attr('def-fill');
                    d3.select(this).attr('fill', defFill);

                    tooltip.style("opacity", 0)
                    tooltext.style("opacity", 0)
                });            
        }
        
        $('.toggle').add('.toggle-lbl').on('click', function(e){
            e.preventDefault();
            $(this).siblings('.helth-indicators').toggle(); 
            if ($(this).hasClass('toggle')){
                $(this).find('.arrow').toggleClass('down');                
            } else if($(this).hasClass('toggle-lbl')) {
                $(this).siblings('.toggle').find('.arrow').toggleClass('down');        
            }

        });
        
        if ($('.indicator-popup').length){
                    
            const indicatorDetales = settings.spc_health_chart.indicator_detales;
            let Width = $(window).width(); 

            $('.indicator-popup').dialog({
                autoOpen : false,
                modal : true,
                width: Width/100 * 85,
                resizable: false,
                draggable: false,
                show : "blind",
                hide : "blind",
                open: function(event, ui) {
                    $(this)
                        .parent()
                        .children()
                        .children('.ui-dialog-titlebar-close')
                        .css({
                        "margin-right":"15px",
                        "margin-top": "0"
                    });
                    $('.ui-widget-overlay').css({
                        background: '#000',
                        opacity: '0.5',
                    });                    
                }
            });

            $('.status-strength').on('click', function(){
                const dataCategory = $(this).attr('data-category');
                const dataIndicator = $(this).attr('data-indicator');
                const dataValue = $(this).attr('data-value');
                
                let CurrentIndicator = {};
                for (var key in indicatorDetales){
                    if(key == dataIndicator){
                        CurrentIndicator = indicatorDetales[key]
                    }
                }
                
                let indicatorsArray = [];
                let CurrentValue = '';
                for (var key in CurrentIndicator.values){
                    indicatorsArray[key] = CurrentIndicator.values[key]
                    if (key == dataValue){
                        CurrentValue = CurrentIndicator.values[key]
                    }
                }
                
                let notApplicable = indicatorsArray['not-applicable'];
                if (indicatorsArray['not-applicable'].length > 1){
                    notApplicable = '';
                    for (var item in indicatorsArray['not-applicable']){
                        notApplicable += '<p>' + indicatorsArray['not-applicable'][item] + '</p>';
                    }
                } 
 
                const popup = $('.indicator-popup');
                popup.parent()
                    .find('.indicator-title')
                    .html(CurrentIndicator.title);
                popup.parent()
                    .find('#indicator-value')
                    .attr('class', '')
                    .addClass('status-strength')
                    .addClass(dataValue)
                popup.parent()
                    .find('#indicator-text')
                    .html(CurrentValue);
                popup.parent()
                    .find('#not-present .text')
                    .html(indicatorsArray['not-present']);
                popup.parent()
                    .find('#under-development .text')
                    .html(indicatorsArray['under-development']);
                popup.parent()
                    .find('#present .text')
                    .html(CurrentIndicator.values.present);
                popup.parent()
                    .find('#low .text')
                    .html(CurrentIndicator.values.low);
                popup.parent()
                    .find('#medium .text')
                    .html(CurrentIndicator.values.medium);
                popup.parent()
                    .find('#high .text')
                    .html(CurrentIndicator.values.high);
                popup.parent()
                    .find('#not-applicable .text')
                    .html(notApplicable);
                popup.parent()
                    .css({
                        "max-width": "1100px",
                        "position":"fixed",
                        "border-color": "#fff",
                        "box-shadow": "0px 2px 50px rgba(0, 5, 160, 0.102)",
                        "border-radius": "25px"
                    })
                    .end()
                    .dialog('open')
                popup.find('.country-detales').height(popup.height());
                
                if ($(this).attr('data-country').length){
                    popup.find('.country-detales h4').text($(this).attr('data-country-title'));
                    popup.find('.country-flag').attr('src', '/sites/all/modules/custom/spc_health_dashboard/img/flags/'+ $(this).attr('data-country') +'.svg');
                    popup.find('.map').css({
                        "background-image": "url(/sites/all/modules/custom/spc_health_dashboard/img/maps/"+ $(this).attr('data-country') +".svg)"
                    });
                }
                
            });
            
            // on window resize run function
            $(window).resize(function () {
                const popup = $('.indicator-popup');
                let Width = $(window).width(); 
                $('.indicator-popup').dialog({
                    width: Width/100 * 85,
                });
                popup.find('.country-detales').height(popup.height());
            });            
        }
        
        $('.categories-switcher p.next ').on('click', function(){
            let cat = $('.category-item');
            let index = 0;
            cat.each(function(i){
                if($(this).hasClass('current')){;
                    index = i;
                }
            });
            let next = $(cat[index+1]).find('a');
            window.location.href = next.attr('href');
        });
        
        $('.categories-switcher p.prev ').on('click', function(){
            let cat = $('.category-item');
            let index = 0;
            cat.each(function(i){
                if($(this).hasClass('current')){;
                    index = i;
                }
            });
            let next = $(cat[index-1]).find('a');
            window.location.href = next.attr('href');
        });
        
        $(window).on('load resize', function(){
            let Width = $(window).width(); 
            if (Width <= 550){
                $('.category-content>h4').show();
                $('.category-countries>h4').hide();
                $('.category-countries.col-sm-6')
                    .width($('.container').width())
                    .css({
                        "overflow-x": "scroll"
                    });                
            } else {
               $('.category-content>h4').hide();
               $('.category-countries>h4').show(); 
               $('.category-countries.col-sm-6')
                    .width(500)
                    .css({
                        "overflow-x": "visible"
                    });
            }
            if (Width <= 980){
                $('.category-content>h4').show();
                $('.category-countries>h4').hide();
                $('.category-countries.col-sm-12')
                    .width($('.container').width())
                    .css({
                        "overflow-x": "scroll"
                    });  
            } else {
                $('.category-content>h4').hide();
                $('.category-countries>h4').show();
                $('.category-countries.col-sm-12')
                    .width(900)
                    .css({
                        "overflow-x": "visible"
                    });
            }

        });
        
        $('.more-less').on('click', function(){
            if ($(this).hasClass('show-more')){
                $(this).siblings('.dots').hide(); 
                $(this).siblings('.more').show();
                $(this).removeClass('show-more').addClass('show-less').text('Read less');                
            } else {
                $(this).siblings('.dots').show(); 
                $(this).siblings('.more').hide();
                $(this).removeClass('show-less').addClass('show-more').text('Read more');                
            }

        });
                        
        //end context
        }
    };
}(jQuery));