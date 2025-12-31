#ifndef BLE_FUNCTIONS_H
#define BLE_FUNCTIONS_H

class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    bleConnected = true;
    Serial.println("BLE Connected");
  }
  
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    bleConnected = false;
    Serial.println("BLE Disconnected");
    BLEDevice::startAdvertising();
  }
};

class MyCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String value = pCharacteristic->getValue().c_str();
    if (value.length() > 0) {
      Serial.print("BLE Received: ");
      Serial.println(value);
      handleBLEData(value);
    }
  }
};

void initBLE() {
  BLEDevice::init("ESP32-Watch");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  
  BLEService *pService = pServer->createService(SERVICE_UUID);
  
  pTxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_TX,
    BLECharacteristic::PROPERTY_NOTIFY
  );
  pTxCharacteristic->addDescriptor(new BLE2902());
  
  BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID_RX,
    BLECharacteristic::PROPERTY_WRITE
  );
  pRxCharacteristic->setCallbacks(new MyCallbacks());
  
  pService->start();
  pServer->getAdvertising()->start();
  Serial.println("BLE initialized - waiting for connection...");
}

void handleBLEData(String data) {
  if (data.startsWith("NOTIF:")) {
    addNotification(data.substring(6));
    buzzer(100);
  } else if (data.startsWith("MUSIC:")) {
    updateMusicState(data.substring(6));
  } else if (data.startsWith("CALL:")) {
    handleIncomingCall(data.substring(5));
  }
}

void addNotification(String msg) {
  if (notifCount < 10) {
    notifications[notifCount++] = msg;
  }
}

void updateMusicState(String data) {
  int sep = data.indexOf('|');
  if (sep > 0) {
    musicState.title = data.substring(0, sep);
    int sep2 = data.indexOf('|', sep + 1);
    if (sep2 > 0) {
      musicState.artist = data.substring(sep + 1, sep2);
      musicState.playing = data.substring(sep2 + 1) == "1";
    }
  }
}

void handleIncomingCall(String caller) {
  currentApp = APP_PHONE;
  currentScreen = SCREEN_APP;
  screenActive = true;
  lastActivity = millis();
  buzzer(1000);
}

void sendBLECommand(String cmd) {
  if (deviceConnected) {
    pTxCharacteristic->setValue(cmd.c_str());
    pTxCharacteristic->notify();
  }
}

#endif
