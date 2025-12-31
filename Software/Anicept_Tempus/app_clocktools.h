#ifndef APP_CLOCKTOOLS_H
#define APP_CLOCKTOOLS_H

enum ClockToolMode {
  TOOL_TIMER,
  TOOL_STOPWATCH,
  TOOL_ALARM
};

ClockToolMode toolMode = TOOL_TIMER;

void drawClockToolsApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Clock Tools", t);
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  
  switch(toolMode) {
    case TOOL_TIMER:
      tft.setCursor(70, 60);
      tft.print("Timer");
      // Timer implementation
      break;
    case TOOL_STOPWATCH:
      tft.setCursor(40, 60);
      tft.print("Stopwatch");
      // Stopwatch implementation
      break;
    case TOOL_ALARM:
      tft.setCursor(70, 60);
      tft.print("Alarm");
      // Alarm implementation
      break;
  }
}

#endif
