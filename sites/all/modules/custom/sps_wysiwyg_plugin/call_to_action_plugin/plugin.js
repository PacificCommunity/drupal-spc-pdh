(function($) {
    CKEDITOR.plugins.add( 'call_to_action_plugin', {
        init: function( editor ){

            const styles = ''
                +'display: inline-block;'
                + 'background: #001E73;'
                + 'padding: 6px 22px;'
                + 'border-radius: 20px;'
                + 'color: #fff;'
                + 'margin: 10px 0px;';
                
            const text = 'Make Double click to set the text';

            editor.addCommand( 'call_to_action_command', {
                exec : function( editor ) {
                    editor.insertHtml( '<a href="" style="' + styles + '">' + text + '</a>' );
                }
            });

            editor.ui.addButton( 'call_to_action_button', {
                label: 'Call to Action Button',
                command: 'call_to_action_command',
                icon: this.path + 'images/action_button_fill.svg'
            });
        }
    });
})(jQuery);
