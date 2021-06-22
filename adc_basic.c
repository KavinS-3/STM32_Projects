#include<stm32f10x.h>
#include<stm32f10x_gpio.h>
#include<stm32f10x_rcc.h>
#include<stm32f10x_adc.h>
#include "define.h"

int main(void)
{
	float value = 0.0;
	GPIO_InitTypeDef led;
	GPIO_InitTypeDef led1;
	GPIO_InitTypeDef sensor;
	
	sensor.GPIO_Pin = GPIO_Pin_1;	
	sensor.GPIO_Mode = GPIO_Mode_AIN;
	
	led1.GPIO_Pin = GPIO_Pin_3;
	led.GPIO_Pin = GPIO_Pin_0;
	
	led1.GPIO_Mode = GPIO_Mode_Out_PP;
	led1.GPIO_Speed = GPIO_Speed_2MHz;
	
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Speed = GPIO_Speed_2MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	GPIO_Init(GPIOA,&led);
	GPIO_Init(GPIOA,&led1);
	GPIO_Init(GPIOB,&sensor);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_41Cycles5);
	
	// Init ADC1
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC1, &ADC_InitStruct);
	
	// Enable ADC
	ADC_Cmd(ADC1, ENABLE);
	
	// Reset ADC Calibration
	ADC_ResetCalibration(ADC1);	
	while(ADC_GetCalibrationStatus(ADC1));
	
	// ADC Calibration
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));

	// Select input channel for ADC1
	// ADC1 channel 9 is on PB1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_7Cycles5);
	
	while(1)
	{
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
		
		value = ((float)ADC_GetConversionValue(ADC1)/4096)*3.3;
		
		if(value < 2)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_0);
		}
		else
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		}
			
		ADC_ClearFlag(ADC1, ADC_FLAG_EOC);
	}
}
