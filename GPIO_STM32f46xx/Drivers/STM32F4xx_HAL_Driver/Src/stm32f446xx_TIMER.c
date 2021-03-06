/*
 * stm32f446xx_TIMER.c
 *
 *  Created on: Oct 17, 2021
 *      Author: subhash
 */

#include "stm32f446xx_TIMER.h"




void Timer_peripheral_clk(TIM_TypeDef* TIMx){
	if(TIMx == TIM11){
		RCC->APB2ENR |=(1<<18);
	}
	else if(TIMx == TIM10){
		RCC->APB2ENR |=(1<<17);
	}
	else if(TIMx == TIM9){
		//APB2
		RCC->APB2ENR |=(1<<16);
	}
	else if(TIMx == TIM8){
		RCC->APB2ENR |=(1<<1);
	}
	else if(TIMx == TIM1){
		//APB2
		RCC->APB2ENR |=(1<<0);
	}
	else if(TIMx == TIM14){
		RCC->APB1ENR |=(1<<8);
	}
	else if(TIMx == TIM13){
		RCC->APB1ENR |=(1<<7);
	}
	else if(TIMx == TIM12){
		RCC->APB1ENR |=(1<<6);
	}
	else if(TIMx == TIM7){
		RCC->APB1ENR |=(1<<5);
	}
	else if(TIMx == TIM6){
		RCC->APB1ENR |=(1<<4);
	}
	else if(TIMx == TIM5){
		RCC->APB1ENR |=(1<<3);
	}
	else if(TIMx == TIM4){
		RCC->APB1ENR |=(1<<2);
	}
	else if(TIMx == TIM3){
		RCC->APB1ENR |=(1<<1);
	}
	else if(TIMx == TIM2){
		//APB1
		RCC->APB1ENR |=(1<<0);
	}
}





void PWM_init(TIM_TypeDef* TIMx,PWM_INIT init){
	Timer_peripheral_clk(TIMx);
	///setting PSC and ARR
	TIMx->PSC =init.PSC;
	TIMx->ARR =init.ARR;
	//setup duty cycle and enabling capture compare
    TIMx->CCER |=(1<<((init.channel-1)*4));
    if(init.channel==1){
    	TIMx->CCR1 =init.CCR;
    }
    else if(init.channel ==2){
    	TIMx->CCR2 =init.CCR;
    }
    else if(init.channel ==3){
    	TIMx->CCR3 =init.CCR;
    }
    else if(init.channel ==4){
    	TIMx->CCR4 =init.CCR;
    }
    //setting up PWM mode
    if(init.channel == 1 ){
    	TIMx->CCMR1 |=(init.PWM_MODE<<4);
    	TIMx->CCMR1 |=(1<<3);
    }
    else if( init.channel == 2){
    	TIMx->CCMR1 |=(init.PWM_MODE<<12);
    	TIMx->CCMR1 |=(1<<11);
    }
    else if(init.channel == 3){
    	TIMx->CCMR2 |=(init.PWM_MODE<<4);
    	TIMx->CCMR2 |=(1<<3);
    }
    else if(init.channel == 4){
    	TIMx->CCMR2 |=(init.PWM_MODE<<12);
    	TIMx->CCMR2 |=(1<<11);
    }
    //set ARPE
    TIMx->CR1 |=(1<<7);
    //set UG bit in EGR
    TIMx->EGR |=1;
}

void PWM_START(TIM_TypeDef* TIMx){
	TIMx->CR1 |=1;
}
void PWM_DUTY(TIM_TypeDef* TIMx,uint32_t data,PWM_INIT init){
	if(init.channel==1){
		TIMx->CCR1 =data;
	}
	else if(init.channel == 2){
		TIMx->CCR2 =data;
	}
	else if (init.channel == 3){
		TIMx->CCR3 =data;
	}
	else if (init.channel == 4){
		TIMx->CCR4 =data;
	}
}


