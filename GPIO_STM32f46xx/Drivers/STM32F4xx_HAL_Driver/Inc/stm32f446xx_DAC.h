/*
 * stm32f446xx_DAC.h
 *
 *  Created on: Oct 16, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_DAC_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_DAC_H_

#include "stm32f446xx.h"
#include "stm32f446xx_GPIO.h"

//channel
//software trigger
typedef struct{
	uint8_t channel;
	uint8_t software_trigger;
}DAC_INIT;

#define DAC_CHANNEL_1			1
#define DAC_CHANNEL_2			2

#define DAC_SOFTWARE_TRIGGER_ENABLE      1
#define DAC_SOFTWARE_TRIGGER_DISABLE	 2


void DAC_init(DAC_TypeDef* DACx,DAC_INIT init);
void DAC_OUT(DAC_TypeDef* DACx,uint8_t data,DAC_INIT init);
#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_DAC_H_ */
