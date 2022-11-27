################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MemoryServices/Ea/Ea.c 

OBJS += \
./MemoryServices/Ea/Ea.o 

C_DEPS += \
./MemoryServices/Ea/Ea.d 


# Each subdirectory must supply rules for building sources it contributes
MemoryServices/Ea/%.o MemoryServices/Ea/%.su: ../MemoryServices/Ea/%.c MemoryServices/Ea/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"MemoryServices/Ea/Ea.c_includes.args"

clean: clean-MemoryServices-2f-Ea

clean-MemoryServices-2f-Ea:
	-$(RM) ./MemoryServices/Ea/Ea.d ./MemoryServices/Ea/Ea.o ./MemoryServices/Ea/Ea.su

.PHONY: clean-MemoryServices-2f-Ea

