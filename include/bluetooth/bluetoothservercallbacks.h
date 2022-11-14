#pragma once

#include <BLEServer.h>

class BluetoothServerCallBacks: public BLEServerCallbacks {
public:
    void onConnect(BLEServer* pServer);
    void onDisconnect(BLEServer* pServer);
};
