(function ($) {
    var titles = $('.thematic-group-articles .thematic-group-article-item h4 a')
    if (titles) {
        titles.each(function(){
            var title = this.innerText;
            if (title.length > 40) {
                var shortTitle = $.trim(title).substring(0, 40).split(' ').slice(0, -1).join(' ') + '...';
                this.innerText = shortTitle;
            }
        })
    }
})(jQuery);
