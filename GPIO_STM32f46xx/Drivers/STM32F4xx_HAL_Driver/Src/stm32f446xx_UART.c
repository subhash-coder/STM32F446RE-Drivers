/*
 * stm32f446xx_UART.c
 *
 *  Created on: Oct 14, 2021
 *      Author: subhash
 */

#include "stm32f446xx_UART.h"

void USART_CLK_ENABLE(USART_TypeDef* USARTx){
	if(USARTx == USART2){
		RCC->APB1ENR |=(1<<17);
	}

	else if(USARTx == USART3){
		RCC->APB1ENR |=(1<<18);
	}
	else if(USARTx == UART4){
		RCC->APB1ENR |=(1<<19);
	}
	else if(USARTx == UART5){
		RCC->APB1ENR |=(1<<20);
	}
}


void USART_init(USART_TypeDef* USARTx,USART_INIT init){
	USART_CLK_ENABLE(USARTx);
	//1.setup mode tx or rx
	if(init.USART_MODE == USART_MODE_TX){
		USARTx->CR1 |=(1<<3);
	}
	else if(init.USART_MODE == USART_MODE_RX){
		USARTx->CR1 |=(1<<2);
	}
	else{
		USARTx->CR1 |=(1<<3);
		USARTx->CR1 |=(1<<2);
	}
	//2.setup baud
	if(init.USART_BAUD ==USART_BAUD_9600){
			//for over sampling 16
		 	//Setting up USARTDIV
		    USARTx->BRR |=(104<<4);
		    USARTx->BRR |=(2);
	}
	else if(init.USART_BAUD==USART_BAUD_115200){
			USARTx->BRR |=(8<<4);
			USARTx->BRR |=(10);
	}
	//3.No of stop bits
	if(init.USART_NO_STOP_BITS==USART_STOPBITS_0_5){
		USARTx->CR2 |=(1<<12);
	}
	else if(init.USART_NO_STOP_BITS == USART_STOPBITS_2){
		USARTx->CR2 |=(2<<12);
	}
	else if(init.USART_NO_STOP_BITS == USART_STOPBITS_1_5){
		USARTx->CR2 |=(3<<12);
	}
	//4.word length
	if(init.USART_WORD_LENGTH == USART_WORDLEN_9BITS){
		USARTx->CR1 |=(1<<12);
	}
	//5.parity control
	if(init.USART_PARITY_CONTROL == USART_PARITY_ENABLE){
		USARTx->CR1 |=(1<<10);
	}
	//6.Hardware flow control
	if(init.USART_HWFLOW_CONTROL == USART_HW_FLOW_CTRL_CTS){
		USARTx->CR3 |=(1<<9);
	}
	else if(init.USART_HWFLOW_CONTROL == USART_HW_FLOW_CTRL_RTS){
		USARTx->CR3 |=(1<<8);
	}
	else if(init.USART_HWFLOW_CONTROL == USART_HW_FLOW_CTRL_CTS_RTS){
		USARTx->CR3 |=(1<<9);
		USARTx->CR3 |=(1<<8);
	}
}

void USART_TX(USART_TypeDef* USARTx,uint8_t data){
	while(!(USARTx->SR & (1<<7)));
	USARTx->DR=data;
	while(!(USARTx->SR & (1<<6)));
}

void USART_RX(USART_TypeDef* USARTx,uint8_t* pData){
	while(!(USARTx->SR & (1<<5)));
	uint8_t ch=USART2->DR;
	*pData=(char)ch;


}
void USART_ENABLE(USART_TypeDef* USARTx){
	 USARTx->CR1 |=(1<<13);
}

void UART2_INIT(){ // Enable it after using this using USART_ENABLE
	RCC->APB1ENR |=(1<<17);
		__RCC_GPIOA_CLK_ENABLE();
		GPIO_INIT init;
		init.GPIO_ALTFUNC=7;
		init.GPIO_MODE=GPIO_MODE_ALT;
		init.GPIO_OPTYPE=GPIO_PUSH_PULL;
		init.GPIO_OP_PUSH_PULL=GPIO_PULL_UP;
		init.GPIO_PIN=2;
		init.GPIO_SPEED=GPIO_FAST_SPEED;
		GPIO_init(GPIOA, init);
		GPIO_ALT_INIT(GPIOA, init);
	    init.GPIO_PIN=3;
	    GPIO_init(GPIOA, init);
	    GPIO_ALT_INIT(GPIOA, init);

	    USART_INIT Init;
	    Init.USART_BAUD=USART_BAUD_9600;
	    Init.USART_HWFLOW_CONTROL=USART_HW_FLOW_CTRL_NONE;
	    Init.USART_MODE=USART_MODE_RX_TX;
	    Init.USART_NO_STOP_BITS=USART_STOPBITS_1;
	    Init.USART_PARITY_CONTROL=USART_PARITY_DISABLE;
	    Init.USART_WORD_LENGTH=USART_WORDLEN_8BITS;
	    USART_init(USART2, Init);
}
