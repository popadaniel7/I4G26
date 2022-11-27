################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/IntLights/IntLights.c 

OBJS += \
./ApplicationLayer/IntLights/IntLights.o 

C_DEPS += \
./ApplicationLayer/IntLights/IntLights.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/IntLights/%.o ApplicationLayer/IntLights/%.su: ../ApplicationLayer/IntLights/%.c ApplicationLayer/IntLights/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/IntLights/IntLights.c_includes.args"

clean: clean-ApplicationLayer-2f-IntLights

clean-ApplicationLayer-2f-IntLights:
	-$(RM) ./ApplicationLayer/IntLights/IntLights.d ./ApplicationLayer/IntLights/IntLights.o ./ApplicationLayer/IntLights/IntLights.su

.PHONY: clean-ApplicationLayer-2f-IntLights

