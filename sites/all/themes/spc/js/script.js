(function ($) {
    var titles = $('#mini-panel-thematic_articles_and_publicatio .thematic-group-articles-item h4 a')
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
