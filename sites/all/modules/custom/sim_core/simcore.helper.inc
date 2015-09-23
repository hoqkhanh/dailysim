<?php
global $TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT, $THAN_TAI, $OND_DIA, $TIEN_DON, $TIEN_DOI;

    $TU_QUY = 1;
    $NGU_QUY = 2;
    $LUC_QUY = 3;
    $LOC_PHAT = 4;
    $THAN_TAI = 5;
    $OND_DIA = 6;
    $TIEN_DON = 7;
    $TIEN_DOI = 8;


function _get_kind_of_phone_number($number){
    global $TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT, $THAN_TAI, $OND_DIA, $TIEN_DON, $TIEN_DOI;
    $types = [$TU_QUY, $NGU_QUY, $LUC_QUY, $LOC_PHAT,
        $THAN_TAI, $OND_DIA, $TIEN_DON, $TIEN_DOI];
    $functionNames = ['is_tu_quy','is_ngu_quy','is_luc_quy','is_loc_phat',
        'is_than_tai','is_ong_dia','is_tien_don'];
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
        default:
            return 0;
            break;
    }
}


function is_tu_quy($phoneNumber){
    global $TU_QUY;
    $result = preg_match('/([0-9])\1{3}/',$phoneNumber);
    if($result){
        return $TU_QUY;
    }
    return $result;
}

function is_ngu_quy($phoneNumber){
    global $NGU_QUY;
    $result = preg_match('/([0-9])\1{4}/',$phoneNumber);
    if($result){
        return $NGU_QUY;
    }
    return $result;
}


function is_luc_quy($phoneNumber){
    global $LUC_QUY;
    $result = preg_match('/([0-9])\1{5}/',$phoneNumber);
    if($result){
        return $LUC_QUY;
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
?>