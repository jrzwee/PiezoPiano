/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL GENERAL

****************************** Andreas Zapfl ******************************/

// ********************************************* INCLUDES ***************
#include "hal_general.h"

// ********************************************* GLOBAL VARIABLES ***************


// ********************************************* OTHER FUNCTIONS ***************
void HAL_Init()
{
	HAL_CLKCTRL_Init();				// System Clock Init
	HAL_GPIO_Init();				// GPIO Init
	HAL_TimerC0_Init();				// TimerA1 Init
}
