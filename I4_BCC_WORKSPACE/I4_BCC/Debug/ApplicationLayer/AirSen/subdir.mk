################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/AirSen/AirSen.c 

OBJS += \
./ApplicationLayer/AirSen/AirSen.o 

C_DEPS += \
./ApplicationLayer/AirSen/AirSen.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/AirSen/%.o ApplicationLayer/AirSen/%.su: ../ApplicationLayer/AirSen/%.c ApplicationLayer/AirSen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/AirSen/AirSen.c_includes.args"

clean: clean-ApplicationLayer-2f-AirSen

clean-ApplicationLayer-2f-AirSen:
	-$(RM) ./ApplicationLayer/AirSen/AirSen.d ./ApplicationLayer/AirSen/AirSen.o ./ApplicationLayer/AirSen/AirSen.su

.PHONY: clean-ApplicationLayer-2f-AirSen

