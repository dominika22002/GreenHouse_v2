#include "bluetooth/bluetoothservercallbacks.h"

#include <Arduino.h>

void BluetoothServerCallBacks::onConnect(BLEServer* pServer) {
    Serial.println("device connected");
}

void BluetoothServerCallBacks::onDisconnect(BLEServer* pServer) {
    Serial.println("device disconnected");
}
