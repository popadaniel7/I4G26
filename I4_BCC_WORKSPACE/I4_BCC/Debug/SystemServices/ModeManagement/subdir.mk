################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/ModeManagement/ModeManagement.c 

OBJS += \
./SystemServices/ModeManagement/ModeManagement.o 

C_DEPS += \
./SystemServices/ModeManagement/ModeManagement.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/ModeManagement/%.o SystemServices/ModeManagement/%.su: ../SystemServices/ModeManagement/%.c SystemServices/ModeManagement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/ModeManagement/ModeManagement.c_includes.args"

clean: clean-SystemServices-2f-ModeManagement

clean-SystemServices-2f-ModeManagement:
	-$(RM) ./SystemServices/ModeManagement/ModeManagement.d ./SystemServices/ModeManagement/ModeManagement.o ./SystemServices/ModeManagement/ModeManagement.su

.PHONY: clean-SystemServices-2f-ModeManagement

