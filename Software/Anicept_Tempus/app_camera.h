#ifndef APP_CAMERA_H
#define APP_CAMERA_H

void drawCameraApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Camera", t);
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  tft.setCursor(30, 80);
  tft.print("Tap to snap");
  
  // Shutter button
  tft.fillCircle(CENTER_X, 170, 35, t.accent);
  tft.fillCircle(CENTER_X, 170, 30, t.bg);
  tft.fillCircle(CENTER_X, 170, 25, t.accent);
  
  // When tapped, send BLE command
  // sendBLECommand("CAMERA:SNAP");
}

#endif
