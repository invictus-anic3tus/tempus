#ifndef DISPLAY_FUNCTIONS_H
#define DISPLAY_FUNCTIONS_H

void drawHeader(const char* title, Theme t) {
  tft.fillRect(0, 0, SCREEN_WIDTH, 30, t.accent);
  tft.setTextColor(t.bg);
  tft.setTextSize(2);
  tft.setCursor(10, 8);
  tft.print(title);
}

void drawStatusBar(Theme t) {
  tft.setTextSize(1);
  tft.setTextColor(t.text);
  
  // Battery percentage
  tft.setCursor(5, 5);
  tft.print((int)batteryLevel);
  tft.print("%");
  
  // Battery icon
  tft.drawRect(50, 5, 20, 10, t.text);
  tft.fillRect(70, 7, 2, 6, t.text);
  int fillWidth = (batteryLevel / 100.0) * 18;
  tft.fillRect(51, 6, fillWidth, 8, t.accent);
  
  // BLE status
  if (bleConnected) {
    tft.fillCircle(220, 10, 5, TFT_BLUE);
  } else {
    tft.drawCircle(220, 10, 5, t.fg);
  }
  
  // Notification indicator
  if (notifCount > 0) {
    tft.fillCircle(200, 10, 8, TFT_RED);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(197, 5);
    if (notifCount > 9) {
      tft.print("9+");
    } else {
      tft.print(notifCount);
    }
  }
}

void showBootScreen() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(4);
  tft.setTextColor(TFT_CYAN);
  tft.setCursor(25, 80);
  tft.print("ESP32");
  tft.setTextSize(3);
  tft.setCursor(40, 120);
  tft.print("WATCH");
  
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(60, 180);
  tft.print("Initializing...");
}

void drawAppLauncher(Theme t) {
  static bool needsRedraw = true;
  
  if (!needsRedraw) return;
  
  tft.fillScreen(t.bg);
  drawHeader("Apps", t);
  
  // Draw 3x3 grid of app icons
  int gridSize = 3;
  int iconSpacing = 80;
  int startX = (SCREEN_WIDTH - (gridSize * iconSpacing)) / 2 + 20;
  int startY = 50;
  
  for (int i = 0; i < APP_COUNT && i < 9; i++) {
    int row = i / gridSize;
    int col = i % gridSize;
    int x = startX + col * iconSpacing;
    int y = startY + row * iconSpacing;
    
    // Draw icon
    drawIcon(x, y, app_icons[i]);
    
    // Draw app name below icon
    tft.setTextSize(1);
    tft.setTextColor(t.text);
    int nameLen = strlen(appNames[i]);
    tft.setCursor(x + 20 - (nameLen * 3), y + 45);
    tft.print(appNames[i]);
  }
  
  needsRedraw = false;
}

#endif
