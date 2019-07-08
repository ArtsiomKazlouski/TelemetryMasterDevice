#include <SoftwareSerial.h>

#include "TrafficLight.h"


unsigned long time;


int x[] = {4, 5, 6, 7};
TrafficLight trafficLight = TrafficLight(x, 4);

SoftwareSerial BTSerial(2, 3); // RX | TX

#define PARSE_AMOUNT 2
String intData[PARSE_AMOUNT];
boolean recievedFlag;


void setup() {  
  Serial.begin(9600);  
  BTSerial.begin(9600);
}
void loop() {  
  
  trafficLight.refresh(); 

  parsing();
  if (recievedFlag) {
    recievedFlag = false;
    String command = intData[0];   
    Serial.println(command);    
    if(command == "syn"){   
      unsigned long time = millis();
      String reply = "ack:"+String(time);
      Serial.println(reply);
      
      BTSerial.println(reply);
    }
    if(command == "start"){
      unsigned long startAt = atol(intData[1].c_str()); 
      trafficLight.init(startAt);    
      Serial.println(startAt);  
    }
  }  
}

boolean getStarted;
byte index;
String string_convert = "";
void parsing() {
  if (BTSerial.available() > 0) {
    char incomingByte = BTSerial.read();        
    if (getStarted) {                         
      if (incomingByte != '$' && incomingByte != ';') {  
        string_convert += incomingByte;       
      } else {                                
        intData[index] = string_convert;  
        string_convert = "";                  
        index++;                              
      }
    }
    if (incomingByte == '^') {                      
      getStarted = true;                      
      index = 0;                              
      string_convert = "";                    
    }
    if (incomingByte == ';') {                
      getStarted = false;                     
      recievedFlag = true;                    
    }
  }
}
