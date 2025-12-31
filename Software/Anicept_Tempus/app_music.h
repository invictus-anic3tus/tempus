#ifndef APP_MUSIC_H
#define APP_MUSIC_H

void drawMusicApp(Theme t) {
  tft.fillScreen(t.bg);
  drawHeader("Music", t);
  
  tft.setTextSize(2);
  tft.setTextColor(t.text);
  tft.setCursor(10, 50);
  String title = musicState.title;
  if (title.length() > 18) title = title.substring(0, 18) + "...";
  tft.print(title);
  
  tft.setTextSize(1);
  tft.setCursor(10, 75);
  String artist = musicState.artist;
  if (artist.length() > 25) artist = artist.substring(0, 25) + "...";
  tft.print(artist);
  
  // Play/Pause button
  if (musicState.playing) {
    // Pause icon (two bars)
    tft.fillRect(100, 130, 15, 50, t.accent);
    tft.fillRect(125, 130, 15, 50, t.accent);
  } else {
    // Play icon (triangle)
    tft.fillTriangle(105, 130, 105, 180, 145, 155, t.accent);
  }
  
  // Previous button
  tft.fillTriangle(45, 155, 75, 140, 75, 170, t.fg);
  tft.fillRect(40, 140, 5, 30, t.fg);
  
  // Next button
  tft.fillTriangle(195, 155, 165, 140, 165, 170, t.fg);
  tft.fillRect(195, 140, 5, 30, t.fg);
}

#endif
