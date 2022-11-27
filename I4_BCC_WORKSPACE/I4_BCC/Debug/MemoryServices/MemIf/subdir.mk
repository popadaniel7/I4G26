################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MemoryServices/MemIf/MemIf.c 

OBJS += \
./MemoryServices/MemIf/MemIf.o 

C_DEPS += \
./MemoryServices/MemIf/MemIf.d 


# Each subdirectory must supply rules for building sources it contributes
MemoryServices/MemIf/%.o MemoryServices/MemIf/%.su: ../MemoryServices/MemIf/%.c MemoryServices/MemIf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"MemoryServices/MemIf/MemIf.c_includes.args"

clean: clean-MemoryServices-2f-MemIf

clean-MemoryServices-2f-MemIf:
	-$(RM) ./MemoryServices/MemIf/MemIf.d ./MemoryServices/MemIf/MemIf.o ./MemoryServices/MemIf/MemIf.su

.PHONY: clean-MemoryServices-2f-MemIf

