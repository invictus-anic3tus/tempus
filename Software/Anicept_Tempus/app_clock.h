#ifndef APP_CLOCK_H
#define APP_CLOCK_H

void drawClockApp(Theme t) {
  static int lastSec = -1;
  DateTime now = rtc.now();
  
  if (now.second() != lastSec) {
    tft.fillScreen(t.bg);
    drawStatusBar(t);
    
    if (settings.analogClock) {
      drawAnalogClock(now, t);
    } else {
      drawDigitalClock(now, t);
    }
    
    // Draw date
    tft.setTextColor(t.text);
    tft.setTextSize(2);
    char dateStr[20];
    sprintf(dateStr, "%02d/%02d/%04d", now.month(), now.day(), now.year());
    int dateWidth = strlen(dateStr) * 12;
    tft.setCursor((SCREEN_WIDTH - dateWidth) / 2, 200);
    tft.print(dateStr);
    
    lastSec = now.second();
  }
}

void drawAnalogClock(DateTime now, Theme t) {
  int h = now.hour() % 12;
  int m = now.minute();
  int s = now.second();
  
  // Draw clock face circle
  tft.drawCircle(CENTER_X, CENTER_Y - 20, 80, t.fg);
  tft.drawCircle(CENTER_X, CENTER_Y - 20, 79, t.fg);
  
  // Draw hour markers
  for (int i = 0; i < 12; i++) {
    float angle = (i * 30 - 90) * PI / 180;
    int x1 = CENTER_X + cos(angle) * 70;
    int y1 = CENTER_Y - 20 + sin(angle) * 70;
    int x2 = CENTER_X + cos(angle) * 75;
    int y2 = CENTER_Y - 20 + sin(angle) * 75;
    tft.drawLine(x1, y1, x2, y2, t.accent);
    
    // Thicker markers at 12, 3, 6, 9
    if (i % 3 == 0) {
      int x3 = CENTER_X + cos(angle) * 65;
      int y3 = CENTER_Y - 20 + sin(angle) * 65;
      tft.drawLine(x3, y3, x2, y2, t.accent);
    }
  }
  
  // Hour hand
  float hAngle = ((h + m/60.0) * 30 - 90) * PI / 180;
  int hx = CENTER_X + cos(hAngle) * 40;
  int hy = CENTER_Y - 20 + sin(hAngle) * 40;
  tft.drawLine(CENTER_X, CENTER_Y - 20, hx, hy, t.accent);
  tft.drawLine(CENTER_X + 1, CENTER_Y - 20, hx + 1, hy, t.accent);
  
  // Minute hand
  float mAngle = ((m + s/60.0) * 6 - 90) * PI / 180;
  int mx = CENTER_X + cos(mAngle) * 60;
  int my = CENTER_Y - 20 + sin(mAngle) * 60;
  tft.drawLine(CENTER_X, CENTER_Y - 20, mx, my, t.fg);
  
  // Second hand
  float sAngle = (s * 6 - 90) * PI / 180;
  int sx = CENTER_X + cos(sAngle) * 70;
  int sy = CENTER_Y - 20 + sin(sAngle) * 70;
  tft.drawLine(CENTER_X, CENTER_Y - 20, sx, sy, TFT_RED);
  
  // Center dot
  tft.fillCircle(CENTER_X, CENTER_Y - 20, 4, t.accent);
  tft.fillCircle(CENTER_X, CENTER_Y - 20, 2, t.bg);
}

void drawDigitalClock(DateTime now, Theme t) {
  tft.setTextSize(5);
  tft.setTextColor(t.text);
  
  int h = settings.format24h ? now.hour() : (now.hour() % 12 == 0 ? 12 : now.hour() % 12);
  
  char timeStr[10];
  sprintf(timeStr, "%02d:%02d", h, now.minute());
  
  int w = strlen(timeStr) * 30;
  tft.setCursor((SCREEN_WIDTH - w) / 2, 80);
  tft.print(timeStr);
  
  // AM/PM indicator
  if (!settings.format24h) {
    tft.setTextSize(2);
    tft.setCursor(190, 90);
    tft.print(now.hour() >= 12 ? "PM" : "AM");
  }
  
  // Seconds
  tft.setTextSize(3);
  char secStr[5];
  sprintf(secStr, ":%02d", now.second());
  tft.setCursor(CENTER_X - 20, 140);
  tft.print(secStr);
}

#endif
