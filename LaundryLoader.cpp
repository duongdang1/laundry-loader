#include <Servo.h>
#include "HX711.h"
#include <LiquidCrystal.h>

Servo myservo;
float x;
#define calibration_factor -11830.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2

HX711 scale;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  Serial.println("HX711 scale demo");
  lcd.begin(16, 2);
  lcd.print("weight:");
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  Serial.println("Readings:");
  lcd.print("Readings:");
  myservo.write(90);
}

void loop() {
 
    Serial.print("Reading: ");
    Serial.print(scale.get_units()); //scale.get_units() returns a float
    Serial.print(" ounce"); //You can change this to kg but you'll need to refactor the calibration_factor
    lcd.print(scale.get_units());
    lcd.print(" ounce");
    lcd.setCursor(0, 1);
    Serial.println();
    x = float(scale.get_units());
    if(x < -9.7 || x == -9.7){
    Serial.println("Inside 1st if statement");
      delay(1000);
      myservo.write(180);
      delay(1000);
      myservo.write(90);
 
   
  }
   
}