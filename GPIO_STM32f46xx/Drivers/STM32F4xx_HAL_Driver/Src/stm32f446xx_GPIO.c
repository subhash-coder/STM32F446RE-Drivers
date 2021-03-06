/*
 * stm32f446xx_GPIO.c
 *
 *  Created on: Oct 14, 2021
 *      Author: subhash
 */

#include "stm32f446xx_GPIO.h"

void GPIO_init(GPIO_TypeDef* GPIOx,GPIO_INIT Init){

	//1.PIN mode
	GPIOx->MODER |=(Init.GPIO_MODE <<(Init.GPIO_PIN*2));
	//2.PIN output type
	GPIOx->OTYPER |=(Init.GPIO_OPTYPE<<(Init.GPIO_PIN));
	//3.PIN speed
	GPIOx->OSPEEDR &=~(3<<(Init.GPIO_PIN*2));
	GPIOx->OSPEEDR |=(Init.GPIO_SPEED<<(Init.GPIO_PIN*2));
	//4.PIN PULL UP OR DOWN
	GPIOx->PUPDR &=~(3<<(Init.GPIO_PIN*2));
	GPIOx->PUPDR |=(Init.GPIO_OP_PUSH_PULL<<(Init.GPIO_PIN*2));


}



void LED_ON(){
	//PA5
	GPIOA->ODR |=(1<<5);
}
void LED_INIT(){
		__RCC_GPIOA_CLK_ENABLE();
	    GPIO_INIT Init;
	    Init.GPIO_MODE=GPIO_MODE_OUTPUT;
	    Init.GPIO_OPTYPE=GPIO_PUSH_PULL;
	    Init.GPIO_OP_PUSH_PULL=GPIO_NO_PUSH_PULL;
	    Init.GPIO_PIN=5;
	    Init.GPIO_SPEED=GPIO_FAST_SPEED;
	    GPIO_init(GPIOA, Init);
}
void LED_OFF(){
	GPIOA->ODR &=~(1<<5);
}
void LED_TOGGLE(){
	if((GPIOA->ODR & (1<<5))){
		LED_OFF();
	}
	else{
		LED_ON();
	}
}
void GPIO_OUTPUT_LOW(GPIO_TypeDef* GPIOx,uint8_t pin){
	GPIOx->ODR &=~(1<<pin);
}
void GPIO_OUTPUT_HIGH(GPIO_TypeDef* GPIOx,uint8_t pin){
	GPIOx->ODR |=(1<<pin);
}
uint32_t GPIO_INPUT(GPIO_TypeDef* GPIOx,uint8_t pin){
	return GPIOx->IDR &(1<<pin);
}
uint8_t EXTI_LINE(GPIO_TypeDef* GPIOx){
	if(GPIOx==GPIOA){
		return 0;
	}
	else if(GPIOx==GPIOB){
		return 1;
	}
	else if(GPIOx==GPIOC){
		return 2;
	}
	else if(GPIOx==GPIOD){
		return 3;
	}
	else if(GPIOx==GPIOE){
		return 4;
	}
	else if(GPIOx==GPIOF){
		return 5;
	}
	else {
		return 6;
	}
}
void GPIO_INTERRUPT_CONFIG(GPIO_TypeDef* GPIOx,GPIO_INIT init,uint8_t trigger){

	//Enable clock SYSCONFIG
	RCC->APB2ENR |=(1<<14);
	//1.Interrupt mask register
	EXTI->IMR |=(1<<init.GPIO_PIN);
	//2.rising trigger selection or falling or both
	if(trigger ==EXTI_RISING){
		EXTI->RTSR |=1<<init.GPIO_PIN;
	}
	else if(trigger ==EXTI_FALLING){
		EXTI->FTSR |=1<<init.GPIO_PIN;
	}
	else{
		EXTI->FTSR |=1<<init.GPIO_PIN;
		EXTI->RTSR |=1<<init.GPIO_PIN;
	}
	uint8_t temp=init.GPIO_PIN/4;
	SYSCFG->EXTICR[temp] &=~(15<<(init.GPIO_PIN%4));
	SYSCFG->EXTICR[temp] |=(EXTI_LINE(GPIOx)<<((init.GPIO_PIN%4)*4));

}
void GPIO_ALT_INIT(GPIO_TypeDef* GPIOx,GPIO_INIT init){
	GPIOx->AFR[init.GPIO_PIN/8] |=(init.GPIO_ALTFUNC<<((init.GPIO_PIN%8)*4));
}

