################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/HVAC/HVAC.c 

OBJS += \
./ApplicationLayer/HVAC/HVAC.o 

C_DEPS += \
./ApplicationLayer/HVAC/HVAC.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/HVAC/%.o ApplicationLayer/HVAC/%.su: ../ApplicationLayer/HVAC/%.c ApplicationLayer/HVAC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/HVAC/HVAC.c_includes.args"

clean: clean-ApplicationLayer-2f-HVAC

clean-ApplicationLayer-2f-HVAC:
	-$(RM) ./ApplicationLayer/HVAC/HVAC.d ./ApplicationLayer/HVAC/HVAC.o ./ApplicationLayer/HVAC/HVAC.su

.PHONY: clean-ApplicationLayer-2f-HVAC

