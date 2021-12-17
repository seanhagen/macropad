#include "base.h"

/*
Station::Station(void) { _setup(); }

Station::Station(stationConfig conf) {
  _config = conf;
  _setup();
}

*/

RPKeyboard::RPKeyboard() {
  Serial.begin(115200);
  // while (!Serial) { delay(10); }     // wait till serial port is opened
  delay(100); // RP2040 delay is not a bad idea
  Serial.println("Adafruit Macropad with RP2040");
}

void RPKeyboard::setup(void) {
  setupNeopixels();
  setupDisplay();
  setupSpeaker();
  setupKeys();
  setupEncoder();

  // We will use I2C for scanning the Stemma QT port
  Wire.begin();
}

void RPKeyboard::loop(void) {
  loopEncoder();
  // loopNeopixels();
  loopDisplay();
}
