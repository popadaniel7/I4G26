################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/ErrorManagement/ErrorManagement.c 

OBJS += \
./SystemServices/ErrorManagement/ErrorManagement.o 

C_DEPS += \
./SystemServices/ErrorManagement/ErrorManagement.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/ErrorManagement/%.o SystemServices/ErrorManagement/%.su: ../SystemServices/ErrorManagement/%.c SystemServices/ErrorManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/ErrorManagement/ErrorManagement.c_includes.args"

clean: clean-SystemServices-2f-ErrorManagement

clean-SystemServices-2f-ErrorManagement:
	-$(RM) ./SystemServices/ErrorManagement/ErrorManagement.d ./SystemServices/ErrorManagement/ErrorManagement.o ./SystemServices/ErrorManagement/ErrorManagement.su

.PHONY: clean-SystemServices-2f-ErrorManagement

