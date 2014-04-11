//open run on windows
void win_run(){
  //open run on windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
}

//open powershell on windows
void win_ps(){
  //open run
  win_run();
  //open powershell
  Keyboard.println(F("powershell -ExecutionPolicy Bypass"));
  delay(200);
}

//open a cmd on windows
void win_cmd(){
  //open run
  win_run;
  //open cmd
  Keyboard.println(F("cmd"));
  delay(200);
}
