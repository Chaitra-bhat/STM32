#include<stm32f4xx.h>

#define GPIOA_ENABLE 		(1U<<0)
#define LED_PIN				(1U<<5)


int main()
{
	RCC->AHB1ENR |= GPIOA_ENABLE;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		for(int i=0; i<100000;i++);
	}

	return 0;
}
