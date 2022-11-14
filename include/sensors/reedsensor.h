#pragma once

class ReedSensor {
    int pin;

public:
ReedSensor(int newPin);

bool isSensorClose();
};