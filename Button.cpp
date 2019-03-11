#include "Button.h"

Button::Button(byte pin){
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
  };
Button::~Button(){};
void Button::refresh(){  };
bool Button::pressed(){ return !digitalRead(pin); };
bool Button::clicked(){ return false; };
bool Button::released(){ return false; };
