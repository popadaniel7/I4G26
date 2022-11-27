################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/BswM/BswM.c 

OBJS += \
./SystemServices/BswM/BswM.o 

C_DEPS += \
./SystemServices/BswM/BswM.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/BswM/%.o SystemServices/BswM/%.su: ../SystemServices/BswM/%.c SystemServices/BswM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/BswM/BswM.c_includes.args"

clean: clean-SystemServices-2f-BswM

clean-SystemServices-2f-BswM:
	-$(RM) ./SystemServices/BswM/BswM.d ./SystemServices/BswM/BswM.o ./SystemServices/BswM/BswM.su

.PHONY: clean-SystemServices-2f-BswM

