#include "base.h"

// void RPKeyboard::setupNeopixels() {
//   // // Create the neopixel strip with the built in definitions NUM_NEOPIXEL
//   and
//   // // PIN_NEOPIXEL
//   // _pixels = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB +
//   // NEO_KHZ800);

//   // pinMode(PIN_LED, OUTPUT);

//   // // start pixels!
//   // _pixels.begin();
//   // _pixels.setBrightness(30);
//   // _pixels.show(); // Initialize all pixels to 'off'
// }

// void RPKeyboard::loopNeopixels() {
//   // for (int i = 0; i < _pixels.numPixels(); i++) {
//   //   _pixels.setPixelColor(
//   //       i, Wheel(((i * 256 / _pixels.numPixels()) + pixelIdx) & 255));
//   // }
//   // // show neopixels, incredment swirl

//   // for (int i = 1; i <= 12; i++) {
//   //   if (!digitalRead(i)) {                    // switch pressed!
//   //     _pixels.setPixelColor(i - 1, 0xFFFFFF); // make white
//   //   }
//   // }

//   // _pixels.show();
//   // pixelIdx++;
// }

// // Input a value 0 to 255 to get a color value.
// // The colours are a transition r - g - b - back to r.
// uint32_t RPKeyboard::Wheel(byte WheelPos) {
//   // if (WheelPos < 85) {
//   //   return _pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//   // } else if (WheelPos < 170) {
//   //   WheelPos -= 85;
//   //   return _pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//   // } else {
//   //   WheelPos -= 170;
//   //   return _pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//   // }
