################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MemoryServices/Fee/Fee.c 

OBJS += \
./MemoryServices/Fee/Fee.o 

C_DEPS += \
./MemoryServices/Fee/Fee.d 


# Each subdirectory must supply rules for building sources it contributes
MemoryServices/Fee/%.o MemoryServices/Fee/%.su: ../MemoryServices/Fee/%.c MemoryServices/Fee/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"MemoryServices/Fee/Fee.c_includes.args"

clean: clean-MemoryServices-2f-Fee

clean-MemoryServices-2f-Fee:
	-$(RM) ./MemoryServices/Fee/Fee.d ./MemoryServices/Fee/Fee.o ./MemoryServices/Fee/Fee.su

.PHONY: clean-MemoryServices-2f-Fee

