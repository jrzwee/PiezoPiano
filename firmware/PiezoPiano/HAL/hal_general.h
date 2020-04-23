/****************************** FH Joanneum ECE16 ******************************

Exercise: 			Piezo Piano
Date:				2019-07-02
Type:				HAL GENERAL

****************************** Andreas Zapfl ******************************/

#ifndef HAL_GENERAL_H_
#define HAL_GENERAL_H_

// ********************************************* MACROS ***************
#define setBit(x, y)		(x) |= (y)
#define clearBit(x, y)		(x) &= ~(y)

// ********************************************* DEFINES ***************
#define BIT0				(0x01)
#define BIT1				(0x02)
#define BIT2				(0x04)
#define BIT3				(0x08)
#define BIT4				(0x10)
#define BIT5				(0x20)
#define BIT6				(0x40)
#define BIT7				(0x80)

// BTN PORT B
#define BTN1 BIT0
#define BTN2 BIT1
#define BTN3 BIT2
#define BTN4 BIT3
#define BTN5 BIT4
#define BTN6 BIT5
// BTN PORT E
#define BTN7 BIT2
#define BTN8 BIT3

// NOTE PORT D
#define NTE1 BIT4
#define NTE2 BIT3
#define NTE3 BIT2
#define NTE4 BIT1
#define NTE5 BIT0
#define NTE6 BIT5
#define NTE7 BIT6
#define NTE8 BIT7


// ********************************************* INCLUDES ***************
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/portpins.h>
#include <avr/iom328pb.h>

#include "hal_clkctrl.h"
#include "hal_timerC0.h"
#include "hal_gpio.h"

// ********************************************* PROTOTYPES ***************
void HAL_Init();

#endif /* HAL_GENERAL_H_ */