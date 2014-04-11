/*
Stuff needed for direct attack function
*/

void direct_payload(){
  do_payload(get_direct_payload()); 
}

byte get_direct_payload(){
  return read_mem(1);
}

void set_direct_payload(char n){
  write_mem(1, n);
  store_mode('2');
}
