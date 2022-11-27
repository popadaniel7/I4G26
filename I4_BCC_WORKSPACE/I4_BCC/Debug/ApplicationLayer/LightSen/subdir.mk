################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/LightSen/LightSen.c 

OBJS += \
./ApplicationLayer/LightSen/LightSen.o 

C_DEPS += \
./ApplicationLayer/LightSen/LightSen.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/LightSen/%.o ApplicationLayer/LightSen/%.su: ../ApplicationLayer/LightSen/%.c ApplicationLayer/LightSen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/LightSen/LightSen.c_includes.args"

clean: clean-ApplicationLayer-2f-LightSen

clean-ApplicationLayer-2f-LightSen:
	-$(RM) ./ApplicationLayer/LightSen/LightSen.d ./ApplicationLayer/LightSen/LightSen.o ./ApplicationLayer/LightSen/LightSen.su

.PHONY: clean-ApplicationLayer-2f-LightSen

