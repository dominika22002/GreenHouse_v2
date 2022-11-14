#pragma once

#include <BLEDevice.h>

class BluetoothCallBacks: public BLECharacteristicCallbacks {
public:
    void onWrite(BLECharacteristic *pCharacteristic);
	void onRead(BLECharacteristic* pCharacteristic);
};
