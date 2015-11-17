<?php

global $TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT, $THAN_TAI, $OND_DIA,
       $TIEN_DON, $TIEN_DOI, $GANH_DAO, $NAM_SINH, $TAXI, $LAP, $KEP, $DOI,
       $DAO, $DACBIET, $TAM_HOA_DON, $TAM_HOA_KEP, $DAUSOCO, $TU_QUY_GIUA,
       $NGU_QUY_GIUA, $LUC_QUY_GIUA, $TAXI_2, $TAXI_3, $TAXI_4;

    $TU_QUY = 1;
    $NGU_QUY = 3;
    $LUC_QUY = 2;
    $LOC_PHAT = 4;
    $THAN_TAI = 5;
    $OND_DIA = 6;
    $TIEN_DON = 7;
    $GANH_DAO = 36;
    $TAXI = 9;
    $LAP = 12;
    $KEP = 13;
    $DOI = 14;
    $DAO = 15;
    $GANH = 16;
    $DACBIET = 17;
    $TAM_HOA_DON = 20;
    $TAM_HOA_KEP = 21;
    $DAUSOCO = 19;
    $NAM_SINH = 18;

    $NHO_3TR = 100;
    $TU_3TR_6TRU = 101;
    $LON_6TR = 102;

    $TU_QUY_GIUA = 33;
    $NGU_QUY_GIUA = 34;
    $LUC_QUY_GIUA = 35;

    $TAXI_2 = 9;
    $TAXI_3 = 10;
    $TAXI_4 = 11;

function _get_kind_of_phone_number($number){
    global $TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT, $THAN_TAI, $OND_DIA,
           $TIEN_DON, $TIEN_DOI, $GANH_DAO, $NAM_SINH, $TAXI, $LAP, $KEP, $DOI,
           $DAO, $DACBIET, $TAM_HOA_DON, $TAM_HOA_KEP, $DAUSOCO, $NAM_SINH, $TU_QUY_GIUA,
           $NGU_QUY_GIUA, $LUC_QUY_GIUA, $TAXI_2, $TAXI_3, $TAXI_4;

    $types = [$TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT, $THAN_TAI, $OND_DIA,
        $TIEN_DON, $TIEN_DOI, $GANH_DAO, $NAM_SINH, $TAXI, $LAP, $KEP, $DOI,
        $DAO, $DACBIET, $TAM_HOA_DON, $TAM_HOA_KEP, $DAUSOCO, $NAM_SINH,
        $TU_QUY_GIUA,$NGU_QUY_GIUA, $LUC_QUY_GIUA, $TAXI_2, $TAXI_3, $TAXI_4];

    $functionNames = ['is_luc_quy_giua', 'is_ngu_quy_giua', 'is_tu_quy_giua',
        'is_luc_quy', 'is_ngu_quy', 'is_tu_quy','is_loc_phat',
        'is_than_tai','is_ong_dia','is_tien_don', 'is_taxi_2', 'is_taxi_3', 'is_taxi_4',
        'is_kep', 'is_ganh_dao', 'is_nam_sinh', 'is_tam_hoa_don'];
    $result = 0;
    foreach($functionNames as $functionName){
        $result = $functionName($number);
        if($result != 0){
            break;
        }
    }
    switch($result){
        case $TU_QUY:{
            return $TU_QUY;
            break;
        }
        case $NGU_QUY:{
            return $NGU_QUY;
            break;
        }
        case $LUC_QUY:{
            return $LUC_QUY;
            break;
        }
        case $LOC_PHAT:{
            return $LOC_PHAT;
            break;
        }
        case $THAN_TAI:{
            return $THAN_TAI;
            break;
        }
        case $OND_DIA:{
            return $OND_DIA;
            break;
        }
        case $TIEN_DON:{
            return $TIEN_DON;
            break;
        }
        case $KEP:{
            return $KEP;
            break;
        }
        case $GANH_DAO:{
            return $GANH_DAO;
            break;
        }
        case $NAM_SINH:{
            return $NAM_SINH;
            break;
        }
        case $TAXI_2:{
            return $TAXI_2;
            break;
        }
        case $TAXI_3:{
            return $TAXI_3;
            break;
        }
        case $TAXI_4:{
            return $TAXI_4;
            break;
        }
        case $TAM_HOA_DON:{
            return $TAM_HOA_DON;
            break;
        }
        case $TU_QUY_GIUA:{
            return $TU_QUY_GIUA;
            break;
        }
        case $NGU_QUY_GIUA:{
            return $NGU_QUY_GIUA;
            break;
        }
        case $LUC_QUY_GIUA:{
            return $LUC_QUY_GIUA;
            break;
        }
        default:
            return 0;
            break;
    }
}


function is_tu_quy($phoneNumber){
    global $TU_QUY;
    $result = preg_match('/([0-9])\1{3}$/',$phoneNumber);
    if($result){
        return $TU_QUY;
    }
    return $result;
}

function is_tu_quy_giua($phoneNumber){
    global $TU_QUY_GIUA;
    $result = preg_match('/([0-9])\1{3}/',$phoneNumber);
    $isTuQuy = is_tu_quy($phoneNumber);
    if(!empty($isTuQuy)){
        return $isTuQuy;
    }
    if($result){
        return $TU_QUY_GIUA;
    }
    return $result;
}

function is_ngu_quy($phoneNumber){
    global $NGU_QUY;
    $result = preg_match('/([0-9])\1{4}$/',$phoneNumber);
    if($result){
        return $NGU_QUY;
    }
    return $result;
}

function is_ngu_quy_giua($phoneNumber){
    global $NGU_QUY_GIUA;
    $result = preg_match('/([0-9])\1{4}/',$phoneNumber);
    $isNguQuy = is_ngu_quy($phoneNumber);
    if(!empty($isNguQuy)){
        return $isNguQuy;
    }
    if($result){
        return $NGU_QUY_GIUA;
    }
    return $result;
}


function is_luc_quy($phoneNumber){
    global $LUC_QUY;
    $result = preg_match('/([0-9])\1{5}$/',$phoneNumber);
    if($result){
        return $LUC_QUY;
    }
    return $result;
}

function is_luc_quy_giua($phoneNumber){
    global $LUC_QUY_GIUA;
    $result = preg_match('/([0-9])\1{5}/',$phoneNumber);
    $isLucQuy = is_luc_quy($phoneNumber);

    if(!empty($isLucQuy)){
        return $isLucQuy;
    }
    if($result){
        return $LUC_QUY_GIUA;
    }
    return $result;
}


function is_loc_phat($phoneNumber){
    global $LOC_PHAT;
    $result = preg_match('/(68|86|6688|8866|688|866|1368)$/',$phoneNumber);
    if($result){
        return $LOC_PHAT;
    }
    return $result;
}

function is_than_tai($phoneNumber){
    global $THAN_TAI;
    $result = preg_match('/(39|79)$/',$phoneNumber);
    if($result){
        return $THAN_TAI;
    }
    return $result;
}

function is_ong_dia($phoneNumber){
    global $OND_DIA;
    $result = preg_match('/(78|38)$/',$phoneNumber);
    if($result){
        return $OND_DIA;
    }
    return $result;
}

function is_tien_don($phoneNumber){
    global $TIEN_DON;
    $result = preg_match('/(012|123|234|345|456|567|678|789|1357|357|579|02468|0246|024|2468|246|468|000102|010203|020304|030405|040506|050607|111213|212223|131415|313233|141516|414243|151617|515253|161718|616263|171819|717273|232425|323435|242526|424344|252627|525354|262728|626364|272829|72737|4303132|333435|343536|353637|373839|454647|484950|535455|545556|565758|575859|646566|656667|676869|737475|747576|757677|767778|777879|808182|818283|828384|838485|848586|858687|868788|909192|919293|929394|939495|949596|959697|969798|979899|707172|718191|606162|121314|151617|161718|171819|142434)$/',$phoneNumber);
    if($result){
        return $TIEN_DON;
    }
    return $result;
}

function is_tien_doi($phoneNumber){
}


//function is_taxi($phoneNumber){
//    global $TAXI;
//    $result = preg_match('/(([0-9]{3})\g2|([0-9]{2})\g3{2})$/',$phoneNumber);
//    if($result){
//        return $TAXI;
//    }
//    return $result;
//}

function is_taxi_2($phoneNumber){
    global $TAXI_2;
    $result = preg_match('/([0-9]{2})\g1{2}$/',$phoneNumber);
    if($result){
        return $TAXI_2;
    }
    return $result;
}

function is_taxi_3($phoneNumber){
    global $TAXI_3;
    $result = preg_match('/(([0-9]{3})\g2)$/',$phoneNumber);
    if($result){
        return $TAXI_3;
    }
    return $result;
}

function is_taxi_4($phoneNumber){
    global $TAXI_4;
    $result = preg_match('/([0-9]{4})\g1{1}$/',$phoneNumber);
    if($result){
        return $TAXI_4;
    }
    return $result;
}

function is_lap($phoneNumber){
}

function is_kep($phoneNumber){
    global $KEP;
    $result = preg_match('/(000111|0011|000222|0022|000333|0033|000444|0044|000555|0055|000666|0066|000777|0077|000888|0088|000999|0099|111000|1100|111222|1122|111333|1133|111444|1144|111555|1155|111666|1166|111777|1177|111888|1188|111999|1199|222000|2200|222111|2211|222333|2233|222444|2244|222555|2255|222666|2266|222777|2277|222888|2288|222999|2299|333000|3300|333111|3311|333222|3322|333444|3344|333555|3355|333666|3366|333777|3377|333888|3388|333999|3399|444000|4400|444111|4411|444222|4422|444333|4433|444555|4455|444666|4466|444777|4477|444888|4488|444999|4499|555000|5500|555111|5511|555222|5522|555333|5533|555444|5544|555666|5566|555777|5577|555888|5588|555999|5599|666000|6600|666111|6611|666222|6622|666333|6633|666444|6644|666555|6655|666777|6677|666888|6688|666999|6699|777000|7700|777111|7711|777222|7722|777333|7733|777444|7744|777555|7755|777666|7766|777888|7788|777999|7799|888000|8800|888111|8811|888222|8822|888333|8833|888444|8844|888555|8855|888666|8866|888777|8877|888999|8899|999000|9900|999111|9911|999222|9922|999333|9933|999444|9944|999555|9955|999666|9966|999777|9977|999888|9988)$/',$phoneNumber);
    if($result){
        return $KEP;
    }
    return $result;
}

function is_doi($phoneNumber){
}

function is_ganh_dao($phoneNumber){
    global $GANH_DAO;
    $result = preg_match('/(([0-9]{2})([0-9]{1,2})\g{-2}|([0-9]{1})([0-9]{1})\g{-1}\g{-2})$/',$phoneNumber);
    if($result){
        return $GANH_DAO;
    }
    return $result;
}


function is_dac_biet($phoneNumber){
}

function is_nam_sinh($phoneNumber){
    global $NAM_SINH;
    $result = preg_match('/(((0[123456789]|[1-2][0-9]|30)(0[123456789]|10|11|12)(([6-9][0-9])|([1][0-2])|([0][0-9])))|19[6-9]\d|20[0-1]\d)$/',$phoneNumber);
    if($result){
        return $NAM_SINH;
    }
    return $result;
}

function is_dau_so_co($phoneNumber){
}

function is_tam_hoa_don($phoneNumber){
    global $TAM_HOA_DON;
    $result = preg_match('/([0-9])\1{2}$/',$phoneNumber);
    if($result){
        return $TAM_HOA_DON;
    }
    return $result;
}

function is_tam_hoa_kep($phoneNumber){
}

function is_nam_sinh_dd_mm_yy($phoneNumber){
}


// END OF SIM TYPE DEFINITION

function convertTextToNumber($text){
    $textAfterFormat = str_replace(array(",","."),"",$text);
    $priceNumber = intval($textAfterFormat);
    return $priceNumber;
}

function formatText($text){
    $textAfterFormat = str_replace(array(",","."),"",$text);
    return $textAfterFormat;
}

function congNoTypeCalculation($data, $chietKhau){
    $tongCongNo = 0;
    foreach($data as $sim){
                $tongCongNo += tinhCongNoByPrice($sim->field_gia['und'][0]['value'], $chietKhau);
    }
    return $tongCongNo;
}

function tinhCongNoByPrice($price, $chietKhau){
    foreach($chietKhau as $loaiChietKhau){
        if(empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && !empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price <= $loaiChietKhau->field_hang_muc_toi_da['und'][0]['value']){
                return $price* (100 - $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value']) / 100;
        };
        if(!empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && !empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price >= $loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value']
            && $price <= $loaiChietKhau->field_hang_muc_toi_da['und'][0]['value']){
            return $price* (100 - $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value']) / 100;
        };
        if(!empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price >= $loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value']){
            return $price* (100 - $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value']) / 100;
        };
    }
    return 0;
}

function tinhHoaHongSim($price, $chietKhau){
    foreach($chietKhau as $loaiChietKhau){
        if(empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && !empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price <= $loaiChietKhau->field_hang_muc_toi_da['und'][0]['value']){
            return $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value'];
        };
        if(!empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && !empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price >= $loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value']
            && $price <= $loaiChietKhau->field_hang_muc_toi_da['und'][0]['value']){
            return $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value'];
        };
        if(!empty($loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value'])
            && empty($loaiChietKhau->field_hang_muc_toi_da['und'][0]['value'])
            && $price >= $loaiChietKhau->field_hang_muc_toi_tieu['und'][0]['value']){
            return $loaiChietKhau->field_ti_le_chiet_khau['und'][0]['value'];
        };
    }
    return 0;
}

function giaThucSim($giaSauChietKhau,$phiCatSim){
   $result =  $giaSauChietKhau - $phiCatSim;
   if($result < 0){
       return $giaSauChietKhau;
   }
    return $result;
}

function checkNhaMang($phoneNumber){
    if(preg_match('/^(091|094|0123|0124|0125|0127|0129)/',$phoneNumber)){
        return "vinaphone";
    }
    if(preg_match('/^(090|093|0120|0121|0122|0126|0128)/',$phoneNumber)){
        return "mobifone";
    }
    if(preg_match('/^(097|098|096|0162|0163|0164|0165|0166|0167|0168|0169)/',$phoneNumber)){
        return "viettel";
    }
    if(preg_match('/^(092|0186|0188)/',$phoneNumber)){
        return "vietnamobile";
    }
    if(preg_match('/^(099|0199)/',$phoneNumber)){
        return "gmobile";
    }
    return null;
}

function getNhaMangTermId($phoneNumber){
    $nhaMang = checkNhaMang($phoneNumber);
    $result = null;
    if(!empty($nhaMang)){
        $result = reset(taxonomy_get_term_by_name($nhaMang,'provider'));
    }
    return $result;
}
?>