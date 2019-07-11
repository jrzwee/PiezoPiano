/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL TCA0 TimerA0

****************************** Andreas Zapfl ******************************/

#ifndef HAL_TIMERA0_H_
#define HAL_TIMERA0_H_

// ********************************************* PROTOTYPES ***************
void HAL_TimerC0_Init();

unsigned long long millis();
unsigned long long micros();

#endif /* HAL_TIMERA0_H_ */