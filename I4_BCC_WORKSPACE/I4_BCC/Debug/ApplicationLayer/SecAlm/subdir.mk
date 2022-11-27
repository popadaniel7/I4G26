################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/SecAlm/SecAlm.c 

OBJS += \
./ApplicationLayer/SecAlm/SecAlm.o 

C_DEPS += \
./ApplicationLayer/SecAlm/SecAlm.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/SecAlm/%.o ApplicationLayer/SecAlm/%.su: ../ApplicationLayer/SecAlm/%.c ApplicationLayer/SecAlm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/SecAlm/SecAlm.c_includes.args"

clean: clean-ApplicationLayer-2f-SecAlm

clean-ApplicationLayer-2f-SecAlm:
	-$(RM) ./ApplicationLayer/SecAlm/SecAlm.d ./ApplicationLayer/SecAlm/SecAlm.o ./ApplicationLayer/SecAlm/SecAlm.su

.PHONY: clean-ApplicationLayer-2f-SecAlm

