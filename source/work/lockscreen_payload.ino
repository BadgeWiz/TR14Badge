
void lockscreen_win() {
  //leave a message
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  //open notepad
  Keyboard.println(F("notepad.exe"));
  delay(1000);
  // maximize
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();
  delay(200);
  //print_troopers_logo();
  delay(500);
  //lock screen
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}

void print_osx_backslash() {
  Keyboard.press(KEY_LEFT_ALT);  
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('7');
  delay(100);
  Keyboard.releaseAll();
  delay(200); 
}

void lockscreen_osx() {
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
  Keyboard.println(F("vi"));
  delay(100);
  Keyboard.print('i');
  //print_troopers_logo();
  delay(100);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.print('n');
  Keyboard.releaseAll();
  delay(200);
  if(!gl) {
    Keyboard.println(F("/System/Library/CoreServices/Menu\\ Extras/User.menu/Contents/Resources/CGSession -suspend"));
  }
  else {
    Keyboard.print(F("&Szstem&Librarz&CoreServices&Menu"));
    print_osx_backslash();
    Keyboard.print(F(" Extras&User.menu&Contents&Resources&CGSession /suspend"));
    Keyboard.println(F("&Szstem&Librarz&CoreServices&Menu"));
  }
}


void lockscreen_gnulinux() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  Keyboard.releaseAll();
  delay(2000);
  if(!gl) {
    Keyboard.println(F("xterm -e vi"));
  }
  else {
    Keyboard.println(F("xterm /e vi"));  
  }
  delay(1000);
  Keyboard.press(KEY_F11); // maximize windows 
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print('i');
  delay(100);
  //print_troopers_logo();

  // lock method 1
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  Keyboard.releaseAll();
  delay(300);
  if(!gl) {
    Keyboard.println(F("xscreensaver-command -lock"));  
  }
  else {
    Keyboard.println(F("xscreensaver/command /lock"));  
  }

  // lock method 2 (should work for most)  
  // CTRL-ALT-DEL:
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('l');
  delay(500);
  Keyboard.releaseAll();

}

//The Troopers Logo has been excluded, due to it's size

void print_troopers_logo() {
  if(!gl) {
    Keyboard.println(F("Hey there, you did not lock your Notebook, let me do that for you."));
    Keyboard.println(F("Sincerly your TROOPERS14 Badge"));
  }
  else {
    Keyboard.println(F("Hez there, zou did not lock zour Notebook, let me do that for zou."));
    Keyboard.println(F("Sincerlz zour TROOPERS14 Badge"));

  }
  Keyboard.println(F(""));
  kspace(44);
  Keyboard.println(F("+"));
  kspace(42);
  Keyboard.println(F(";@@@+"));
  kspace(40);
  Keyboard.println(F("#@@@@@@@#"));
  kspace(37);
  Keyboard.println(F(",@@@@@@@@@@@@@;"));
  kspace(34);
  Keyboard.println(F(",@@@@@@@@@@@@@@@@@@@:"));
  kspace(31);
  Keyboard.println(F("'@@@@@@@@@@@@@@@@@@@@@@@@@+"));
  kspace(27);
  Keyboard.println(F(",@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:"));
  kspace(23);
  Keyboard.println(F(";@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@'"));
  kspace(18);
  Keyboard.println(F(",#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:"));
  kspace(13);
  Keyboard.println(F(",@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,"));
  kspace(11);
  Keyboard.println(F("@@@@@@@@@@@@@@@@@@@@@@#':.`               `.;'#@@@@@@@@@@@@@@@@@@@@"));
  kspace(11);
  Keyboard.println(F("@@@@@@@@@@@@@#.`     .'##@@@@@@@@@@@@@@@@@@@#+;`    `:@@@@@@@@@@@@@`"));
  kspace(10);
  Keyboard.println(F(".@@@@@@@;.    '#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+,   .@@@@@@@@;"));
  kspace(10);
  Keyboard.println(F("+@#:   .'@@@@@@@@@@,   :@@@:     @@#     :@@@:;#@@@@@@@@@@@#:  .#@@@@"));
  kspace(12);
  Keyboard.println(F(".@@@@@@@@+   @@@      '@@  @@:  @# +':  @@      #@ ;#@@@@@@@@@,  '@"));
  kspace(7);
  Keyboard.println(F("`#@@@@@@@#+@       @# .@@@  @+ #@@@  @' #@@; #@  @@;`@@     #@@@@@@@@@'"));
  kspace(7);
  Keyboard.println(F("@@@@@@.    @  @@@  @' @@@@  @; @@@@  @; #@@. @@  @@@@@, ##;  @@' `;@@@@@@,"));
  kspace(7);
  Keyboard.println(F("@@@#    .@@@. @@@. @' #@@@` @: @@@@  @:      @@ `;@@@@  @@@` @@      @@@@#"));
  kspace(7);
  Keyboard.println(F("+@@@ '+ '@@@+ '@+  @+ #@@@: @; #@@@  @, .   '@;     @@  @@@  @: +@@. @@@@."));
  kspace(7);
  Keyboard.println(F("`@@@@@@  @@@@     .@@ ,@@@: @# '@@@  @` @@@@@@, @@@+@@       @  @@@@@@@@@"));
  kspace(8);
  Keyboard.println(F("@@@@@@  @@@@  #+  @@  @@@  @@  #@.  @  @@@@@@  @@@@@@ .+   @@`  `@@@@@@@"));
  kspace(6);
  Keyboard.println(F("; @@@@@@` #@@@  @@  +@`      @@,     @@  @@@@@@  `,+@@' '@` @@@@     @@@@#"));
  kspace(4);
  Keyboard.println(F(":@@'#@@@@@@ ,@@@  @@@  @@.   ;@@@@@##@@@@@#@@@@@@@     #` @@@ ;@@@@@#  @@@@.@@."));
  kspace(3);
  Keyboard.println(F("@@@@@.@@@@@@  @@@, #@@'#@@@@@@@@##+':,.```.,;+##@@@@@@@@@` @@@  @#@@@@  @@@@ @@@@@"));
  kspace(2);
  Keyboard.println(F("@@@@@@.@@@@@@  @@@@@@@@@@+`      .:'#@@@@@@@`           '#@@@@@` @    ;  @@@@;@@@@#"));
  kspace(1);
  Keyboard.println(F("@@@@@@@@@@@@@@;:@@@@;`   ,;:,;;, @@@@@@: @@@.       @' ,;:`   `'@@@@;    #@@@@@@@@@,"));
  Keyboard.println(F("#@@@@@@@@@@@@@@@@,  `'` #@  #@ ` @@@@@`               #+ , :@,      :@@@@@@@@@.@@@@@@"));
  Keyboard.println(F("`;  @@@@@@@@@:.+:.;::    ,;;::: @@@@@@                 @: :;,; @@@@@+   '@@@@@#@@@@"));
  kspace(2);
  Keyboard.println(F("`@@@@@@@@@@@@@# +` @+@  +#   @@@@#                   +@ @` ,,#`@#,`@ @@@@'#@@@@@@@;"));
  kspace(1);
  Keyboard.println(F("#@@@@@@@@@@@@@`  : .   @ ;;:`+@@@#                     @@ '. @@@#@#@#..@@@@@@@@@@@@@"));
  Keyboard.println(F("#@@' @@@@@@.  :#;@ @   .+   # @@@  :;                  @,@,. @,@+.@@,+@ `  ;@@@@@@.':"));
  kspace(4);
  Keyboard.println(F("@@@@' .#@@@@  .#,: . @+  #@@+#@@,                   #@ .@,.#@@'@@,.+ @@'  #@@@#"));
  kspace(5);
  Keyboard.println(F("`@  @@@@@@ +, .@`   @ @ @@,   @@:                   @`@`@@@@@.@@  @ @@@@@,  #@"));
  kspace(9);
  Keyboard.println(F("@@@@@#,   :@@      ,,`    @@@@'                 @ @,@@@@'`.@@;`@ @@@@@@"));
  kspace(9);
  Keyboard.println(F("@@@@@ @   ++ #:  @@'        :@'                  @.@@@@@ @@@@.@+`#@@@@@"));
  kspace(9);
  Keyboard.println(F("#@@@@ @@`   @@@+,@@,@            ,              @`@@@+@ ,@@    ,@.@@@@@"));
  kspace(9);
  Keyboard.println(F(";@@@@# '    # @``@@@ :        '   ';           @`@@+   @@:     @ @@@@@@"));
  kspace(9);
  Keyboard.println(F(",@@@@@@ @   @  @.`@@@:#       #     @@@    @# @ @@:   @@;     @ @@@@@@+"));
  kspace(9);
  Keyboard.println(F("`@@@@@`:,;@  @@,+@#@@# @      ,     @@@@  #@ @ @@`   '@@     @`+@@@@@@,"));
  kspace(10);
  Keyboard.println(F("@@@@@@ #   .@@:@ ,@@@`@       @  ,@@@@@ `@@ @@@  '  @@     ;'`.@@@@@@`"));
  kspace(10);
  Keyboard.println(F("@@@@@@..    @@@ @:`@@@ :       #@@@@@@@@`@ @.  .@  :@#     @ ` @@@@@@"));
  kspace(10);
  Keyboard.println(F("@@@@@@# @   ;@@@;;@.@@@;         @@@@@@@@;;'@@@@@@+.@     @ `'@@@@@@@"));
  kspace(10);
  Keyboard.println(F("@@@@@@@@ +  ,@@@#+ @ @@'@`:     @@@@@@@@@ @@@@@@@@+@.    @ ` +@@@@@@@"));
  kspace(10);
  Keyboard.println(F("@@@@@@@`.,   `@@@ @#@ @; #@    @@@@@@@@@ @.@@@@@@@@:@@@@@`#:;:@@@@@@@"));
  kspace(10);
  Keyboard.println(F(";@@@@@@ + @  . @@@ `@#  @#@   @@@@@@@@@@`+@@@@@@@@@       @ @`@@@@@@#"));
  kspace(10);
  Keyboard.println(F("`@@@@@@',` ;  @,@@@',, @@.@   @@@@@@@@@@ @+@@@@@@@,      @ :`'@@@@@@,"));
  kspace(11);
  Keyboard.println(F("@@@@@@@` ,;   @ @@+; @@@.@   '@@@@@@@@@  ;@@@@@@#      +:,. +@@@@@@"));
  kspace(11);
  Keyboard.println(F("@@@@@@++#. @  ;@ @' @@@,@@   @#`@@@@@@ @`@'@@@@@      `@  +#:@@@@@@"));
  kspace(11);
  Keyboard.println(F("@@@@@@@+#  @` ,'#` @@@:@@`  @@ #@@@@@@,@@ +@@@@       @ . ;#@@@@@@@"));
  kspace(11);
  Keyboard.println(F(";@@@@@@,`+ :  `+` @@@;@@@+@ @@'@@@@@@ @@@.+;@@       @ `'':`@@@@@@#"));
  kspace(12);
  Keyboard.println(F("@@@@@@` +@ @  @  #@'@@@@@ .;@@@@@@@++@@@@ #@`      @`. +@. @@@@@@`"));
  kspace(12);
  Keyboard.println(F("@@@@@@#+.`' `    #++ @@@@@# @@@@@@@ @@'@@+::      :+ '+, '@@@@@@@"));
  kspace(12);
  Keyboard.println(F("@@@@@@@#  ' @    '+@ :@@@@ '`@@@@@.@@@+@@@ @@+.   @  ;#. ;@@@@@@@"));
  kspace(12);
  Keyboard.println(F(".@@@@@@ ##.  @'  '@@@ @,@@@; .;#@' @@@@:@@#   .+@@ '+, +#,@@@@@@+"));
  kspace(13);
  Keyboard.println(F("@@@@@@;+#. '  @;@@@@; @@@@,@  `: @@.@@@@@#:  @ .  '+. +#:@@@@@@"));
  kspace(13);
  Keyboard.println(F("@@@@@@@` +#``+ :@'@@@ ';@@@` #'`,@@@@@@@  ,#@., :#, '#, @@@@@@@"));
  kspace(13);
  Keyboard.println(F(":@@@@@@  +@``+ ' @@@@@,@;@@+@ +  @@@,@@@@@#`;,. :@. '@. @@@@@@+"));
  kspace(14);
  Keyboard.println(F("@@@@@@##. ++`  @;+@@@  #@@@ ,  #`@@@@'   `#` '#: '+, +@@@@@@@"));
  kspace(14);
  Keyboard.println(F("@@@@@@@#. ++` + :@`@@@,# @@@# ,@ #@@@,+@@@ : '#: ;+. +@@@@@@@"));
  kspace(14);
  Keyboard.println(F("`@@@@@@,'#``+#` ' @@@@;`@@@@ '`@@:@@@'. @  :#, :@. ;#.@@@@@@;"));
  kspace(15);
  Keyboard.println(F("@@@@@@@++``+#`` @',@@@  .@@@; @@`@   :@ ; ;+, ;#, '+@@@@@@@"));
  kspace(15);
  Keyboard.println(F("#@@@@@@. @@  @@  ,@.@@@@#+@@,@ @@`@@@@  ,@: '@: '@. @@@@@@@"));
  kspace(16);
  Keyboard.println(F("@@@@@@@`++.`#+``' @@@@ `#@@@` #@`,  .; :+: '+; '+,@@@@@@@"));
  kspace(16);
  Keyboard.println(F("@@@@@@@#``+#``++ @+.@@@;.,@@+@   ,#: :#: :#. :#. ;@@@@@@@"));
  kspace(15);
  Keyboard.println(F(". @@@@@@@``+#``++  ,@;@@,+@@@@ .` :+; ;#; ;#, ;#, @@@@@@@``"));
  kspace(15);
  Keyboard.println(F(":@@' `#@@##  ## `# + @@@@` @@@@@ @; ,@: .@, ;@, ;@@@@  ;@@."));
  kspace(14);
  Keyboard.println(F("@@@@@@@'@@@'.`+'..++ @':@@#@:@@`+ +'`:+;`:': ''; '@@@ @;#@@@@"));
  kspace(13);
  Keyboard.println(F(";+@@@@@@;  ;@#@  ##  # ,@@@@ ': @ ' .@; :@: :@. :@:` ;@@@@@@@';"));
  kspace(14);
  Keyboard.println(F("@@@@`+@@@@@@,  `:'.,+ + @@@@'+: # `;;' ;;'`;.` .+@@@@@@@ #'@@"));
  kspace(16);
  Keyboard.println(F(",:  @ @;@@@@@@@@+:`   `.,: , '; :`    `:+@@@@@@@@@`@.@ '@`"));
  kspace(16);
  Keyboard.println(F("@   :#@;'  @`'@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,'@`. @  @"));
  kspace(16);
  Keyboard.println(F("@@@@:#'#@.+@ @+`  @'`,#'##@@@@@@#@@,#`@ ``#: @ , +`,@@@@@"));
  kspace(18);
  Keyboard.println(F(".+@@@@#:+@ @+..'@.   :`#;@ #@@`@@.# . .`#` @ @#@@@@@:"));
  kspace(23);
  Keyboard.println(F("'@@@@@@@@,:@ ,+  ` :# +@@ ,@:.,  @;@@@@@@@#,"));
  kspace(22);
  Keyboard.println(F(",@@,  ,#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+. `;@'"));
  kspace(23);
  Keyboard.println(F("@@@@@@@@'    `,;'+#@@@@@@#+';,`   :+@@@@@@@"));
  kspace(24);
  Keyboard.println(F("@@@@@@@@@,' @@@@@ ' @@ ' @@..;;'@@@@@@@@@"));
  Keyboard.println(F("                         @@@@@@@@@ `@@@@@, `@@: @ @@ : @@@@@@@@@`"));
  Keyboard.println(F("                         :@@@@@@@@:@@@@@`',: @@ ;,#@+:@@@@@@@@@+"));
  Keyboard.println(F("                          #@@@@@@@ @@@@@  @' ;#@ . @@ @@@@@@@@@"));
  Keyboard.println(F("                           @@@@@@@`@@@@@.;:;. @@ ;:.:@`@@@@@@@"));
  Keyboard.println(F("                            @@@@@+#@@@@.@+ `@;`:@  `@@,@@@@@@"));
  Keyboard.println(F("                             @@@@ @.@@@ ,',;,' @#:@@ '@ @@@@"));
  Keyboard.println(F("                              @@@ @@@@@,@ @' .@ #@ @'';@.@@"));
  Keyboard.println(F("                               @##;@@@;@@@:;,;:+',@,@ @@`@"));
  Keyboard.println(F("                                 @,@@@ @@@@#@#@@ @@`@@ :@"));
  Keyboard.println(F("                                `@@@@@.@@@@@@@@@@`;@ @;#@#"));
  Keyboard.println(F("                                @ @@@,@@@@@@@@@@@,@@+;@ @."));
  Keyboard.println(F("                                @@@@@ @@@@@:,#@@@@ @@    ,@  ;"));
  Keyboard.println(F("                               @.@@@++@@@@;@, #@@@@`@@   `'+.:"));
  Keyboard.println(F("                               @@@@@ `@@@@' '@#@@@@ @ `   ,:# ."));
  Keyboard.println(F("                              @'@@@#   @@@@;'#@@@@   #, ,  `;'@'."));
  Keyboard.println(F("                             @@@@@@     +@@@@@@@@     ;`` `:`;"));
  Keyboard.println(F("                            @'@@@@:       @@@@@`    ; #; : ` ."));
  Keyboard.println(F("                           +@@.@@@         #@@        # .    ;"));
  Keyboard.println(F("                         @+@@@#@@                     .@;"));
  Keyboard.println(F("                          @'@@@#                      + `"));
  Keyboard.println(F("                          +@ ,                          #"));
  Keyboard.println(F("                        .@+@#"));
  Keyboard.println(F("                          ``"));
  Keyboard.println();
  Keyboard.println();
  Keyboard.println();
  Keyboard.println(F("P.S."));
  Keyboard.print(F("My "));
  Keyboard.print(username);
  Keyboard.println(F(" rocks!!"));
}

void kspace(int n){
  for (int i=0;i<n;i++){
  Keyboard.print((" "));
  }
}
