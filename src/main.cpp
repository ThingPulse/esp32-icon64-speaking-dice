#include <Arduino.h>
#include <FastLED.h>

// LED Settings
#define NUM_LEDS          64
#define DATA_PIN          32 

/*
   0     4
   1  3  5
   2     6
*/
uint8_t dots[7][4] = {{63, 62, 48, 49},
                      {60, 59, 51, 52},
                      {57, 56, 55, 54},
                      {35, 36, 28, 27}, 
                      {15, 14,  0,  1}, 
                      {12, 11,  3,  4},
                      { 9,  8,  7,  6}}; 

uint8_t faces[6][6] = {{3, 7, 7, 7, 7, 7},
                       {0, 6, 7, 7, 7, 7}, 
                       {0, 3, 6, 7, 7, 7},
                       {0, 2, 4, 6, 7, 7},
                       {0, 2, 3, 4, 6, 7}, 
                       {0, 1, 2, 4, 5, 6}};

// Define the led chain
CRGB leds[NUM_LEDS];
uint8_t counter = 0;

void displayFace(uint8_t value) {
  uint8_t pixelIndex = 0;
  CHSV color = CHSV(random(0,254), 255, 100);
  for (uint8_t i = 0; i < 6; i++) {
    uint8_t dot = faces[value][i];
    if (dot == 7) {
      break;
    }
    for (uint8_t j = 0; j < 4; j++) {
      pixelIndex = dots[dot][j];
      leds[pixelIndex] = color;
    }
  }
}

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
    FastLED.clear();
    uint8_t randomNumber = random(1, 7);
    log_v("Value: %d", randomNumber);
    displayFace(randomNumber - 1);
    FastLED.show();
    counter++;
    delay(5000);
}