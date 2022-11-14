#pragma once

class Vent {
    int pin;
    bool isRunning;

public:
Vent(int newPin);

bool getIsRunning();

void start();

void stop();
};