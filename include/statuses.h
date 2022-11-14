#pragma once

enum Modes {
    AUTOMATIC,
    MANUAL
};

class Statuses {
    Statuses(){}

public:
    int currentRequest;
    int currentValue;
    int isBluetoothConnected;

    Modes mode;

    float analogSensorValue;
    float temperatureValue;
    float humidityValue;
    bool reedSensorValue;
    int  ledsPwmValue;

    bool isLedsOn;
    bool isVent1On;
    bool isVent2On;
    bool isWaterPompOn;

    static Statuses & instance() {
        static Statuses s;
        return s;
    } // instance

};