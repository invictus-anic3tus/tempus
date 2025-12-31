#include <TFT_eSPI.h>
#include <RTClib.h>
#include <Wire.h>
#include <LSM6DSOXSensor.h>
#include <Preferences.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "config.h"
#include "globals.h"
#include "icons.h"
#include "ble_functions.h"
#include "sensor_functions.h"
#include "display_functions.h"
#include "app_clock.h"
#include "app_messages.h"
#include "app_phone.h"
#include "app_music.h"
#include "app_health.h"
#include "app_camera.h"
#include "app_settings.h"
#include "app_clocktools.h"
#include "app_compass.h"

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Smartwatch Starting...");
  
  // Initialize pins
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BATTERY_PIN, INPUT);
  
  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);
  
  // Initialize display
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  
  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
  } else {
    Serial.println("RTC initialized");
  }
  
  // Initialize IMU
  if (lsm6dsox.begin() != LSM6DSOX_OK) {
    Serial.println("IMU not found!");
  } else {
    lsm6dsox.Enable_X();
    lsm6dsox.Enable_G();
    Serial.println("IMU initialized");
  }
  
  // Load settings from flash
  loadSettings();
  
  // Initialize BLE
  initBLE();
  
  // Show boot screen
  showBootScreen();
  delay(2000);
  
  // Go to clock
  currentApp = APP_CLOCK;
  currentScreen = SCREEN_MAIN_CLOCK;
  screenActive = true;
  lastActivity = millis();
  
  Serial.println("Setup complete!");
}

void loop() {
  // Check buttons
  checkButtons();
  
  // Update sensors
  updateSensors();
  
  // Check gestures
  if (settings.gestureControl) {
    checkGestures();
  }
  
  // Handle touch input (if touch screen)
  // checkTouch();
  
  // Update current app display
  updateCurrentApp();
  
  // Screen timeout
  if (screenActive && millis() - lastActivity > SCREEN_TIMEOUT) {
    screenActive = false;
    tft.fillScreen(TFT_BLACK);
    Serial.println("Screen off");
  }
  
  delay(50);
}

void checkButtons() {
  static bool btn1Last = HIGH;
  static bool btn2Last = HIGH;
  static unsigned long btn1PressTime = 0;
  static unsigned long btn2PressTime = 0;
  
  bool btn1 = digitalRead(BUTTON_1);
  bool btn2 = digitalRead(BUTTON_2);
  
  // Button 1 - Short press
  if (btn1 == LOW && btn1Last == HIGH) {
    btn1PressTime = millis();
    delay(DEBOUNCE_DELAY);
  }
  
  if (btn1 == HIGH && btn1Last == LOW) {
    unsigned long pressDuration = millis() - btn1PressTime;
    lastActivity = millis();
    
    if (!screenActive) {
      screenActive = true;
      Serial.println("Screen on - Button 1");
    } else if (pressDuration < LONG_PRESS_TIME) {
      // Short press - go to app or go back
      if (currentScreen == SCREEN_MAIN_CLOCK) {
        currentApp = (AppID)settings.button1App;
        currentScreen = SCREEN_APP;
        Serial.print("Button 1 -> App: ");
        Serial.println(currentApp);
      } else {
        currentScreen = SCREEN_MAIN_CLOCK;
        currentApp = APP_CLOCK;
        Serial.println("Back to clock");
      }
    } else {
      // Long press - go to home/app launcher
      currentScreen = SCREEN_APP_LAUNCHER;
      Serial.println("Long press - App launcher");
    }
  }
  
  // Button 2 - Short press
  if (btn2 == LOW && btn2Last == HIGH) {
    btn2PressTime = millis();
    delay(DEBOUNCE_DELAY);
  }
  
  if (btn2 == HIGH && btn2Last == LOW) {
    unsigned long pressDuration = millis() - btn2PressTime;
    lastActivity = millis();
    
    if (!screenActive) {
      screenActive = true;
      Serial.println("Screen on - Button 2");
    } else if (pressDuration < LONG_PRESS_TIME) {
      if (currentScreen == SCREEN_MAIN_CLOCK) {
        currentApp = (AppID)settings.button2App;
        currentScreen = SCREEN_APP;
        Serial.print("Button 2 -> App: ");
        Serial.println(currentApp);
      } else {
        currentScreen = SCREEN_MAIN_CLOCK;
        currentApp = APP_CLOCK;
        Serial.println("Back to clock");
      }
    }
  }
  
  btn1Last = btn1;
  btn2Last = btn2;
}

void updateCurrentApp() {
  if (!screenActive) return;
  
  Theme t = themes[settings.theme];
  
  if (currentScreen == SCREEN_APP_LAUNCHER) {
    drawAppLauncher(t);
    return;
  }
  
  if (currentScreen == SCREEN_MAIN_CLOCK) {
    currentApp = APP_CLOCK;
  }
  
  switch (currentApp) {
    case APP_CLOCK:
      drawClockApp(t);
      break;
    case APP_MESSAGES:
      drawMessagesApp(t);
      break;
    case APP_PHONE:
      drawPhoneApp(t);
      break;
    case APP_MUSIC:
      drawMusicApp(t);
      break;
    case APP_HEALTH:
      drawHealthApp(t);
      break;
    case APP_CAMERA:
      drawCameraApp(t);
      break;
    case APP_SETTINGS:
      drawSettingsApp(t);
      break;
    case APP_CLOCK_TOOLS:
      drawClockToolsApp(t);
      break;
    case APP_COMPASS:
      drawCompassApp(t);
      break;
  }
}
