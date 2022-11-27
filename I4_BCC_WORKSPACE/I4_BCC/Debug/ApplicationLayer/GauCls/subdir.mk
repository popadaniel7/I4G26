################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/GauCls/GauCls.c 

OBJS += \
./ApplicationLayer/GauCls/GauCls.o 

C_DEPS += \
./ApplicationLayer/GauCls/GauCls.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/GauCls/%.o ApplicationLayer/GauCls/%.su: ../ApplicationLayer/GauCls/%.c ApplicationLayer/GauCls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/GauCls/GauCls.c_includes.args"

clean: clean-ApplicationLayer-2f-GauCls

clean-ApplicationLayer-2f-GauCls:
	-$(RM) ./ApplicationLayer/GauCls/GauCls.d ./ApplicationLayer/GauCls/GauCls.o ./ApplicationLayer/GauCls/GauCls.su

.PHONY: clean-ApplicationLayer-2f-GauCls

