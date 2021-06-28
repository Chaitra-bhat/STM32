/*
 * adc.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Navjeevan
 */
#include<stm32f407xx.h>
#include<stdio.h>
#include<stdint.h>
#include<adc.h>

#define ADC1_ENA	(1U<<8)
#define GPIOA_ENA	(1U<<0)
#define CH1		(1U<<0)
#define SEQ_LEN1 	0x00
#define CR2_ADON	(1U<<0)
#define CR2_SWSTRT	(1U<<30)
#define SR_EOC		(1U<<1)
#define CR2_CONT	(1U<<1)

void pa1_adc_init()
{
	//Enable clok
	RCC->AHB1ENR |= GPIOA_ENA;

	//Set mode to analog mode - PA1 (from datasheet)
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	//Configure ADC peripheral

	//Configure clock for ADC module
	RCC->APB2ENR |= ADC1_ENA;

	//Configure ADC parameters
	ADC1->SQR3 = CH1;
	ADC1->SQR1 = SEQ_LEN1;
	ADC1->CR2 |= CR2_ADON;
}

void start_conversion()
{
	//enable continuos conversion
	ADC1->CR2 |= CR2_CONT;
	// start ADC conversion
	ADC1->CR2 |= CR2_SWSTRT;
}


uint32_t adc_read()
{
	while(!(ADC1->SR & SR_EOC));
	return ADC1->DR;
}
