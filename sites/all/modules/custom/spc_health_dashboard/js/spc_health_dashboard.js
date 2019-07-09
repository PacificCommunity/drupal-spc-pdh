(function ($) {
    Drupal.behaviors.spcHealthDashboard = {
        attach: function (context, settings) {
        //start context
 
        const data = settings.spc_health_chart.summary_chart;

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
        const range = ["present", "under-development", "not-present"];
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
                
                d3.select(this).style("opacity", 0.5);
                let hovRange = d3.select(this.parentNode).attr('range');
                let hovRangeWidth = d3.select(this.parentNode).attr('range-width');

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
                d3.select(this).style("opacity", 1)
                tooltip.style("opacity", 0)
                tooltext.style("opacity", 0)
            });
       
        //end context
        }
    };
}(jQuery));