#ifndef ICONS_H
#define ICONS_H

// Icon format: RGB565, 40x40 pixels
// Use image2cpp to convert PNG/JPG to C arrays

// Clock icon (40x40)
const uint16_t icon_clock[1600] PROGMEM = {
  // Paste your generated array here
  // Example placeholder - circular clock face
  0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0xFFFF, // ... (1600 values)
};

// Messages icon (40x40)
const uint16_t icon_messages[1600] PROGMEM = {
  // Message bubble icon data
};

// Phone icon (40x40)
const uint16_t icon_phone[1600] PROGMEM = {
  // Phone handset icon data
};

// Music icon (40x40)
const uint16_t icon_music[1600] PROGMEM = {
  // Musical note icon data
};

// Health icon (40x40)
const uint16_t icon_health[1600] PROGMEM = {
  // Heart or activity icon data
};

// Camera icon (40x40)
const uint16_t icon_camera[1600] PROGMEM = {
  // Camera icon data
};

// Settings icon (40x40)
const uint16_t icon_settings[1600] PROGMEM = {
  // Gear icon data
};

// Clock tools icon (40x40)
const uint16_t icon_clocktools[1600] PROGMEM = {
  // Stopwatch icon data
};

// Compass icon (40x40)
const uint16_t icon_compass[1600] PROGMEM = {
  // Compass icon data
};

// Array of icon pointers for easy access
const uint16_t* app_icons[] = {
  icon_clock,
  icon_messages,
  icon_phone,
  icon_music,
  icon_health,
  icon_camera,
  icon_settings,
  icon_clocktools,
  icon_compass
};

// Helper function to draw icon
void drawIcon(int x, int y, const uint16_t* icon) {
  for (int dy = 0; dy < ICON_HEIGHT; dy++) {
    for (int dx = 0; dx < ICON_WIDTH; dx++) {
      uint16_t color = pgm_read_word(&icon[dy * ICON_WIDTH + dx]);
      if (color != 0x0000) { // Skip transparent pixels (black = transparent)
        tft.drawPixel(x + dx, y + dy, color);
      }
    }
  }
}

#endif
