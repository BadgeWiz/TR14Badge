//Will switch the ARDUINO off, no recovery except for reset!
void power_down(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
}

//blink LEDs once
void blinkL(){
  digitalWrite(ll, LOW);
  digitalWrite(llc, LOW);
  digitalWrite(lrc, LOW);
  digitalWrite(lr, LOW);
  delay(100);
  digitalWrite(ll, HIGH);
  digitalWrite(llc, HIGH);
  digitalWrite(lrc, HIGH);
  digitalWrite(lr, HIGH);
  delay(500);
  digitalWrite(ll, LOW);
  digitalWrite(llc, LOW);
  digitalWrite(lrc, LOW);
  digitalWrite(lr, LOW);
  delay(500);
  //reset LEDs to current blind menu position
  bmenu_item(bmenu_pos);      
}

//blink LEDs c-times
void blinkL(int c){
  digitalWrite(ll, LOW);
  digitalWrite(llc, LOW);
  digitalWrite(lrc, LOW);
  digitalWrite(lr, LOW);
  delay(100);
  for (int i=0; i<c; i++)
  {
    digitalWrite(ll, HIGH);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, HIGH);
    delay(500);
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    delay(500);
  }
  //reset LEDs to current blind menu position
  bmenu_item(bmenu_pos);
}

void toggleleds(){
  if(ledstatus){
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    ledstatus==false;
  }
  else{
    digitalWrite(ll, HIGH);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, HIGH);
    ledstatus==true;
  }
}


