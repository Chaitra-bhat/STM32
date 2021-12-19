/*
 * uart.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Navjeevan
 */

#ifndef UART_H_
#define UART_H_
#include <stm32f4xx.h>

#include <stdint.h>
#include <stdio.h>

#define GPIOA_ENA		(1U<<0)
#define USART2ENA		(1U<<17)

#define SYS_FREQ		16000000
#define USARt_BAUDRATE  115200




//function prototypes
void usart2_txRx_init(void);
static void setBaudrate(USART_TypeDef *USARTx, uint32_t PeriphClock, uint32_t Baudrate);
static uint16_t compute_uart_baudrate(uint32_t PeriphClock, uint32_t Baudrate);
void uart2_write(int ch);
char uart2_read();


#endif /* UART_H_ */
