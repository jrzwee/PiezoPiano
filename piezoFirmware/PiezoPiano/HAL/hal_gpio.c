/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL GPIO

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"

// ********************************************* DEFINES ***************


// ********************************************* GLOBAL VARIABLES ***************


// ********************************************* OTHER FUNCTIONS ***************
void HAL_GPIO_Init()
{
	// ********** PORT D **********
	// IO SETUP: OUTPUT
	setBit(DDRD, 0xFF);

	// OUTPUT OFF	
	clearBit(PORTD, 0xFF);
	
	// ********** PORT B + E**********
	// IO SETUP: INPUT
	clearBit(DDRB, 0x3F);
	clearBit(DDRE, 0x0C);
		
	// IO SETUP: PULLUP
	setBit(PORTB, 0x3F);
	setBit(PORTE, 0x0C);
	

}