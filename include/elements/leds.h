#pragma once

class Leds {
    int pin;

public:
Leds(int newPin);

void on();

void off();
void setPWM(int value);
};