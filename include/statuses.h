#pragma once


class Statuses {
    int currentRequest;
    int currentValue;

    float analogSensorValue;
    float temperatureValue;
    float humidityValue;
    bool reedSensorValue;
    int  ledsPwmValue;

    bool isLedsOn;
    bool isVent1On;
    bool isVent2On;
    bool isWaterPompOn;

    Statuses(){}

public:

    int getCurrentRequest(){ return currentRequest;}
    int getCurrentValue(){ return currentValue;}

    float getAnalogSensorValue(){ return analogSensorValue;}
    float getTemperatureValue(){ return temperatureValue; }
    float getHumidityValue(){ return humidityValue; }
    bool getReedSensorValue(){ return reedSensorValue;}
    int getLedsPwmValue(){ return ledsPwmValue; }

    bool getIsLedsOn(){ return isLedsOn; }
    bool getIsVent1On(){ return isVent1On; }
    bool getIsVent2On(){ return isVent2On; }
    bool getIsWaterPompOn(){ return isWaterPompOn; }

    void setCurrentRequest(int newCurrentRequest){currentRequest = newCurrentRequest;}
    void setCurrentValue(int newCurrentValue){currentValue = newCurrentValue;}

    void setAnalogSensorValue(float newAnalogSensorValue){ analogSensorValue = newAnalogSensorValue; }
    void setTemperatureValue(float newTemperatureValue){ temperatureValue = newTemperatureValue; }
    void setHumidityValue(float newHumidityValue){ humidityValue = newHumidityValue; }
    void setReedSensorValue(bool newReedSensorValue){ reedSensorValue = newReedSensorValue;}
    void setLedsPwmValue(int newLedsPwmValue){ ledsPwmValue = newLedsPwmValue; }

    void setIsLedsOn(bool newIsLedsOn){ isLedsOn = newIsLedsOn; }
    void setIsVent1On(bool newInVent1On){ isVent1On = newInVent1On;}
    void setIsVent2On( bool newInVent2On){ isVent2On = newInVent2On;}
    void setIsWaterPompOn( bool newIsWaterPompOn){ isWaterPompOn = newIsWaterPompOn; }

    static Statuses & instance() {
        static Statuses s;
        return s;
    } // instance

};