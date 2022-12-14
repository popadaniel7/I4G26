################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Daniel/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-BLEMGR/1.3.0/Middlewares/Third_Party/parson/parson.c 

OBJS += \
./Middlewares/parson/Data\ Exchange/parson/parson.o 

C_DEPS += \
./Middlewares/parson/Data\ Exchange/parson/parson.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/parson/Data\ Exchange/parson/parson.o: C:/Users/Daniel/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-BLEMGR/1.3.0/Middlewares/Third_Party/parson/parson.c Middlewares/parson/Data\ Exchange/parson/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/parson/Data Exchange/parson/parson.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/parson/Data Exchange/parson/parson.c_includes.args"

clean: clean-Middlewares-2f-parson-2f-Data-20-Exchange-2f-parson

clean-Middlewares-2f-parson-2f-Data-20-Exchange-2f-parson:
	-$(RM) ./Middlewares/parson/Data\ Exchange/parson/parson.d ./Middlewares/parson/Data\ Exchange/parson/parson.o ./Middlewares/parson/Data\ Exchange/parson/parson.su

.PHONY: clean-Middlewares-2f-parson-2f-Data-20-Exchange-2f-parson

