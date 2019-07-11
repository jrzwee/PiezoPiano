/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL TC1

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"

// ********************************************* DEFINES ***************
#define	T_BIT				1E-3
#define F_TIMER				(1/T_BIT)
#define TCA_PRESCALE		1
#define TCA_LIM				(F_CPU/TCA_PRESCALE/F_TIMER-1)

// NOTES
#define C4 168/2
#define D4 150/2
#define E4 133/2
#define F4 126/2
#define G4 112/2
#define A4 100/2
#define H4 89/2
#define C5 84/2

// ********************************************* GLOBAL VARIABLES ***************
// Volatile -> Compiler is not optimizing count_
// Compiler eliminates the count_ if not volatile
volatile unsigned long long count_ = 0;

volatile unsigned int notes[8] = {0};

// ********************************************* OTHER FUNCTIONS ***************
void HAL_TimerC0_Init()
{
	// Timer C0
	TCCR0A |= (1<<WGM01);	// CTC Mode
	TCCR0B |= (1<<CS00);	// Prescaler 0
	OCR0A = 91;				// Compare Value
	TIMSK0 |= (1<<OCIE0A);	// Enable Compare Interrupt
  
	TCNT0 = 0;				// Reset Counter
}


// Return Up Time in Milliseconds
unsigned long long millis()
{
	return count_;
}

// Return Up Time in Microseconds
unsigned long long micros()
{
	// Timer Register Value / 20 because of the Main CLK
	// 1/20E6*20 = 1E-6
	return count_ * 1000 + (TCNT0 / 8);
}

ISR(TIMER0_COMPA_vect)
{
	count_++;
	
	notes[0]++;
	notes[1]++;
	notes[2]++;
	notes[3]++;
	notes[4]++;
	notes[5]++;
	notes[6]++;
	notes[7]++;
		
	
	// NOTE 1
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