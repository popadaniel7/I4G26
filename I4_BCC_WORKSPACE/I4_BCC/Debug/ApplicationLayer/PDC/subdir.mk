################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/PDC/PDC.c 

OBJS += \
./ApplicationLayer/PDC/PDC.o 

C_DEPS += \
./ApplicationLayer/PDC/PDC.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/PDC/%.o ApplicationLayer/PDC/%.su: ../ApplicationLayer/PDC/%.c ApplicationLayer/PDC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/PDC/PDC.c_includes.args"

clean: clean-ApplicationLayer-2f-PDC

clean-ApplicationLayer-2f-PDC:
	-$(RM) ./ApplicationLayer/PDC/PDC.d ./ApplicationLayer/PDC/PDC.o ./ApplicationLayer/PDC/PDC.su

.PHONY: clean-ApplicationLayer-2f-PDC

