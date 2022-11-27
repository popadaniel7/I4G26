################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/VibSen/VibSen.c 

OBJS += \
./ApplicationLayer/VibSen/VibSen.o 

C_DEPS += \
./ApplicationLayer/VibSen/VibSen.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/VibSen/%.o ApplicationLayer/VibSen/%.su: ../ApplicationLayer/VibSen/%.c ApplicationLayer/VibSen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/VibSen/VibSen.c_includes.args"

clean: clean-ApplicationLayer-2f-VibSen

clean-ApplicationLayer-2f-VibSen:
	-$(RM) ./ApplicationLayer/VibSen/VibSen.d ./ApplicationLayer/VibSen/VibSen.o ./ApplicationLayer/VibSen/VibSen.su

.PHONY: clean-ApplicationLayer-2f-VibSen

