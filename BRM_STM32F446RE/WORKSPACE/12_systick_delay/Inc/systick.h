/*
 * systick.h
 *
 *  Created on: Dec 20, 2021
 *      Author: Navjeevan
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include<stm32f4xx.h>

#define SYSTICK_LOADVALUE		16000000
#define SYSTICK_CR				(1U<<0)
#define SYSTICK_CLK				(1U<<2)
#define SYSTICK_CNTFLG			(1U<<16)



void systick_delayMs(int delay);


#endif /* SYSTICK_H_ */
