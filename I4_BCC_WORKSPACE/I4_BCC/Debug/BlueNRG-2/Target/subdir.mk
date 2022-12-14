################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BlueNRG-2/Target/hci_tl_interface.c 

OBJS += \
./BlueNRG-2/Target/hci_tl_interface.o 

C_DEPS += \
./BlueNRG-2/Target/hci_tl_interface.d 


# Each subdirectory must supply rules for building sources it contributes
BlueNRG-2/Target/%.o BlueNRG-2/Target/%.su: ../BlueNRG-2/Target/%.c BlueNRG-2/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 '-DMBEDTLS_CONFIG_FILE="mbedtls_config.h"' -c -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../BlueNRG-2/Target -IC:/Users/Daniel/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-BLE2/3.3.0/Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -IC:/Users/Daniel/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-BLE2/3.3.0/Middlewares/ST/BlueNRG-2/utils -IC:/Users/Daniel/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-BLE2/3.3.0/Middlewares/ST/BlueNRG-2/includes -I../Core/ThreadSafe -I../MBEDTLS/App -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/mbedTLS/include/mbedtls -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/mbedTLS/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BlueNRG-2d-2-2f-Target

clean-BlueNRG-2d-2-2f-Target:
	-$(RM) ./BlueNRG-2/Target/hci_tl_interface.d ./BlueNRG-2/Target/hci_tl_interface.o ./BlueNRG-2/Target/hci_tl_interface.su

.PHONY: clean-BlueNRG-2d-2-2f-Target

