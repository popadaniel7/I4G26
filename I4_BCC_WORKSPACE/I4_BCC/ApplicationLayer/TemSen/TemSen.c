#include "TemSen.h"
#include "adc.h"
#include "Project_Definitions.h"
#include "SecAlm.h"

float TemSenAdcRxValue;
float TemSenRxTemperature;

uint32 ADC_BUFFER[ADC_BUFFER_LENGTH] = {0};

void TemSenMainFunction();
void TemSenTemperatureStatus();
float TemSenReturnTemperatureValue(float TemSenVal);
float TemSenAdcReceivedValues();
StdReturnType TemSenInit();


void TemSenTemperatureStatus()
{

	float tempStatus = 0;

	tempStatus = TemSenAdcReceivedValues();

	if(tempStatus <= 3)
	{
		//buzz
		//SecAlmToggleAlarmBuzzer(STD_HIGH);

	}

	/*
	 * need more to be implemented to treat temperature cases
	 */

}

StdReturnType TemSenInit()
{

	TemSenAdcRxValue 		= STD_LOW;
	TemSenRxTemperature 	= STD_LOW;

	return E_OK;

}

float TemSenReturnTemperatureValue(float TemSenVal)
{

	float auxValue = 0;
	float returnValue = 0;

	auxValue = TemSenVSensVal;
	auxValue = auxValue * TemSenVal;
	returnValue = (TemSenVRefVal - TemSenVSensVal) / TemSenAvgSlopeVal + 25;

	return returnValue;

}

float TemSenAdcReceivedValues()
{

	uint32 RxTem = 0;

	HAL_ADC_Start_DMA(&hadc1, ADC_BUFFER, 6);
	RxTem = TemSenReturnTemperatureValue(ADC_BUFFER[0]);

	return RxTem;

}

void TemSenMainFunction()
{

	TemSenRxTemperature = TemSenAdcReceivedValues();

}
