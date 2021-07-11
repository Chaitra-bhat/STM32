/*
 * gpio.h
 *
 *  Created on: Jul 4, 2021
 *      Author: Navjeevan
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <stdio.h>
#include <stm32f407xx.h>

/*volatile keyword is used as registers get updated every clock cycle,
to capture every input it is necessary to set to  the keyword volatile,
indicating they update at every clock cycle*/
#define __vo			volatile



/* REGISTER DEFINITIONS FOR GPIO*/
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;


/* DEFINITONS FOR EACH GPIO*/
#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH					((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI					((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ					((GPIO_RegDef_t*)GPIOJ_BASEADDR)

#define GPIO_PINUMBER_0  			0
#define GPIO_PINUMBER_1				1
#define GPIO_PINUMBER_2				2
#define GPIO_PINUMBER_3				3
#define GPIO_PINUMBER_4 			4
#define GPIO_PINUMBER_5				5
#define GPIO_PINUMBER_6				6
#define GPIO_PINUMBER_7				7
#define GPIO_PINUMBER_8				8
#define GPIO_PINUMBER_9				9
#define GPIO_PINUMBER_10			10
#define GPIO_PINUMBER_11			11
#define GPIO_PINUMBER_12			12
#define GPIO_PINUMBER_13			13
#define GPIO_PINUMBER_14			14
#define GPIO_PINUMBER_15			15

#define GPIO_MODE_INPUT 		0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALTERNATEFUNC 	2
#define GPIO_MODE_ANALOG 		3
#define GPIO_MODE_IT_FT     		4
#define GPIO_MODE_IT_RT		        5
#define GPIO_MODE_IT_RFT    		6

#define GPIO_OPTYPE_PUSHPULL 		0
#define GPIO_OPTYPE_OPENDRAIN   	1

#define GPIO_OSPEED_LOW			0
#define GPIO_OSPEED_MEDIUM		1
#define GPIO_OSPEED_FAST		2
#define GPIO_OSPEED_HIGH		3

#define GPIO_PUPD_NO   		0
#define GPIO_PUPD_PU			1
#define GPIO_PUPD_PD			2


/*PERIPHERAL CLOCK ENABLE FOR GPIO DEFINITIONS*/
#define	GPIOA_PCLK_EN()			((RCC->AHB1ENR)|= (1<<0))
#define	GPIOB_PCLK_EN()			((RCC->AHB1ENR)|= (1<<1))
#define	GPIOC_PCLK_EN()			((RCC->AHB1ENR)|= (1<<2))
#define	GPIOD_PCLK_EN()			((RCC->AHB1ENR)|= (1<<3))
#define	GPIOE_PCLK_EN()			((RCC->AHB1ENR)|= (1<<4))
#define	GPIOF_PCLK_EN()			((RCC->AHB1ENR)|= (1<<5))
#define	GPIOG_PCLK_EN()			((RCC->AHB1ENR)|= (1<<6))
#define	GPIOH_PCLK_EN()			((RCC->AHB1ENR)|= (1<<7))
#define	GPIOI_PCLK_EN()			((RCC->AHB1ENR)|= (1<<8))
#define	GPIOJ_PCLK_EN()			((RCC->AHB1ENR)|= (1<<9))

/*PERIPHERAL CLOCK DISABLE FOR GPIO DEFINITIONS*/
#define	GPIOA_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<0))
#define	GPIOB_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<1))
#define	GPIOC_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<2))
#define	GPIOD_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<3))
#define	GPIOE_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<4))
#define	GPIOF_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<5))
#define	GPIOG_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<6))
#define	GPIOH_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<7))
#define	GPIOI_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<8))
#define	GPIOJ_PCLK_DI()			((RCC->AHB1RSTR)&= ~(1<<9))

#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct
{
	GPIO_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t GPIO_PinConfig;   /*!< This holds GPIO pin configuration settings >*/

}GPIO_Handle_t;



/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* GPIO_H_ */
