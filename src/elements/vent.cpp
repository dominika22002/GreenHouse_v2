#include "elements/vent.h"

#include <Arduino.h>

Vent::Vent(int newPin) : isRunning(false) {
  pin = newPin;
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

void Vent::start(){
  digitalWrite(pin,HIGH);
  isRunning = true;
}

void Vent::stop(){
  digitalWrite(pin,LOW);
  isRunning = false;
}

bool Vent::getIsRunning(){
    return isRunning;
}