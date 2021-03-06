/*
 * stm32f446xx_ADC.h
 *
 *  Created on: Oct 16, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_ADC_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_ADC_H_
#include "stm32f446xx.h"
#include "stm32f446xx_GPIO.h"

#define ADC_SAMPLE_3_CYCLES				0;
#define ADC_SAMPLE_15_CYCLES			1;
#define ADC_SAMPLE_28_CYCLES			2;
#define ADC_SAMPLE_56_CYCLES			3;
#define ADC_SAMPLE_84_CYCLES			4;
#define ADC_SAMPLE_112_CYCLES			5;
#define ADC_SAMPLE_144_CYCLES			6;
#define ADC_SAMPLE_480_CYCLES			7;




typedef struct{
	uint32_t ADC_SAMPLE_RATE;
	uint8_t  ADC_channel;
//	uint8_t  ADC_continuous;
}ADC_INIT;

void ADC_init(ADC_TypeDef* ADCx,ADC_INIT init);
void ADC_START(ADC_TypeDef* ADCx);
void ADC_START(ADC_TypeDef* ADCx);

#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_ADC_H_ */
