################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/CenLoc/CenLoc.c 

OBJS += \
./ApplicationLayer/CenLoc/CenLoc.o 

C_DEPS += \
./ApplicationLayer/CenLoc/CenLoc.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/CenLoc/%.o ApplicationLayer/CenLoc/%.su: ../ApplicationLayer/CenLoc/%.c ApplicationLayer/CenLoc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"ApplicationLayer/CenLoc/CenLoc.c_includes.args"

clean: clean-ApplicationLayer-2f-CenLoc

clean-ApplicationLayer-2f-CenLoc:
	-$(RM) ./ApplicationLayer/CenLoc/CenLoc.d ./ApplicationLayer/CenLoc/CenLoc.o ./ApplicationLayer/CenLoc/CenLoc.su

.PHONY: clean-ApplicationLayer-2f-CenLoc

