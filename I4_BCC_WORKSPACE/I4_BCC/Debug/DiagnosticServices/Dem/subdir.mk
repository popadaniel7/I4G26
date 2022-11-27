################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DiagnosticServices/Dem/Dem.c 

OBJS += \
./DiagnosticServices/Dem/Dem.o 

C_DEPS += \
./DiagnosticServices/Dem/Dem.d 


# Each subdirectory must supply rules for building sources it contributes
DiagnosticServices/Dem/%.o DiagnosticServices/Dem/%.su: ../DiagnosticServices/Dem/%.c DiagnosticServices/Dem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"DiagnosticServices/Dem/Dem.c_includes.args"

clean: clean-DiagnosticServices-2f-Dem

clean-DiagnosticServices-2f-Dem:
	-$(RM) ./DiagnosticServices/Dem/Dem.d ./DiagnosticServices/Dem/Dem.o ./DiagnosticServices/Dem/Dem.su

.PHONY: clean-DiagnosticServices-2f-Dem

