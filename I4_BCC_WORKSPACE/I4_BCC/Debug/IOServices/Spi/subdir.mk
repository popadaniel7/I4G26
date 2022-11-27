################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Spi/SpiH.c 

OBJS += \
./IOServices/Spi/SpiH.o 

C_DEPS += \
./IOServices/Spi/SpiH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Spi/%.o IOServices/Spi/%.su: ../IOServices/Spi/%.c IOServices/Spi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Spi/SpiH.c_includes.args"

clean: clean-IOServices-2f-Spi

clean-IOServices-2f-Spi:
	-$(RM) ./IOServices/Spi/SpiH.d ./IOServices/Spi/SpiH.o ./IOServices/Spi/SpiH.su

.PHONY: clean-IOServices-2f-Spi

