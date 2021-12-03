#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_SH110X.h>
#include <RotaryEncoder.h>
#include <SPI.h>
#include <Wire.h>

// LEDs
#define PIN_LED 13

// Extra hardware!
#define PIN_SWITCH 0
#define PIN_SPEAKER_ENABLE 14
#define PIN_SPEAKER 16

#define PIN_ROTB 18
#define PIN_ROTA 17

#define OLED_CS 22
#define OLED_RST 23
#define OLED_DC 24

#define PIN_NEOPIXEL 19
#define NUM_NEOPIXEL 12

// SPI
#define PIN_SPI1_MISO 28
#define PIN_SPI1_MOSI 27
#define PIN_SPI1_SCK 26

// oled stuff
#define OLED_SCK 26
#define OLED_MOSI 27

// Create the neopixel strip with the built in definitions NUM_NEOPIXEL and
// PIN_NEOPIXEL
Adafruit_NeoPixel pixels =
    Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

// Create the OLED display
Adafruit_SH1106G display =
    // Adafruit_SH1106G(128, 64, &SPI, OLED_DC, OLED_RST, OLED_CS);
    Adafruit_SH1106G(128, 64, OLED_MOSI, OLED_SCK, OLED_DC, OLED_RST, OLED_CS);

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
  // while (!Serial) { delay(10); }     // wait till serial port is opened
  delay(100); // RP2040 delay is not a bad idea

  Serial.println("Adafruit Macropad with RP2040");

  // start pixels!
  pixels.begin();
  pixels.setBrightness(255);
  pixels.show(); // Initialize all pixels to 'off'

  // Start OLED
  display.begin(0, true); // we dont use the i2c address but we will reset!
  display.display();

  // set all mechanical keys to inputs
  for (uint8_t i = 0; i <= 12; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  // set rotary encoder inputs and interrupts
  pinMode(PIN_ROTA, INPUT_PULLUP);
  pinMode(PIN_ROTB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ROTA), checkPosition, FALLING);
  attachInterrupt(digitalPinToInterrupt(PIN_ROTB), checkPosition, FALLING);
  // attachInterrupt(digitalPinToInterrupt(PIN_ROTA), checkPosition, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(PIN_ROTB), checkPosition, CHANGE);

  // We will use I2C for scanning the Stemma QT port
  Wire.begin();

  // text display tests
  display.setTextSize(1);
  display.setTextWrap(false);
  display.setTextColor(SH110X_WHITE,
                       SH110X_BLACK); // white text, black background

  pixels.setBrightness(30);

  pinMode(PIN_SPEAKER, OUTPUT);
  digitalWrite(PIN_SPEAKER, LOW);
}

uint8_t j = 0;
// bool i2c_found[128] = {false};

void loop() {
  if (posCheck) {
    Serial.println("encoder thing!");
    posCheck = false;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("* Adafruit Macropad *");

  // encoder.tick(); // check the encoder
  int newPos = encoder.getPosition();
  if (encoder_pos != newPos) {
    Serial.print("Encoder:");
    Serial.print(newPos);
    Serial.print(" Direction:");
    Serial.println((int)(encoder.getDirection()));
    encoder_pos = newPos;
  }
  display.setCursor(0, 8);
  display.print("Rotary encoder: ");
  display.print(encoder_pos);

  // check encoder press
  display.setCursor(0, 24);
  if (!digitalRead(PIN_SWITCH)) {
    Serial.println("Encoder button");
    display.print("Encoder pressed ");
  }

  for (int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
  }

  for (int i = 1; i <= 12; i++) {
    if (!digitalRead(i)) { // switch pressed!
      Serial.print("Switch ");
      Serial.println(i);
      pixels.setPixelColor(i - 1, 0xFFFFFF); // make white
      // move the text into a 3x4 grid
      display.setCursor(((i - 1) % 3) * 48, 32 + ((i - 1) / 3) * 8);
      display.print("KEY");
      display.print(i);
    }
  }

  // show neopixels, incredment swirl
  pixels.show();
  j++;

  // display oled
  display.display();
}
