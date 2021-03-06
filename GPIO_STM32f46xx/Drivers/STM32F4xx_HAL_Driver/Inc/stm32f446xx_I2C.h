/*
 * stm32f446xx_I2C.h
 *
 *  Created on: Oct 19, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_I2C_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_I2C_H_
#include "stm32f446xx.h"
void I2C_init(I2C_TypeDef* I2Cx);
void I2C_write_init(I2C_TypeDef* I2Cx,uint8_t address);
void I2C_read_init(I2C_TypeDef* I2Cx,uint8_t address);
void I2C_start(I2C_TypeDef* I2Cx);
void I2C_stop(I2C_TypeDef* I2Cx);
void I2C_send(I2C_TypeDef* I2Cx,uint8_t data);
void I2C_receive(I2C_TypeDef* I2Cx,uint8_t* bucket);
void I2C_deinit(I2C_TypeDef* I2Cx);
void I2C_Disable_ACK(I2C_TypeDef* I2Cx);
void I2C_Enable_ACK(I2C_TypeDef* I2Cx);
#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_I2C_H_ */
