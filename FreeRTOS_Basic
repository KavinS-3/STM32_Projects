#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define STACK_SIZE 32
#define PRIORITY 1

void Led_Init(void);   

void vTaskLedOn (void *argument);
void vTaskLedOff (void *argument);

void vTaskLedOn1 (void *argument);
void vTaskLedOff1 (void *argument);

void vTaskLedOn2 (void *argument);
void vTaskLedOff2 (void *argument);

int main(void){
	
	Led_Init();
	
	xTaskCreate(vTaskLedOn, "LED_ON", STACK_SIZE, NULL,PRIORITY, NULL);
	xTaskCreate(vTaskLedOff, "LED_OFF", STACK_SIZE, NULL, PRIORITY, NULL);
	
	xTaskCreate(vTaskLedOn1, "LED_ON", STACK_SIZE, NULL, PRIORITY, NULL);
	xTaskCreate(vTaskLedOff1, "LED_OFF", STACK_SIZE, NULL, PRIORITY, NULL);
	
	xTaskCreate(vTaskLedOn2, "LED_ON", STACK_SIZE, NULL, PRIORITY, NULL);
	xTaskCreate(vTaskLedOff2, "LED_OFF", STACK_SIZE, NULL, PRIORITY, NULL);
	
	vTaskStartScheduler();
}

void Led_Init(void){
		
	
	GPIO_InitTypeDef led;
	GPIO_InitTypeDef led1;
	GPIO_InitTypeDef led2;
	
	led.GPIO_Pin = GPIO_Pin_7;
	led1.GPIO_Pin = GPIO_Pin_6;
	led2.GPIO_Pin = GPIO_Pin_14;
	
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Speed = GPIO_Speed_2MHz;
	
  led1.GPIO_Mode = GPIO_Mode_Out_PP;
	led1.GPIO_Speed = GPIO_Speed_2MHz;
	
	led2.GPIO_Mode = GPIO_Mode_Out_PP;
	led2.GPIO_Speed = GPIO_Speed_2MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_Init(GPIOA, &led);
	GPIO_Init(GPIOB, &led1);
	GPIO_Init(GPIOC, &led2);
}

void vTaskLedOn (void *argument){
	
	while(1)
	{
		vTaskDelay(300);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
  //GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		vTaskDelay(400);
	}
	
}

void vTaskLedOff (void *argument){
	
	while(1)
	{
		
		vTaskDelay(400);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		//GPIO_SetBits(GPIOA, GPIO_Pin_6);
		vTaskDelay(300);
	}
	
}
void vTaskLedOn1 (void *argument){
	
	while(1)
	{
		vTaskDelay(200);
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);
		//GPIO_SetBits(GPIOB, GPIO_Pin_0);
		vTaskDelay(600);
	}
}
void vTaskLedOff1 (void *argument){
	
	while(1)
	{
		vTaskDelay(600);
		GPIO_SetBits(GPIOB, GPIO_Pin_6);
		//GPIO_SetBits(GPIOB, GPIO_Pin_0);
		vTaskDelay(200);
	}
	
}

void vTaskLedOn2 (void *argument){
	
	while(1)
	{
		vTaskDelay(300);
	GPIO_ResetBits(GPIOC, GPIO_Pin_14);
		//GPIO_SetBits(GPIOB, GPIO_Pin_0);
		vTaskDelay(500);
	
		
	}
}
void vTaskLedOff2 (void *argument){
	
	while(1)
	{
		vTaskDelay(500);
		GPIO_SetBits(GPIOC, GPIO_Pin_14);
		//GPIO_SetBits(GPIOB, GPIO_Pin_0);
		vTaskDelay(300);
	}
	
}
