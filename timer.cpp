#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#define PAUSE_PIN 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
int pause = 2;
int min = 22;
int sec = 59;
int mCounter = 0;

void setup(){
lcd.begin();
lcd.setBacklight((uint8_t)1);
lcd.print("weWorkInSilence");
//   Serial.begin(9600);
pinMode(PAUSE_PIN, INPUT_PULLUP);

}

void loop(){
  delay(1000);
  int counter = digitalRead(PAUSE_PIN);
  if (counter == 0) pause++;
  if (pause%2 == 0){
    mainTimer (mCounter);
    // Serial.println("NotOdd");
  }

}

void mainTimer (int count){
  if (min>=0 && sec>=0){
    lcd.setCursor(0,1);
    if (min < 10) lcd.print("0");
    lcd.print(min);
    lcd.print(":");
    if (sec < 10) lcd.print("0");
    lcd.print(sec);
    timerAtWork();
  }
else {
    while(true){
      lcd.setCursor(0,1);
      lcd.print("               ");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("00:00 it's time");
      delay(1000);
    }
  }
  mCounter++;
  //Serial.print(mCounter);
  //Serial.print(min);
  // Serial.println(sec);
}

void timerAtWork() {
  if (sec == 0){
    min--;
    sec = 59;
  }
else sec--;
}
