#pragma once

#include <BLEDevice.h>

class BluetoothCallBacks: public BLECharacteristicCallbacks {
public:
    BluetoothCallBacks();
    
    void onWrite(BLECharacteristic *pCharacteristic);
	void onRead(BLECharacteristic* pCharacteristic);
};
