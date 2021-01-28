#include <Arduino.h>
#include <FastLED.h>

// LED Settings
#define NUM_LEDS          64
#define DATA_PIN          32 

// Define the led chain
CRGB leds[NUM_LEDS];
uint8_t counter = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
    FastLED.clear();
    leds[counter % 64] = CHSV(counter, 255, 100);
    FastLED.show();
    counter++;
    delay(100);
}