// PiezoPiano Test Functions for v1.3

#include <Adafruit_NeoPixel.h>
#include "pitches.h"

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN         10    // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS   1     // How many NeoPixels are attached to the Arduino?

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() 
{
  Serial1.begin(9600);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  // ----------------- WS2812 TEST -----------------
  Serial1.print("WS2812 TEST");
  pixels.clear(); // Set all pixel colors to 'off'

  // RED
  pixels.setPixelColor(0, pixels.Color(150, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop

  // GREEN
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop

  // BLUE
  pixels.setPixelColor(0, pixels.Color(0, 0, 150));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop

  // WHITE
  pixels.setPixelColor(0, pixels.Color(25, 25, 25));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
  
  Serial1.println(" - DONE!");

  // ----------------- PIEZO TEST -----------------
  Serial1.print("Piezo TEST");
  int noteDuration = 250;

  int piezoPlacementV12[] = {9, 11, 7, 6, 5, 4, 1, 0};
  int piezoPlacementV13[] = {9, 8, 7, 6, 5, 4, 1, 0};

  for(int i = 0; i <= 7; i++)
  {
    tone(piezoPlacementV13[i], NOTE_C4, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }

  Serial1.println(" - DONE!");

  Serial1.println("Serial1 TEST: Send number between 0 to 100.");
}

void loop() 
{
  int brightness;
  int ledPin = 9;

  // check if data has been sent from the computer:
  if (Serial1.available()) {
    // read the most recent byte (which will be from 0 to 255):
    brightness = Serial1.parseInt();

    // set the brightness of the LED:
    analogWrite(ledPin, map(brightness, 0, 100, 0, 255));

    Serial1.println(brightness);

  }
}