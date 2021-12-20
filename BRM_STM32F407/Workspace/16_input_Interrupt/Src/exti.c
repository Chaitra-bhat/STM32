/*
 * exti.c
 *
 *  Created on: Jun 30, 2021
 *      Author: Navjeevan
 */

#include<stm32f407xx.h>
#include<exti.h>


#define GPIOCENA	(1U<<2)
#define SYSCNFG		(1U<<14)

void pc13_exti_init()
{
	//disable global interrupts
	__disable_irq();

	//Enable clock access for GPIOC
	RCC->AHB1ENR |= GPIOCENA;

	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);
	//Enable clock for SysConfig
	RCC->APB2ENR |= SYSCNFG;

	//Select PortC for EXTI
	SYSCFG->EXTICR[3] |= (1U<<5);
	//unmask exti13
	EXTI->IMR |= (1U<<13);
	//Select falling edge trigger
	EXTI->FTSR |= (1U<<13);
	//Enable EXTI line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();
}
