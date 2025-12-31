#ifndef SENSOR_FUNCTIONS_H
#define SENSOR_FUNCTIONS_H

void updateSensors() {
  // Update battery level
  int raw = analogRead(BATTERY_PIN);
  batteryLevel = (raw / 4095.0) * 100.0;
  
  // Step detection
  if (settings.stepTracking) {
    int32_t accel[3];
    lsm6dsox.Get_X_Axes(accel);
    
    float mag = sqrt(accel[0]*accel[0] + accel[1]*accel[1] + accel[2]*accel[2]);
    
    if (abs(mag - lastAccelMag) > STEP_THRESHOLD && 
        millis() - lastStepTime > STEP_MIN_INTERVAL) {
      stepCount++;
      lastStepTime = millis();
    }
    
    lastAccelMag = mag;
  }
}

void checkGestures() {
  int32_t accel[3];
  lsm6dsox.Get_X_Axes(accel);
  
  // Wrist raise detection (Z-axis)
  if (accel[2] > 8000 && !screenActive) {
    screenActive = true;
    lastActivity = millis();
    Serial.println("Wrist raise detected");
  }
}

void buzzer(int duration) {
  tone(BUZZER_PIN, 2000, duration);
}

void loadSettings() {
  prefs.begin("smartwatch", false);
  settings.theme = prefs.getInt("theme", 0);
  settings.analogClock = prefs.getBool("analog", true);
  settings.format24h = prefs.getBool("24h", false);
  settings.button1App = prefs.getInt("btn1", APP_MESSAGES);
  settings.button2App = prefs.getInt("btn2", APP_MUSIC);
  settings.brightness = prefs.getInt("bright", 128);
  settings.stepTracking = prefs.getBool("steps", true);
  settings.gestureControl = prefs.getBool("gesture", true);
  prefs.end();
  Serial.println("Settings loaded");
}

void saveSettings() {
  prefs.begin("smartwatch", false);
  prefs.putInt("theme", settings.theme);
  prefs.putBool("analog", settings.analogClock);
  prefs.putBool("24h", settings.format24h);
  prefs.putInt("btn1", settings.button1App);
  prefs.putInt("btn2", settings.button2App);
  prefs.putInt("bright", settings.brightness);
  prefs.putBool("steps", settings.stepTracking);
  prefs.putBool("gesture", settings.gestureControl);
  prefs.end();
  Serial.println("Settings saved");
}

#endif
