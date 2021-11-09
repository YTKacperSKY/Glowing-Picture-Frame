#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 6
#define LED_COUNT 58

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {
  rainbow(10);
}

void setAll(int r, int g, int b) {
  for(int i=0; i<strip.numPixels(); i++) {
        
        strip.setPixelColor(i, r, g, b);
      }
}


void rainbow(int wait) {
  while(true) {
    
      for(int r = 255; r >= 0; r--) {
        setAll(r, 255 - r, 0);
        strip.show(); 
        delay(wait); 
      }

      
      for(int r = 255; r >= 0; r--) {
        setAll(0, r, 255 - r);
        strip.show(); 
        delay(wait);
      }

      
      for(int r = 255; r >= 0; r--) {
        setAll(255 - r, 0, r);
        strip.show(); 
        delay(wait);
      }
      
  }
}
