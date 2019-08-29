<div class="console">
    <?php foreach ($messages as $type => $message_list): ?>
        <div class="messages <?php print $type; ?>">
            <ul>
            <?php foreach ($message_list as $message): ?>
                <li><?php print $message ?></li>
            <?php endforeach; ?>
            </ul>    
        </div>
    <?php endforeach; ?>
</div>

<div class="spc-user-login-form-wrapper">
  <?php print drupal_render_children($form) ?>
</div>