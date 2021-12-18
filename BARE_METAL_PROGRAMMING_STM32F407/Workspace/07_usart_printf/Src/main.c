#include <stdio.h>
#include <stdint.h>
#include <stm32f446xx.h>


#define GPIOA_ENABLE	(1U<<0)
#define UART2EN		(1<<17)

#define SYSFREQ			16000000
#define APB1_CLK		SYSFREQ

#define UART_BAUDRATE	115200

#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)

void uart_TX_init();
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t baudrate);
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t baudrate);
void uart_write(int ch);

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}


int main()
{

	uart_TX_init();

	while(1)
	{
		printf("Hello Chaitra\n\r");
	}
	return 0;
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

