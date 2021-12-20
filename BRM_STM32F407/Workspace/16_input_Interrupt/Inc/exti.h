/*
 * exti.h
 *
 *  Created on: Jun 30, 2021
 *      Author: Navjeevan
 */

#ifndef EXTI_H_
#define EXTI_H_
#define LINE13	(1U<<13)

void pc13_exti_init();
static void exti_callback();
void exti15_10_irq();


#endif /* EXTI_H_ */
