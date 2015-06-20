// Libs
#include "Arduino.h"

#include "Adafruit_NeoPixel.h"
// https://github.com/adafruit/Adafruit_NeoPixel

// Config
#define PIN 6
#define N_LEDS 64

// Set up neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Blink color
uint32_t blink = strip.Color(255, 255, 0);
uint32_t blink_off = strip.Color(122, 122, 0);

// Background color
uint32_t bg = strip.Color(255, 0, 0);

// Blink delay
int blink_delay = 400;

// Main setup function
void setup() {

  // Start NeoPixel strip
  strip.begin();

  // Set global brightness
  strip.setBrightness(50);

  // Background
  background();
}

// Main loop function
void loop() {

  left(blink);
  delay(blink_delay);
  left(blink_off);
  delay(blink_delay);
}


// Set basic red background
static void background() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, bg);
  }
  strip.show();
}

// Right arrow
static void right(uint32_t c) {
  for (uint16_t i = 16; i < 48; i++) {
    strip.setPixelColor(i, c);
  }

  strip.setPixelColor(3, c);
  strip.setPixelColor(10, c);
  strip.setPixelColor(11, c);

  strip.setPixelColor(59, c);
  strip.setPixelColor(50, c);
  strip.setPixelColor(51, c);

  strip.setPixelColor(40, bg);
  strip.setPixelColor(16, bg);

  strip.show();
}

// Left arrow
static void left(uint32_t c) {
  for (uint16_t i = 16; i < 48; i++) {
    strip.setPixelColor(i, c);
  }

  strip.setPixelColor(4, c);
  strip.setPixelColor(12, c);
  strip.setPixelColor(13, c);

  strip.setPixelColor(60, c);
  strip.setPixelColor(52, c);
  strip.setPixelColor(53, c);

  strip.setPixelColor(47, bg);
  strip.setPixelColor(23, bg);

  strip.show();
}
