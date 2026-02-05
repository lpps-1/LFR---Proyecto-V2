#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

// Button pins
extern const int BTN_UP;
extern const int BTN_DOWN;
extern const int BTN_OK;
extern const int BTN_CANCEL;

// Menu variables
const int NUM_ITEMS = 7;
String menuItems[NUM_ITEMS] = {
    "Black Line",
    "White Line",
    "Motor Test",
    "Calibrate",
    "AV",
    "DV",
    "RC Mode"
};
int selectedIndex = 0;

// -------------------- Menu functions --------------------
void renderMenu();
void showOptions();
void handleMenuInput();

// -------------------- Show menu --------------------
void showOptions() {
    renderMenu();
}

// -------------------- Render menu --------------------
void renderMenu() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    int above = (selectedIndex - 1 + NUM_ITEMS) % NUM_ITEMS;
    int current = selectedIndex;
    int below = (selectedIndex + 1) % NUM_ITEMS;

    int16_t x1, y1;
    uint16_t w1, h1;

    // --- Upper preview item ---
    display.setTextSize(1);
    display.getTextBounds(menuItems[above], 0, 0, &x1, &y1, &w1, &h1);
    display.setCursor((128 - w1) / 2, ((64 - h1) / 2) - 20);
    display.print(menuItems[above]);

    // --- Current selected item ---
    display.setTextSize(2);
    uint16_t w2, h2;
    display.getTextBounds(menuItems[current], 0, 0, &x1, &y1, &w2, &h2);
    int yMiddle = (64 - h2) / 2;

    // --- Blinking rounded bubble (ISSUE: may exceed screen height causing bottom-right glitched pixel) ---
    unsigned long now = millis();
    const unsigned long blinkCycle = 1000;
    const unsigned long onTime = 800;
    bool blinkState = (now % blinkCycle) < onTime;
    if (blinkState) {
        display.drawRoundRect(0, yMiddle - 2, 128, h2 + 6, 5, SSD1306_WHITE); // <--- CULPRIT
    }

    display.setCursor((128 - w2) / 2, yMiddle);
    display.print(menuItems[current]);

    // --- Lower preview item ---
    display.setTextSize(1);
    display.getTextBounds(menuItems[below], 0, 0, &x1, &y1, &w1, &h1);
    display.setCursor((128 - w1) / 2, yMiddle + h2 + 11);
    display.print(menuItems[below]);

    display.display();
}

// -------------------- Handle menu scrolling --------------------
void handleMenuInput() {
    static unsigned long lastScroll = 0;
    static unsigned long upPressStart = 0;
    static unsigned long downPressStart = 0;
    unsigned long now = millis();
    const unsigned long scrollDelay = 150;
    const unsigned long holdDelay = 500;

    bool upState = digitalRead(BTN_UP) == LOW;
    bool downState = digitalRead(BTN_DOWN) == LOW;

    // --- UP button ---
    if (upState) {
        if (upPressStart == 0) upPressStart = now;
        if (now - upPressStart > holdDelay && now - lastScroll > scrollDelay) {
            selectedIndex = (selectedIndex - 1 + NUM_ITEMS) % NUM_ITEMS;
            lastScroll = now;
        }
    } else if (upPressStart != 0) {
        if (now - upPressStart < holdDelay) {
            selectedIndex = (selectedIndex - 1 + NUM_ITEMS) % NUM_ITEMS;
            lastScroll = now;
        }
        upPressStart = 0;
    }

    // --- DOWN button ---
    if (downState) {
        if (downPressStart == 0) downPressStart = now;
        if (now - downPressStart > holdDelay && now - lastScroll > scrollDelay) {
            selectedIndex = (selectedIndex + 1) % NUM_ITEMS;
            lastScroll = now;
        }
    } else if (downPressStart != 0) {
        if (now - downPressStart < holdDelay) {
            selectedIndex = (selectedIndex + 1) % NUM_ITEMS;
            lastScroll = now;
        }
        downPressStart = 0;
    }
}

#endif
