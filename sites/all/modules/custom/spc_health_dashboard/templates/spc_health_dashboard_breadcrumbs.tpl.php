<div class="breadcrumb">
    <?php foreach ($breadcrumbs as $key => $item): ?>
        <?php echo $key == 0 ? '' : '<div class="delimiter">&gt;</div>' ?>
        <div class="inline <?php echo $key ? 'dropdown' : 'first' ?>">
            <a href="<?php echo $item['url'] ?>">
                <?php echo $item['title'] ?>
            </a>
            <?php if (count($item['submenu']) > 0 ): ?>
                <div class="breadcrumb-subitems">
                    <div class="subitems-wrapper">
                    <?php foreach ($item['submenu'] as $subitem): ?>
                        <a href="<?php echo $subitem['url'] ?>">
                            <?php echo $subitem['title'] ?>
                        </a>
                    <?php endforeach; ?>
                    </div>
                </div>
            <?php endif; ?>
        </div>
    <?php endforeach; ?>
</div>