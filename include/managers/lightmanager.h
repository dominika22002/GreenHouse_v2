#pragma once

#include "elements/leds.h"

#include <iostream>
#include <chrono>
#include <ctime>    


class LightManager {
    Leds leds;


public:
    LightManager(int ledsPin);

    void automatic();

    void manual(int value);
};