/*
 * main.c
 *
 *  Created on: Oct 14, 2021
 *      Author: subhash
 */


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "stm32f446xx_GPIO.h"
#include "stm32f446xx_UART.h"
#include "stm32f446xx_ADC.h"
#include "stm32f446xx_DAC.h"
#include "stm32f446xx_TIMER.h"
#include "stm32f446xx_I2C.h"
extern void initialise_monitor_handles(void);
uint16_t msTicks=0;
void delayMs(uint16_t Ms){
	msTicks=0;
	while(msTicks<Ms);
}
#define MPU6050_REG_POWER			0x6B
#define MPU6050_REG_ACCEL_CONFIG	0x1C
#define MPU6050_REG_GYRO_CONFIG		0x1B
//These are the MPU6050_address of mpu6050 from which you will fetch accelerometer x,y,x high and low values
#define MPU6050_REG_ACC_X_HIGH		0x3B
#define MPU6050_REG_ACC_X_LOW		0x3C
#define MPU6050_REG_ACC_Y_HIGH		0x3D
#define MPU6050_REG_ACC_Y_LOW		0x3E
#define MPU6050_REG_ACC_Z_HIGH		0x3F
#define MPU6050_REG_ACC_Z_LOW		0x40
//These are the MPU6050_addresses of mpu6050 from which you will fetch gyro x,y,x high and low values
#define MPU6050_REG_GYRO_X_HIGH		0x43
#define MPU6050_REG_GYRO_X_LOW		0x44
#define MPU6050_REG_GYRO_Y_HIGH		0x45
#define MPU6050_REG_GYRO_Y_LOW		0x46
#define MPU6050_REG_GYRO_Z_HIGH		0x47
#define MPU6050_REG_GYRO_Z_LOW		0x48
/*
 * Different full scale ranges for acc and gyro
 * refer table 6.2 and 6.3 in the document MPU-6050 Product Specification Reveision 3.4
 */
#define ACC_FS_SENSITIVITY_0		16384
#define ACC_FS_SENSITIVITY_1		8192
#define ACC_FS_SENSITIVITY_2		4096
#define ACC_FS_SENSITIVITY_3		2048

#define GYR_FS_SENSITIVITY_0		131
#define GYR_FS_SENSITIVITY_1		65.5
#define GYR_FS_SENSITIVITY_2		32.8
#define GYR_FS_SENSITIVITY_3		16.4

/*This is the I2C slave address of mpu6050 sensor*/
uint8_t MPU6050_address=0x68;

#define MAX_VALUE	50
void mpu6050_read_mul(uint8_t register_address,uint8_t* temp,int count);
void mpu6050_write(uint8_t register_address,uint8_t data);
void mpu6050_read(uint8_t register_address,uint8_t* data);
void mpu6050_init(I2C_TypeDef* I2Cx);
void I2C1_init();
void mpu6050_read_acc(short* acc);
void mpu6050_read_gyro(short* gyro);
void I2C_read(I2C_TypeDef* I2Cx,uint8_t slave_address,uint8_t register_address,uint8_t* bucket,int count);
int main(){
	//PB6 clk
	//PB7 SDA
 	initialise_monitor_handles();
 	I2C1_init();
    mpu6050_init(I2C1);
    uint8_t bucket[6];
    uint8_t bucket1[6];
    short accel[3];
    short gyro[3];
   while(1){

	   I2C_read(I2C1, MPU6050_address, MPU6050_REG_ACC_X_HIGH, bucket, 6);
	   I2C_read(I2C1,MPU6050_address,MPU6050_REG_GYRO_X_HIGH,bucket1,6);


	   for(int i=0;i<3;i++){
	      	accel[i]=0;
	      	accel[i]|=(bucket[i*2]<<8);
	      	accel[i]|=(bucket[(i*2)+1]);
	   }
	   for(int i=0;i<3;i++){
	   	      	gyro[i]=0;
	   	    	gyro[i]|=(bucket1[i*2]<<8);
	   	    	gyro[i]|=(bucket1[(i*2)+1]);
	   	   }

	  printf("ACCE X:%f Y:%f Z:%f\n\n",(float)accel[0]/ACC_FS_SENSITIVITY_3,(float)accel[1]/ACC_FS_SENSITIVITY_3,(float)accel[2]/ACC_FS_SENSITIVITY_3);
	  printf("GYRO X:%f Y:%f Z:%f\n\n",(float)gyro[0]/GYR_FS_SENSITIVITY_3,(float)gyro[1]/GYR_FS_SENSITIVITY_3,(float)gyro[2]/GYR_FS_SENSITIVITY_3);


   }
}
void SysTick_Handler(void){
	msTicks++;
}
void mpu6050_init(I2C_TypeDef* I2Cx){
	//1. disable sleep mode
	mpu6050_write(MPU6050_REG_POWER,0x00);
	//2. config accel
	mpu6050_write(MPU6050_REG_ACCEL_CONFIG, 0x18);
	//3.config gyro
	mpu6050_write(MPU6050_REG_GYRO_CONFIG, 0x18);
}
void mpu6050_write(uint8_t register_address,uint8_t data){
	I2C_start(I2C1);
	I2C_write_init(I2C1, MPU6050_address);
	I2C_send(I2C1,register_address);
	I2C_send(I2C1, data);
	I2C_stop(I2C1);
}
void mpu6050_read(uint8_t register_address,uint8_t* data){
	I2C_start(I2C1);
	I2C_write_init(I2C1, MPU6050_address);
	I2C_send(I2C1, register_address);
	I2C_start(I2C1);
	I2C_read_init(I2C1,MPU6050_address);
	I2C_Disable_ACK(I2C1);
	I2C_receive(I2C1,data);
	I2C_stop(I2C1);
	//dont forgot to disable nack if its ack outside of this function
}
void I2C1_init(){
		__RCC_GPIOB_CLK_ENABLE();
	 	GPIO_INIT init;
	 	init.GPIO_ALTFUNC=4;
	 	init.GPIO_MODE=GPIO_MODE_ALT;
	 	init.GPIO_OPTYPE=GPIO_OPEN_DRAIN;
	 	init.GPIO_OP_PUSH_PULL=GPIO_PULL_UP;
	 	init.GPIO_PIN=6;
	 	init.GPIO_SPEED=GPIO_FAST_SPEED;
	    GPIO_ALT_INIT(GPIOB, init);
	    GPIO_init(GPIOB, init);
	    init.GPIO_PIN=7;
	    GPIO_ALT_INIT(GPIOB, init);
	    GPIO_init(GPIOB, init);
	    I2C_init(I2C1);
}
void I2C_read(I2C_TypeDef* I2Cx,uint8_t slave_address,uint8_t register_address,uint8_t* bucket,int count){
		I2C_Enable_ACK(I2Cx);
		I2C_start(I2Cx);
		I2C_write_init(I2Cx, MPU6050_address);
		I2C_send(I2C1, register_address);
		I2C_start(I2C1);
		//read init
		I2Cx->DR=((MPU6050_address<<1)|1);
		uint32_t temp;


		if(count==1){
			//wait and clear address flag
			while(!(I2Cx->SR1 & (1<<1)));
			temp=I2Cx->SR2;

			I2C_Disable_ACK(I2Cx);
			while(!(I2Cx->SR1 & (1<<6)));

			mpu6050_read(register_address, bucket);
			//already sent stop bit
		}
		else if (count==2){
			//wait and clear address flag
			while(!(I2Cx->SR1 & (1<<1)));

			//enable pos disable ack
			I2C_Disable_ACK(I2Cx);
			I2Cx->CR1 |=(1<<11);

			//wait and clear address flag
			temp=I2Cx->SR2;
			//wait till BTF is set
			while(!(I2Cx->SR1 & (1<<2)));

			I2C_stop(I2Cx);
			for(int i=0;i<2;i++){
				while(!(I2Cx->SR1 & (1<<6)));
				bucket[i]=I2Cx->DR;
			}

		}//already sent stop bit

		else if(count>1){
			//wait and clear address flag
			while(!(I2Cx->SR1 & (1<<1)));
			temp=I2Cx->SR2;
			for(int i=count;i>0;i--){
				while(!(I2Cx->SR1 & (1<<6)));

				if(i==3){
					//wait till BTF is set
					while(!(I2Cx->SR1 & (1<<2)));

					I2C_Disable_ACK(I2Cx);
					//read n-2
					bucket[count-i]=I2Cx->DR;
					//wait till BTF is set
					while(!(I2Cx->SR1 & (1<<2)));
					I2C_stop(I2Cx);

					bucket[count-i+1]=I2Cx->DR;
					while(!(I2Cx->SR1 & (1<<6)));
					bucket[count-i+2]=I2Cx->DR;
					break;

				}
				bucket[count-i]=I2Cx->DR;

			}
		}
		//clear POS
		I2Cx->CR1 &=~(1<<11);

}
