#include <stm32f407xx.h>
//#include<stm32f4xx.h>

#define GPIOD_EN	(1U<<3)
#define PIN12		(1U<<12)
#define LED_PIN		PIN12

int main()
{
	//Enable clock
	RCC->AHB1ENR |= GPIOD_EN;

	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);

	while(1)
	{
		GPIOD->BSRR = LED_PIN;
		for(int i=0; i<1000000;i++);

		GPIOD->BSRR = (1U<<28);
		for(int i=0; i<1000000;i++);
	}

	return 0;
}
