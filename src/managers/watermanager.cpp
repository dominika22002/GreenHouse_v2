#include "managers/watermanager.h"

#include "global.h"

#include <Arduino.h>

namespace {
    constexpr int MIN_VAL_WATER_POT = 20;
    constexpr int MAX_VAL_WATER_POT = 80;
}

WaterManager::WaterManager(int waterPompPin, int reedSensorPin, int analogSensorPin):
    waterPomp(waterPompPin),
    reedSensor(reedSensorPin),
    analogSensor(analogSensorPin) {
}

void WaterManager::automatic(){
    Serial.println("WaterManager::automatic()\n");

    analogSensor.measure();
    Serial.printf("Reed Sensor: %d",reedSensor.isSensorClose()? 1 : 0);
    Statuses::instance().setAnalogSensorValue(analogSensor.getValue());

    if (analogSensor.getValue() <= MIN_VAL_WATER_POT) {
        if (!reedSensor.isSensorClose()){
            waterPomp.on();
            Statuses::instance().setIsWaterPompOn(true);

        } else {
            waterPomp.off();
            Statuses::instance().setIsWaterPompOn(false);
        }
    } else if (analogSensor.getValue() >= MAX_VAL_WATER_POT) {
        waterPomp.off();
        Statuses::instance().setIsWaterPompOn(false);
    }
    Statuses::instance().setReedSensorValue(reedSensor.isSensorClose());

}

void WaterManager::manual(bool waterPlants){
    Serial.println("WaterManager::manual()");

    analogSensor.measure();
    Statuses::instance().setAnalogSensorValue(analogSensor.getValue());
    
    if (waterPlants==true) {
        if (analogSensor.getValue() < MAX_VAL_WATER_POT) {
            if (!reedSensor.isSensorClose()){
                waterPomp.on();
                Statuses::instance().setIsWaterPompOn(true);
            } else {
                waterPomp.off();
                Statuses::instance().setIsWaterPompOn(false);
            }
        } else if (analogSensor.getValue() >= MAX_VAL_WATER_POT) {
            waterPomp.off();
            Statuses::instance().setIsWaterPompOn(false);
        }
    }
    Statuses::instance().setReedSensorValue(reedSensor.isSensorClose());
}
