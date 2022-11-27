################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/DoutH/DoutH.c 

OBJS += \
./IOServices/DoutH/DoutH.o 

C_DEPS += \
./IOServices/DoutH/DoutH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/DoutH/%.o IOServices/DoutH/%.su: ../IOServices/DoutH/%.c IOServices/DoutH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/DoutH/DoutH.c_includes.args"

clean: clean-IOServices-2f-DoutH

clean-IOServices-2f-DoutH:
	-$(RM) ./IOServices/DoutH/DoutH.d ./IOServices/DoutH/DoutH.o ./IOServices/DoutH/DoutH.su

.PHONY: clean-IOServices-2f-DoutH

