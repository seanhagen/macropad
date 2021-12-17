#include "base.h"

void RPKeyboard::setupEncoder(void) {
  /* this is actually handled in the constructor for the rotary encoder, so we
   * don't need to to anything! */

  // Create the rotary encoder
  _encoder = RotaryEncoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);
}

void RPKeyboard::loopEncoder(void) {
  _encoder.tick(); // check the encoder
  int newPos = _encoder.getPosition();
  if (encoder_pos != newPos) {
    Serial.print("Encoder:");
    Serial.print(newPos);
    Serial.print(" Direction:");
    Serial.println((int)(_encoder.getDirection()));
    encoder_pos = newPos;
  }
}
