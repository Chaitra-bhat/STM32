
#include<adc.h>
#include<uart.h>
#include<stdint.h>
#include<stdio.h>
#include<stm32f4xx.h>
int sensor_value;

int main(void)
{
	adc_init();
	usart2_txRx_init();
	start_conversion();

	while(1)
	{

		sensor_value = adc_read();
		printf("ADC conversion value: %d \n\r", sensor_value);
	}

}
