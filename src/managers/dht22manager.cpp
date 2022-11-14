#include "managers/dht22manager.h"

#include "global.h"

#include <Arduino.h>

namespace {
    constexpr int blabla = 0;
}
namespace {
    constexpr int MAX_TEMPERATURE = 26;
    constexpr int MIN_TEMPERATURE = 26;
    constexpr int MAX_HUMIDITY = 80;
    constexpr int MIN_HUMIDITY = 60;
}

Dht22Manager::Dht22Manager(int vent1Pin, int vent2Pin, int dhtSensorPin):
    vent1(vent1Pin),
    vent2(vent2Pin),
    dhtSensor(dhtSensorPin) {  
    dhtSensor.initialize();
}

void Dht22Manager::automatic(){
    Serial.println("Dht22Manager::automatic()");

    dhtSensor.measure();

    Statuses::instance().temperatureValue = dhtSensor.getTemperature();
    Statuses::instance().humidityValue = dhtSensor.getHumidity();

    // Temperature sensor management
    if (dhtSensor.getTemperature() > MAX_TEMPERATURE){
        if (!vent1.getIsRunning()){
            vent1.start();
            Statuses::instance().isVent1On = true;
        }
    }    
    if (dhtSensor.getTemperature() <= MIN_TEMPERATURE){
        if (vent1.getIsRunning()){
            vent1.stop();
            Statuses::instance().isVent1On = false;
        }
        
    }

    // Humidity sensor management
    if (dhtSensor.getHumidity() > MAX_HUMIDITY){
        if (!vent1.getIsRunning()){
            vent1.start();
            Statuses::instance().isVent1On = true;
        }
        if (!vent2.getIsRunning()){
            vent2.stop();
            Statuses::instance().isVent1On =false;
        }
    }    
    if (dhtSensor.getHumidity() <= MIN_HUMIDITY){
        if (vent1.getIsRunning()){
            vent1.start();
            Statuses::instance().isVent2On = true;
        }
        if (vent2.getIsRunning()){
            vent2.stop();
            Statuses::instance().isVent2On = false;
        }
    }
    dhtSensor.printMeasureResults();
}

void Dht22Manager::manual(){
    dhtSensor.measure();

    Statuses::instance().temperatureValue = dhtSensor.getTemperature();
    Statuses::instance().humidityValue = dhtSensor.getHumidity();

}

void Dht22Manager::manualVent1(bool isRunningVent1){
    if (isRunningVent1){
        if (!vent1.getIsRunning()){
            vent1.start();
        }
    } else {
        if (vent1.getIsRunning()){
            vent1.stop();
        }
    }

    Statuses::instance().isVent1On = isRunningVent1;
}

void Dht22Manager::manualVent2(bool isRunningVent2){
    if (isRunningVent2){
        if (!vent2.getIsRunning()){
            vent2.start();
        }
    } else {
        if (vent2.getIsRunning()){
            vent2.stop();
        }
    }
    Statuses::instance().isVent2On = isRunningVent2;
}