#include "sensors/dhtsensor.h"

namespace {
  constexpr int DHT_TYPE = DHT22;
}


DhtSensor::DhtSensor(int newPin): 
    humidity(0), 
    temperature(0), 
    dht(newPin, DHT_TYPE),
    humiditySensor(sensor_t()),
    temperatureSensor(sensor_t())
    {
}
void DhtSensor::initialize() {
  dht.begin();
  dht.temperature().getSensor(&temperatureSensor);
  dht.humidity().getSensor(&humiditySensor);
}

float DhtSensor::getHumidity() {
    return humidity;

}
float DhtSensor::getTemperature() {
    return temperature;
}

void DhtSensor::measure() {
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    temperature = event.temperature;

    dht.humidity().getEvent(&event);
    humidity = event.relative_humidity;
}

void DhtSensor::printMeasureResults(){
    Serial.printf("Temperature:\t%0.1f °C\n", temperature);
    Serial.printf("Humidity:\t%0.1f %%\n", humidity);
}

void DhtSensor::humiditySensorInformation(){
    Serial.printf("\n---Humidity Sensor---\n");
    Serial.printf("Sensor Type:\t%s\n", humiditySensor.name);
    Serial.printf("Driver Version:\t%d\n", humiditySensor.version);
    Serial.printf("Unique ID:\t%d\n", humiditySensor.sensor_id);
    Serial.printf("Max Value:\t%0.1f %%\n", humiditySensor.max_value);
    Serial.printf("Min Value:\t%0.1f %%\n", humiditySensor.min_value);
    Serial.printf("Resolution:\t%0.1f %%\n", humiditySensor.resolution);
}
void DhtSensor::temperatureSensorInformation(){
    Serial.printf("\n---Temperature Sensor---\n");
    Serial.printf("Sensor Type:\t%s\n", temperatureSensor.name);
    Serial.printf("Driver Version:\t%d\n", temperatureSensor.version);
    Serial.printf("Unique ID:\t%d\n", temperatureSensor.sensor_id);
    Serial.printf("Max Value:\t%0.1f °C\n", temperatureSensor.max_value);
    Serial.printf("Min Value:\t%0.1f °C\n", temperatureSensor.min_value);
    Serial.printf("Resolution:\t%0.1f °C\n", temperatureSensor.resolution);
}