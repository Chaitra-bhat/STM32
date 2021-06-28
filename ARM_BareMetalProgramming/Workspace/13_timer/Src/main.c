#include<uart.h>
#include<adc.h>
#include<systick.h>
#include<timer.h>


#define RCC_GPIOD_EN			(1U<<3)
#define LED_PIN					12
#define SR_UIF_TIM2				(1U<<0)

int main()
{
	uart_TX_init();
	timer_1Hz_init();
	//Enable clock for GPIOD
	RCC->AHB1ENR |= (RCC_GPIOD_EN);

		//Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<25);



	while(1)
	{
		while(!(TIM2->SR & SR_UIF_TIM2));

		TIM2->SR &= ~SR_UIF_TIM2;
		printf("A second passed\n\r");
		GPIOD->ODR ^= LED_PIN;
	}
	return 0;
}

