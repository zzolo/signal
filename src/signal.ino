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

  right();
  delay(blink_delay);
  background();
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
static void right() {
  for (uint16_t i = 16; i < 48; i++) {
    strip.setPixelColor(i, blink);
  }

  strip.setPixelColor(3, blink);
  strip.setPixelColor(10, blink);
  strip.setPixelColor(11, blink);

  strip.setPixelColor(59, blink);
  strip.setPixelColor(50, blink);
  strip.setPixelColor(51, blink);

  strip.setPixelColor(40, bg);
  strip.setPixelColor(16, bg);

  strip.show();
}
