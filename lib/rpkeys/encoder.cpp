#include "base.h"

const int8_t KNOBDIR[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

#define LATCH3 3

void RPKeyboard::setupEncoder(void) {
  /* this is actually handled in the constructor for the rotary encoder, so we
   * don't need to to anything! */

  // Create the rotary encoder
  // _encoder = RotaryEncoder(PIN_ROTA, PIN_ROTB,
  // RotaryEncoder::LatchMode::FOUR3);
  pinMode(PIN_ROTA, INPUT_PULLUP);
  pinMode(PIN_ROTB, INPUT_PULLUP);

  int sig1 = digitalRead(PIN_ROTA);
  int sig2 = digitalRead(PIN_ROTB);
  _oldState = sig1 | (sig2 << 1);

  _position = 0;
  _positionExt = 0;
  _positionExtPrev = 0;

  Serial.print("old state: ");
  Serial.println(_oldState);
}

void RPKeyboard::loopEncoder(void) {
  int sig1 = digitalRead(PIN_ROTA);
  int sig2 = digitalRead(PIN_ROTB);
  int8_t thisState = sig1 | (sig2 << 1);

  if (_oldState != thisState) {
    _position += KNOBDIR[thisState | (_oldState << 2)];
    _oldState = thisState;

    if (thisState == LATCH3) {
      _positionExt = _position >> 2;
      _positionExtTimePrev = _positionExtTime;
      _positionExtTime = millis();
      Serial.print("knob value: ");
      Serial.println(_positionExt);
    }
  }

  // _encoder.tick(); // check the encoder
  // int newPos = _encoder.getPosition();
  // if (encoder_pos != newPos) {
  //   Serial.print("Encoder:");
  //   Serial.print(newPos);
  //   Serial.print(" Direction:");
  //   Serial.println((int)(_encoder.getDirection()));
  //   encoder_pos = newPos;
  // }
}
