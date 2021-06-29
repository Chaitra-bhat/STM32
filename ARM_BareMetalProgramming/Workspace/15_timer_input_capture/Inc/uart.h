/*
 * uart.h
 *
 *  Created on: Jun 27, 2021
 *      Author: Chaitra
 */

#include <stm32f407xx.h>
#include <stdio.h>
#include <stdint.h>

void uart_TX_init();
void uart_RXTX_init();
char uart2_read();
