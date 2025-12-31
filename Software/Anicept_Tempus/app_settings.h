#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

void drawSettingsApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Settings", t);
  
  tft.setTextSize(1);
  tft.setTextColor(t.text);
  
  const char* items[] = {
    "Theme",
    "Clock Style", 
    "Time Format",
    "Brightness",
    "Step Tracking",
    "Gestures",
    "Button 1 App",
    "Button 2 App"
  };
  
  for (int i = 0; i < 8; i++) {
    tft.setCursor(10, 40 + i * 22);
    tft.print(items[i]);
    
    // Show current value
    tft.setCursor(160, 40 + i * 22);
    switch(i) {
      case 0: tft.print(settings.theme); break;
      case 1: tft.print(settings.analogClock ? "Analog" : "Digital"); break;
      case 2: tft.print(settings.format24h ? "24h" : "12h"); break;
      case 3: tft.print(settings.brightness); break;
      case 4: tft.print(settings.stepTracking ? "ON" : "OFF"); break;
      case 5: tft.print(settings.gestureControl ? "ON" : "OFF"); break;
      case 6: tft.print(appNames[settings.button1App]); break;
      case 7: tft.print(appNames[settings.button2App]); break;
    }
  }
  
  tft.setTextSize(1);
  tft.setCursor(20, 220);
  tft.print("Press to cycle options");
}

#endif
