/*
Just a few notes on how things work

----MODES----
var: byte gmode

gmode is the global badge mode, mainly used to decide what to do during loop().

After flashing the badge will be in 'p' mode, this mode opens a serial console 
and waits for the badge to be provisioned with it's initial configuration data.

The badge should usualy start (the mode stored at address 0 in the EEPROM) 
in 'x' mode. In this mode the badge expects no shield and will check if it's available.
When actually running in 'x' mode, the badge will print it's ID once, and then go to sleep.

If the shield is available, the badge will switch into '0' mode. This mode should be 
looked at as the default mode. The badge's blind menu is active in this mode and can be
controlled using the two pusbuttons and the three LEDs

The mode '1' is used to run the serial connection for the serial menu. In this mode, 
the Badge will permanently check the serial port for a new input and will take it if available.

The mode '2' is there to fire a payload, previously configured via the serial menu.
The payload will be fired as soon as the badge is attached the next time.

'z' mode is simply there for provisioning. The badge will start in this mode, until it has
been provisioned via a serial connection.



*/
