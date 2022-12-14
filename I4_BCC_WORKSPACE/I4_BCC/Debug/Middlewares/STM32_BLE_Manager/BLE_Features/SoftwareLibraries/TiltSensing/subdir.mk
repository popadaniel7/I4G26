################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Daniel/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-BLEMGR/1.3.0/Middlewares/ST/STM32_BLE_Manager/Src/BLE_TiltSensing.c 

OBJS += \
./Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.o 

C_DEPS += \
./Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.o: C:/Users/Daniel/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-BLEMGR/1.3.0/Middlewares/ST/STM32_BLE_Manager/Src/BLE_TiltSensing.c Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" @"Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.c_includes.args"

clean: clean-Middlewares-2f-STM32_BLE_Manager-2f-BLE_Features-2f-SoftwareLibraries-2f-TiltSensing

clean-Middlewares-2f-STM32_BLE_Manager-2f-BLE_Features-2f-SoftwareLibraries-2f-TiltSensing:
	-$(RM) ./Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.d ./Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.o ./Middlewares/STM32_BLE_Manager/BLE_Features/SoftwareLibraries/TiltSensing/BLE_TiltSensing.su

.PHONY: clean-Middlewares-2f-STM32_BLE_Manager-2f-BLE_Features-2f-SoftwareLibraries-2f-TiltSensing

