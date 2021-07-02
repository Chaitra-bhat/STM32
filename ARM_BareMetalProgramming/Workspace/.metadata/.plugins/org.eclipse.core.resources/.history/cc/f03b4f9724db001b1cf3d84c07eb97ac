#include<uart.h>

#define GREEN_LED_PIN	12
#define GPIOD_ENA		(1U<<3)

char data;

int main()
{
	//For LED blinking, enable clock of gpiod as inbuilt LED is connected there.	RCC->AHB1ENR |= GPIOD_ENA;
	RCC->AHB1ENR |= GPIOD_ENA;

	//Enable port12 as output functionality to blink LED
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);


	uart_RXTX_init();

	while(1)
	{
		data = uart2_read();
		if(data == 'A'){
			GPIOD->ODR |= GREEN_LED_PIN;
			//printf("Received data\r");
		}
		else
		{
			GPIOD->ODR &= ~(GREEN_LED_PIN);
		}
	}
	return 0;
}

