################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/AinH/AinH.c 

OBJS += \
./IOServices/AinH/AinH.o 

C_DEPS += \
./IOServices/AinH/AinH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/AinH/%.o IOServices/AinH/%.su: ../IOServices/AinH/%.c IOServices/AinH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/AinH/AinH.c_includes.args"

clean: clean-IOServices-2f-AinH

clean-IOServices-2f-AinH:
	-$(RM) ./IOServices/AinH/AinH.d ./IOServices/AinH/AinH.o ./IOServices/AinH/AinH.su

.PHONY: clean-IOServices-2f-AinH

