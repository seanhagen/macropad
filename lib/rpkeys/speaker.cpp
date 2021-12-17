#include "base.h"

void RPKeyboard::setupSpeaker() {
  pinMode(PIN_SPEAKER, OUTPUT);
  digitalWrite(PIN_SPEAKER, LOW);
}
