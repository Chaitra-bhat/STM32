/*
 * adc.h
 *
 *  Created on: Jun 27, 2021
 *      Author: Navjeevan
 */

#ifndef ADC_H_
#define ADC_H_
#include<stm32f407xx.h>
#include<stdio.h>
#include<stdint.h>

void pa1_adc_init();
void start_conversion();
uint32_t adc_read();

#endif /* ADC_H_ */
