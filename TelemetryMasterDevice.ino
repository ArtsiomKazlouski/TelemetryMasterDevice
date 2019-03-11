#include "Button.h"
#include "Race.h"
#include "TrafficLight.h"

Race race;
unsigned long time;
byte sc_beat;

Button startButton = Button(12), stopButton = Button(13), finishButton = Button(8);
int x[] = {7, 6, 5, 4};
TrafficLight trafficLight = TrafficLight(x, 4);

void setup() {
  race = Race();  
  Serial.begin(9600);
}
void loop() {
  startButton.refresh();  

  if(race.getState() == ReadyToRace && startButton.pressed()){
    race.start();    
    trafficLight.init(race.getStartTime());
  }

  race.refresh();
  trafficLight.refresh();

  if(stopButton.pressed()){
    race = Race();  
    trafficLight.reset();
  }

  if(race.getState() == Going && finishButton.pressed()){
    race.finish();
  }
  
  Serial.print("Race state: ");
  time = millis();
  

  Serial.print(race.toString()); //prints time since program started
  Serial.print(" Race duratin: ");
  Serial.println(race.getDuration());
//  delay(1000);          // wait a second so as not to send massive amounts of data
}
