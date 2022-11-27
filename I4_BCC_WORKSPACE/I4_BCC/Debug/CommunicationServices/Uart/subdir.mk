################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommunicationServices/Uart/Uart.c 

OBJS += \
./CommunicationServices/Uart/Uart.o 

C_DEPS += \
./CommunicationServices/Uart/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
CommunicationServices/Uart/%.o CommunicationServices/Uart/%.su: ../CommunicationServices/Uart/%.c CommunicationServices/Uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"CommunicationServices/Uart/Uart.c_includes.args"

clean: clean-CommunicationServices-2f-Uart

clean-CommunicationServices-2f-Uart:
	-$(RM) ./CommunicationServices/Uart/Uart.d ./CommunicationServices/Uart/Uart.o ./CommunicationServices/Uart/Uart.su

.PHONY: clean-CommunicationServices-2f-Uart

