#include "sensors/reedsensor.h"

#include <Arduino.h>

ReedSensor::ReedSensor(int newPin){
  pin = newPin;
  pinMode(pin, INPUT);
}

bool ReedSensor::isSensorClose(){
    return digitalRead(pin)  == HIGH ? true : false;
}
