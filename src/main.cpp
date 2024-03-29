#include <Arduino.h>

// Includes with electronic (sensors and elements)
#include "managers/dht22manager.h"
#include "managers/lightmanager.h"
#include "managers/watermanager.h"

// Include with communication header file
#include "bluetooth/bluetoothcallbacks.h"
#include "bluetooth/bluetoothservercallbacks.h"

#include "global.h"

namespace {
namespace EspInitialization {
    constexpr int BAUD_RATE = 9600;   ///< Speed of transmission
    constexpr int DELAY_MS = 1000;    ///< Delay in milliseconds
} // namespace EspInitialisation

namespace PinOut {
    constexpr int ANALOG_PIN = 35;    ///< Water level analog sensor pin
    constexpr int DHT_PIN = 16;       ///< Dht22 pin
    constexpr int LEDS_PIN = 32;      ///< Leds pin
    constexpr int REED_PIN = 18;      ///< Water level contracton sensor pin
    constexpr int VENT_1_PIN = 14;    ///< First vent pin
    constexpr int VENT_2_PIN = 12;    ///< Second vent pin
    constexpr int WATER_POMP_PIN = 26;///< Water pomp pin
} // namespace PinOut

namespace BluetoothService {
    constexpr char SERVICE_UUID[] = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
    constexpr char CHARACTERISTIC_UUID[] = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
    constexpr char DEVICE_NAME[] = "GreenHouse";
}

// Managers
WaterManager waterManager(PinOut::WATER_POMP_PIN, PinOut::REED_PIN, PinOut::ANALOG_PIN);
Dht22Manager dht22Manager(PinOut::VENT_1_PIN, PinOut::VENT_2_PIN, PinOut::DHT_PIN);
LightManager lightManager(PinOut::LEDS_PIN);

// Bluetooth connection
BLECharacteristic *pCharacteristic;
BLEServer *pServer;
BLEService *pService;
BLEAdvertising *pAdvertising;

void doRequest(){
    bool isRequest = Statuses::instance().currentRequest != 0;

    switch (Statuses::instance().currentRequest)
    {
    case 1:
        dht22Manager.manualVent1(Statuses::instance().currentValue);
        Serial.println("After dht22Manager.manualVent1()");
        break;
    
    case 2:
        dht22Manager.manualVent2(Statuses::instance().currentValue);
        Serial.println("After dht22Manager.manualVent2()");
        break;
    
    case 3:
        lightManager.manual(Statuses::instance().currentValue);
        Serial.println("After lightManager.manual()");
        break;
    
    case 4:
        waterManager.manual(Statuses::instance().currentValue);
        Serial.println("After waterManager.manual()");
        break;
    
    case 5:
        waterManager.manual(Statuses::instance().currentValue);
        Serial.println("After waterManager.manual()");
        break;
    default:
        break;
    }
    if (isRequest){
        Statuses::instance().currentRequest = 0;
        Statuses::instance().currentValue = 0;
    }
}

void automaticMode(){
    if (Statuses::instance().mode == Modes::AUTOMATIC) {
        dht22Manager.automatic();
        lightManager.automatic();
        waterManager.automatic();
    }
}

void manualMode(){
    if (Statuses::instance().mode == Modes::MANUAL) { 
        Serial.printf("Time to reset timer: %d\n", 
                            TimeService::instance().initialTimeToResetMode - 
                            TimeService::instance().timeToResetMode);
    }
}


}; // end namespace

void setup() {
    Serial.begin(EspInitialization::BAUD_RATE);

    // Initialization of bluetooth service
    BLEDevice::init(BluetoothService::DEVICE_NAME);
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new BluetoothServerCallBacks());
    pService = pServer->createService(BluetoothService::SERVICE_UUID);

    pCharacteristic= pService->createCharacteristic(
                                            BluetoothService::CHARACTERISTIC_UUID,
                                            BLECharacteristic::PROPERTY_READ |
                                            BLECharacteristic::PROPERTY_WRITE |
                                            BLECharacteristic::PROPERTY_NOTIFY );

    pCharacteristic->setCallbacks(new BluetoothCallBacks());

    pCharacteristic->setValue("GreenHouse says hello");
    pService->start();
    pAdvertising = pServer->getAdvertising();
    pAdvertising->start();

    Statuses::instance().mode = Modes::AUTOMATIC;
    // End of initialization bluetooth service
}

void loop() {
    delay(EspInitialization::DELAY_MS);
    if (!Statuses::instance().isBluetoothConnected){
        pAdvertising->start();
    }
    doRequest();
    automaticMode();
    manualMode();

    TimeService::instance().checkTimes();
    Serial.printf("Application mode: ");
    Serial.printf(Statuses::instance().mode == Modes::AUTOMATIC ? "automatic\n" : "manual\n");
}