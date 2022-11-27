################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/RainSen/RainSen.c 

OBJS += \
./ApplicationLayer/RainSen/RainSen.o 

C_DEPS += \
./ApplicationLayer/RainSen/RainSen.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/RainSen/%.o ApplicationLayer/RainSen/%.su: ../ApplicationLayer/RainSen/%.c ApplicationLayer/RainSen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/RainSen/RainSen.c_includes.args"

clean: clean-ApplicationLayer-2f-RainSen

clean-ApplicationLayer-2f-RainSen:
	-$(RM) ./ApplicationLayer/RainSen/RainSen.d ./ApplicationLayer/RainSen/RainSen.o ./ApplicationLayer/RainSen/RainSen.su

.PHONY: clean-ApplicationLayer-2f-RainSen

