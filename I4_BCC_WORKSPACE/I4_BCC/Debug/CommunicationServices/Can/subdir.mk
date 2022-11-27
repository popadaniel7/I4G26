################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommunicationServices/Can/Can.c 

OBJS += \
./CommunicationServices/Can/Can.o 

C_DEPS += \
./CommunicationServices/Can/Can.d 


# Each subdirectory must supply rules for building sources it contributes
CommunicationServices/Can/%.o CommunicationServices/Can/%.su: ../CommunicationServices/Can/%.c CommunicationServices/Can/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"CommunicationServices/Can/Can.c_includes.args"

clean: clean-CommunicationServices-2f-Can

clean-CommunicationServices-2f-Can:
	-$(RM) ./CommunicationServices/Can/Can.d ./CommunicationServices/Can/Can.o ./CommunicationServices/Can/Can.su

.PHONY: clean-CommunicationServices-2f-Can

