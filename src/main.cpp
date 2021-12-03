#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_ROTB 18
#define PIN_ROTA 17
#define PIN_SWITCH 0

// Create the rotary encoder
RotaryEncoder encoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);

volatile bool btnPressed = false;
bool btnCurrentState = false;
void btnPress() { btnPressed = !btnPressed; }

// our encoder position state
int encoder_pos = 0;

void setup() {
  Serial.begin(115200);
  delay(100); // RP2040 delay is not a bad idea

  Serial.println("Adafruit Macropad with RP2040");

  pinMode(PIN_SWITCH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_SWITCH), btnPress, CHANGE);
}

void loop() {
  if (btnCurrentState != btnPressed) {
    btnCurrentState = btnPressed;
    if (btnCurrentState) {
      Serial.println("encoder button released");
    } else {
      Serial.println("encoder button pressed");
    }
  }

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
