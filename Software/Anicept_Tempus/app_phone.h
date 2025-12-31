#ifndef APP_PHONE_H
#define APP_PHONE_H

void drawPhoneApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Phone", t);
  
  tft.setTextSize(3);
  tft.setTextColor(t.accent);
  tft.setCursor(30, 70);
  tft.print("INCOMING");
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  tft.setCursor(30, 110);
  tft.print("Unknown");
  
  // Accept button (green)
  tft.fillCircle(60, 180, 30, TFT_GREEN);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(50, 170);
  tft.print("Y");
  
  // Reject button (red)
  tft.fillCircle(180, 180, 30, TFT_RED);
  tft.setCursor(170, 170);
  tft.print("N");
}

#endif
