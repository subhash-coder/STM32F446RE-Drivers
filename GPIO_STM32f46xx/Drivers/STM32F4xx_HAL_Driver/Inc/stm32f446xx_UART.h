/*
 * stm32f446xx_UART.h
 *
 *  Created on: Oct 14, 2021
 *      Author: subhash
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F446XX_UART_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F446XX_UART_H_
#include "stm32f446xx.h"
#include "stm32f446xx_GPIO.h"

typedef struct{
	uint8_t USART_MODE;
	uint32_t USART_BAUD;
	uint32_t USART_NO_STOP_BITS;
	uint32_t USART_WORD_LENGTH;
	uint32_t USART_PARITY_CONTROL;
	uint32_t USART_HWFLOW_CONTROL;
}USART_INIT;

#define USART_MODE_TX				0
#define USART_MODE_RX				1
#define USART_MODE_RX_TX			2

#define USART_BAUD_9600				9600

#define USART_BAUD_115200			115200


#define USART_PARITY_EN_ODD 		1
#define USART_PARITY_EN_EVEN		2
#define USART_PARITY_DISABLE		3
#define USART_PARITY_ENABLE		4

#define USART_WORDLEN_8BITS			0
#define USART_WORDLEN_9BITS			1

#define USART_STOPBITS_1			0
#define USART_STOPBITS_0_5			1
#define USART_STOPBITS_2			2
#define USART_STOPBITS_1_5			3

#define USART_HW_FLOW_CTRL_NONE    	0
#define USART_HW_FLOW_CTRL_CTS    	1
#define USART_HW_FLOW_CTRL_RTS    	2
#define USART_HW_FLOW_CTRL_CTS_RTS	3

#define USART_FLAG_TXE 			( 1 << USART_SR_TXE)
#define USART_FLAG_RXNE 		( 1 << USART_SR_RXNE)
#define USART_FLAG_TC 			( 1 << USART_SR_TC)

#define USART_BUSY_IN_RX 1
#define USART_BUSY_IN_TX 2
#define USART_READY 0

#define 	USART_EVENT_TX_CMPLT   	0
#define		USART_EVENT_RX_CMPLT   	1
#define		USART_EVENT_IDLE     	2
#define		USART_EVENT_CTS       	3
#define		USART_EVENT_PE        	4
#define		USART_ERR_FE     		5
#define		USART_ERR_NE    	 	6
#define		USART_ERR_ORE    		7

void USART_init(USART_TypeDef* USARTx,USART_INIT init);
void USART_TX(USART_TypeDef* USARTx,uint8_t data);
void USART_RX(USART_TypeDef* USARTx,uint8_t* pData);
void USART_CLK_ENABLE(USART_TypeDef* USARTx);
void USART_ENABLE(USART_TypeDef* USARTx);
void UART2_INIT();


#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F446XX_UART_H_ */
