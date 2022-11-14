#include "elements/waterpomp.h"

#include <Arduino.h>

WaterPomp::WaterPomp(int newPin){
  pin = newPin;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void WaterPomp::on(){
  digitalWrite(pin, HIGH);
}

void WaterPomp::off(){
  digitalWrite(pin, LOW);
}
