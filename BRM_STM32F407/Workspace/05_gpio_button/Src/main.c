#include <stm32f407xx.h>
//#include<stm32f4xx.h>

#define GPIOD_EN	(1U<<3)
#define GPIOA_EN	(1U<<0)
#define BUTTON_PRESSED	1

#define PIN12		(1U<<12)
#define LED_PIN		PIN12
#define BUTTON_PIN  (1U<<0)

int main()
{
	//Enable clock FOR gpio A and D
	RCC->AHB1ENR |= GPIOD_EN;
	RCC->AHB1ENR |= GPIOA_EN;

	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);

	// For Button
	GPIOA->MODER &= ~(1U<<0);
	GPIOA->MODER &= ~(1U<<1);

	while(1)
	{
		if((GPIOA->IDR & BUTTON_PIN) == BUTTON_PRESSED)
		{
			GPIOD->ODR |= LED_PIN;
		}
		else
			GPIOD->ODR &= ~(LED_PIN);
	}

	return 0;
}
