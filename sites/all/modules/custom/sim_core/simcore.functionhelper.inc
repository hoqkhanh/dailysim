<?php
/*
* support load field_collection_items
*/
function _field_collection_load_items($fields){

if(!$fields || empty($fields)){
return false;
}
$items = array();
foreach ($fields as $field) {
$items[] = field_collection_field_get_entity($field);

}
// Load up the field collection items
// Load up the field collection items
//$items_revision = field_collection_item_revision_load($revision);




return $items;
}
function _field_collection_get_item($item,$field_name){

if(!$item || empty($item)){
return false;
}
$item = field_get_items('field_collection_item',$item,$field_name);

return $item;
}