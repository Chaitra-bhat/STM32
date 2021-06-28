#include<uart.h>
#include<adc.h>
#include<systick.h>


#define RCC_GPIOD_EN			(1U<<3)
#define LED_PIN					12


int main()
{
	uart_TX_init();
	//Enable clock for GPIOD
	RCC->AHB1ENR |= (RCC_GPIOD_EN);

		//Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<25);



	while(1)
	{
		printf("A second passed\n\r");
		GPIOD->ODR ^= LED_PIN;
		systickDelayMs(1000);
	}
	return 0;
}

