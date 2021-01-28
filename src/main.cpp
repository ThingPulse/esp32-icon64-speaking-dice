#include <Arduino.h>

void setup() {
  delay(1000);
  log_v("Hello world: %dms", millis());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  log_i("Free heap: %d", ESP.getFreeHeap());
  log_w("Total PSRAM: %d", ESP.getPsramSize());
  log_e("Total heap: %d", ESP.getHeapSize());

}

void loop() {

}