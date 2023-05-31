################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BLEMGR/App/BLE_Implementation.c 

OBJS += \
./BLEMGR/App/BLE_Implementation.o 

C_DEPS += \
./BLEMGR/App/BLE_Implementation.d 


# Each subdirectory must supply rules for building sources it contributes
BLEMGR/App/%.o BLEMGR/App/%.su: ../BLEMGR/App/%.c BLEMGR/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"BLEMGR/App/BLE_Implementation.c_includes.args"

clean: clean-BLEMGR-2f-App

clean-BLEMGR-2f-App:
	-$(RM) ./BLEMGR/App/BLE_Implementation.d ./BLEMGR/App/BLE_Implementation.o ./BLEMGR/App/BLE_Implementation.su

.PHONY: clean-BLEMGR-2f-App

