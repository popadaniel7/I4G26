################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/ExtLights/ExtLights.c 

OBJS += \
./ApplicationLayer/ExtLights/ExtLights.o 

C_DEPS += \
./ApplicationLayer/ExtLights/ExtLights.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/ExtLights/%.o ApplicationLayer/ExtLights/%.su: ../ApplicationLayer/ExtLights/%.c ApplicationLayer/ExtLights/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/ExtLights/ExtLights.c_includes.args"

clean: clean-ApplicationLayer-2f-ExtLights

clean-ApplicationLayer-2f-ExtLights:
	-$(RM) ./ApplicationLayer/ExtLights/ExtLights.d ./ApplicationLayer/ExtLights/ExtLights.o ./ApplicationLayer/ExtLights/ExtLights.su

.PHONY: clean-ApplicationLayer-2f-ExtLights

