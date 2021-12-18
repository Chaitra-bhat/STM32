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
#define GPIOA_ENA (1U<<0)
#define GPIOA_PIN5	5U

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


void timer2_output_compare()
{
	RCC->AHB1ENR |= GPIOA_ENA;

	GPIOA->MODER |=(1U<<11);
	GPIOA->MODER &= ~(1U<<10);

	GPIOA->AFR[0] |= (1U<<20);
	GPIOA->AFR[0] &= ~(1U<<21);
	GPIOA->AFR[0] &= ~(1U<<22);
	GPIOA->AFR[0] &= ~(1U<<23);
	//Enable clock access
	RCC->APB1ENR |= TIM2_ENA;

	//set prescaler value
	TIM2->PSC = 1600 - 1;

	//set auto-reload value
	TIM2->ARR = 10000 - 1;

	TIM2->CCMR1 |= (1U<<4) | (1U<<5);
	TIM2->CCER |= (1U<<0);

	//clear counter
	TIM2->CNT = 0;

	//enable timer
	TIM2->CR1 |= TIM2_CR1_ENA;

}
