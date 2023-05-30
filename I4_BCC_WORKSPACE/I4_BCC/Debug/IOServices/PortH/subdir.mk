################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IOServices/PortH/PortH.c 

OBJS += \
./IOServices/PortH/PortH.o 

C_DEPS += \
./IOServices/PortH/PortH.d 


# Each subdirectory must supply rules for building sources it contributes
IOServices/PortH/%.o IOServices/PortH/%.su IOServices/PortH/%.cyclo: ../IOServices/PortH/%.c IOServices/PortH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/Appl_Main" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Btc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/DiagCtrl" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SenCtrl" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/AdcH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/PortH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/TimH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/SystemManager" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/WatchdogManager" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/Rte" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/Crc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/EcuM" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/CenLoc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices/Dem" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Uart" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/ExtLights" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/IntLights" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SecAlm" -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/ThreadSafe -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ProjectIncludes" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Pdc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-IOServices-2f-PortH

clean-IOServices-2f-PortH:
	-$(RM) ./IOServices/PortH/PortH.cyclo ./IOServices/PortH/PortH.d ./IOServices/PortH/PortH.o ./IOServices/PortH/PortH.su

.PHONY: clean-IOServices-2f-PortH

