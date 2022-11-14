#include "bluetooth/bluetoothcallbacks.h"
#include "global.h"

#include <Arduino.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
namespace {
    void getRequest(std::string request){
        std::stringstream requestStream(request);
        std::istream_iterator<int> begin(requestStream);
        std::istream_iterator<int> end;
        std::vector<int> requestVector(begin, end);
    
        Statuses::instance().currentRequest = requestVector[0];
        Statuses::instance().currentValue = requestVector[1];
        Serial.printf("Request %d with value %d \n",
                        Statuses::instance().currentRequest,
                        Statuses::instance().currentValue);

       
    }    
}

void BluetoothCallBacks::onWrite(BLECharacteristic *pCharacteristic) {
    std::string value = pCharacteristic->getValue();

    if (value.length() <= 0){
        Serial.printf("Problem with request");
        return;
    }
    getRequest(value);

    Statuses::instance().mode = Modes::MANUAL;
    TimeService::instance().resetTimeToResetMode();
    Serial.println(Statuses::instance().mode == Modes::AUTOMATIC ? "automatic" : "manual");
}

void BluetoothCallBacks::onRead(BLECharacteristic *pCharacteristic){
    if (Statuses::instance().currentRequest != 0){
        Serial.printf("Response to %d request\n",Statuses::instance().currentRequest);
        uint8_t tempData[1] = {1};
        pCharacteristic->setValue(tempData, 1);
        pCharacteristic->notify();
        return;
    }


    float temperature = Statuses::instance().temperatureValue;
    float humidity = Statuses::instance().humidityValue;

    // convert float value into 16 bit integer value (LSB first MSB last)
    uint8_t tempData[12];

    uint8_t isDataBaseValue     = (uint8_t)(0);
    uint8_t temperatureInt      = (uint8_t)(temperature);
    uint8_t temperatureDecPoint = (uint8_t)(temperature*10-temperatureInt*10);
    uint8_t humidityInt         = (uint8_t)(humidity);
    uint8_t humidityDecPoint    = (uint8_t)(humidity*10-humidityInt*10);
    uint8_t analogInt           = (uint8_t)(Statuses::instance().analogSensorValue);

    uint8_t reedSensorBool  = (uint8_t)(Statuses::instance().reedSensorValue);
    uint8_t ledsPwmInt      = (uint8_t)(Statuses::instance().ledsPwmValue);
    uint8_t ledsBool        = (uint8_t)(Statuses::instance().isLedsOn);
    uint8_t vent1Bool       = (uint8_t)(Statuses::instance().isVent1On);
    uint8_t vent2Bool       = (uint8_t)(Statuses::instance().isVent2On);
    uint8_t waterPompBool   = (uint8_t)(Statuses::instance().isWaterPompOn);


    tempData[0]  = isDataBaseValue;
    tempData[1]  = temperatureInt;
    tempData[2]  = temperatureDecPoint;
    tempData[3]  = humidityInt;
    tempData[4]  = humidityDecPoint;
    tempData[5]  = analogInt;
    tempData[6]  = reedSensorBool;
    tempData[7]  = ledsPwmInt;
    tempData[8]  = ledsBool;
    tempData[9]  = vent1Bool;
    tempData[10] = vent2Bool;
    tempData[11] = waterPompBool;

    pCharacteristic->setValue(tempData, 12);
    pCharacteristic->notify();
}
