#include "Race.h"

Race::Race(){
  this->state = ReadyToRace;
  this->startAt = 0;
}

String Race::toString(){
  return raceState_STRING[this->state];
}

void Race::start(){
  this->state = Starting;
  this->startAt = millis()+4000;  
}

void Race::finish(){
  this->state = Finished;
  this->finishAt = millis();
}

void Race::refresh(){
  if(this->state == Starting && this->startAt < millis()){
    this->state = Going;
  }
};

long Race::getStartTime(){
  return this->startAt;
};

long Race::getDuration(){
  if(this->state == Finished){
    return this->finishAt - this->startAt;
  }
  if(this->state == Going){
    return millis() - this->startAt;
  }
  return 0;
};

raceState Race::getState(){
  return this->state;   
}
