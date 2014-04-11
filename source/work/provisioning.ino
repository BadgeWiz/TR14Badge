/*
stuff for initial provisioning


The provisioning process for the public release will simply provision the EEPROM with all needed data. The authid part is skiped!
 */

//data
//length
const int pdatal = 116;
//content
char pdata[pdatal];
//position counter
int pdatac = 0;
//current char
char ichar = 0;

//init everything we need for provisioning
void start_prov(){
  Serial.begin(9600);
  delay(3000);
  pinMode(ll, OUTPUT);
  digitalWrite(ll,HIGH);
  Serial.println(F("At your service, master!"));
  pinMode(lr, OUTPUT);
    digitalWrite(lr,HIGH);
}

//read all data for provisioning and process it
void do_prov() {
  //skip this usual Badge use
  /*
  if(Serial.available()) {
    ichar = Serial.read();
    Serial.print(char(ichar));
    if(ichar != 13) {
      pdata[pdatac] = char(ichar);
      pdatac++;
    }
  }

  if(ichar == 13) {
    Serial.flush();
    
    //write data to EEPROM
    for (int i=0;i<pdatal;i++){
      write_mem((i+500),pdata[i]);
    }
for (int i=0;i<pdatal;i++){
      pdata[i]='\0';
    }

    //read data back from
    for (int i=0;i<pdatal;i++){
      pdata[i] = read_mem((i+500));
    }
    */
    
    finalize_prov();

  //}
}

void finalize_prov(){
  
    //set base name
    write_mem(200,'M');
    write_mem(201,'a');
    write_mem(202,'s');
    write_mem(203,'t');
    write_mem(204,'e');
    write_mem(205,'r');
    write_mem(206,'\0');
    write_mem(220,'\0');
    write_mem(221,'\0');
    
    //set base payloads
    for (int i=0;i<pl_amount;i++)
    {
      write_mem(100+i,1+i);
    }
    
    //give some feedback
    Serial.println(F("Thank you master!"));
    Serial.println(F("My new name shall be:"));
    Serial.println(pdata);
    Serial.end();
    
    //set next mode to normal start mode
    store_mode('x');
      digitalWrite(ll,LOW);
    //switch off
    gmode='z';
    power_down();

}

