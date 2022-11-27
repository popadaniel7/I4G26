################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/VoltH/VoltH.c 

OBJS += \
./ApplicationLayer/VoltH/VoltH.o 

C_DEPS += \
./ApplicationLayer/VoltH/VoltH.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/VoltH/%.o ApplicationLayer/VoltH/%.su: ../ApplicationLayer/VoltH/%.c ApplicationLayer/VoltH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/VoltH/VoltH.c_includes.args"

clean: clean-ApplicationLayer-2f-VoltH

clean-ApplicationLayer-2f-VoltH:
	-$(RM) ./ApplicationLayer/VoltH/VoltH.d ./ApplicationLayer/VoltH/VoltH.o ./ApplicationLayer/VoltH/VoltH.su

.PHONY: clean-ApplicationLayer-2f-VoltH

