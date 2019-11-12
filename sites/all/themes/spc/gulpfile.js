const gulp = require("gulp");
const less = require("gulp-less");
const spritesmith = require("gulp.spritesmith");

//npx gulp sprite
gulp.task("sprite", () => {
  var spriteData = gulp.src("./img/spc_new/sprite_src/*.*").pipe(
    spritesmith({
      imgName: "spc_sprite.png",
      cssName: "spc_sprite.css",
      padding: 20
    })
  );

  spriteData.img.pipe(gulp.dest("./img/sprite/"));
  spriteData.css.pipe(gulp.dest("./css/sprite/"));
});

const build = () =>
  gulp
    .src("./less/style.less")
    .pipe(less())
    .pipe(gulp.dest("./css"));

gulp.task("build", build);
gulp.task("watch", () =>
  gulp.watch("./less/**/*.less", { ignoreInitial: false }, build)
);
