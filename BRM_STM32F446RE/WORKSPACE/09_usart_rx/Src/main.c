#include<stm32f4xx.h>
#include<stdint.h>
#include<stdio.h>
#include<uart.h>

#define LEDPIN5		(1U<<5)
#define GPIOENA		(1U<<0)


char key;
int main()
{
	RCC->AHB1ENR |= GPIOENA;

	GPIOA->MODER |= (1U<<10);

	usart2_txRx_init();

	while(1)
	{
		key = uart2_read();
		if(key == '1')
		{
			GPIOA->ODR |= LEDPIN5;
		}
		else
		{
			GPIOA->ODR &= ~(LEDPIN5);
		}

	}
}
