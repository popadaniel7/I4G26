################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/FlashTest/FlashTest.c 

OBJS += \
./SystemServices/FlashTest/FlashTest.o 

C_DEPS += \
./SystemServices/FlashTest/FlashTest.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/FlashTest/%.o SystemServices/FlashTest/%.su: ../SystemServices/FlashTest/%.c SystemServices/FlashTest/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/FlashTest/FlashTest.c_includes.args"

clean: clean-SystemServices-2f-FlashTest

clean-SystemServices-2f-FlashTest:
	-$(RM) ./SystemServices/FlashTest/FlashTest.d ./SystemServices/FlashTest/FlashTest.o ./SystemServices/FlashTest/FlashTest.su

.PHONY: clean-SystemServices-2f-FlashTest

