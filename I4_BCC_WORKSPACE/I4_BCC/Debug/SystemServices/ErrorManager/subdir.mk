################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SystemServices/ErrorManager/ErrorManager.c 

OBJS += \
./SystemServices/ErrorManager/ErrorManager.o 

C_DEPS += \
./SystemServices/ErrorManager/ErrorManager.d 


# Each subdirectory must supply rules for building sources it contributes
SystemServices/ErrorManager/%.o SystemServices/ErrorManager/%.su: ../SystemServices/ErrorManager/%.c SystemServices/ErrorManager/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE '-DMBEDTLS_CONFIG_FILE="mbedtls_config.h"' -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/RTE" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/BswM" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/Crc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/EcuM" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/CenLoc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/BTC" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/I2c" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices/Dem" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/Adc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/Port" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/Pwm" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/Spi" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/Tim" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/MemoryServices/Fee" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/MemoryServices/MemIf" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/MemoryServices/NvM" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Uart" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices/Dcm" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/ExtLights" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/IntLights" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SecAlm" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ProjectIncludes" -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../MBEDTLS/App -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/mbedTLS/include/mbedtls -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/mbedTLS/include -I../Core/ThreadSafe -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Can/CanOs" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Can/Mcp2515_CanOs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SystemServices-2f-ErrorManager

clean-SystemServices-2f-ErrorManager:
	-$(RM) ./SystemServices/ErrorManager/ErrorManager.d ./SystemServices/ErrorManager/ErrorManager.o ./SystemServices/ErrorManager/ErrorManager.su

.PHONY: clean-SystemServices-2f-ErrorManager

