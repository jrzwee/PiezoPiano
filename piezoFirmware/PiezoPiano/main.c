/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				Main Source File

Info:				None

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"
// #define F_CPU 8000000UL  // 1 MHz
// #include <util/delay.h>

// ********************************************* DEFINES ***************

// ********************************************* SERIAL NUMBER ***************

// ********************************************* GLOBAL VAR ***************

// ********************************************* MAIN FUNCTION **************
int main(void)
{
	HAL_Init();		// Hardware Peripheral Init
	
	sei();			// Global Enable Interrupts
	
	while(1){}
}