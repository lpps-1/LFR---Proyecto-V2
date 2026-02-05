#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "animation.h"
#include "menu.h"
#include "black_line.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Button pins
const int BTN_DOWN   = 2;
const int BTN_UP     = 4;
const int BTN_OK     = 6;
const int BTN_CANCEL = 3;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- Button states ---
bool okPrev = HIGH;
bool cancelPrev = HIGH;
unsigned long lastCancelTime = 0;
const unsigned long cancelDelay = 500; // 500ms debounce

// --- Black line menu state ---
enum BlackLineState { MENU, READY_SCREEN, FOLLOWING };
BlackLineState blackLineState = MENU;

void setup() {
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_OK, INPUT_PULLUP);
    pinMode(BTN_CANCEL, INPUT_PULLUP);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    Serial.begin(9600);

    initBlackLine();

    // --- Startup animations ---
    bool skipAll = false;
    int logoW = 128, logoH = 128;
    float startScale = 0.2, endScale = 0.6, step = 0.04;
    int totalFrames = (endScale - startScale) / step;
    unsigned long frameTime = LOGO_ANIMATION_TIME / totalFrames;
    unsigned long lastFrame = millis();
    float scale = startScale;

    while (scale <= endScale && !skipAll) {
        display.clearDisplay();
        drawScaledBitmapCentered(teamLogoBitmap, logoW, logoH, scale, SSD1306_WHITE);
        display.display();
        if (digitalRead(BTN_OK) == LOW) skipAll = true;
        if (millis() - lastFrame >= frameTime) { scale += step; lastFrame = millis(); }
    }

    unsigned long glitchStart = millis();
    while (!skipAll && millis() - glitchStart < GLITCH_TIME) {
        glitchEffect(1);
        if (digitalRead(BTN_OK) == LOW) skipAll = true;
    }

    unsigned long nuevoStart = millis();
    while (!skipAll && millis() - nuevoStart < NUEVO_DISPLAY_TIME) {
        showNuevo();
        if (digitalRead(BTN_OK) == LOW) skipAll = true;
    }

    showOptions();
}

void loop() {
    bool okNow = digitalRead(BTN_OK);
    bool cancelNow = digitalRead(BTN_CANCEL);
    unsigned long now = millis();

    // --- CANCEL handling with 500ms ignore window ---
    if (cancelPrev == HIGH && cancelNow == LOW) {
        if (now - lastCancelTime > cancelDelay) {
            if (blackLineState == FOLLOWING) {
                stopBlackLine();
            }
            blackLineState = MENU;
            showOptions();
            lastCancelTime = now;
        }
    }
    cancelPrev = cancelNow;

    switch (blackLineState) {
        case MENU:
            handleMenuInput();
            renderMenu();

            // Check if Black Line is selected
            if (okPrev == HIGH && okNow == LOW) {
                String selected = menuItems[selectedIndex];
                if (selected == "Black Line") {
                    blackLineState = READY_SCREEN;
                    display.clearDisplay();
                    display.setTextSize(1);
                    display.setTextColor(SSD1306_WHITE);
                    display.setCursor(0, 28);
                    display.println("Press OK to Start Following");
                    display.display();
                }
            }
            break;

        case READY_SCREEN:
            // Wait for second OK press to start following
            if (okPrev == HIGH && okNow == LOW) {
                blackLineState = FOLLOWING;
                blackLineStopped = false;
                blackLineActive = true;
            }
            break;

        case FOLLOWING:
            if (blackLineActive && !blackLineStopped) {
                blackLineStep();
            }
            break;
    }

    okPrev = okNow;

    delay(20);
}
