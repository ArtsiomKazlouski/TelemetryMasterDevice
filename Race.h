#ifndef RACE_H
#define RACE_H
 
#include <Arduino.h>
 
enum raceState {
  Aborted,
  ReadyToRace,
  Starting,
  Going,
  Finished  
};

static const char *raceState_STRING[] = {
    "Aborted", "Ready", "Steady", "Go", "Finished"
};

class Race {
  private: 
   raceState state;
   
   unsigned long startAt;
   unsigned long finishAt;
  public:
   Race();
   String toString();
   void start();
   void finish();   
   void refresh();
   long getStartTime();
   long getDuration();
   raceState getState();
};
 
#endif
