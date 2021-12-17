#include "base.h"

// void RPKeyboard::setupDisplay() {
//   // // Create the OLED display
//   // _display = Adafruit_SH1106G(128, 64, OLED_MOSI, OLED_SCK, OLED_DC,
//   // OLED_RST,
//   //                             OLED_CS);

//   // // Start OLED
//   // _display.begin(0, true); // we dont use the i2c address but we will
//   reset!
//   // _display.display();
//   // // text display tests
//   // _display.setTextSize(1);
//   // _display.setTextWrap(false);
//   // _display.setTextColor(SH110X_WHITE,
//   //                       SH110X_BLACK); // white text, black background
// }

// void RPKeyboard::loopDisplay() {
//   // _display.clearDisplay();
//   // _display.setCursor(0, 0);
//   // _display.println("* Adafruit Macropad *");

//   // _display.setCursor(0, 8);
//   // _display.print("Rotary encoder: ");
//   // _display.print(encoder_pos);

//   // // check encoder press
//   // _display.setCursor(0, 24);
//   // if (!digitalRead(PIN_SWITCH)) {
//   //   Serial.println("Encoder button");
//   //   _display.print("Encoder pressed ");
//   // }

//   // for (int i = 1; i <= 12; i++) {
//   //   if (!digitalRead(i)) { // switch pressed!
//   //     Serial.print("Switch ");
//   //     Serial.println(i);
//   //     // move the text into a 3x4 grid
//   //     _display.setCursor(((i - 1) % 3) * 48, 32 + ((i - 1) / 3) * 8);
//   //     _display.print("KEY");
//   //     _display.print(i);
//   //   }
//   // }

//   // // display oled
//   // _display.display();
// }
