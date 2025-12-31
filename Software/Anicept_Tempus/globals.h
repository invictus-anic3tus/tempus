#ifndef GLOBALS_H
#define GLOBALS_H

// App IDs
enum AppID {
  APP_CLOCK,
  APP_MESSAGES,
  APP_PHONE,
  APP_MUSIC,
  APP_HEALTH,
  APP_CAMERA,
  APP_SETTINGS,
  APP_CLOCK_TOOLS,
  APP_COMPASS,
  APP_COUNT
};

// Screen states
enum ScreenState {
  SCREEN_MAIN_CLOCK,
  SCREEN_APP,
  SCREEN_APP_LAUNCHER
};

// Theme structure
struct Theme {
  uint16_t bg;
  uint16_t fg;
  uint16_t accent;
  uint16_t text;
};

// Settings structure
struct Settings {
  int theme;
  bool analogClock;
  bool format24h;
  int button1App;
  int button2App;
  int brightness;
  bool stepTracking;
  bool gestureControl;
};

// Music player state
struct MusicState {
  String title;
  String artist;
  bool playing;
};

// Predefined themes
Theme themes[] = {
  {TFT_BLACK, TFT_WHITE, TFT_CYAN, TFT_WHITE},      // 0: Dark
  {TFT_WHITE, TFT_BLACK, TFT_BLUE, TFT_BLACK},      // 1: Light
  {0x1082, 0xFFFF, TFT_GREEN, TFT_WHITE},           // 2: Matrix
  {0x4208, TFT_ORANGE, TFT_RED, TFT_ORANGE}         // 3: Sunset
};

// App names
const char* appNames[] = {
  "Clock",
  "Messages",
  "Phone",
  "Music",
  "Health",
  "Camera",
  "Settings",
  "Tools",
  "Compass"
};

// Global objects
extern TFT_eSPI tft;
extern RTC_DS3231 rtc;
extern LSM6DSOXSensor lsm6dsox;
extern Preferences prefs;

// BLE variables
extern BLEServer* pServer;
extern BLECharacteristic* pTxCharacteristic;
extern bool deviceConnected;

// Global state variables
extern Settings settings;
extern AppID currentApp;
extern ScreenState currentScreen;
extern bool screenActive;
extern unsigned long lastActivity;
extern int stepCount;
extern float batteryLevel;
extern bool bleConnected;

// Notifications
extern String notifications[10];
extern int notifCount;

// Music state
extern MusicState musicState;

// Step detection
extern float lastAccelMag;
extern unsigned long lastStepTime;

// Initialize global objects
TFT_eSPI tft = TFT_eSPI();
RTC_DS3231 rtc;
LSM6DSOXSensor lsm6dsox(&Wire);
Preferences prefs;

BLEServer* pServer = NULL;
BLECharacteristic* pTxCharacteristic;
bool deviceConnected = false;

Settings settings;
AppID currentApp = APP_CLOCK;
ScreenState currentScreen = SCREEN_MAIN_CLOCK;
bool screenActive = false;
unsigned long lastActivity = 0;
int stepCount = 0;
float batteryLevel = 0;
bool bleConnected = false;

String notifications[10];
int notifCount = 0;

MusicState musicState;

float lastAccelMag = 0;
unsigned long lastStepTime = 0;

