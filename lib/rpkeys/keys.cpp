#include "base.h"

void RPKeyboard::setupKeys() {
  // set all mechanical keys to inputs
  for (uint8_t i = 0; i <= 12; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}
