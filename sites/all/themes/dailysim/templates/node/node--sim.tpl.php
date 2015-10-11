<?php
$term  = taxonomy_term_load($node->field_dai_ly['und'][0]['tid']);
$field_chiet_khau = field_get_items('taxonomy_term', $term,'field_chiet_khau');
$field_chiet_khau = _field_collection_load_items($field_chiet_khau);

?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

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
    <?php if(user_is_logged_in()):?>
    <h2>Thông tin quản lý sim</h2>
    <div id="info-sim">

                <div class="row">
                    <span class="label">Tên đại lý:</span>
                    <span class="value"><?php echo $node->field_dai_ly['und'][0]['taxonomy_term']->name;?></span>
                </div>
                <?php if(isset($node->field_dai_ly['und'][0]['taxonomy_term']->field_phone['und'][0])):?>
                <div class="row">
                    <span class="label">Số điện thoại đại lý:</span>
                    <span class="value"><?php echo $node->field_dai_ly['und'][0]['taxonomy_term']->field_phone['und'][0]['safe_value'];?></span>
                </div>
                <?php endif;?>
                <div class="row">
                    <span class="label">% Hoa hồng:</span>
                    <span class="value"><?php echo tinhHoaHongSim($node->field_gia['und'][0]['value'],$field_chiet_khau);?> %</span>
                </div>
                <?php if(isset($node->field_dai_ly['und'][0]['taxonomy_term']->field_ho_tro_cat_sim['und'][0])):?>
                <div class="row">
                    <span class="label">Phí hỗ trợ cắt sim (nếu có):</span>
                    <span class="value"><?php echo $node->field_dai_ly['und'][0]['taxonomy_term']->field_ho_tro_cat_sim['und'][0]['value'];?> VNĐ</span>
                </div>
                 <?php endif;?>
                <div class="row">
                    <span class="label">Giá thực của sim:</span>
                    <span class="value"><?php echo giaThucSim(tinhCongNoByPrice($node->field_gia['und'][0]['value'],$field_chiet_khau),$node->field_dai_ly['und'][0]['taxonomy_term']->field_ho_tro_cat_sim['und'][0]['value']);?> VNĐ</span>
                </div>
                <div class="row">
                    <span class="label">Tiền lời:</span>
                    <span class="value"><?php echo ($node->field_gia['und'][0]['value'] -
                            (tinhCongNoByPrice($node->field_gia['und'][0]['value'],$field_chiet_khau) - $node->field_dai_ly['und'][0]['taxonomy_term']->field_ho_tro_cat_sim['und'][0]['value']));?> VNĐ</span>
                </div>

<!--            <a class="daily-link" href="--><?php //echo base_path().drupal_get_path_alias('taxonomy/term/'.$node->field_dai_ly['und'][0]['taxonomy_term']->tid);?><!--">Xem chi tiết ></a>-->
    </div>
    <?php endif;?>

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
