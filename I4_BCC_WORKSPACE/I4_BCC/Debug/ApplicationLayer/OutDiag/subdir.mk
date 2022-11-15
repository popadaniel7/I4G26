################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApplicationLayer/OutDiag/OutDiag.c 

OBJS += \
./ApplicationLayer/OutDiag/OutDiag.o 

C_DEPS += \
./ApplicationLayer/OutDiag/OutDiag.d 


# Each subdirectory must supply rules for building sources it contributes
ApplicationLayer/OutDiag/%.o ApplicationLayer/OutDiag/%.su: ../ApplicationLayer/OutDiag/%.c ApplicationLayer/OutDiag/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ProjectIncludes" -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer" -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/CenLoc" -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/ExtLights" -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/IntLights" -I"C:/Users/Daniel/Desktop/BMWI4_REPOSITORY/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SecAlm" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ApplicationLayer-2f-OutDiag

clean-ApplicationLayer-2f-OutDiag:
	-$(RM) ./ApplicationLayer/OutDiag/OutDiag.d ./ApplicationLayer/OutDiag/OutDiag.o ./ApplicationLayer/OutDiag/OutDiag.su

.PHONY: clean-ApplicationLayer-2f-OutDiag

