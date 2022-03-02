// PiezoPiano Test Functions for v1.3

#include <Adafruit_NeoPixel.h>
#include "pitches.h"

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN         10    // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS   1     // How many NeoPixels are attached to the Arduino?

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 400 // Time (in milliseconds) to pause between pixels
int noteDuration = 100;

int piezoPlacementV12[] = {9, 11, 7, 6, 5, 4, 1, 0};
int piezoPlacementV13[] = {9, 8, 7, 6, 5, 4, 1, 0};

int buttonPlacementV13[] = {20,21,22,32,33,34,35,36};

void setup() 
{
  pinMode(buttonPlacementV13[0], INPUT_PULLUP);
  pinMode(buttonPlacementV13[1], INPUT_PULLUP);
  pinMode(buttonPlacementV13[2], INPUT_PULLUP);
  pinMode(buttonPlacementV13[3], INPUT_PULLUP);
  pinMode(buttonPlacementV13[4], INPUT_PULLUP);
  pinMode(buttonPlacementV13[5], INPUT_PULLUP);
  pinMode(buttonPlacementV13[6], INPUT_PULLUP);
  pinMode(buttonPlacementV13[7], INPUT_PULLUP);

  attachInterrupt(buttonPlacementV13[0], tone_1, LOW);
  attachInterrupt(buttonPlacementV13[1], tone_1, LOW);
  attachInterrupt(buttonPlacementV13[2], tone_1, LOW);

  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);

  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);

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

  for(int i = 0; i <= 7; i++)
  {
    tone(piezoPlacementV13[i], NOTE_C4, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }

  Serial1.println(" - DONE!");

  // ----------------- RGB TEST -----------------
  Serial1.print("RGB TEST");

  delay(DELAYVAL);
  digitalWrite(37, LOW);

  delay(DELAYVAL);
  digitalWrite(37, HIGH);
  digitalWrite(38, LOW);
  
  delay(DELAYVAL);
  digitalWrite(38, HIGH);
  digitalWrite(39, LOW);

  delay(DELAYVAL);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);

  Serial1.println(" - DONE!");

}

void loop() 
{
  if(digitalRead(buttonPlacementV13[0])==1)
    noTone(piezoPlacementV13[0]);

  if(digitalRead(buttonPlacementV13[1])==1)
    noTone(piezoPlacementV13[1]);

  if(digitalRead(buttonPlacementV13[2])==1)
    noTone(piezoPlacementV13[2]);

}

void tone_1()
{
  tone(piezoPlacementV13[0], NOTE_C4);
  tone(piezoPlacementV13[1], NOTE_C4);
  tone(piezoPlacementV13[2], NOTE_C4);
}