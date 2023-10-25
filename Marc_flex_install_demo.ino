
//Enable (1) or disable (0) code sections = keyboard inputs, make sure the line ends with;

//startup delay in seconds - note this is from the time the AtTiny85 device is plugged in and powered. E.g. 420s would give you a very safe 7 minutes - 2 to plug in and select boot device and 5 for the OS boot from a slow drive
int startup = 180;

//Installation vs Test mode - go through with the final "Are you sure" popup
int reallyinstall = 1;

/* you can switch further modules off and on here to adjust for potential future GUI changes */
//ChromeVox popup, disable if you intend to be quick or disable it manually each time
int chromevox = 1;

/* the next section contains other definitions */

#include <DigiKeyboard.h>
#define KEY_TAB 43
#define KEY_DOWN_ARROW  0x51
int keyWait = 275;

/* setup runs once */

void setup() {
// turn LEDs on
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  
/* emulated keystrokes start here */
 //Startup delay
 wait(startup);
 // turn LEDs off
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  
 //ChromeVox popup
 if(chromevox > 0){  
  DigiKeyboard.sendKeyStroke(0);
  wait(5);
  pressKey(KEY_TAB, 1);
  pressKey(KEY_ENTER, 1);
  }

 //Welcome Screen (defaults to "Get started")
  DigiKeyboard.sendKeyStroke(0);
  wait(1);
  pressKey(KEY_ENTER, 1);

  wait(5);

 //Install Screen

  pressKey(KEY_TAB, 4); //Install
  pressKey(KEY_ENTER, 1); //tick

  pressKey(KEY_TAB, 1); //Next
  pressKey(KEY_ENTER, 1);  

  wait(5);

 //Install ChromeOS Flex
  pressKey(KEY_ENTER, 1);

  wait(5);

 // Confirmation popup
 if(reallyinstall > 0) {
  pressKey(KEY_TAB, 1);
  pressKey(KEY_ENTER, 1);
  }

}
/* loop is the main fuction as the microcontroller would run continuously */
/* this sketch will blink the LED (on either variant) as the screen might be off and more time might pass until you return to the device */
void loop() {

  digitalWrite(0, HIGH);   // Turn the LED on
  digitalWrite(1, HIGH);
  delay(1000);             // Wait for a second
  digitalWrite(0, LOW);    // Turn the LED off
  digitalWrite(1, LOW); 
  delay(1000);             // Wait for a second
  digitalWrite(0, HIGH);   // Turn the LED on
  digitalWrite(1, HIGH);
  delay(250);             // Wait for a quarter second
  digitalWrite(0, LOW);    // Turn the LED off
  digitalWrite(1, LOW); 
  delay(250);             // Wait for a quarter second

}

//function definitions

uint8_t pressKey(uint8_t key, int times) {
  for (int i = 1; i <= times; i++) {
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(key);
    DigiKeyboard.delay(keyWait);
  }
}

int wait(int seconds) {
  for (int i = 0; i < seconds; i++) {
    DigiKeyboard.delay(1000);
  }
}
