################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/AirQty/AirQty.c 

OBJS += \
./ApplicationLayer/AirQty/AirQty.o 

C_DEPS += \
./ApplicationLayer/AirQty/AirQty.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/AirQty/%.o ApplicationLayer/AirQty/%.su: ../ApplicationLayer/AirQty/%.c ApplicationLayer/AirQty/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/AirQty/AirQty.c_includes.args"

clean: clean-ApplicationLayer-2f-AirQty

clean-ApplicationLayer-2f-AirQty:
	-$(RM) ./ApplicationLayer/AirQty/AirQty.d ./ApplicationLayer/AirQty/AirQty.o ./ApplicationLayer/AirQty/AirQty.su

.PHONY: clean-ApplicationLayer-2f-AirQty

