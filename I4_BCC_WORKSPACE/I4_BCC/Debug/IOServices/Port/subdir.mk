################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/Port/Port.c 

OBJS += \
./IOServices/Port/Port.o 

C_DEPS += \
./IOServices/Port/Port.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/Port/%.o IOServices/Port/%.su: ../IOServices/Port/%.c IOServices/Port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"IOServices/Port/Port.c_includes.args"

clean: clean-IOServices-2f-Port

clean-IOServices-2f-Port:
	-$(RM) ./IOServices/Port/Port.d ./IOServices/Port/Port.o ./IOServices/Port/Port.su

.PHONY: clean-IOServices-2f-Port

