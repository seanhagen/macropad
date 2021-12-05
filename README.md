# Adafruit Macropad

Code for my Adafruit Macropad powered by a RP2040!

My goal is to set up the Macropad so I can use it for all the hard-to-remember
keyboard shortcuts for various modes & tasks while programming. Or gaming. Or
just browsing the web.

Basic idea:

 - encoder switches between "profiles" (debugging, refactoring, Destiny 2, etc)
 - each profile uses the 12 keys for stuff I regularly forget, the OLED display
   shows what each key does 
 
## Other Thoughts 

### Encoder Usage

The encoder can be used to switch between "modes". For example, double clicking
the encoder puts it in "keypad" mode, where it basically functions as a
numpad. Single-clicking could cycle through any available modes for a given
profile, if a profile needs more than 12 keys.

Also, holding key & rotating encoder could be handy for some things too.

### Communication With Host Machine 

Could be handy to have something that can talk via Serial or some other protocol
with the Macropad. Changing the color of the NeoPixel for a key based on what's
happening in the editor, for example. Or showing a status indicator in the OLED.


## Resources

- [Adafruit Macropad RP2040](https://cdn-learn.adafruit.com/assets/assets/000/104/022/original/adafruit_products_Adafruit_MacroPad_RP2040_Pinout.png?1629726427)
