################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommunicationServices/I2c/I2c.c 

OBJS += \
./CommunicationServices/I2c/I2c.o 

C_DEPS += \
./CommunicationServices/I2c/I2c.d 


# Each subdirectory must supply rules for building sources it contributes
CommunicationServices/I2c/%.o CommunicationServices/I2c/%.su: ../CommunicationServices/I2c/%.c CommunicationServices/I2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"CommunicationServices/I2c/I2c.c_includes.args"

clean: clean-CommunicationServices-2f-I2c

clean-CommunicationServices-2f-I2c:
	-$(RM) ./CommunicationServices/I2c/I2c.d ./CommunicationServices/I2c/I2c.o ./CommunicationServices/I2c/I2c.su

.PHONY: clean-CommunicationServices-2f-I2c

