/*
 * timer.c
 *
 *  Created on: Jun 28, 2021
 *      Author: Navjeevan
 */
#include<stdint.h>
#include<stdio.h>
#include<stm32f407xx.h>

#define TIM2_ENA	(1U<<0)
#define TIM2_CR1_ENA (1U<<0)

void timer_1Hz_init()
{
	//Enable clock access
	RCC->APB1ENR |= TIM2_ENA;

	//set prescaler value
	TIM2->PSC = 1600 - 1;

	//set auto-reload value
	TIM2->ARR = 10000 - 1;
	//clear counter
	TIM2->CNT = 0;

	//enable timer
	TIM2->CR1 |= TIM2_CR1_ENA;

}

