/*
everything concerned with printing token
*/
/////FINAL FUNCTION

void print_token(){
  for (int i=500; i<pdatal+500;i++){
    Keyboard.print((char)read_mem(i));
  }
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}
