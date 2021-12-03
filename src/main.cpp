#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_ROTB 18
#define PIN_ROTA 17

// Create the rotary encoder
RotaryEncoder encoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);

volatile bool posCheck = false;

void checkPosition() {
  // just call tick() to check the state.
  encoder.tick();
  posCheck = true;
}

// our encoder position state
int encoder_pos = 0;

void setup() {
  Serial.begin(115200);
  delay(100); // RP2040 delay is not a bad idea

  Serial.println("Adafruit Macropad with RP2040");

  // set rotary encoder inputs and interrupts
  pinMode(PIN_ROTA, INPUT_PULLUP);
  pinMode(PIN_ROTB, INPUT_PULLUP);
}

void loop() {
  encoder.tick(); // check the encoder
  int newPos = encoder.getPosition();
  if (encoder_pos != newPos) {
    Serial.print("Encoder:");
    Serial.print(newPos);
    Serial.print(" Direction:");
    Serial.println((int)(encoder.getDirection()));
    encoder_pos = newPos;
  }
}
