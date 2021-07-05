#include<stm32f10x.h>
#include<stm32f10x_gpio.h>
#include<stm32f10x_rcc.h>


#define Dt  1000

//stores the LED state
unsigned char LED_state_G;

//Function prototypes
void LED_FLASH_Init(void);
void LED_FLASH_Change_State(void);
void DELAY_LOOP_Wait(const unsigned int);



int main(void)
{
		GPIO_InitTypeDef LED_1;

		LED_1.GPIO_Mode = GPIO_Mode_Out_PP;
			
		LED_1.GPIO_Pin=GPIO_Pin_0;
			
		LED_1.GPIO_Speed = GPIO_Speed_2MHz;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

		GPIO_Init(GPIOA,&LED_1);	
	
	
		LED_FLASH_Init();
	
	while(1)
	{
		//Change the LED state OFF to ON or vice versa
		LED_FLASH_Change_State();
		//Delay for *approx* 1000ms
		DELAY_LOOP_Wait(Dt);
	}
}
void LED_FLASH_Init(void)
{
	LED_state_G = 0;
}

void LED_FLASH_Change_State(void)
{
			
	if(LED_state_G == 1)
	{
		LED_state_G =0;
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		
	}
	else
	{
		LED_state_G=1;
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
	}
}	
	
void DELAY_LOOP_Wait(const unsigned int DELAY)
{
	unsigned int  x,y;
	
	for(x=0;x<=DELAY;x++)
	{
		for(y=0;y<=11000;y++);
	}
}
	
	
	
	
	
	
	
	
