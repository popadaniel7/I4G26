################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/Crc/CrcH.c 

OBJS += \
./SystemServices/Crc/CrcH.o 

C_DEPS += \
./SystemServices/Crc/CrcH.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/Crc/%.o SystemServices/Crc/%.su: ../SystemServices/Crc/%.c SystemServices/Crc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/Crc/CrcH.c_includes.args"

clean: clean-SystemServices-2f-Crc

clean-SystemServices-2f-Crc:
	-$(RM) ./SystemServices/Crc/CrcH.d ./SystemServices/Crc/CrcH.o ./SystemServices/Crc/CrcH.su

.PHONY: clean-SystemServices-2f-Crc

