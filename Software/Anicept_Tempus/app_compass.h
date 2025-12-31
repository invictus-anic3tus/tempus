#ifndef APP_COMPASS_H
#define APP_COMPASS_H

void drawCompassApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Compass", t);
  
  int32_t gyro[3];
  lsm6dsox.Get_G_Axes(gyro);
  
  // Draw compass circle
  tft.drawCircle(CENTER_X, CENTER_Y + 10, 70, t.fg);
  tft.drawCircle(CENTER_X, CENTER_Y + 10, 69, t.fg);
  
  // Cardinal directions
  tft.setTextSize(2);
  tft.setTextColor(TFT_RED);
  tft.setCursor(CENTER_X - 8, 50);
  tft.print("N");
  
  tft.setTextColor(t.text);
  tft.setCursor(CENTER_X - 8, CENTER_Y + 80);
  tft.print("S");
  
  tft.setCursor(40, CENTER_Y + 5);
  tft.print("W");
  
  tft.setCursor(190, CENTER_Y + 5);
  tft.print("E");
  
  // Direction needle
  float angle = atan2(gyro[1], gyro[0]);
  int x = CENTER_X + cos(angle) * 55;
  int y = CENTER_Y + 10 + sin(angle) * 55;
  
  // Draw needle (pointing north)
  tft.drawLine(CENTER_X, CENTER_Y + 10, x, y, TFT_RED);
  tft.drawLine(CENTER_X + 1, CENTER_Y + 10, x + 1, y, TFT_RED);
  tft.drawLine(CENTER_X - 1, CENTER_Y + 10, x - 1, y, TFT_RED);
  
  // Draw opposite end
  int x2 = CENTER_X - cos(angle) * 20;
  int y2 = CENTER_Y + 10 - sin(angle) * 20;
  tft.drawLine(CENTER_X, CENTER_Y + 10, x2, y2, TFT_WHITE);
  
  // Center dot
  tft.fillCircle(CENTER_X, CENTER_Y + 10, 5, t.accent);
  
  // Show degrees
  int degrees = (int)(angle * 180 / PI + 90) % 360;
  if (degrees < 0) degrees += 360;
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  tft.setCursor(CENTER_X - 20, 190);
  tft.print(degrees);
  tft.print((char)247); // degree symbol
}

#endif
