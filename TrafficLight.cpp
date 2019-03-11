#include "TrafficLight.h"


TrafficLight::TrafficLight(int pins[], int sizeMod){
  this->pins = pins;  
  this->mod = sizeMod;
  for (int i = 0; i < this->mod; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);    
  }
}

void TrafficLight::init(long startAtMilis){
  this->startAt = startAtMilis;
  this->enabled = true;
}

void TrafficLight::reset(){
  this->enabled = false;
  for (int i = 0; i < this->mod; i++) {    
    digitalWrite(pins[i], LOW);    
  }  
}

void TrafficLight::refresh(){
  if(this->enabled == false){
    return;
  }


  int beforeStart = this->startAt - millis() + 1000;    
  int count = this->mod - 1 - (beforeStart/1000);
  for (int i = 0; i < this->mod; i++) {        
    if(count >= i){
      digitalWrite(pins[i], HIGH); 
    }else{
      digitalWrite(pins[i], LOW);    
    }
  }
}
