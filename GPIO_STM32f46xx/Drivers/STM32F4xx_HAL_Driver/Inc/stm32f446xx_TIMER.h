/*
 * stm32f446xx_TIMER.h
 *
 *  Created on: Oct 17, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_TIMER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_TIMER_H_
#include "stm32f446xx.h"
#include "stm32f446xx_GPIO.h"
//TIMER
//TIM2->PSC=1000;
// 	TIM2->ARR=3200;
// 	TIM2->CR1 |=1;
//1 to 8
//2 to 5
//9 to 14
//contains PWM

#define PWM_POLARITY_NEGATIVE		1;
#define PWM_POLARITY_POSITIVE		2;

#define PWM_MODE_1					6;
#define PWM_MODE_2					7;


typedef struct{
	uint32_t PSC;
	uint32_t ARR;
	uint32_t CCR;//defines duty cycle
	uint8_t PWM_MODE;
	uint8_t Polarity;
	uint8_t channel;
}PWM_INIT;

void PWM_init(TIM_TypeDef* TIMx,PWM_INIT init);
void PWM_START(TIM_TypeDef* TIMx);
void PWM_DUTY(TIM_TypeDef* TIMx,uint32_t data,PWM_INIT init);
void Timer_peripheral_clk(TIM_TypeDef* TIMx);

#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_TIMER_H_ */
