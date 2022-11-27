################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/WatchdogManagement/WatchdogManagement.c 

OBJS += \
./SystemServices/WatchdogManagement/WatchdogManagement.o 

C_DEPS += \
./SystemServices/WatchdogManagement/WatchdogManagement.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/WatchdogManagement/%.o SystemServices/WatchdogManagement/%.su: ../SystemServices/WatchdogManagement/%.c SystemServices/WatchdogManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/WatchdogManagement/WatchdogManagement.c_includes.args"

clean: clean-SystemServices-2f-WatchdogManagement

clean-SystemServices-2f-WatchdogManagement:
	-$(RM) ./SystemServices/WatchdogManagement/WatchdogManagement.d ./SystemServices/WatchdogManagement/WatchdogManagement.o ./SystemServices/WatchdogManagement/WatchdogManagement.su

.PHONY: clean-SystemServices-2f-WatchdogManagement

