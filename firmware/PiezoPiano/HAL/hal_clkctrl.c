/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL CLKCTRL (System Clock)

Main Clock is set by:
	- FUSE 8MHz
	- PRESCALER default divide by 8
= 1MHz

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"

// ********************************************* GLOBAL VARIABLES ***************


// ********************************************* OTHER FUNCTIONS ***************
void HAL_CLKCTRL_Init()
{
	// Configure Clock Divider to achieve 8MHz Main Clock
	// Disable Fuse = No Prescaler
	// Page 50 PDF
}
