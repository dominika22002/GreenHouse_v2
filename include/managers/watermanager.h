#pragma once

#include "elements/waterpomp.h"
#include "sensors/analogsensor.h"
#include "sensors/reedsensor.h"

class WaterManager {
    WaterPomp waterPomp;
    ReedSensor reedSensor;
    AnalogSensor analogSensor;

public:
    WaterManager(int waterPompPin, int reedSensorPin, int analogSensorPin);

    void automatic();
    
    void manual(bool waterPlants);
};