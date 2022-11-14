#include "managers/lightmanager.h"
#include "global.h"
#include <Arduino.h>

LightManager::LightManager(int ledsPin):
    leds(ledsPin) {
}

void LightManager::automatic(){
    Serial.println("LightManager::automatic()");
}

void LightManager::manual(int value){
    leds.setPWM(value);
    Statuses::instance().ledsPwmValue = value;
    Statuses::instance().isLedsOn = value == 0 ? false : true;
}