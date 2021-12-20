/*
 * systick.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Navjeevan
 */

#include<systick.h>

void systick_delayMs(int delay)
{
	//configure systick
	//clocks per millisecond
	SysTick->LOAD = SYSTICK_LOADVALUE;

	// Clear the systick current value regsiter
	SysTick->VAL = 0;

	//Enable the systick and select general clock source
	SysTick->CTRL = SYSTICK_CR | SYSTICK_CLK;

	for (int i=0; i<delay;i++){

	//wait until counter flag is set
	while(!(SysTick->CTRL & SYSTICK_CNTFLG));
	}
	SysTick->CTRL = 0;
}


