(function($) {
 CKEDITOR.plugins.add( 'my_plugin', {
  init: function( editor )
  {
   editor.addCommand( 'wysiwyg_command', {
    exec : function( editor ) {
     //here is where we tell CKEditor what to do.
     editor.insertHtml( '<a href="">call to action</a>' );
    }
   });
   
   editor.ui.addButton( 'my_plugin_button', {
    label: 'Do something awesome', //this is the tooltip text for the button
    command: 'wysiwyg_command',
    icon: '/home/shchedrin/projects/pacific/sites/all/modules/custom/sps_wysiwyg_plugin/images/action_button.png'
   });
  }
 });
})(jQuery);
