#ifndef CONFIG_H
#define CONFIG_H

// Pin definitions
#define BUTTON_1 14
#define BUTTON_2 15
#define BUZZER_PIN 16
#define BATTERY_PIN 4
#define TOUCH_INT 5

// I2S Microphone pins
#define I2S_WS 6
#define I2S_SD 7
#define I2S_SCK 8

// I2C pins
#define I2C_SDA 21
#define I2C_SCL 22

// Display settings
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240
#define CENTER_X 120
#define CENTER_Y 120

// Timing constants
#define SCREEN_TIMEOUT 10000
#define DEBOUNCE_DELAY 50
#define LONG_PRESS_TIME 1000
#define STEP_THRESHOLD 1000
#define STEP_MIN_INTERVAL 300

// BLE UUIDs
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

// Icon sizes
#define ICON_WIDTH 40
#define ICON_HEIGHT 40

#endif
