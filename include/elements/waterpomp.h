#pragma once

class WaterPomp {
    int pin;

public:
WaterPomp(int newPin);

void on();
void off();
};