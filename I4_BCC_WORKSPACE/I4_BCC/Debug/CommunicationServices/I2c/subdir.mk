################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommunicationServices/I2c/I2cExtEeprom.c \
../CommunicationServices/I2c/I2cH.c \
../CommunicationServices/I2c/I2cLcd.c 

OBJS += \
./CommunicationServices/I2c/I2cExtEeprom.o \
./CommunicationServices/I2c/I2cH.o \
./CommunicationServices/I2c/I2cLcd.o 

C_DEPS += \
./CommunicationServices/I2c/I2cExtEeprom.d \
./CommunicationServices/I2c/I2cH.d \
./CommunicationServices/I2c/I2cLcd.d 


# Each subdirectory must supply rules for building sources it contributes
CommunicationServices/I2c/%.o CommunicationServices/I2c/%.su CommunicationServices/I2c/%.cyclo: ../CommunicationServices/I2c/%.c CommunicationServices/I2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=5 -c -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/ThreadSafe -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/Appl_Main" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/BTC" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/CenLoc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/DiagCtrl" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/ExtLights" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Hvac" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/IntLights" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Pdc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SecAlm" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SenCtrl" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Can" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/I2c" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Uart" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices/Dem" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/AdcH" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/PortH" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/SpiH" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/IOServices/TimH" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/ProjectIncludes" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/Crc" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/EcuM" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/SystemManager" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/SystemServices/WatchdogManager" -I"C:/Users/Daniel/Documents/BMWI4/I4_BCC_WORKSPACE/I4_BCC/Rte" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CommunicationServices-2f-I2c

clean-CommunicationServices-2f-I2c:
	-$(RM) ./CommunicationServices/I2c/I2cExtEeprom.cyclo ./CommunicationServices/I2c/I2cExtEeprom.d ./CommunicationServices/I2c/I2cExtEeprom.o ./CommunicationServices/I2c/I2cExtEeprom.su ./CommunicationServices/I2c/I2cH.cyclo ./CommunicationServices/I2c/I2cH.d ./CommunicationServices/I2c/I2cH.o ./CommunicationServices/I2c/I2cH.su ./CommunicationServices/I2c/I2cLcd.cyclo ./CommunicationServices/I2c/I2cLcd.d ./CommunicationServices/I2c/I2cLcd.o ./CommunicationServices/I2c/I2cLcd.su

.PHONY: clean-CommunicationServices-2f-I2c

