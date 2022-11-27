################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Dma/DmaH.c 

OBJS += \
./IOServices/Dma/DmaH.o 

C_DEPS += \
./IOServices/Dma/DmaH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Dma/%.o IOServices/Dma/%.su: ../IOServices/Dma/%.c IOServices/Dma/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Dma/DmaH.c_includes.args"

clean: clean-IOServices-2f-Dma

clean-IOServices-2f-Dma:
	-$(RM) ./IOServices/Dma/DmaH.d ./IOServices/Dma/DmaH.o ./IOServices/Dma/DmaH.su

.PHONY: clean-IOServices-2f-Dma

