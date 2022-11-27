################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTE/RTE.c 

OBJS += \
./RTE/RTE.o 

C_DEPS += \
./RTE/RTE.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/%.o RTE/%.su: ../RTE/%.c RTE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"RTE/RTE.c_includes.args"

clean: clean-RTE

clean-RTE:
	-$(RM) ./RTE/RTE.d ./RTE/RTE.o ./RTE/RTE.su

.PHONY: clean-RTE

