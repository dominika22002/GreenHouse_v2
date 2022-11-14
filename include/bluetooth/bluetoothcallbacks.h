#pragma once

#include <BLEDevice.h>

class BluetoothCallBacks: public BLECharacteristicCallbacks {
    int currentRequest;
public:
    BluetoothCallBacks();
    
    void onWrite(BLECharacteristic *pCharacteristic);
	void onRead(BLECharacteristic* pCharacteristic);
};
