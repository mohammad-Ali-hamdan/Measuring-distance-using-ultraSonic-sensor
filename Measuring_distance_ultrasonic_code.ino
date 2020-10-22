#include <LiquidCrystal.h>
 
#define trigger 18 //A5 pin 28 in Atmega328
#define echo 19   // A4 pin 27 in Atmega328
 
LiquidCrystal lcd(2,3,4,5,6,7);
 
float time1 =0,distance=0;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);  //  Signal Created
 pinMode(echo,INPUT);      //  Signal recieved
 lcd.print(" Ultra sonic");
 lcd.setCursor(0,1);
 lcd.print("Distance Meter");
 delay(2000);
 lcd.clear();

}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time1=pulseIn(echo,HIGH);
 distance=time1*340/20000;
 lcd.clear();
 lcd.print("Distance:");
 lcd.print(distance);
 lcd.print("cm");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print("m");
 delay(1000);
}
