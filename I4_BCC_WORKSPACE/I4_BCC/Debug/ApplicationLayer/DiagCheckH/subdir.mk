################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/DiagCheckH/DiagCheckH.c 

OBJS += \
./ApplicationLayer/DiagCheckH/DiagCheckH.o 

C_DEPS += \
./ApplicationLayer/DiagCheckH/DiagCheckH.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/DiagCheckH/%.o ApplicationLayer/DiagCheckH/%.su: ../ApplicationLayer/DiagCheckH/%.c ApplicationLayer/DiagCheckH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/DiagCheckH/DiagCheckH.c_includes.args"

clean: clean-ApplicationLayer-2f-DiagCheckH

clean-ApplicationLayer-2f-DiagCheckH:
	-$(RM) ./ApplicationLayer/DiagCheckH/DiagCheckH.d ./ApplicationLayer/DiagCheckH/DiagCheckH.o ./ApplicationLayer/DiagCheckH/DiagCheckH.su

.PHONY: clean-ApplicationLayer-2f-DiagCheckH

