/*
Storage overview
 #0 mode
 #1 direct payload id
 #2 language
 #100 begin payload bookmarks
 #109 end payload bookmarks
 
 #200 begin hacking area
 #200 begin username
 #220 end username
 #400 end hacking area
 #500 begin user id
 #615 end user id
 */
void set_mode(){
  char t = EEPROM.read(0);
  if ((t == 'x')||(t=='1')||(t=='2')){
  gmode=t;
  }
}

void store_mode(byte m){
  write_mem(0,m);
}

void write_mem(int pos, byte data){
  EEPROM.write(pos, data);
}

byte read_mem (int pos){
  return EEPROM.read(pos);
}

void get_username(){
  int c=200;
  char t;
  for (int i=0; i<20; i++){
    username[i]='\0';
  }
  while (c<221){
    t=read_mem(c);
    if ((t>33) && (t<126)){
    username[c-200]=t;
    c++;
    } else {
      break;
    }
  }
}

//begin remove from public
void pub_read_mem(int paras[2]){
  int c=0;
  if ((paras[1]>paras[0]) && (paras[1] < 1023)){
    for (int i = paras[0]; i<=paras[1];i++)
    {
      if (rmode){
      Serial.print((char)read_mem(i));
      } else{
        Serial.print(read_mem(i));
      }
      Serial.print(" ");
      c++;
      if (c>=8){
        c=0;
        Serial.print(13);
      }
    }
  }
  else{
    Serial.println(F("Wrong Format"));
  }
}

void pub_write_mem(int ret[], char command[]){

  if ((ret[0]>=200) && (ret[0] < 370)){
    if (command[31]=='\0'){
      int i=7;
      while (command[i]!='\0' && i<377){
        write_mem((ret[0] + i -7),command[i]);
        i++;
        Serial.println(F("I'm doing it!!!"));
      }
    }
    else{
      Serial.println(F("Wrong Format"));
    }
  }
  else{
    Serial.println(F("Wrong Format"));
  }
}

void pub_write_mem_null(int ret[]){

  if ((ret[0]>=200) && (ret[0] < 370)){
    
      for (int i=ret[0];i<=ret[1];i++){
        write_mem(i,'\0');
        Serial.println(F("I'm doing it!!!"));
      }
  }else{
      Serial.println(F("Wrong Format"));
  }
}
//end remove from public



