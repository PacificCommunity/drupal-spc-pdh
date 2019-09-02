const gulp = require('gulp');
const spritesmith = require('gulp.spritesmith');

//npx gulp sprite
gulp.task('sprite', () => {
    var spriteData = 
        gulp.src('./img/spc_new/sprite_src/*.*')
            .pipe(spritesmith({
                imgName: 'spc_sprite.png',
                cssName: 'spc_sprite.css',
                padding: 20
            }));

    spriteData.img.pipe(gulp.dest('./img/sprite/'));
    spriteData.css.pipe(gulp.dest('./css/sprite/'));
});
