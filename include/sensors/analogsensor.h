#pragma once

class AnalogSensor {
    int pin;
    int value;

public:
AnalogSensor(int newPin);

void measure();

int getValue();

void analogSensorInformation();
};