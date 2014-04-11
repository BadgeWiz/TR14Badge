/*
Blind Menu
 For 4 LEDs and 4 buttons
 */
void watch_buttons(){
  //bl
  //increase blind menu position
  if (!digitalRead(bl) && (!bls)){
    //button pressed

    // you can't switch payloads when console is active 
    if(!is_console_active) {
      bmenu_item(bmenu_pos+1);
      delay(150);
      bls=true;
    }
  } 
  else if(digitalRead(bl) && bls){
    bls=false;
  }
  //blc
  //print token
  if (!digitalRead(blc) && (!blcs)){
    //button pressed

    // you can't print a token when serial is active 
    if(!is_console_active) {
      digitalWrite(ll, HIGH);
      print_token();
      digitalWrite(ll, LOW);
      blcs=true;
    }
  } 
  else if(digitalRead(blc) && blcs){
    blcs=false;
  }
  //brc
  //show help
  if (!digitalRead(brc) && (!brcs)){
    //button pressed

    // you can't switch payloads when console is active 
    if(!is_console_active) {
      bmenu_item(bmenu_pos+1);
      delay(150);
      brcs=true;
    }
  } 
  else if(digitalRead(brc) && brcs){
    brcs=false;
  }
  //br
  //firepayload
  if (!digitalRead(br) && !brs){
    //button pressed

    do_bmenu_item();
    brs=true;
  } 
  else if(digitalRead(br) && brs){
    brs=false;
  }
}

//init LEDs
void init_blind_menu(){
  //LEDs
  pinMode(ll, OUTPUT);
  pinMode(llc, OUTPUT);
  pinMode(lrc, OUTPUT);
  pinMode(lr, OUTPUT);
  bmenu_item(0);
}

//Execute selected menu item
void do_bmenu_item(){
  Keyboard.begin();
  delay(500);
  switch(bmenu_pos){
  case 0:
    digitalWrite(ll, HIGH);
    print_token();
    digitalWrite(ll, LOW);
    break;
  case 1:
    if(is_console_active) {
      //start serial mode
      gmode = '0';
      Serial.end();
      is_console_active = 0;
    }
    else {
      //start serial mode
      gmode = '1';
      is_console_active = 1;
    }
    break;
    // Payloads 2 to 7
  default:
    if(bmenu_pos <= 7 && bmenu_pos >= 2) 
      do_payload(fetch_payload(bmenu_pos-2));
    break;
  }
  delay(500);
  Keyboard.end();
}

//change menu item
void bmenu_item(int bmpos){
  bmenu_pos=bmpos;
  if (bmenu_pos >= 8){
    bmenu_pos=0;
  }
  switch(bmenu_pos){
  case 0:        // Function 0 
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    is_blink = 1;    
    break;
  case 1: // Function 1, Binary 0001
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, HIGH);
    break;
  case 2: // Function 2, Binary 0010
    digitalWrite(llc, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, LOW);
    break;
  case 3: // Function 3, Binary 0011
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, HIGH);
    break;
  case 4: // Function 4, Binary 0100
    digitalWrite(ll, LOW);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    break;
  case 5: // Function 5, Binary 0101
    digitalWrite(ll, LOW);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, HIGH);
    break;
  case 6: // Function 6, Binary 0110 
    digitalWrite(ll, LOW);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, LOW);
    break;
  case 7: // Function 7, Binary 0111
    digitalWrite(ll, LOW);
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, HIGH);
    break;
  default:
    digitalWrite(ll, LOW);
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    break;
  }
  // when after case 0 mode is changed, blinking must stop
  if(bmenu_pos)
    is_blink = 0;
}

/* All 4 LEDs blinking
 Thats the case when Function 0 (print token) is called or the serial menu is active
 */
int blink_counter = 0;
int blink_counterh = 0;
int f1 = 8000;
int f2_h = 8;
int f2_l = 20;
int ledht = false;
int blink_state = 0;
boolean led = false;


void do_blink() {

  if (blink_counter > f1){
    blink_counter=0;
    blink_state++;
    if (blink_state>3){
      blink_state=0;
    }
  }
  else{
    blink_counter++;
  }

  switch(blink_state){
  case 0://off
    digitalWrite(llc, LOW);
    digitalWrite(lrc, LOW);
    digitalWrite(lr, LOW);
    break;
  case 1://half
    if (ledht && blink_counterh >= f2_h){
      digitalWrite(llc, LOW);
      digitalWrite(lrc, LOW);
      digitalWrite(lr, LOW);
      blink_counterh = 0;
      ledht = false;
    }
    if (!ledht && blink_counterh >= f2_l){
      digitalWrite(llc, HIGH);
      digitalWrite(lrc, HIGH);
      digitalWrite(lr, HIGH);
      blink_counterh = 0;
      ledht = true;
    }
    blink_counterh++;
    break;
  case 2://on
    digitalWrite(llc, HIGH);
    digitalWrite(lrc, HIGH);
    digitalWrite(lr, HIGH);
    break;
  case 3://half
    if (ledht && blink_counterh >= f2_h){
      digitalWrite(llc, LOW);
      digitalWrite(lrc, LOW);
      digitalWrite(lr, LOW);
      blink_counterh = 0;
      ledht = false;
    }
    if (!ledht && blink_counterh >= f2_l){
      digitalWrite(llc, HIGH);
      digitalWrite(lrc, HIGH);
      digitalWrite(lr, HIGH);
      blink_counterh = 0;
      ledht = true;
    }
    blink_counterh++;
    break;
  }




  if(digitalRead(ll) && is_console_active == 1) {
    digitalWrite(ll, LOW);
  }
  else if(!digitalRead(ll) && is_console_active == 1) {
    digitalWrite(ll, HIGH);
  }    
}





