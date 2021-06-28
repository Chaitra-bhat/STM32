/*
 * systick.c
 *
 *  Created on: Jun 28, 2021
 *      Author: Navjeevan
 */
#include<stm32f407xx.h>
#include<uart.h>

#define SYSTICK_LOADVAL	16000U
#define SYSTICK_ENABLE	(1U<<0)
#define SYSTICK_CLCKSRC	(1U<<2)
#define SYSTICK_CNTRFLG	(1U<<16)



void systickDelayMs(int delay)
{
	//Configure systick
	//load with number of clock milli seconds
	SysTick->LOAD = SYSTICK_LOADVAL;

	//clear current value register
	SysTick->VAL = 0;

	SysTick->CTRL = SYSTICK_ENABLE | SYSTICK_CLCKSRC;

	for (int i=0;i<delay;i++){
		//wait until the count flag is set
		while(!(SysTick->CTRL & SYSTICK_CNTRFLG));
	}
	SysTick->CTRL = 0;
}


