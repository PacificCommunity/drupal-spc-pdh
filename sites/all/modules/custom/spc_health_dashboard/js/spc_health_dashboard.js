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
                        $('.ui-widget-overlay').on('click', function(){
                           $('.indicator-popup').dialog( "close" );
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
                let next = '';

                cat.each(function(i){
                    if($(this).hasClass('current')){;
                        index = i;
                    }
                });

                if (index >= cat.length-1){
                    next = $(cat[0]).find('a');
                }else{
                    next = $(cat[index+1]).find('a');   
                }
                window.location.href = next.attr('href');
            });

            $('.categories-switcher p.prev ').on('click', function(){
                let cat = $('.category-item');
                let index = 0;
                let next = '';

                cat.each(function(i){
                    if($(this).hasClass('current')){;
                        index = i;
                    }
                });
                if (index == 0){
                    next = $(cat[cat.length-1]).find('a');
                } else {
                    next = $(cat[index-1]).find('a');
                }
                window.location.href = next.attr('href');
            });

            if ($('.categories-switcher').length && $(window).width() < 1200){
                let cat = $('.category-item');
                let left = 0;
                let fixer = 0;
                cat.each(function(){
                    if($(this).hasClass('current')){
                        return false;
                    } else {
                        fixer++;
                        left +=  $(this).width() + 10 * (fixer * 0.2);
                    }
                });
                $('.categories-switcher .list').css({
                    "margin-left": '-' + left + 'px'
                });
            }

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

            //indicators map 
            if ($('.pacific-map').length){
                const countriesData = settings.spc_health_chart.countries_detales;
                const curCategory = $('.map-svg').attr('data-current-category');
                const curIndicator = $('.map-svg').attr('data-current-indicator');              
                
                const width = 800;
                const height = 600;

                const colors = {
                    'not-applicable': "FF0000",
                    "not-present": "#FF0000",
                    "under-development":"#FFC000",
                    "present":"#CFFF6F",
                    "low":"#CFFF6F",
                    "medium":"#CFFF6F",
                    "high": "CFFF6F"
                } 

                let svg = d3
                    .select('.map-svg')
                    .append("svg")
                    .attr('class', 'svg-pasific')
                    .attr("viewBox", [0, 0, width, height]);

                svg.append("image")
                    .attr("class", "pasific-image")
                    .attr("width", width)
                    .attr("height", height)
                    .attr("x", -20)
                    .attr("y", -50)        
                    .attr("xlink:href", $('.map-svg').attr("data-src"));

                for (let i in countriesData){
                    let country = countriesData[i];
                    
                    for (let key in country){
                        let cName = country.title;
                        let cId = country.id;
                        
                        if (country['map-coordinates'] != undefined ){
                            let coordinates = country['map-coordinates'];
                            
                            if (key == 'indicators'){
                                let indicators  = country.indicators;
                                
                                for (let indicator in indicators){
                                    if (indicator == curIndicator){
                                        let value = indicators[curIndicator]['value'];
                                        
                                        // country circle internal indicator     
                                        svg.append("circle")
                                           .attr("class", cId + "-center")
                                           .attr('data-country-id', cId)
                                           .attr("cx", coordinates.cx)
                                           .attr("cy", coordinates.cy)
                                           .attr("r", 15)
                                           .style("fill", colors[value]);

                                        // country circle external indicator     
                                        svg.append("circle")
                                           .style("opacity", 0.5)
                                           .attr("class", cId)
                                           .attr('data-country-id', cId)
                                           .attr("cx", coordinates.cx)
                                           .attr("cy", coordinates.cy)
                                           .attr("r", 25)
                                           .style("fill", colors[value])
                                           .on('mouseover', function(){
                                                let setf = d3.select(this);
                                                setf.style("stroke-width", 2)
                                                    .style("stroke", "#fff");
                                                let cid = setf.attr('data-country-id');
                                                d3.select('.' + cid + '-center')                        
                                                    .style("stroke-width", 2)
                                                    .style("stroke", "#fff");
                                                d3.select('.' + cid + "-name") 
                                                    .style("opacity", 1);
                                            })
                                            .on('mouseout', function(d){
                                                let setf = d3.select(this);
                                                setf.style("stroke", "transparent");
                                                let cid = setf.attr('data-country-id');
                                                d3.select('.' + cid + '-center')                        
                                                    .style("stroke", "transparent");
                                                d3.select('.' + cid + "-name") 
                                                    .style("opacity", 0);
                                            });
                                            
                                        //country name 
                                        svg.append("text")
                                            .text(cName)
                                            .attr("class", cId + "-name")
                                            .attr("text-anchor", "middle")
                                            .attr("x", coordinates.cx)
                                            .attr("y", coordinates.cy + 35)
                                            .attr("font-size", "10px")
                                            .attr("fill", "#fff")
                                            .style("text-shadow", "2px 2px 2px black")
                                            .style("opacity", 0);
                                    }
                                }
                            }
                        }
                    }
                }

                //hover on country name
                $('.country-item').on('mouseover', function(e){
                    
                    let cid = $(this).find('.country-on-map').attr('data-country-id');
                    d3.select('.' + cid)                        
                        .style("stroke-width", 2)
                        .style("stroke", "#fff");
                    d3.select('.' + cid + '-center')                        
                        .style("stroke-width", 2)
                        .style("stroke", "#fff");
                    d3.select('.' + cid + "-name") 
                        .style("opacity", 1);
                });
                
                $('.country-item').on('mouseout', function(e){
                    let cid = $(this).find('.country-on-map').attr('data-country-id');
                    d3.selectAll('.' + cid)                        
                        .style("stroke", "transparent");
                    d3.select('.' + cid + '-center')                        
                        .style("stroke", "transparent");
                    d3.select('.' + cid + "-name") 
                        .style("opacity", 0);
                }); 
            }

            //search by countries, categories and indicators.
            if ($('.health-dashboard-search-form')){
                
                const searchCountries = settings.spc_health_chart.search_countries;
                const searchCategories = settings.spc_health_chart.search_categories;
                const searchIndicators = settings.spc_health_chart.search_indicators;

                $('#health-dashboard-search').on('keyup', function(e){

                    let term = $(this).val().toLowerCase();
                    let contryRes = getCountries(term);
                    if(contryRes !== '') {
                        $('.sug-countries .sug-list').html(contryRes);
                        $('.sug-countries').show();
                    } else {
                        $('.sug-countries .sug-list').html('');
                        $('.sug-countries').hide();
                    }
                    
                    let categoriesRes = getCategories(term);
                    if (categoriesRes !== ''){
                        $('.sug-categories .sug-list').html(categoriesRes);
                        $('.sug-categories').show();
                    } else {
                        $('.sug-categories .sug-list').html('');
                        $('.sug-categories').hide();
                    }
                    
                    let indicatorsRes = getIndicators(term);
                    if (indicatorsRes !== ''){
                        $('.sug-indicators .sug-list').html(indicatorsRes);
                        $('.sug-indicators').show();
                    } else {
                        $('.sug-indicators .sug-list').html('');
                        $('.sug-indicators').hide();
                    }
                        
                    $('.search-sugestion').show();
                    $('.health-dashboard-content').css({
                        'z-index': -1
                    });
                    
                    let code = e.keyCode || e.which;
                    if (code == 40){
                        
                        let activeItem = false;
                        let searchList = $('.sug-list li a');

                        searchList.each(function(key, value){
                            if($(value).hasClass('active')){
                                activeItem = true;
                            }
                        });

                        if (activeItem == true){
                            searchList.each(function(key, value){
                                if($(value).hasClass('active')){
                                    $(searchList[key]).removeClass('active');
                                    $(searchList[key+1]).addClass('active');

                                }
                            });                                
                        } else {
                            $(searchList[0]).addClass('active');
                        }


                     }
                    
                });
                
                $('.health-dashboard-search-form').submit(function(e){
                    e.preventDefault();
                    window.location.href = $('.sug-list li a.active').attr('href');
                });
                
                $(document).mouseup(function(e){
                    var container = $('.search-sugestion');
                    if (!container.is(e.target) && container.has(e.target).length === 0){
                        container.hide();
                        $('.health-dashboard-content').css({
                            'z-index': 0
                        });
                    }
                });
                
                function getCountries(term){
                    let html = '';
                    for (let Key in searchCountries){
                        let title = searchCountries[Key]['#title'].toLowerCase();
                        if (title.indexOf(term) != -1){
                            html += '<li>'
                                +'<a href="/health-dashboard/country/' + Key + '">'
                                + searchCountries[Key]['#title']
                                + '</li>';                            
                        }
                    }
                    return html;
                }
                
                function getCategories(term){
                    let html = '';
                    for (let Key in searchCategories){
                        let title = searchCategories[Key]['#title'].toLowerCase();
                        if (title.indexOf(term) != -1){
                            html += '<li>'
                                +'<a href="/health-dashboard/' + Key + '">'
                                + searchCategories[Key]['#title']
                                + '</li>';
                        }
                    }
                    return html;
                }
                
                function getIndicators(term){
                    let html = '';
                    for (let Key in searchIndicators){
                        let title = searchIndicators[Key]['title'].toLowerCase();
                        if (title.indexOf(term) != -1){
                            html += '<li>'
                                +'<a href="/health-dashboard/' + searchIndicators[Key]['indicator-category'] + '/' + Key + '">'
                                + searchIndicators[Key]['title']
                                + '</li>';
                        }
                    }
                    return html;
                }                     
            }
            
                        
        //end context
        }
    };
}(jQuery));