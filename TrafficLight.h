#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
 
#include <Arduino.h>


class TrafficLight {
  private: 
   int * pins;
   int mod;
   long startAt;
   bool enabled;
  public:
   TrafficLight(int pins[], int sizeMod);
   void init(long startAtMilis);   
   void reset();
   void refresh();
};
 
#endif
