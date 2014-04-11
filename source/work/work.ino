/*
Fully blown functionality for TR14 Badge
 1. If no active shield -> print token
 2. If active shield -> menu with 3 LEDs
 Choice for Serial Menu or direct Payloads
 */

////////////--INCLUDES

//for setting the ARDUINO to sleep
#include <avr/sleep.h>
//for EEPROM access
#include <EEPROM.h>
// for storing the strings in flash only
#include <avr/pgmspace.h>


/* INIT of global vars */

////////////--HARDWARE

//Pins for buttons and also check pins
const int bl = 7;
const int blc = 6;
const int brc = 5;
const int br = 4;

//Pins for leds
const int ll = 8;
const int llc = 9;
const int lrc = 2;
const int lr = 3;

//debounce
boolean bls = false;
boolean blcs = false;
boolean brcs = false;
boolean brs = false;

////////////--SOFTWARE

//--overall
//global mode
//FINAL TODO, change global mode to 'p'
byte gmode='p';
//global language, for changing keystrokes
// 0:us,1:de
byte gl = read_mem(2);





//--blind menu
//current menu position
int bmenu_pos=0;
int blinkcounter = 0;
boolean ledstatus = false;
int pl_slots= 5;
byte is_blink = 0; // help var for blinking functionallity during case 0
int is_console_active = 0;
//--hacking stuff
char username[21];

//setup function, run on each power-up
void setup(){

  // Running the first time
  if( gl != 0 && gl != 1) { 
    write_mem(2, 0);
    gl = 0;
  }
  set_mode();

  //Init buttons/check pins
  pinMode(bl,INPUT);
  pinMode(blc,INPUT);
  pinMode(brc,INPUT);
  pinMode(br,INPUT);

  if (gmode=='p'){
    start_prov();
  }
  else{
    get_username();
    if(digitalRead(bl)&&digitalRead(blc)&&digitalRead(brc)&&digitalRead(br)){
      gmode='0';
      init_blind_menu();
    } 
    else gmode='x';
  }


}

//arduino cycle function, will be repeated over and over
void loop(){

  switch (gmode) {
  case 'x': //no shield
    Keyboard.begin();
    delay(3000);
    print_token();
    Keyboard.end();
    gmode='z';
    break;

  case '0': //blind menu
    watch_buttons(); //go to the blind_menu tab
    if(is_blink || is_console_active){
      do_blink();
    }
    break;

  case '1': //serial menu mode
    doMenu(); //go to the serial_menu tab
    watch_buttons(); //go to the blind_menu tab
    if(is_blink || is_console_active){
      do_blink();
    }
    break;

  case '2': //do direct payload and sleep
    direct_payload(); //go to the direct_payload tab
    gmode='z';
    break;

  case 'z': //power down, and wait for reset
    power_down(); //done here
    break;

  case 'p': //Initial provisioning mode
    do_prov(); //go to the provisioning tab
    break;
  }
}

