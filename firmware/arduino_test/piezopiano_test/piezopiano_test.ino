// PiezoPiano Test Functions for v1.3

#include <Adafruit_NeoPixel.h>
#include "pitches.h"

#define PIN         10    // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS   1     // How many NeoPixels are attached to the Arduino?

#define F_TIMER				65536/2
#define TCA_LIMIT			((F_CPU/F_TIMER)+1)

#define DELAYVAL 400      // Time (in milliseconds) to pause between pixels

int noteDuration = 100;   // Note dauration for the test

int pos_piezo_V12[] = {9, 11, 7, 6, 5, 4, 1, 0};  // Digital pin location for the piezos starting from left to right V1.2
int pos_piezo[] = {9, 8, 7, 6, 5, 4, 1, 0};       // Digital pin location for the piezos starting from left to right V1.3 +
int pos_button[] = {20, 21, 22, 32, 33, 34, 35, 36};     // Digital pin location for the buttons starting from left to right V1.3 +

int melody[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

#define REAL_NOTE_C4 F_TIMER/(NOTE_C4)
#define REAL_NOTE_D4 F_TIMER/(NOTE_D4)
#define REAL_NOTE_E4 F_TIMER/(NOTE_E4)
#define REAL_NOTE_F4 F_TIMER/(NOTE_F4)
#define REAL_NOTE_G4 F_TIMER/(NOTE_G4)
#define REAL_NOTE_A4 F_TIMER/(NOTE_A4)
#define REAL_NOTE_B4 F_TIMER/(NOTE_B4)
#define REAL_NOTE_C5 F_TIMER/(NOTE_C5)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned int notes[8] = {0};

void setup() 
{
  // ----------------- INIT GPIO -----------------
  GPIO_Init();

  // ----------------- ACTIVATE SERIAL -----------------
  Serial1.begin(9600);
    
  // ----------------- TESTING -----------------
  WS_LED_Test();
  Piezo_Test();
  RGB_Test();

  // ----------------- INIT TIMER -----------------
  // Must be here due to cap discharge at the buttons
  // Triggers LEDs otherwise
  TimerC0_Init();
  TimerC0_Start();
}

void loop() {
  for(int i = 0; i <= 7; i++)
    if(digitalRead(pos_button[i]))
      digitalWrite(pos_piezo[i], LOW);
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

  digitalWrite(pos_piezo[0], LOW);
  digitalWrite(pos_piezo[1], LOW);
  digitalWrite(pos_piezo[2], LOW);
  digitalWrite(pos_piezo[3], LOW);
  digitalWrite(pos_piezo[4], LOW);
  digitalWrite(pos_piezo[5], LOW);
  digitalWrite(pos_piezo[6], LOW);
  digitalWrite(pos_piezo[7], LOW);

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
  /* set Normal mode */
  TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_NORMAL_gc;
  
  /* disable event counting */
  TCA0.SINGLE.EVCTRL &= ~(TCA_SINGLE_CNTEI_bm);
  
  /* set the period */
  TCA0.SINGLE.PER = TCA_LIMIT;  
  
  TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc;         /* set clock source (sys_clk/1) */

  /* enable overflow interrupt */
  TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
}

void TimerC0_Start()
{
  TCA0.SINGLE.CTRLA = TCA_SINGLE_ENABLE_bm;             /* start timer */
}

void TimerC0_Stop()
{
  TCA0.SINGLE.CTRLA = ~(TCA_SINGLE_ENABLE_bm);             /* stop timer */
}

ISR(TCA0_OVF_vect)
{
  notes[0]++;
	notes[1]++;
	notes[2]++;
	notes[3]++;
	notes[4]++;
	notes[5]++;
	notes[6]++;
	notes[7]++;
	
	//NOTE 1
	if(!(PORTC.IN & PIN6_bm) && (notes[0] >= (REAL_NOTE_C4)))
	{
		PORTB.OUTTGL = PIN1_bm; // Toggle Pin
		notes[0] = 0;
	}

	// NOTE 2
	if(!(PORTC.IN & PIN7_bm) && (notes[1] >= (REAL_NOTE_D4)))
	{
		PORTB.OUTTGL = PIN0_bm;
		notes[1] = 0;
	}

	// NOTE 3
	if(!(PORTD.IN & PIN0_bm) && (notes[2] >= (REAL_NOTE_E4)))
	{
		PORTA.OUTTGL = PIN7_bm;
		notes[2] = 0;
	}

	// NOTE 4
	if(!(PORTE.IN & PIN2_bm) && (notes[3] >= (REAL_NOTE_F4)))
	{
		PORTA.OUTTGL = PIN6_bm;
		notes[3] = 0;
	}

	// NOTE 5
	if(!(PORTE.IN & PIN3_bm) && (notes[4] >= (REAL_NOTE_G4)))
	{
		PORTA.OUTTGL = PIN5_bm;
		notes[4] = 0;
	}

	// NOTE 6
	if(!(PORTF.IN & PIN0_bm) && (notes[5] >= (REAL_NOTE_A4)))
	{
		PORTA.OUTTGL = PIN4_bm;
		notes[5] = 0;
	}
	
	// NOTE 7
	if(!(PORTF.IN & PIN1_bm) && (notes[6] >= (REAL_NOTE_B4)))
	{
		PORTA.OUTTGL = PIN1_bm;
		notes[6] = 0;
	}

	// NOTE 8
	if(!(PORTF.IN & PIN2_bm) && (notes[7] >= (REAL_NOTE_C5)))
	{
		PORTA.OUTTGL = PIN0_bm;
		notes[7] = 0;
	}

  /* The interrupt flag has to be cleared manually */
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
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