document.addEventListener("DOMContentLoaded", function(e) {
  var modulePath = "/"+Drupal.settings.spcChart.path;

  var width = 1160,
    height = 975,
    radius = (Math.min(width, height) / 2) - 10;

  var chartBlock = d3.select("#sdgChart");
  var svg = chartBlock.append("svg")
      .attr("width", width)
      .attr("height", height)
    .append("g")
      .attr("transform", "translate(" + width / 2 + "," + (height / 2) + ")");

  d3.json(modulePath+"/data/fixed_data.json").then(function(data) {

    var domainWidth = 25;
    var goalWidth = 100;

    var domains_arc = d3.arc()
      .innerRadius(radius - domainWidth)
      .outerRadius(radius);

    var goals_arc = d3.arc()
      .outerRadius(radius - domainWidth)
      .innerRadius(radius - goalWidth);

    var pie = d3.pie()
      .value(function(d) { return d.value; })
      .sort(null);

    var path = svg.selectAll("path.domain")
        .data(pie(data.domains))
        .enter()
      .append("path")
        .attr("class", "domain")
        .attr("id", function(d,i) { return "domain_"+i; })
        .attr("d", domains_arc)
        .style("fill", "#4184be")
        .style("stroke", "#fff")
        .style("stroke-width", "5px");

    svg.selectAll(".domain-text")
        .data(data.domains)
        .enter()
      .append("text")
        .attr("class", "domain-text")
        .attr("x", 15)
        .attr("dy", 18) 
      .append("textPath")
        .attr("xlink:href",function(d,i){return "#domain_"+i;})
        .text(function(d){return d.name;})
        .style("fill", "#fff");

        var goals = svg.selectAll(".goal")
        .data(pie(data.goals))
        .enter()
      .append("a")
        .attr("xlink:href", function(d) {return d.data.link;})
        .attr("target", "_blank")

    goals.append("path")
      .attr("class", "goal")
      .attr("id", function(d,i) { return "goal_"+i; })
      .attr("d", goals_arc)
      .style("fill", function(d) { return d.data.color; })
      .style("stroke", "#fff")
      .style("stroke-width", "5px");

    goals.append("image")
      .attr("xlink:href",function(d,i){return modulePath+d.data.icon;})
      .attr("x", function(d){
        return (goals_arc.centroid(d)[0] - 25);
      })
      .attr("y", function(d){
        return (goals_arc.centroid(d)[1] - 25);
      })
      .attr("width", "50")
      .attr("height", "50");

    chartBlock.append("img")
      .attr("src", modulePath+"/images/center-image.png")
      .attr("class", "center-image");
  });


  d3.json(modulePath+"/data/bars_data.json").then(function(data) {

    var height = 775,
      barHeight = height / 2 - 40;
      
    data.forEach(element => {
      element.data.forEach(el => {
        el['color'] = element.color;
      })
    });

    var barsNames = [];
    data.forEach(item => {
      item.data.forEach(i => {
        barsNames.push(i.name);
      })
    })
    var numBarsData = barsNames.length;

    var barScale = d3.scaleLinear()
      .domain([0, d3.max(data, function(d) { return d3.max(d.data, function(d) { return d.value; }); })])
      .range([0, barHeight]);

    var x = d3.scaleLinear()
      .domain([0, d3.max(data, function(d) { return d3.max(d.data, function(d) { return d.value; }); })])
      .range([0, -barHeight]);

    function countRotate(i) {
      var coef = 360 / numBarsData;
      data[i]['rotate'] = (i === 0 ? 0 : (data[i-1].data.length * coef + data[i-1]['rotate']));
      return (i === 0 ? 0 : (data[i-1].data.length * coef + data[i-1]['rotate']))
    }

    var arc = d3.arc()
      .startAngle(function(d,i) { return (i * 1 * Math.PI) / (numBarsData/2); })
      .endAngle(function(d,i) { return ((i+1) * 1 * Math.PI) / (numBarsData/2); })
      .innerRadius(100)
      .padAngle(.01);

    var goal = svg.selectAll(".bar")
        .data(data)
        .enter()
      .append("g")
        .attr("class", "bar")
        .attr("transform", function(d,i) { return "rotate(" + (countRotate(i)) + ")"; });
    
    var div = d3.select("body").append("div")	
        .attr("class", "tooltip")				
        .style("opacity", 0);

    var segments = goal.selectAll("path")
        .data(function(d) { return d.data; })
        .enter()
      .append("a")
        .attr("xlink:href", function(d) {return d.link;})
        .attr("target", "_blank")
      .append("path")
        .each(function(d) { d.outerRadius = 0; })
        .style("fill", function (d) { return d.value === 1 ? "#b4b5b4" : (d.value === 0 ? "transparent" : (d.value === 2 ? "#fff" : d.color)); })
        .style("stroke", function (d) {return d.value === 0 ? "#b4b5b4" : ""; })
        .style("stroke-width", function (d) {return d.value === 0 ? "2px" : ""; })
        .style("stroke-dasharray", function (d) {return d.value === 0 ? "2,2" : ""; })
        .attr("d", arc)
        .on("mouseover", function(d) {		
          div.transition()		
              .duration(200)		
              .style("opacity", .9);		
          div	.html(d.description)	
              .style("left", (d3.event.pageX) + "px")		
              .style("top", (d3.event.pageY - 28) + "px");	
          })					
        .on("mouseout", function(d) {		
            div.transition()		
                .duration(500)		
                .style("opacity", 0);	
        });

    segments.transition().duration(1000)
      .attrTween("d", function(d,index) {
        var i = d3.interpolate(d.outerRadius, barScale(d.value === 0 || d.value === 1 || d.value === 2 ? 7 : d.value));
        return function(t) { d.outerRadius = i(t); return arc(d,index); };
      });

    svg.selectAll("circle")
        .data(x.ticks(5))
        .enter()
      .append("circle")
        .attr("r", function(d) {return barScale(d);})
        .style("fill", "none")
        .style("stroke", "black")
        .style("stroke-dasharray", "2,2")
        .style("stroke-width",".5px");

    var labelRadius = barHeight * 1.025;
    var labels = svg.append("g")
      .classed("labels", true);

    labels.append("def")
      .append("path")
      .attr("id", "label-path")
      .attr("d", "m0 " + -labelRadius + " a" + labelRadius + " " + labelRadius + " 0 1,1 -0.01 0");
      
    labels.selectAll("text")
        .data(barsNames)
        .enter()
      .append("text")
        .style("text-anchor", "middle")
        .style("fill", function(d, i) {return "#3e3e3e";})
      .append("textPath")
        .attr("xlink:href", "#label-path")
        .attr("startOffset", function(d, i) {return i * 100 / numBarsData + 50 / numBarsData + '%';})
        .text(function(d) {return d; });
  });

});
