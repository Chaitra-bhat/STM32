/*
 * adc.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Navjeevan
 */
#include<stm32f4xx.h>
#include<stdint.h>

#ifndef ADC_H_
#define ADC_H_

void start_conversion();
void adc_init();
int adc_read();

#endif /* ADC_H_ */
