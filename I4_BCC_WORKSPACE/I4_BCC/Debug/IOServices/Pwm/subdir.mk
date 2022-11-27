################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Pwm/Pwm.c 

OBJS += \
./IOServices/Pwm/Pwm.o 

C_DEPS += \
./IOServices/Pwm/Pwm.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Pwm/%.o IOServices/Pwm/%.su: ../IOServices/Pwm/%.c IOServices/Pwm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Pwm/Pwm.c_includes.args"

clean: clean-IOServices-2f-Pwm

clean-IOServices-2f-Pwm:
	-$(RM) ./IOServices/Pwm/Pwm.d ./IOServices/Pwm/Pwm.o ./IOServices/Pwm/Pwm.su

.PHONY: clean-IOServices-2f-Pwm

