#include "sensors/analogsensor.h"

#include <Arduino.h>

namespace {
    constexpr int MAX_PERCENTS = 100;
    constexpr int MAX_VALUE = 4095;
}

AnalogSensor::AnalogSensor(int newPin){
  pin = newPin;
}

void AnalogSensor::measure(){
  value = analogRead(pin);
}

int AnalogSensor::getValue(){
    return value * MAX_PERCENTS / MAX_VALUE;
}

void AnalogSensor::analogSensorInformation(){
    Serial.printf("\n---Analog Sensor---\n");
    Serial.printf("0%% \t 0V \t 0");
    Serial.printf("100%% \t 3,3V \t 4095");
}