################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DiagnosticServices/Dcm/Dcm.c 

OBJS += \
./DiagnosticServices/Dcm/Dcm.o 

C_DEPS += \
./DiagnosticServices/Dcm/Dcm.d 


# Each subdirectory must supply rules for building sources it contributes
DiagnosticServices/Dcm/%.o DiagnosticServices/Dcm/%.su: ../DiagnosticServices/Dcm/%.c DiagnosticServices/Dcm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"DiagnosticServices/Dcm/Dcm.c_includes.args"

clean: clean-DiagnosticServices-2f-Dcm

clean-DiagnosticServices-2f-Dcm:
	-$(RM) ./DiagnosticServices/Dcm/Dcm.d ./DiagnosticServices/Dcm/Dcm.o ./DiagnosticServices/Dcm/Dcm.su

.PHONY: clean-DiagnosticServices-2f-Dcm

