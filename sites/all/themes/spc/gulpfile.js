const gulp = require('gulp');
const spritesmith = require('gulp.spritesmith');

gulp.task('sprite', () => {
    var spriteData = 
        gulp.src('./img/spc_new/*.*')
            .pipe(spritesmith({
                imgName: '/sites/all/themes/spc/img/sprite/spc_sprite.png',
                cssName: 'spc_sprite.css',
                padding: 20
            }));

    spriteData.img.pipe(gulp.dest('./img/sprite/'));
    spriteData.css.pipe(gulp.dest('./css/sprite/'));
});
