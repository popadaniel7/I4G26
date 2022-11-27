################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommunicationServices/Lin/Lin.c 

OBJS += \
./CommunicationServices/Lin/Lin.o 

C_DEPS += \
./CommunicationServices/Lin/Lin.d 


# Each subdirectory must supply rules for building sources it contributes
CommunicationServices/Lin/%.o CommunicationServices/Lin/%.su: ../CommunicationServices/Lin/%.c CommunicationServices/Lin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"CommunicationServices/Lin/Lin.c_includes.args"

clean: clean-CommunicationServices-2f-Lin

clean-CommunicationServices-2f-Lin:
	-$(RM) ./CommunicationServices/Lin/Lin.d ./CommunicationServices/Lin/Lin.o ./CommunicationServices/Lin/Lin.su

.PHONY: clean-CommunicationServices-2f-Lin

