/*
 * stm32f407xx.h
 *
 *  Created on: Jul 4, 2021
 *      Author: Bhat Chaitra
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

/*GENERAL DEFINITIONS*/
#define __vo						volatile
#define __weak 						__attribute__((weak))
#define ENABLE						1
#define DISABLE						0
#define SET							ENABLE
#define RESET						DISABLE

#define GPIO_BASEADDR_TO_CODE(x)	((x == GPIOA)? 0 :\
									(x == GPIOB)? 1 :\
									(x == GPIOC)? 2 :\
									(x == GPIOD)? 3 :\
									(x == GPIOE)? 4 :\
									(x == GPIOF)? 5 :\
									(x == GPIOG)? 6 :\
									(x == GPIOH)? 7 :\
									(x == GPIOI)? 8 :\
									(x == GPIOJ)? 9 :0)
/*IRQ macros*/
#define	IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40

/*arm cortex M processor NVIC ISERx register*/
#define NVIC_ISER0				((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1				((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2				((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3				((__vo uint32_t*)0xE000E10C)

/*arm cortex M processor NVIC ICERx register*/
#define NVIC_ICER0				((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1				((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2				((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3				((__vo uint32_t*)0xE000E18C)

/* Priority regsiter adress for arm cortex M processor*/
#define NVIC_PR_BASE_ADDR		((__vo uint32_t*)0xE000E400)

#define	NO_PRIORITY_BITS_IMPLEMENTED		4

/* IRQ Priority Macros*/
#define NVIC_PRIO_0					0
#define NVIC_PRIO_1					1
#define NVIC_PRIO_2					2
#define NVIC_PRIO_3					3
#define NVIC_PRIO_4					4
#define NVIC_PRIO_5					5
#define NVIC_PRIO_6					6
#define NVIC_PRIO_7					7
#define NVIC_PRIO_8					8
#define NVIC_PRIO_9					9
#define NVIC_PRIO_10				10
#define NVIC_PRIO_11				11
#define NVIC_PRIO_12				12
#define NVIC_PRIO_13				13
#define NVIC_PRIO_14				14
#define NVIC_PRIO_15				15
#define NVIC_PRIO_16				16



/*MEMORY RELATED DEFINITIONS*/
#define FLASH_BASEADDR				0x80000000U			//BASE ADDRESS OF FLASH MEMORY
#define SRAM1_BASEADDR				0x20000000U			//BASE ADDRESS OF SRAM1
#define SRAM2_BASEADDR				0x2001C000U			//BASE ADDRESS OF SRAM2
#define SYSTEM_MEM_BASEADDR			0x1FFF0000U			//BASE ADDRESS OF SYSTEM MEMORY/ROM
#define OTP_AREA_BASEADDR			0x1FFF7800U			//BASE ADDRESS OF OTP AREAS

/*BUS RELATED DEFINITIONS*/
#define AHB1_BASEADDR				0x40020000U
#define AHB2_BASEADDR				0x50000000U
#define AHB3_BASEADDR				0xA0000000U
#define APB1_BASEADDR				0x40000000U
#define APB2_BASEADDR				0x40010000U

/*GPIO DEFINITIONS*/
#define GPIOA_BASEADDR				0x40020000U
#define GPIOB_BASEADDR				0x40020400U
#define GPIOC_BASEADDR				0x40020800U
#define GPIOD_BASEADDR				0x40020C00U
#define GPIOE_BASEADDR				0x40021000U
#define GPIOF_BASEADDR				0x40021400U
#define GPIOG_BASEADDR				0x40021800U
#define GPIOH_BASEADDR				0x40021C00U
#define GPIOI_BASEADDR				0x40022000U
#define GPIOJ_BASEADDR				0x40022400U

/*I2C DEFINITIONS*/
#define I2C1_BASEADDR				0x40005400U
#define I2C2_BASEADDR				0x40005800U
#define I2C3_BASEADDR				0x40005C00U

/*TIMER DEFINITIONS*/
#define TIM1_BASEADDR				0x40010000U
#define TIM2_BASEADDR				0x40000000U
#define TIM3_BASEADDR				0x40000400U
#define TIM4_BASEADDR				0x40000800U
#define TIM5_BASEADDR				0x40000C00U
#define TIM6_BASEADDR				0x40001000U
#define TIM7_BASEADDR				0x40001400U
#define TIM8_BASEADDR				0x40010400U
#define TIM9_BASEADDR				0x40014000U
#define TIM10_BASEADDR				0x40014400U
#define TIM11_BASEADDR				0x40014800U
#define TIM12_BASEADDR				0x40001800U
#define TIM13_BASEADDR				0x40001C00U
#define TIM14_BASEADDR				0x40002000U

/*SPI DEFINITIONS*/
#define	SPI1_BASEADDR				0x40013000U
#define SPI2_BASEADDR				0x40003800U
#define SPI3_BASEADDR				0x40003C00U
#define SPI4_BASEADDR				0x40013400U
#define SPI5_BASEADDR				0x40015000U
#define SPI6_BASEADDR				0x40015400U

/*SYSCFG DEFINITIONS*/
#define SYSCFG_BASEADDR				0x40013800U

/*EXTI DEFINITIONS*/
#define EXTI_BASEADDR				0x40013C00U

/*ADC DEFINTIONS*/
#define ADC1_BASEADDR				0x40012000U

/*CAN DEFINTIONS*/
#define CAN1_BASEADDR				0x40006400U
#define CAN2_BASEADDR				0x40006800U

/*WATCH DOG DEFINITIONS*/
#define WWDG_BASEADDR				0x40002C00U

/*USART DEFINITIONS*/
#define USART1_BASEADDR				0x40011000U
#define USART2_BASEADDR				0x40004400U
#define USART3_BASEADDR				0x40004800U
#define USART6_BASEADDR				0x40011400U

/*RCC DEFINITIONS*/
#define RCC_BASEADDR				0x40023800U

/*UART DEFINITIONS*/
#define UART4_BASEADRR				0x40004C00U
#define UART5_BASEADDR				0x40005000U
#define UART7_BASEADDR				0x40007800U
#define UART8_BASEADDR				0x40007C00U

/* PWR DEFINITIONS*/
#define PWR_BASEADDR				0x40005000U

/*DAC DEFINITIONS*/
#define DAC_BASEADDR				0x40007400U

/*CRC DEFINITIONS*/
#define CRC_BASEADDR				0x40023000U

/*DMA DEFITIONS*/
#define DMA1_BASEADDR				0x40026000U
#define DMA2_BASEADDR				0x40026400U


/*PERIPHERAL REGISTER DEFINITION STRUCTURE FOR RCC*/
typedef struct {
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t Reserved1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t Reserved2;
	__vo uint32_t Reserved3;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t Reserved4;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t Reserved5;
	__vo uint32_t Reserved6;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t Reserved7;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t Reserved8;
	__vo uint32_t Reserved9;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t Reserved10;
	__vo uint32_t Reserved11;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
}RCC_RegDef_t;


typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	uint32_t      RESERVED1[2];
	__vo uint32_t CMPCR;
	uint32_t      RESERVED2[2];
	__vo uint32_t CFGR;
} SYSCFG_RegDef_t;

/*PERIPHERAL DEFINITION*/
#define RCC								((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI 							((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG							((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*Clock Enable for Syscfg */
#define SYSCFG_CLK_EN()					((RCC->APB2ENR) |= (1<<14))


#endif /* STM32F407XX_H_ */
