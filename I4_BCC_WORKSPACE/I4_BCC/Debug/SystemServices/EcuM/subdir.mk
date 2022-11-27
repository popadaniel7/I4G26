################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/EcuM/EcuM.c 

OBJS += \
./SystemServices/EcuM/EcuM.o 

C_DEPS += \
./SystemServices/EcuM/EcuM.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/EcuM/%.o SystemServices/EcuM/%.su: ../SystemServices/EcuM/%.c SystemServices/EcuM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/EcuM/EcuM.c_includes.args"

clean: clean-SystemServices-2f-EcuM

clean-SystemServices-2f-EcuM:
	-$(RM) ./SystemServices/EcuM/EcuM.d ./SystemServices/EcuM/EcuM.o ./SystemServices/EcuM/EcuM.su

.PHONY: clean-SystemServices-2f-EcuM

