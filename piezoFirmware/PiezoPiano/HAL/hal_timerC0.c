/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL TC1

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"

// ********************************************* DEFINES ***************
#define	F_CPU				8000000
#define F_TIMER				44000
#define TCA_LIM				((F_CPU/F_TIMER)+1)

// NOTES LOW
#define C4 84
#define D4 75
#define E4 67
#define F4 63
#define G4 56
#define A4 50
#define H4 45
#define C5 42

// NOTES HIGH
// #define C4 42
// #define D4 37
// #define E4 33
// #define F4 31
// #define G4 28
// #define A4 25
// #define H4 22
// #define C5 21

// ********************************************* GLOBAL VARIABLES ***************
unsigned char notes[8] = {0};

// ********************************************* OTHER FUNCTIONS ***************
void HAL_TimerC0_Init()
{
	// Timer C0
	TCCR0A |= (1<<WGM01);	// CTC Mode
	TCCR0B |= (1<<CS00);	// Prescaler 0
	
	TIMSK0 |= (1<<OCIE0A);	// Enable Compare Interrupt
	OCR0A = TCA_LIM;		// Compare Value 181.818181
  
	TCNT0 = 0;				// Reset Counter
}

ISR(TIMER0_COMPA_vect)
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
	if(!(PINB & BTN1) && (notes[0] >= C4))
	{
		setBit(PIND, NTE1);
		notes[0] = 0;
	}

	
	// NOTE 2
	if(!(PINB & BTN2) && (notes[1] >= D4))
	{
		setBit(PIND, NTE2);
		notes[1] = 0;
	}


	// NOTE 3
	if(!(PINB & BTN3) && (notes[2] >= E4))
	{
		setBit(PIND, NTE3);
		notes[2] = 0;
	}

	// NOTE 4
	if(!(PINB & BTN4) && (notes[3] >= F4))
	{
		setBit(PIND, NTE4);
		notes[3] = 0;
	}


	// NOTE 5
	if(!(PINB & BTN5) && (notes[4] >= G4))
	{
		setBit(PIND, NTE5);
		notes[4] = 0;
	}


	// NOTE 6
	if(!(PINB & BTN6) && (notes[5] >= A4))
	{
		setBit(PIND, NTE6);
		notes[5] = 0;
	}

	
	// NOTE 7
	if(!(PINE & BTN7) && (notes[6] >= H4))
	{
		setBit(PIND, NTE7);
		notes[6] = 0;
	}


	// NOTE 8
	if(!(PINE & BTN8) && (notes[7] >= C5))
	{
		setBit(PIND, NTE8);
		notes[7] = 0;
	}
}