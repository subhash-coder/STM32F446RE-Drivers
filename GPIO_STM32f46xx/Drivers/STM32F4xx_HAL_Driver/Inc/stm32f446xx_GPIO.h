/*
 * stm32f446xx_GPIO.h
 *
 *  Created on: Oct 14, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_GPIO_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_GPIO_H_
#include "stm32f446xx.h"
/*********   GPIO REGISTERS  ***************************/
typedef struct
{
	uint8_t GPIO_PIN;
	uint8_t GPIO_MODE;
	uint8_t GPIO_SPEED;
	uint8_t GPIO_OP_PUSH_PULL;
	uint8_t GPIO_OPTYPE;
	uint8_t GPIO_ALTFUNC;
}GPIO_INIT;

#define GPIO_PIN0			0
#define GPIO_PIN1			1
#define GPIO_PIN2			2
#define GPIO_PIN3			3
#define GPIO_PIN4			4
#define GPIO_PIN5			5
#define GPIO_PIN6			6
#define GPIO_PIN7			7
#define GPIO_PIN8           8
#define GPIO_PIN9			9
#define GPIO_PIN10			10
#define GPIO_PIN11			11
#define GPIO_PIN12           12
#define GPIO_PIN13			13
#define GPIO_PIN14			14
#define GPIO_PIN15			15

#define GPIO_MODE_INPUT		0
#define GPIO_MODE_OUTPUT	1
#define GPIO_MODE_ALT		2
#define GPIO_MODE_ANALOG	3

#define GPIO_PUSH_PULL		0
#define GPIO_OPEN_DRAIN		1

#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_FAST_SPEED		2
#define GPIO_HIGH_SPEED		3

#define GPIO_NO_PUSH_PULL	0
#define GPIO_PULL_UP		1
#define GPIO_PULL_DOWN      2

#define __RCC_GPIOA_CLK_ENABLE()		(RCC->AHB1ENR |=(1))
#define __RCC_GPIOB_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<1))
#define __RCC_GPIOC_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<2))
#define __RCC_GPIOD_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<3))
#define __RCC_GPIOE_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<4))
#define __RCC_GPIOF_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<5))
#define __RCC_GPIOG_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<6))
#define __RCC_GPIOH_CLK_ENABLE()		(RCC->AHB1ENR |=(1<<7))

#define EXTI_RISING				0
#define EXTI_FALLING			1
#define EXTI_FALLING_RISING  	2





void GPIO_init(GPIO_TypeDef* GPIOx,GPIO_INIT Init);
void LED_INIT();
void LED_OFF();
void LED_TOGGLE();
void GPIO_OUTPUT_HIGH(GPIO_TypeDef* GPIOx,uint8_t pin);
void GPIO_OUTPUT_LOW(GPIO_TypeDef* GPIOx,uint8_t pin);

void LED_ON();

uint32_t GPIO_INPUT(GPIO_TypeDef* GPIOx,uint8_t pin);

void GPIO_INTERRUPT_CONFIG(GPIO_TypeDef* GPIOx,GPIO_INIT init,uint8_t trigger);

void GPIO_ALT_INIT(GPIO_TypeDef* GPIOx,GPIO_INIT init);














#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_GPIO_H_ */
