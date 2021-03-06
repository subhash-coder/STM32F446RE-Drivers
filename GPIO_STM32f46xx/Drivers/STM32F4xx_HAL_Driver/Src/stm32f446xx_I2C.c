/*
 * stm32f446xx_I2C.c
 *
 *  Created on: Oct 19, 2021
 *      Author: subhash
 */

#include "stm32f446xx_I2C.h"

void I2C_peripheral_clk(I2C_TypeDef* I2Cx){
	if(I2Cx ==I2C1){
		RCC->APB1ENR |=(1<<21);
	}
	else if(I2Cx == I2C2){
		RCC->APB1ENR |=(1<<22);
	}
	else{
		RCC->APB1ENR |=(1<<23);
	}
}
void I2C_init(I2C_TypeDef* I2Cx){

	//clock enable
	I2C_peripheral_clk(I2Cx);
	I2Cx->CR1=0x00;
	I2Cx->CR2=0x00;

	//set peripheral frequency
	I2Cx->CR2 |=2;//for standard mode 2mhz
	//set CCR in sm mode of 100KHz
	I2Cx->CCR |=10;
	//set rising time
	I2Cx->TRISE |=3;
	//enable ack or not enable for single read
	I2Cx->CR1 |=(1<<10);
	//I2C own address
	I2Cx->OAR1 |=(0x76<<1);
	///enable peripheral
	I2Cx->CR1 |=1;
}
void I2C_write_init(I2C_TypeDef* I2Cx,uint8_t address){
	I2Cx->DR=(address<<1);
	//check for address
	uint32_t temp;
	while(!(I2Cx->SR1 & (1<<1)));
	temp=I2Cx->SR2;
}
void I2C_read_init(I2C_TypeDef* I2Cx,uint8_t address){
	I2Cx->DR=((address<<1)|1);
	uint32_t temp;
	while(!(I2Cx->SR1 & (1<<1)));
	temp=I2Cx->SR2;
}
void I2C_start(I2C_TypeDef* I2Cx){
	I2Cx->CR1 |=(1<<8);
	//wait
	while(!(I2Cx->SR1 & 1));
}
void I2C_stop(I2C_TypeDef* I2Cx){
	I2Cx->CR1 |=(1<<9);
	while(!(I2Cx->CR1 & (1<<9)));
}
void I2C_send(I2C_TypeDef* I2Cx,uint8_t data){

	I2Cx->DR=data;
	while(!(I2Cx->SR1 & (1<<7)));
}
void I2C_receive(I2C_TypeDef* I2Cx,uint8_t* bucket){
	while(!(I2Cx->SR1 & (1<<6)));
	*bucket=I2Cx->DR;
}
void I2C_deinit(I2C_TypeDef* I2Cx){
	I2Cx->CR1 &=~(1);
}
void I2C_Disable_ACK(I2C_TypeDef* I2Cx){
	I2Cx->CR1 &=~(1<<10);
}
void I2C_Enable_ACK(I2C_TypeDef* I2Cx){
	I2Cx->CR1 |=(1<<10);
}
