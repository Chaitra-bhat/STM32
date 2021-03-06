#include<stm32f4xx.h>

#define GPIOENA			(1U<<0)
#define LED_PIN5		(1U<<5)

#define GPIOA_BSRR_SET		(1U<<5)
#define GPIOA_BSRR_RESET	(1U<<21)

int main()
{
	RCC->AHB1ENR |= GPIOENA;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1)
	{
		GPIOA->BSRR |= GPIOA_BSRR_SET;
		for(int i=0; i<1000000; i++);

		GPIOA->BSRR |= GPIOA_BSRR_RESET;
		for(int i=0; i<1000000; i++);
	}

	return 0;
}
