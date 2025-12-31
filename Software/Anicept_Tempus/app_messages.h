#ifndef APP_MESSAGES_H
#define APP_MESSAGES_H

void drawMessagesApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Messages", t);
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  
  if (notifCount == 0) {
    tft.setCursor(40, 100);
    tft.print("No messages");
  } else {
    for (int i = 0; i < min(notifCount, 5); i++) {
      tft.setCursor(10, 40 + i * 35);
      String msg = notifications[i];
      if (msg.length() > 20) {
        msg = msg.substring(0, 20) + "...";
      }
      tft.print(msg);
    }
  }
}

#endif
