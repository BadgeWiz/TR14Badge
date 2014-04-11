/*

 everything needed for calling payloads
 */

byte fetch_payload(int pos){
  return read_mem((pos+100));
}

//executes certain payload depending on payload id
void do_payload(byte id){
  digitalWrite(ll, HIGH);
  Keyboard.begin();
  switch(id){
  case 1:
    lockscreen_win();
    break;

  case 2:
    lockscreen_osx();
    break;
  case 3:
    lockscreen_gnulinux();
    break;
  case 4:
    call_agenda_win();
    break;
  case 5:
    call_agenda_osx();
    break;
  case 6:
    call_agenda_gnulinux();
    break;
  case 7:
    Keyboard.println(F("Dummy7"));
    //sec_wifi_pws_win{}:
    break;
  case 8:
    Keyboard.println(F("Dummy8"));
    //sec_force_creds_win{}:
    break;
  case 9:
    Keyboard.println(F("Dummy9"));
    //sec_logon_bd_win{}:
    break;
  case 10:
    Keyboard.println(F("Dummy10"));
    //sec_rev_metpret_ps_win{}:
    break;
  case 11:
    Keyboard.println(F("Dummy11"));
    //sec_dp_win1{}:
    break;
  case 12:
    Keyboard.println(F("Dummy12"));
    //sec_dp_win2{}:
    break;
  case 13:
    Keyboard.println(F("Dummy13"));
    //sec_win_shutdown{}:
    break;
  case 14:
    Keyboard.println(F("Dummy14"));
    //sec_win_ncalc{}:
    break;
      case 15:
    Keyboard.println(F("Dummy15"));
    //sec_win_mail{}:
    break;
  default:
    Keyboard.println(F("error :)"));


    break;
  }
  Keyboard.end();
  digitalWrite(ll, LOW);
}

void pd(){
  Keyboard.println(F("Dummy"));
}

