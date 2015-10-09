<form id="search" action="<?php echo $GLOBALS['base_url']?>/search" method="get">
    <input name="do" value="search" type="hidden">
    <div class="row">
        <span class="line"></span>
        <div class="col-md-12 text-center">
            <div class="col-md-4">
                <select name="mang" class="form-control input-sm strong fixprice">
                    <option value="All">Chọn mạng</option>

                    <?php
                        $select_data = array(
                            array('value' => 27, 'key' => "Viettel"),
                            array('value' => 26, 'key' => "Mobifone"),
                            array('value' => 25, 'key' => "Vinaphone"),
                            array('value' => 28, 'key' => "Vietnamobile"),
                            array('value' => 29, 'key' => "Gmobile"),
                        )
                    ?>
                    <?php foreach($select_data as $select):?>
                        <?php if( isset($_GET['mang']) && $_GET['mang'] == $select['value']):?>2ang
                            <option selected value="<?php echo $select['value'];?>"><?php echo $select['key'];?></option>
                        <?php else:?>
                            <option value="<?php echo $select['value'];?>"><?php echo $select['key'];?></option>
                        <?php endif;?>
                    <?php endforeach;?>
                </select>
            </div>
            <div class="col-md-4">
                <div class="input-group fixprice">
                    <div class="input-group-addon font-12 strong"> Giá từ:</div>
                    <input name="gia[min]" value="<?php echo !empty($_GET['gia']['min'])?$_GET['gia']['min']:"";?>" class="form-control input-sm price" placeholder="100,000">
                </div>
            </div>
            <div class="col-md-4">
                <div class="input-group fixprice">
                    <div class="input-group-addon font-12 strong">Đến:</div>
                    <input name="gia[max]" value="<?php echo !empty($_GET['gia']['max'])?$_GET['gia']['max']:"";?>" class="form-control input-sm price" placeholder="1,000,000">
                </div>
            </div>
            <div class="clearfix"></div>
            <div class="row text-center">
                </br>
            </div>
            <div class="clearfix"></div>
            <div class="text-center">
                <div class="col-md-8 col-md-offset-1">
                    <input name="so" id="sim" value="<?php echo !empty($_GET['so'])?$_GET['so']:"";?>" class="form-control popover-dismiss" placeholder="Nhập số sim bạn cần tìm" data-container="body" data-toggle="popover" data-placement="bottom" data-content=" - Sử dụng dấu <span class='red'>x</span> đại điện cho 1 số và dấu <span class='red'>*</span> đại điện cho một chuỗi số. <br /> + Để tìm sim bắt đầu bằng 098, quý khách nhập vào 098*<br /> + Để tìm sim kết thúc bằng 888, quý khách nhập vào *888<br /> + Để tìm sim bắt đầu bằng 098 và kết thúc bằng 888, nhập vào 098*888<br /> + Để tìm sim bên trong có số 888, nhập vào 888<br /> + Để tìm sim bắt đầu bằng 098 và kết thúc bằng 808, 818, 828, 838, 848, 858, 868, 878, 888, 898 nhập vào 098*8x8<br /> " title="" data-original-title="Hướng dẫn tìm kiếm sim">
<!--                    <input type="hidden" name="so_op" value="contains">-->
                </div>
                <div class="col-md-offset-1"><button class="tim btn btn-info">Tìm sim</button></div>
            </div>
            <div class="clearfix"></div>
            <div class="row text-center">
            </div>
        </div>
    </div>
    <div class="clearfix"></div>
    <br><input type="hidden" name="submit" value="true">
</form>