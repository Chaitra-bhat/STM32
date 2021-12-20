#include<uart.h>
#include<adc.h>
#include<systick.h>
#include<timer.h>
#include<exti.h>

#define RCC_GPIOD_EN			(1U<<3)
#define LED_PIN					12
#define SR_UIF_TIM2				(1U<<0)

int main()
{
	//Enable clock for GPIOD
	RCC->AHB1ENR |= (RCC_GPIOD_EN);

		//Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<25);

	uart_TX_init();
	pc13_exti_init();
	while(1)
	{

	}
	return 0;
}

static void exti_callback(){
	printf("Button is pressed\n...");
	GPIOD->ODR ^= LED_PIN;
}

void exti15_10_irq(){
	if((EXTI->PR && LINE13)!= 0)
	{
		//clear PR flag
		EXTI->PR &= ~(LINE13);
		exti_callback();
	}

}
