<form id="search" action="/">
    <input name="do" value="search" type="hidden">
    <div class="row">
        <span class="line"></span>
        <div class="col-md-12 text-center">
            <div class="col-md-4">
                <select name="network" class="form-control input-sm strong fixprice">
                    <option value="0">Chọn mạng</option>
                    <option value="1">Viettel</option>
                    <option value="2">Mobifone</option>
                    <option value="3">Vinaphone</option>
                    <option value="4">Vietnamobile</option>
                    <option value="5">Gmobile</option>
                </select>
            </div>
            <div class="col-md-4">
                <div class="input-group fixprice">
                    <div class="input-group-addon font-12 strong"> Giá từ:</div>
                    <input name="giatu" class="form-control input-sm price" placeholder="100,000">
                </div>
            </div>
            <div class="col-md-4">
                <div class="input-group fixprice">
                    <div class="input-group-addon font-12 strong">Đến:</div>
                    <input name="den" class="form-control input-sm price" placeholder="1,000,000">
                </div>
            </div>
            <div class="clearfix"></div>
            <div class="row text-center">
                </br>
            </div>
            <div class="clearfix"></div>
            <div class="text-center">
                <div class="col-md-8 col-md-offset-1">
                    <input name="sim" id="sim" value="" class="form-control popover-dismiss" placeholder="Nhập số sim bạn cần tìm" data-container="body" data-toggle="popover" data-placement="bottom" data-content=" - Sử dụng dấu <span class='red'>x</span> đại điện cho 1 số và dấu <span class='red'>*</span> đại điện cho một chuỗi số. <br /> + Để tìm sim bắt đầu bằng 098, quý khách nhập vào 098*<br /> + Để tìm sim kết thúc bằng 888, quý khách nhập vào *888<br /> + Để tìm sim bắt đầu bằng 098 và kết thúc bằng 888, nhập vào 098*888<br /> + Để tìm sim bên trong có số 888, nhập vào 888<br /> + Để tìm sim bắt đầu bằng 098 và kết thúc bằng 808, 818, 828, 838, 848, 858, 868, 878, 888, 898 nhập vào 098*8x8<br /> " title="" data-original-title="Hướng dẫn tìm kiếm sim">
                </div>
                <div class="col-md-offset-1"><button class="tim btn btn-info">Tìm sim</button></div>
            </div>
            <div class="clearfix"></div>
            <div class="row text-center">
            </div>
            <div class="description">
                <div class="line"></div>
                <div><strong class="red font-11">Hot key:</strong> <span class="hotkey"><a href="0912*68" class="hotkey">0912*68</a>, <a href="090*888" class="hotkey">090*888</a>, <a href="0913*" class="hotkey">0913*</a> </span></div>
            </div>
        </div>
    </div>
    <div class="clearfix"></div>
    <div class="fullsearch text-center">
        <div class="row">
            Sim 10 số <input type="radio" value="0" name="type">Sim 11 số <input type="radio" value="1" name="type">
            <div class="clearfix"></div>
        </div>
        <div></div>
    </div>
    <br><input type="hidden" name="submit" value="true">
</form>