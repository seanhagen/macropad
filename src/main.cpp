#include "base.h"

RPKeyboard *kb;

void setup() {
  Serial.begin(115200);
  delay(2000);

  kb = new RPKeyboard();
  kb->setup();
}

// bool i2c_found[128] = {false};

void loop() { kb->loop(); }
