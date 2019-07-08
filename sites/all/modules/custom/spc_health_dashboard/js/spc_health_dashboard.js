(function ($) {
    Drupal.behaviors.spcHealthDashboard = {
        attach: function (context, settings) {
        //start context
 
        let healthChart = settings.spc_health_chart.chart[0];
  
        var data = [
          { year: "Leadership", mcintosh: "15", oranges: "9", pears: "6" },
          { year: "Tobacco", mcintosh: "18", oranges: "9", pears: "4" },
          { year: "Alcohol", mcintosh: "20", oranges: "8", pears: "2" },
          { year: "Food", mcintosh: "15", oranges: "5", pears: "4" },
          { year: "P Activity", mcintosh: "10", oranges: "4", pears: "2" },
          { year: "Enforcement", mcintosh: "12", oranges: "6", pears: "3" },
          { year: "H System", mcintosh: "15", oranges: "8", pears: "1" },
          { year: "Monitoring", mcintosh: "11", oranges: "9", pears: "4" }
        ];

        // Transpose the data into layers
        var dataset = d3.layout.stack()(["mcintosh", "oranges", "pears"].map(function(item) {
          return data.map(function(d) {
            return {x: d.year, y: +d[item]};
          });
        }));
        
        var margin = {top: 20, right: 160, bottom: 35, left: 30};

        var width = 900,
            height = 400;

        // Set x, y and colors
        var x = d3.scale.ordinal()
          .domain(dataset[0].map(function(d) { return d.x; }))
          .rangeRoundBands([10, width-10], 0.02);

        var y = d3.scale.linear()
          .domain([0, d3.max(dataset, function(d) {  return d3.max(d, function(d) { return d.y0 + d.y; });  })])
          .range([height, 0]);

        var colors = ["#d9d574", "#f2b447", "#d25c4d" ];
        
        var svg = d3.select(".stacked-chart-global")
          .append("svg")
          .attr("viewBox", [0, 0, width, height])
          .append("g"); 

        // Define and draw axes
        var yAxis = d3.svg.axis()
          .scale(y)
          .orient("left")
          .ticks(5)
          .tickSize(-width, 0, 0)
          .tickFormat( function(d) { return d } );

        var xAxis = d3.svg.axis()
          .scale(x)
          .orient("bottom");

        svg.append("g")
          .attr("class", "y axis")
          .call(yAxis);

        svg.append("g")
          .attr("class", "x axis")
          .attr("transform", "translate(0," + height + ")")
          .call(xAxis);
  
        svg.selectAll(".x .domain").style("opacity", 0);

        // Create groups for each series, rects for each segment 
        var groups = svg.selectAll("g.cost")
          .data(dataset)
          .enter().append("g")
          .attr("class", "cost")
          .style("fill", function(d, i) { return colors[i]; });

        groups.selectAll("rect")
          .data(function(d) { return d; })
          .enter()
          .append("rect")
          .attr("rx", 5)
          .attr("ry", 5)
          .attr("x", function(d) { return x(d.x)+40; })
          .attr("y", function(d) { return y(d.y0 + d.y); })
          .attr("height", function(d) { return (y(d.y0) - y(d.y0 + d.y))-5 ; })
          .attr("width", 30);
       
        //end context
        }
    };
}(jQuery));