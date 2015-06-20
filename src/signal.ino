// Libs
#include "Arduino.h"

#include "Adafruit_NeoPixel.h"
// https://github.com/adafruit/Adafruit_NeoPixel

// Config
#define PIN 6
#define N_LEDS 64

// 2 and 3 are interrupt PINs
#define L_BUTTON 2
#define L_LED 4
#define R_BUTTON 3
#define R_LED 5

// Set up neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Blink color
uint32_t blink = strip.Color(255, 255, 0);
uint32_t blink_off = strip.Color(122, 122, 0);

// Background color
uint32_t bg = strip.Color(255, 0, 0);

// Blink delay
int blink_delay = 400;

// Debounce check time
int debounce_time = 300;

// State
bool l_on = false;
bool r_on = false;

// Main setup function
void setup() {

  // Butttons
  pinMode(L_BUTTON, INPUT);
  pinMode(R_BUTTON, INPUT);

  // Initialize LED
  pinMode(L_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);

  // Interrupt.  0 = PIN 2
  attachInterrupt(0, on_button_left, FALLING);
  attachInterrupt(1, on_button_right, FALLING);

  // Start NeoPixel strip
  strip.begin();

  // Set global brightness
  strip.setBrightness(50);

  // Background
  background();

  // Serial
  Serial.begin(9600);
}

// Main loop function
void loop() {
  background();

  // Check if on
  if (l_on) {
    digitalWrite(L_LED, HIGH);
    left(blink);
    delay(blink_delay);

    digitalWrite(L_LED, LOW);
    left(blink_off);
    delay(blink_delay);
  }
  else if (r_on) {
    digitalWrite(R_LED, HIGH);
    right(blink);
    delay(blink_delay);

    digitalWrite(R_LED, LOW);
    right(blink_off);
    delay(blink_delay);
  }
}


// Handle interrupt
static void on_button_left() {
  // Debounce wrap
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    Serial.write('L');
    l_on = !l_on;
    r_on = false;
  }
  last_interrupt_time = interrupt_time;
}

// Handle interrupt
static void on_button_right() {
  // Debounce wrap
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce_time) {
    Serial.write('R');
    r_on = !r_on;
    l_on = false;
  }
  last_interrupt_time = interrupt_time;
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
