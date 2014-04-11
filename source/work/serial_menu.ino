
/*
Serial control interface
 */



//all vars for serial
const int max_c_chars = 32;
char command[max_c_chars];
int newchar = 0;
int char_c_count = 0;
int char_p_count = 0;
boolean param_input=false;
int ret[2];
boolean rmode=false;
boolean debug=false;

//start serial port
void init_serial_menu() {
  Serial.begin(9600);
  Serial.println(F("Welcome to the TROOPERS14 Badge"));
  Serial.println("");
  Serial.println(F("Type h for the help menu"));
  Serial.print(F("Your wish, "));
  Serial.print(username);
  Serial.print(F(">"));
}

//the actual input and output function
void doMenu() {
  if(Serial.available()) {
    newchar = Serial.read();
    Serial.print(char(newchar));
    if(newchar != 13) {
      command[char_c_count] = char(newchar);
      char_c_count++;
    }
  }


  //command char iterater
  if((newchar == 13) || (char_c_count >= max_c_chars)) {
    Serial.flush();
    Serial.println("");
    Serial.print(F("<"));
    Serial.println(command);
    if ((command[0] == 'H') || (command[0] == 'h') || (command[0] == '?')){
      if (char_p_count == 0){
        Serial.println(F("Troopers 2014 Badge HELP"));
        Serial.println(F("The input is not case sensitive"));
        Serial.println(F("H, Help - Shows this overview"));
        Serial.print(F("T, Toogle Langueage between DE and US(default). Current Keyboard Layout: "));
        Serial.println((read_mem(2)) ? "DE" : "US");
        //Serial.println(F("H Command, Help Command - Shows help concerning Command"));
        Serial.println(F("L, ListPayloads - View all coded Payloads"));
        Serial.println(F("S, SetMenu - Choose Payload order for Blind Menu"));
        //Serial.println(F("D, DirectPayload - Set Payload for next attach"));
        //Serial.println(F("P, Print - Show current payload configurations"));
        Serial.println(F("X, Exit - Exit"));
        Serial.println("");
        if (debug){
          Serial.println(F("Further commands:"));
          Serial.println(F(""));
          Serial.println(F("r xxxx yyyy - read memory from xxxx to yyyy"));
          Serial.println(F("w xxxx abcde - write string, starting at xxxx"));
          Serial.println(F("moder - toggle printing Hex or actual chars for r command"));
          Serial.println(F("erasemem - overwrite EEPROM with NULL bytes"));
          Serial.println(F("doprovisioning - reset settings to freshly provisioned state"));
          Serial.println(F("resetpayloads - reset payload list to 1-6"));
        }
        /*Trooper ORIG
         if (debug){
         Serial.println(F("Dev notes:"));
         Serial.println(F("Debug: r, w, n for debuging memory (start end)"));
         Serial.println(F("Debug: Reminder -> fix number format to not need preceding zeros"));
         Serial.println(F("moder"));
         }
         */
      }
      /*
      else{
       Serial.print(F("Help for the "));
       Serial.print(command);
       Serial.println(F("command has not yet been implemented or the command name is incorrect!"));
       }*/
    }
    else if (((command[0] == 'T') || (command[0] == 't')) && command[1] == '\0') {
      Serial.print(F("Language set to: " ));
      if(gl == 0) {
        gl = 1;
        Serial.println(F("DE"));
      }
      else if(gl == 1) {
        gl = 0;
        Serial.println(F("US"));
      }
      else {
        gl = 0;
        Serial.println(F("US"));
        Serial.println(F("INFO: Language var was just initialised in EEPROM. It wasn't set before. Possibly you overwrote some bytes accidentally."));
      }
      write_mem(2, gl);
    }
    else if ((strcasecmp(command, "l") == 0)){
      sprint_payloads();
    }

    else if (((command[0] == 'S') || (command[0] == 's') && (command[1]==32))){
      if (two_para(command)){
        if ((ret[0]<pl_slots)&&(ret[0]>0)){//correct slot number?
          if ((ret[1]>0)&&(ret[1]<=pl_amount)){//correct payload id?
            if (two_para(command)){
              write_mem((100+ret[0]-1),((char)ret[1]));//store it!
            }

          }
          else{//wrong payload id
            Serial.println(F("Invalid payload id"));
          }
        }
        else{//wrong slot number
          Serial.print(F("You only have "));
          Serial.print(pl_slots);
          Serial.println(F(" available slots"));
          Serial.println(F("Starting at 1"));
        }
      }
    }
    /*
     else if ((command[0] == 'D') || (command[0] == 'd')){
     if (one_para(command)){
     if (command[0] < pl_amount){//check if para id is small enough
     if (command[0] == 99){ //reset direct payload mode
     store_mode('x');
     Serial.println(F("No payload will be fired on next start. The badge will reboot in default mode"));
     }
     else{
     //store selected payload id
     set_direct_payload(command[0]);
     Serial.println(F("Warning: The selected payload will automatically be fired on next attach!"));
     Serial.println(F("Type d 99 to revoke the payload")); 
     }      
     }
     
     }
     }
     */
    else if (((command[0] == 'P') || (command[0] == 'p'))&&(command[1]=='\0')){
      for (int i=0; i < pl_slots; i++) {
        Serial.println(F("The current payload configuration is:"));
        Serial.print(F("Position "));
        Serial.print(i);
        Serial.print(F(" fires payload number: "));
        Serial.println(read_mem(100 + i));
      }
    }
    //dev commands, use with care
    else if ((strcasecmp(command, "erasemem") == 0)){
      for (int i=0;i<1500;i++)
      {
        write_mem(i,'\0');
      }
    }
    else if ((strcasecmp(command, "doprovisioning") == 0)){
      finalize_prov();
    }
    else if ((strcasecmp(command, "resetpayloads") == 0)){
      for (int i=0;i<pl_amount;i++)
      {
        write_mem(100+i,1+i);
      }
    }
    //begin remove for public
    //or maybe just leave it, where it is :P
    else if ((command[0] == 'W') || (command[0] == 'w')){
      if (one_para(command)){
        pub_write_mem(ret, command);
        get_username();
      }   
    }
    else if ((command[0] == 'N') || (command[0] == 'n')){
      if (two_para(command)){
        pub_write_mem_null(ret);
        get_username();
      }   
    }
    else if ((command[0] == 'R') || (command[0] == 'r')){
      if (two_para(command)){
        pub_read_mem(ret);
      }
    }
    else if ((strcasecmp(command, "moder") == 0)){
      rmode=!rmode;
      Serial.print(F("Memory read output has been set to "));
      Serial.println((rmode) ? "c" : "i");
    }
    else if ((strcasecmp(command, "Token") == 0)){
      Serial.println(F("You've found a secret token!"));
      Serial.println(F("...."));
      Serial.println(F("..."));
      Serial.println(F(".."));
      Serial.println(F("."));
      Serial.println(F("......or not...."));
    }
    else if ((strcasecmp(command, "debug") == 0)){
      debug=!debug;
    }
    else if ((strcasecmp(command, "enable") == 0)){
      Serial.println(F("I'm not a Cisco, but it worked!"));
      debug=!debug;
    }
    else if ((strcasecmp(command, "42") == 0)){
      Serial.println(F("I'm not Deep Thought!"));
    }    
    else if ((strcasecmp(command, "hack") == 0)){
      Serial.println(F("Nice try!"));
    }
    else if ((strcasecmp(command, "jeff") == 0)){
      Serial.println(F("This shit is bananas!!!"));
    }
    else if ((strcasecmp(command, "credo") == 0)){
      Serial.println(F("Make the world a safer place!"));
    }
    else if ((strcasecmp(command, "admin") == 0)){
      Serial.println(F("Try root!"));
    }
    else if ((strcasecmp(command, "root") == 0)){
      Serial.println(F("Try admin!"));
    }
    else if ((strcasecmp(command, "hackrf") == 0)){
      Serial.println(F("http://greatscottgadgets.com/hackrf/"));
    }
    else if ((strcasecmp(command, "trust") == 0)){
      Serial.println(F("Think about it"));
    }
    else if ((strcasecmp(command, "sisters") == 0)){
      Serial.println(F("There are seven!"));
    }
    else if ((strcasecmp(command, "ipv6") == 0)){
      Serial.println(F("2003:60:4010:1090::13"));
    }
    else if ((strcasecmp(command, "ping") == 0)){
      Serial.println(F("pong"));
    }
    else if ((strcasecmp(command, "pong") == 0)){
      Serial.println(F("Not requested!"));
    }
    else if ((strcasecmp(command, "marco") == 0)){
      Serial.println(F("polo"));
    }
    else if ((strcasecmp(command, "polo") == 0)){
      Serial.println(F("I don't sell cars!"));
    }
    else if ((strcasecmp(command, "spaceinvaders") == 0)){
      Serial.println(F("They're coming!"));
    }
    else if ((strcasecmp(command, "pacman") == 0)){
      Serial.println(F("Wakka Wakka Wakka"));
    }
    else if ((strcasecmp(command, "troopers") == 0)){
      Serial.println(F("The next Troopers will start on March 16th 2015"));
    }
    else if ((strcasecmp(command, "packetwars") == 0)){
      Serial.println(F("March 19th, Kulturbrauerei"));
    }
    else if ((strcasecmp(command, "monster") == 0)){
      Serial.println(F("Uh, purple hair"));
    }
    else if ((strcasecmp(command, "challenge") == 0)){
      Serial.println(F("riddle.troopers.de"));
    }
    else if ((strcasecmp(command, "heimo") == 0)){
      Serial.println(F("http://www.hmtrainingsolutions.com"));
    }
    else if ((strcasecmp(command, "enno") == 0)){
      Serial.println(F("Insinuator"));
    }
    else if ((strcasecmp(command, "insinuator") == 0)){
      Serial.println(F("http://www.insinuator.net"));
    }
    else if ((strcasecmp(command, "mate") == 0)){
      Serial.println(F("Essence of life!"));
    }
    else if ((strcasecmp(command, "rs6") == 0)){
      Serial.println(F("500 and 60 horsies"));
    }

    else if ((strcasecmp(command, "ls") == 0) || (strcasecmp(command, "dir") == 0)){
      Serial.println(F("I'm not your OS"));
      Serial.println(F("But i can give you a nice recipe"));

      Serial.println(F("250 g unsalted butter"));
      Serial.println(F("200 g good-quality dark chocolate (70% cocoa solids), broken up"));
      Serial.println(F("80 g cocoa powder, sifted"));
      Serial.println(F("65 g plain flour, sifted"));
      Serial.println(F("1 teaspoon baking powder"));
      Serial.println(F("360 g caster sugar"));
      Serial.println(F("4 large free-range eggs"));
      Serial.println(F(""));
      Serial.println(F("Mix it!!!"));
      Serial.println(F("Bake it!!"));
      Serial.println(F("Eat it!!!"));
      Serial.println(F("P.S. 25minutes at 170 celsius"));

    }
    else if ((strcmp(command, "kGebbcref cMVFFVAESoRBgQifWoEO"))==0){
      Serial.print(F("Oh my "));
      Serial.print(username);
      Serial.println(F("You managed to find my secret!"));
      Serial.println(F("But do you really understand it?"));
      Serial.println(F("Have you tried?"));
      Serial.println(F("As Mr. Miyagi would say rotate and shift and do it again, well no, but..."));
      Serial.println(F("Though it's not quite as easy as in the Movies!"));
    }
    //end remove for public   
    else if ((strcasecmp(command, "X") == 0) || (strcasecmp(command, "Exit") == 0)){
      Serial.println(F("Good bye, Trooper"));
      Serial.end();
      is_console_active = 0;
      gmode='0';
    }
    else {
      Serial.println(F("Type h for available commands"));
    }
    char_c_count = 0;
    newchar = 0;
    for(int i = 0; command[i] != '\0'; i++) {
      command[i] = '\0';
    }
    Serial.println("");
    Serial.println("");
    Serial.print(F("Your wish, "));
    Serial.print(username);
    Serial.print(F(">"));
  }
}

boolean two_para(char command[]){
  //int ret[2];
  ret[0]=0;
  ret[1]=0;
  boolean error = false;

  for (int i=0;i<12;i++){
    if (error){
      Serial.println(F("Wrong Format!"));
      return false;
    }
    switch (i){
    case 1: 
      if (command[i]!=32){
        error=true;
      }
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      if (command[i]>57 || command[i]<48){
        error=true;
      }
      break;
    case 6:
      if (command[i]!=32){
        error=true;
      }
      break;
    case 7:
    case 8:
    case 9:
    case 10:
      if (command[i]>57 || command[i]<48){
        error=true;
      }
      break;    
    }
  }

  ret[0]=((command[2]-48)*1000) + ((command[3]-48)*100) + ((command[4]-48) * 10) + (command[5]-48);
  ret[1]=((command[7]-48)*1000) + ((command[8]-48)*100) + ((command[9]-48) * 10) + (command[10]-48);
  return true;
}

boolean one_para(char command[]){
  //int ret[2];
  ret[0]=0;
  ret[1]=0;
  boolean error = false;

  for (int i=0;i<12;i++){
    if (error){
      Serial.println(F("Wrong Format!"));
      return false;
    }
    switch (i){
    case 1: 
      if (command[i]!=32){
        error=true;
      }
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      if (command[i]>57 || command[i]<48){
        error=true;
      }
      break;

    }
  }

  ret[0]=((command[2]-48)*1000) + ((command[3]-48)*100) + ((command[4]-48) * 10) + (command[5]-48);
  return true;
}







