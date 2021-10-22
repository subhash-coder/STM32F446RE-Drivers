################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.c \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.o \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.d \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_ADC.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_DAC.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_GPIO.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_I2C.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_TIMER.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.o: ../Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.c Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32F4xx_HAL_Driver/Src/stm32f446xx_UART.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

