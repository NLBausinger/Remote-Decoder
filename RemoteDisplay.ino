
/* 
 * This program is useful for determining the HEX value
 * of an infrared Remote
 * 
 * By Nathan Bausinger
 * 
  PINOUT:
  IR Chip: Signal to Arduino 13

  LCD: 
  1: GND
  2: Vout
  3: Potentiometer Contrast Pin
  Rs, Enable, D4,D5,D6,D7 = 2,3,4,5,6,7, respectively
  RW pin grounded
  POWERED BACKLIGHT

 */

#include <IRremote.h>
#include <LiquidCrystal.h>


int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

LiquidCrystal LCD(2,3,4,5,6,7);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  LCD.begin(16,2);     //LCD, 16 columns, 2 rows
  LCD.setCursor(0,0);
  LCD.print("Remote Display");
  LCD.setCursor(1,0);
  LCD.print("Ready"); //Preliminary setup for LCD, 
                      //use to test contrast and ensure legibility.
  

void loop() {
  LCD.setCursor(0,0);
  if (irrecv.decode(&results)) { //if data is being inputted from 
                                 //a remote, 
    LCD.clear();
    LCD.print(results.value, HEX); //Clear LCD, display value
    irrecv.resume(); // Receive the next value
  }
  delay(100); //stops LCD from flickering
}
