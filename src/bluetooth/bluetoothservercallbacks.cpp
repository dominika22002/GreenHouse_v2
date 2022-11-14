#include "bluetooth/bluetoothservercallbacks.h"
#include "global.h"

#include <Arduino.h>

void BluetoothServerCallBacks::onConnect(BLEServer* pServer) {
    Statuses::instance().isBluetoothConnected = true;
    Serial.println("device connected");
}

void BluetoothServerCallBacks::onDisconnect(BLEServer* pServer) {
    Statuses::instance().isBluetoothConnected = false;
    Serial.println("device disconnected");
}
