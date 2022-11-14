#pragma once

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


class DhtSensor {
    float humidity;
    float temperature;

    DHT_Unified dht;

    sensor_t humiditySensor;
    sensor_t temperatureSensor;

public:
DhtSensor(int newPin);

void initialize();

float getHumidity();
float getTemperature();

void measure();
void printMeasureResults();

void humiditySensorInformation();
void temperatureSensorInformation();
};