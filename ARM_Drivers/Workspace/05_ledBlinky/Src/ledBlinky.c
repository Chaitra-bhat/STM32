/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Bhat Chaitra
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stm32f407xx.h>
#include <gpio.h>

int main(void)
{
  GPIO_Handle_t GPIOLed;

  GPIOLed.pGPIOx = GPIOD;
  GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINUMBER_12;
  GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
  GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
  GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PUSHPULL;
  GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;

  GPIO_PeriClockControl(GPIOD, ENABLE);
  GPIO_Init(&GPIOLed);

  while(1)
  {
	  GPIO_ToggleOutputPin(GPIOD, GPIO_PINUMBER_12);
	  for(int i=0; i<5000;i++);
  }

}
