#include "base.h"

RPKeyboard *kb;

void setup() {
  kb = new RPKeyboard();
  kb->setup();
}

// bool i2c_found[128] = {false};

void loop() { kb->loop(); }
