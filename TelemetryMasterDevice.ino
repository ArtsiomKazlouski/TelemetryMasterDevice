#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Button.h"
#include "Race.h"
#include "TrafficLight.h"

Race race;
unsigned long time;
byte sc_beat;
long lcdRefreshRate = 300;
long lcdLastRefresh = 0;

Button startButton = Button(12), stopButton = Button(13), finishButton = Button(8);
int x[] = {7, 6, 5, 4};
TrafficLight trafficLight = TrafficLight(x, 4);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  race = Race();  
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}
void loop() {
  startButton.refresh();  
  race.refresh();
  trafficLight.refresh();   

  if(race.getState() == ReadyToRace && startButton.pressed()){
    race.start();    
    trafficLight.init(race.getStartTime());
  }

  

  if(stopButton.pressed()){
    race = Race();  
    trafficLight.reset();
  }

  if(race.getState() == Going && finishButton.pressed()){
    race.finish();
  }

  if(lcdLastRefresh+lcdRefreshRate<millis()){    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("State: "); 
    lcd.print(race.toString()); 
    lcd.setCursor(0, 1);
    lcd.print("Time: "); 
    lcd.print(race.getDuration()/1000); 
    lcdLastRefresh = millis();
  }
  


  
  Serial.print("Race state: ");
  time = millis();
  

  Serial.print(race.toString()); //prints time since program started
  Serial.print(" Race duratin: ");
  Serial.println(race.getDuration());
//  delay(1000);          // wait a second so as not to send massive amounts of data
}
