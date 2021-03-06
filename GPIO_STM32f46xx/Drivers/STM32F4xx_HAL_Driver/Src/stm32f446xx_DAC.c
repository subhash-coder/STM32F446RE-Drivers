/*
 * stm32f446xx_DAC.c
 *
 *  Created on: Oct 16, 2021
 *      Author: subhash
 */
#include "stm32f446xx_DAC.h"
void DAC_init(DAC_TypeDef* DACx,DAC_INIT init){
	//DAC RCC Enable
	RCC->APB1ENR |=(1<<29);
	if(init.software_trigger==DAC_SOFTWARE_TRIGGER_ENABLE){
		if(init.channel==DAC_CHANNEL_1){
			//Trigger enable
			DACx->CR |=(1<<2);
			//mode of trigger
			DACx->CR |=(7<<3);
		}
		else if(init.channel == DAC_CHANNEL_2){
			//Trigger enable
			DACx->CR |=(1<<18);
			//mode of trigger
			DACx->CR |=(7<<19);
		}

	}
	//DAC ENABLE
	if(init.channel==DAC_CHANNEL_1){
		DACx->CR |=1;
	}
	else if(init.channel == DAC_CHANNEL_2){
		DACx->CR |=1<<16;
	}
}

void DAC_OUT(DAC_TypeDef* DACx,uint8_t data,DAC_INIT init){
	//printf("%lu\n",val);
	//use this formula to set into 1byte
	//(val*255)/4096;
	//DAC_DHR8R1
	if(init.channel==DAC_CHANNEL_1){
		DACx->DHR8R1 = data;
	}
	else if(init.channel == DAC_CHANNEL_2){
		DACx->DHR8R2 =data;
	}

	if(init.software_trigger==DAC_SOFTWARE_TRIGGER_ENABLE){
		if(init.channel==DAC_CHANNEL_1){
			DACx->SWTRIGR |=1;
			}
			else if(init.channel == DAC_CHANNEL_2){
				DACx->SWTRIGR |=1<<1;
		//DAC SWTRIGER

		while((DACx->SWTRIGR & 1));
	}

}
}
