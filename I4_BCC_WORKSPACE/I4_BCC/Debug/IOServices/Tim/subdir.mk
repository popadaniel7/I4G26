################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Tim/TimH.c 

OBJS += \
./IOServices/Tim/TimH.o 

C_DEPS += \
./IOServices/Tim/TimH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Tim/%.o IOServices/Tim/%.su: ../IOServices/Tim/%.c IOServices/Tim/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Tim/TimH.c_includes.args"

clean: clean-IOServices-2f-Tim

clean-IOServices-2f-Tim:
	-$(RM) ./IOServices/Tim/TimH.d ./IOServices/Tim/TimH.o ./IOServices/Tim/TimH.su

.PHONY: clean-IOServices-2f-Tim

