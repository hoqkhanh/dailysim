<?php
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php print $user_picture; ?>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="content clearfix"<?php print $content_attributes; ?>>
        <?php
        // We hide the comments and links now so that we can ragnender them later.
        hide($content['links']);
        ?>
        <h2>Chi tiết sim số</h2>
        <div id="info-sim">
            <div class="row">
                <span class="label">Số sim:</span>
                <span class="value"><?php echo $title;?></span>
            </div>
            <div class="row">
                <span class="label">Giá tiền:</span>
                <span class="value"><?php echo $node->field_gia['und'][0]['value'];?> VNĐ</span>
            </div>
            <div class="row">
                <span class="label">Nhà mạng:</span>
                <span class="value"><?php echo $node->field_nh_m_ng['und'][0]['taxonomy_term']->name;?></span>
            </div>
            <div class="row">
                <span class="label">Loại sim:</span>
                <span class="value"><?php echo $node->field_lo_i_sim['und'][0]['taxonomy_term']->name;?></span>
            </div>
        </div>
    </div>
    <?php
    $block_payment = block_load('block', 3);
    $renderable_block=  _block_get_renderable_array(_block_render_blocks(array($block_payment)));
    ?>
    <div id="form-order">
        <h2>Thông tin khách hàng đặt SIM</h2>
        <?php
        $block = module_invoke('webform', 'block_view', 'client-block-41');
        print render($block['content']);
        ?>
    </div>
    <div id="block-payment">
        <h2><?php echo $renderable_block['block_3']['#block']->title;?></h2>
        <div class="content">
            <?php echo $renderable_block['block_3']['#markup'];?>
        </div>
    </div>


    <div class="clearfix">
        <?php if (!empty($content['links'])): ?>
            <div class="links"><?php print render($content['links']); ?></div>
        <?php endif; ?>

    </div>

</div>
