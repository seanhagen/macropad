#ifndef BASE_H
#define BASE_H

#include <Adafruit_NeoPixel.h>
#include <Adafruit_SH110X.h>
#include <RotaryEncoder.h>
#include <SPI.h>
#include <Wire.h>
#include <tusb.h>

// Extra hardware!
#define PIN_SWITCH 0
#define PIN_SPEAKER_ENABLE 14
#define PIN_SPEAKER 16

#define PIN_ROTB 17
#define PIN_ROTA 18

#define OLED_CS 22
#define OLED_RST 23
#define OLED_DC 24

// SPI
#define PIN_SPI1_MISO 28
#define PIN_SPI1_MOSI 27
#define PIN_SPI1_SCK 26

// oled stuff
#define OLED_SCK 26
#define OLED_MOSI 27

#define PIN_NEOPIXEL 19
#define NUM_NEOPIXEL 12

/*
class Station {
public:
  Station(void);
*/

class RPKeyboard {
public:
  RPKeyboard(void);

  void setup();
  void loop();

private:
  void setupNeopixels();
  void setupDisplay();
  void setupSpeaker();
  void setupEncoder();
  void setupKeys();

  void loopNeopixels();
  void loopDisplay();
  void loopSpeaker();
  void loopEncoder();
  void loopKeys();

  int encoder_pos = 0;
  uint8_t pixelIdx = 0;

  RotaryEncoder _encoder;
  Adafruit_SH1106G _display;
  Adafruit_NeoPixel _pixels;

  uint32_t Wheel(byte WheelPos);
};

#endif
