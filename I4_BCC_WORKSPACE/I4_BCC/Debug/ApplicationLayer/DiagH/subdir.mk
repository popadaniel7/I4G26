################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/DiagH/DiagH.c 

OBJS += \
./ApplicationLayer/DiagH/DiagH.o 

C_DEPS += \
./ApplicationLayer/DiagH/DiagH.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/DiagH/%.o ApplicationLayer/DiagH/%.su: ../ApplicationLayer/DiagH/%.c ApplicationLayer/DiagH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/DiagH/DiagH.c_includes.args"

clean: clean-ApplicationLayer-2f-DiagH

clean-ApplicationLayer-2f-DiagH:
	-$(RM) ./ApplicationLayer/DiagH/DiagH.d ./ApplicationLayer/DiagH/DiagH.o ./ApplicationLayer/DiagH/DiagH.su

.PHONY: clean-ApplicationLayer-2f-DiagH

