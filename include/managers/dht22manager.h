#pragma once

#include "elements/vent.h"
#include "sensors/dhtsensor.h"

class Dht22Manager {
    Vent vent1;
    Vent vent2;
    DhtSensor dhtSensor;

public:
    Dht22Manager(int vent1Pin, int vent2Pin, int dhtSensorPin);
    
    void automatic();

    void manual();
    void manualVent1(bool isRunningVent1);
    void manualVent2(bool isRunningVent2);
};