#ifndef APP_HEALTH_H
#define APP_HEALTH_H

void drawHealthApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Health", t);
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  
  // Steps
  tft.setCursor(20, 60);
  tft.print("Steps:");
  tft.setTextSize(3);
  tft.setCursor(40, 85);
  tft.setTextColor(t.accent);
  tft.print(stepCount);
  
  // Goal indicator (example: 10000 steps)
  int goal = 10000;
  int progress = min(100, (stepCount * 100) / goal);
  tft.drawRect(20, 120, 200, 20, t.fg);
  tft.fillRect(21, 121, progress * 2, 18, TFT_GREEN);
  
  // Battery
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  tft.setCursor(20, 160);
  tft.print("Battery:");
  tft.setTextSize(3);
  tft.setCursor(40, 185);
  tft.setTextColor(batteryLevel > 20 ? TFT_GREEN : TFT_RED);
  tft.print((int)batteryLevel);
  tft.print("%");
}

#endif
