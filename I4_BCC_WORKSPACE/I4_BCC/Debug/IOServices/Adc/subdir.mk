################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Adc/AdcH.c 

OBJS += \
./IOServices/Adc/AdcH.o 

C_DEPS += \
./IOServices/Adc/AdcH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Adc/%.o IOServices/Adc/%.su: ../IOServices/Adc/%.c IOServices/Adc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Adc/AdcH.c_includes.args"

clean: clean-IOServices-2f-Adc

clean-IOServices-2f-Adc:
	-$(RM) ./IOServices/Adc/AdcH.d ./IOServices/Adc/AdcH.o ./IOServices/Adc/AdcH.su

.PHONY: clean-IOServices-2f-Adc

