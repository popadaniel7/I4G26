################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f411retx.s 

OBJS += \
./Core/Startup/startup_stm32f411retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f411retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/ExtLights" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/IntLights" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Pdc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SecAlm" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/SenCtrl" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/AdcH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/PortH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices/TimH" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/SystemManager" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/WatchdogManager" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/DiagCtrl" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/Appl_Main" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/Btc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer/CenLoc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/CommunicationServices/Uart" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/DiagnosticServices/Dem" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/IOServices" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/Rte" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/Crc" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/SystemServices/EcuM" -I"C:/Users/Daniel/Documents/BMWI4.git/I4_BCC_WORKSPACE/I4_BCC/ApplicationLayer" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f411retx.d ./Core/Startup/startup_stm32f411retx.o

.PHONY: clean-Core-2f-Startup

