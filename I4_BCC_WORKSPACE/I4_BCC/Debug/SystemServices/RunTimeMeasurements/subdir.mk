################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/RunTimeMeasurements/RunTimeMeasurements.c 

OBJS += \
./SystemServices/RunTimeMeasurements/RunTimeMeasurements.o 

C_DEPS += \
./SystemServices/RunTimeMeasurements/RunTimeMeasurements.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/RunTimeMeasurements/%.o SystemServices/RunTimeMeasurements/%.su: ../SystemServices/RunTimeMeasurements/%.c SystemServices/RunTimeMeasurements/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"SystemServices/RunTimeMeasurements/RunTimeMeasurements.c_includes.args"

clean: clean-SystemServices-2f-RunTimeMeasurements

clean-SystemServices-2f-RunTimeMeasurements:
	-$(RM) ./SystemServices/RunTimeMeasurements/RunTimeMeasurements.d ./SystemServices/RunTimeMeasurements/RunTimeMeasurements.o ./SystemServices/RunTimeMeasurements/RunTimeMeasurements.su

.PHONY: clean-SystemServices-2f-RunTimeMeasurements

