/*
 * uart.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Chaitra
 */

#include "uart.h"

#define GPIOA_ENABLE	(1U<<0)
#define UART2EN			(1<<17)

#define SYSFREQ			16000000
#define APB1_CLK		SYSFREQ

#define CR1_RXNEIE		(1U<<5)
#define UART_BAUDRATE	115200

#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)
#define CR1_RE			(1U<<2)




static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t baudrate);
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t baudrate);
void uart_write(int ch);
char uart2_read();

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}

void uart_RXInterrupt_init()
{
	//Enable clock for gpioa
	RCC->AHB1ENR |= GPIOA_ENABLE;

	//Enable the alternate functionality for Port2 - PA2 (USART2_TX)
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//Enable the alternate functionality for Port2 - PA3 (USART2_RX)
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	//set alternate function type to Tx
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//set alternate function type to Rx
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);

	//enable usart2 clock
	RCC->APB1ENR |= UART2EN;

	//baudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	//transfer direction
	USART2->CR1 = (CR1_TE | CR1_RE);

	USART2->CR1 = CR1_RXNEIE;
	/*Enable RXNE Interrupt and then enable it in NVIC*/
	NVIC_EnableIRQ(USART2_IRQn);

	//enable usart2 module
	USART2->CR1 |= CR1_UE;
}


void uart_TX_init()
{
	//Enable clock for gpioa
	RCC->AHB1ENR |= GPIOA_ENABLE;

	//Enable the alternate functionality for Port2 - PA2 (USART2_TX)
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//set alternate function type to Tx
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//enable usart2 clock
	RCC->APB1ENR |= UART2EN;

	//baudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	//transfer direction
	USART2->CR1 = CR1_TE;

	//enable usart2 module
	USART2->CR1 |= CR1_UE;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t baudrate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, baudrate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t baudrate)
{

	return ((PeriphClk + (baudrate/2U))/baudrate);
}

void uart_write(int ch)
{
	while(!(USART2->SR & SR_TXE));
	//Initially transmit data register should be empty
	USART2->DR = (ch & 0xFF);
	//write to transmit data register
}

char uart2_read()
{
	//Receiver register should not be empty - NE flag
	while(!(USART2->SR & SR_RXNE));

	//read data from register
	return USART2->DR;
}
