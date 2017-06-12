#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 10, 3, 2);
int led = A5; // Pin A5
//int relay1=A0;
int relay1=A1;
void setup()
{
  lcd.begin(16, 2); // LCD Configuration, 2 línes 16 characters cada una.
lcd.setCursor(0, 0);
lcd.write("Voice Control");
delay(2000);
//pos=0;
lcd.clear();
lcd.write("Starting....");
delay(4000);
lcd.clear();
lcd.write("Device is ready");
lcd.clear();
lcd.setCursor(3, 0); 
lcd.print("Waiting for"); 
lcd.setCursor(3, 1);
lcd.print("Voice....");
pinMode(led, OUTPUT); // Set pin 13 as digital out
pinMode(relay1, OUTPUT);
digitalWrite(relay1,1);
// Start up serial connection
Serial.begin(9600); // baud rate
Serial.flush();
}
void loop()
{
String input = "";
// Read any serial input
while (Serial.available() > 0)
{
input += (char) Serial.read(); // Read in one char at a time
delay(5); // Delay for 5 ms so the next char has time to be received
}
if (input == "1") //if the arduino got "1" from the serial communication
{
  Serial.println("Motion detected!");
  lcd.clear() ;
  lcd.setCursor(0, 0); // Set LCD cursor position (column 0, row 0)
  lcd.print("Bulb On!"); 
 
}
else if (input == "0") //if the arduino got "0" from the serial communication
{
   lcd.clear() ;
  lcd.setCursor(0, 0); // Set LCD cursor position (column 0, row 0)
  lcd.print("Bulb Off!"); 
digitalWrite(led, LOW); // off
digitalWrite(relay1,1);
}
}
