################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/TemSen/TemSen.c 

OBJS += \
./ApplicationLayer/TemSen/TemSen.o 

C_DEPS += \
./ApplicationLayer/TemSen/TemSen.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/TemSen/%.o ApplicationLayer/TemSen/%.su: ../ApplicationLayer/TemSen/%.c ApplicationLayer/TemSen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/TemSen/TemSen.c_includes.args"

clean: clean-ApplicationLayer-2f-TemSen

clean-ApplicationLayer-2f-TemSen:
	-$(RM) ./ApplicationLayer/TemSen/TemSen.d ./ApplicationLayer/TemSen/TemSen.o ./ApplicationLayer/TemSen/TemSen.su

.PHONY: clean-ApplicationLayer-2f-TemSen

