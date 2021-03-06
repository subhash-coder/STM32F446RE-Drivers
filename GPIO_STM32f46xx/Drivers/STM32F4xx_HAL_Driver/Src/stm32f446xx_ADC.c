/*
 * stm32f446xx_ADC.c
 *
 *  Created on: Oct 16, 2021
 *      Author: subhash
 */
#include "stm32f446xx_ADC.h"
void ADC_CLOCK_ENABLE(ADC_TypeDef* ADCx){
	if(ADCx==ADC1){
		RCC->APB2ENR |=(1<<8);
	}
	else if(ADCx==ADC2){
		RCC->APB2ENR |=(1<<9);
	}
	else if(ADCx==ADC3){
		RCC->APB2ENR |=(1<<10);
	}
}


void ADC_init(ADC_TypeDef* ADCx,ADC_INIT init){
	ADC_CLOCK_ENABLE(ADCx);
	//Enable end of the conversion
	ADCx->CR1 |=(1<<5);
	//setting sampling rate
	if(init.ADC_channel<=9){
		ADCx->SMPR2 |=init.ADC_SAMPLE_RATE<<(init.ADC_channel*3);
	}
	else{
		ADCx->SMPR1 |=init.ADC_SAMPLE_RATE<<((init.ADC_channel%10)*3);
	}
	//setting up sequence
	ADCx->SQR3  |=init.ADC_channel;
	//enable adc and set it in continuous mode
	ADCx->CR2 |=1<<1;//continuous mode
	ADCx->CR2 |=1;//enable ADC
	for(int i=0;i<500;i++);
	//again enable once
	ADCx->CR2 |=1;
	for(int i=0;i<500;i++);
}

void ADC_START(ADC_TypeDef* ADCx){
	ADCx->CR2 |=(1<<30);
}
