################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/DinH/DinH.c 

OBJS += \
./IOServices/DinH/DinH.o 

C_DEPS += \
./IOServices/DinH/DinH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/DinH/%.o IOServices/DinH/%.su: ../IOServices/DinH/%.c IOServices/DinH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/DinH/DinH.c_includes.args"

clean: clean-IOServices-2f-DinH

clean-IOServices-2f-DinH:
	-$(RM) ./IOServices/DinH/DinH.d ./IOServices/DinH/DinH.o ./IOServices/DinH/DinH.su

.PHONY: clean-IOServices-2f-DinH

