#include<uart.h>

#define GREEN_LED_PIN	12
#define GPIOD_ENA		(1U<<3)

char data;
static void usart2_callback(void);

int main()
{
	//For LED blinking, enable clock of gpiod as inbuilt LED is connected there.	RCC->AHB1ENR |= GPIOD_ENA;
	RCC->AHB1ENR |= GPIOD_ENA;

	//Enable port12 as output functionality to blink LED
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);


	uart_RXInterrupt_init();

	while(1)
	{
		data = uart2_read();

	}
	return 0;
}

static void usart2_callback(){
	if(data == 'A'){
		GPIOD->ODR |= GREEN_LED_PIN;
					//printf("Received data\r");
		}
	else
		{
		GPIOD->ODR &= ~(GREEN_LED_PIN);
		}
}
void USART2_IRQ_Handler()
{
	if(USART2->SR & SR_RXNE)
	{
		data = USART2->DR;
		usart2_callback();

	}
}
