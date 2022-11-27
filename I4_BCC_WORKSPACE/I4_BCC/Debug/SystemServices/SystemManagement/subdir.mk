################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/SystemManagement/SystemManagement.c 

OBJS += \
./SystemServices/SystemManagement/SystemManagement.o 

C_DEPS += \
./SystemServices/SystemManagement/SystemManagement.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/SystemManagement/%.o SystemServices/SystemManagement/%.su: ../SystemServices/SystemManagement/%.c SystemServices/SystemManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/SystemManagement/SystemManagement.c_includes.args"

clean: clean-SystemServices-2f-SystemManagement

clean-SystemServices-2f-SystemManagement:
	-$(RM) ./SystemServices/SystemManagement/SystemManagement.d ./SystemServices/SystemManagement/SystemManagement.o ./SystemServices/SystemManagement/SystemManagement.su

.PHONY: clean-SystemServices-2f-SystemManagement

