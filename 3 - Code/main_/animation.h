#ifndef ANIMATION_H
#define ANIMATION_H
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "logo.h"

extern Adafruit_SSD1306 display;
int LOGO_ANIMATION_TIME = 600;   // total time for logo scaling animation 
int GLITCH_TIME        = 100;    // total glitch effect duration 
int NUEVO_DISPLAY_TIME = 1500;   // duration to show NUEVO V2 
void drawScaledBitmapCentered(const unsigned char *bitmap, int w, int h, float scale, uint16_t color) {
    int scaledW = w * scale;
    int scaledH = h * scale;
    int xOffset = (128 - scaledW) / 2;
    int yOffset = (64 - scaledH) / 2;
    for (int y = 0; y < scaledH; y++) {
        for (int x = 0; x < scaledW; x++) {
            int srcX = x / scale;
            int srcY = y / scale;
            int byteIndex = srcY * ((w + 7) / 8) + (srcX / 8);
            int bitIndex = srcX % 8;
            if (pgm_read_byte(&bitmap[byteIndex]) & (0x80 >> bitIndex)) {
                display.drawPixel(xOffset + x, yOffset + y, color);
            }
        }
    }
}
// Logo Scaling 
void animateLogo(const unsigned char *bitmap, int w, int h) {
    float startScale = 0.2;
    float endScale   = 0.6;
    float step       = 0.04;
    int totalFrames  = (endScale - startScale) / step;
    unsigned long frameTime = LOGO_ANIMATION_TIME / totalFrames;
    unsigned long lastFrame = millis();
    for (float scale = startScale; scale <= endScale; scale += step) {
        display.clearDisplay();
        drawScaledBitmapCentered(bitmap, w, h, scale, SSD1306_WHITE);
        display.display();
        while (millis() - lastFrame < frameTime);
        lastFrame = millis();
    }
}
// Glitch Effect
void glitchEffect(unsigned long msPerFrame = 1) { 
    unsigned long start = millis();
    while (millis() - start < GLITCH_TIME) {
        display.clearDisplay();
        for (int y = 0; y < 64; y += 2) {
            if (random(0, 2)) display.drawFastHLine(0, y, 128, SSD1306_WHITE);
        }
        display.display();
        delay(msPerFrame);
    }
}
//Show NUEVO V2
void showNuevo() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    const char* title = "NUEVO V2";
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(title, 0, 0, &x1, &y1, &w, &h);
    display.setCursor((128 - w) / 2, 18);
    display.print(title);
    display.setTextSize(1);
    const char* sub = "By LPPS-1";
    display.getTextBounds(sub, 0, 0, &x1, &y1, &w, &h);
    display.setCursor((128 - w) / 2 + 20, 40);
    display.print(sub);
    display.display();
    delay(NUEVO_DISPLAY_TIME);
}
#endif
