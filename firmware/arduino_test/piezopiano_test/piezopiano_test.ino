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
int pos_piezo[] = {9, 8, 7, 6, 5, 4, 1, 0};

int pos_button[] = {20,21,22,32,33,34,35,36};

int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

unsigned char notes[8] = {0};

void setup() 
{

  GPIO_Init();
  TimerC0_Init();

  // ----------------- ACTIVATE SERIAL -----------------
  Serial1.begin(9600);
  
  // ----------------- TESTING -----------------
  WS_LED_Test();
  Piezo_Test();
  RGB_Test();

  // ----------------- ENABLE INTERRUPT -----------------
  attachInterrupt(pos_button[0], tone_1, LOW);
  attachInterrupt(pos_button[1], tone_1, LOW);
  attachInterrupt(pos_button[2], tone_1, LOW);
  attachInterrupt(pos_button[3], tone_1, LOW);
  attachInterrupt(pos_button[4], tone_1, LOW);
  attachInterrupt(pos_button[5], tone_1, LOW);
  attachInterrupt(pos_button[6], tone_1, LOW);
  attachInterrupt(pos_button[7], tone_1, LOW);


}

void loop() 
{
  for(int i = 0; i <= 7; i++)
  {
    if(digitalRead(pos_button[i])==1)
    {
      noTone(pos_piezo[i]);
      digitalWrite(pos_piezo[i], LOW);
    }
  }
}

void GPIO_Init()
{
  // Buttons
  pinMode(pos_button[0], INPUT_PULLUP);
  pinMode(pos_button[1], INPUT_PULLUP);
  pinMode(pos_button[2], INPUT_PULLUP);
  pinMode(pos_button[3], INPUT_PULLUP);
  pinMode(pos_button[4], INPUT_PULLUP);
  pinMode(pos_button[5], INPUT_PULLUP);
  pinMode(pos_button[6], INPUT_PULLUP);
  pinMode(pos_button[7], INPUT_PULLUP);

  // Piezos
  pinMode(pos_piezo[0], OUTPUT);
  pinMode(pos_piezo[1], OUTPUT);
  pinMode(pos_piezo[2], OUTPUT);
  pinMode(pos_piezo[3], OUTPUT);
  pinMode(pos_piezo[4], OUTPUT);
  pinMode(pos_piezo[5], OUTPUT);
  pinMode(pos_piezo[6], OUTPUT);
  pinMode(pos_piezo[7], OUTPUT);

  // RGB LED = Common Anode
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
}

void TimerC0_Init()
{

}

void WS_LED_Test()
{
  // ----------------- WS2812 TEST -----------------
  Serial1.print("WS2812 TEST");

  pixels.begin();
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
}

void Piezo_Test()
{
  // ----------------- PIEZO TEST -----------------
  Serial1.print("Piezo TEST");

  for(int i = 0; i <= 7; i++)
  {
    tone(pos_piezo[i], melody[i], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(pos_piezo[i]);
  }

  Serial1.println(" - DONE!");
}

void RGB_Test()
{
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

void tone_1()
{
  for(int i = 0; i <= 7; i++)
  {
    if(digitalRead(pos_button[i])==0)
      digitalWrite(pos_piezo[i], HIGH);
  }
}