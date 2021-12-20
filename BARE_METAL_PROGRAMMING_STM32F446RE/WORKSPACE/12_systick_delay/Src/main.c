//driver specific header files
#include<adc.h>
#include<uart.h>
#include<systick.h>

// SOme additonal header files
#include<stdint.h>
#include<stdio.h>
#include<stm32f4xx.h>



int main(void)
{

	RCC->AHB1ENR |= (1U<<0);

	GPIOA->MODER |= (1U<<10);

	usart2_txRx_init();

	while(1)
	{
		printf("A second passed \n\r");
		GPIOA->ODR ^= (1U<<5);
		systick_delayMs(1000);
	}

}
