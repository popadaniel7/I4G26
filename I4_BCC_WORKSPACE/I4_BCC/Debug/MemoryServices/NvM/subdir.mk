################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MemoryServices/NvM/NvM.c 

OBJS += \
./MemoryServices/NvM/NvM.o 

C_DEPS += \
./MemoryServices/NvM/NvM.d 


# Each subdirectory must supply rules for building sources it contributes
MemoryServices/NvM/%.o MemoryServices/NvM/%.su: ../MemoryServices/NvM/%.c MemoryServices/NvM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"MemoryServices/NvM/NvM.c_includes.args"

clean: clean-MemoryServices-2f-NvM

clean-MemoryServices-2f-NvM:
	-$(RM) ./MemoryServices/NvM/NvM.d ./MemoryServices/NvM/NvM.o ./MemoryServices/NvM/NvM.su

.PHONY: clean-MemoryServices-2f-NvM

