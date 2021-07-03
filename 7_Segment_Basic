#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_conf.h>
#include "delay.h"

#define d 500

GPIO_InitTypeDef GPIO_InitStructure; //Structure Reference

int main(void)
{
	unsigned char num[17]={0x00e7,0x0006,0x00d3,0x0097,0x0036, 0x00b5,0x00f5, 0x0007,0x00f7,0x00b7,0x0077,0x00f4,0x00e1,0x00d6,0x00f1,0x0071,0x0008};

	int i;

	//GPIO_InitTypeDef GPIO_InitStruct={0};
	
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	while(1)					
	{
		for(i=-1;i<=17;(GPIOA->ODR =  num[i]))
//for(i=-1;i<=num[i];(GPIOA->ODR =  num[i]))
			{
				i++;
				delay(d);		
		  }
	}
	
}

