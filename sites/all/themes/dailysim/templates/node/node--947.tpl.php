<?php
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> node-sim"<?php print $attributes; ?>>
    <div class="content clearfix"<?php print $content_attributes; ?>>
        <div id="form-order">
            <h2>Thông tin khách hàng đặt SIM</h2>
            <?php
            $block = module_invoke('webform', 'block_view', 'client-block-41');
            print render($block['content']);
            ?>
        </div>
    </div>
    <div class="clearfix">
        <?php if (!empty($content['links'])): ?>
            <div class="links"><?php print render($content['links']); ?></div>
        <?php endif; ?>

    </div>

</div>
