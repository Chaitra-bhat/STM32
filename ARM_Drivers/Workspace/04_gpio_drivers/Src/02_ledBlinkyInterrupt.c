
#include <stdint.h>
#include <stm32f407xx.h>
#include <gpio.h>
#include <string.h>

//void EXTI0_IRQHandler(void);

void delay(int n){
	for(int i=0; i<n;i++);
}

int main(void)
{
  GPIO_Handle_t GPIOLed, GPIOButton;
  memset(&GPIOLed,0,sizeof(GPIOLed));
  memset(&GPIOButton,0,sizeof(GPIOButton));

  GPIOLed.pGPIOx = GPIOD;
  GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINUMBER_12;
  GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
  GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
  GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PUSHPULL;
  GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
  GPIO_PeriClockControl(GPIOD, ENABLE);
  GPIO_Init(&GPIOLed);

  GPIOButton.pGPIOx = GPIOA;
  GPIOButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINUMBER_5;
  GPIOButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
  GPIOButton.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PUSHPULL;
  GPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_PU;
  GPIOButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_FAST;


  GPIO_PeriClockControl(GPIOA, ENABLE);

  GPIO_Init(&GPIOButton);

  GPIO_WriteToOutputPin(GPIOD, GPIO_PINUMBER_12, RESET);
  //IRQ CONFIGURATIONS
  GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_PRIO_15);
  GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

  	  while(1);
}

//Implement the ISR
void EXTI9_5_IRQHandler(void){
	  delay(200000); //To overcome button debouncing
	  GPIO_IRQHandling(GPIO_PINUMBER_5);
	  GPIO_ToggleOutputPin(GPIOD, GPIO_PINUMBER_12);
}
