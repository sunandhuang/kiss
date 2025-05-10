#include "stm32f10x.h"
/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
    void KEY_INIT(void)
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
        GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4 | GPIO_Pin_5;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
    void LED_INIT(void )
    {
      GPIO_InitTypeDef GPIO_InitStructure; 
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init (GPIOE, &GPIO_InitStructure); 
    }
    
    void Delay(u32 Times)
{
  u16 i;
  while(Times--)
  {
    for(i=0;i>0xFFFF;i++);
  }
}
void Liushui(void)
{
  GPIO_ResetBits(GPIOE,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);//??
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_8);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_9);
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_10);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_11);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_12);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_13);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_14);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_15);  
  Delay(0xFFFFF);
}
void Faeoma (void)
{
  GPIO_ResetBits(GPIOE,GPIO_Pin_8);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_8);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_9);  
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_9);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_10); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_10);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_11); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_11);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_12); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_12);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_13); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_13);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_14); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_14);  
  GPIO_ResetBits(GPIOE,GPIO_Pin_15); 
  Delay(0xFFFFF);
  GPIO_SetBits(GPIOE,GPIO_Pin_15);  
}

int main(void)
{
    KEY_INIT();
    LED_INIT();
  while (1)
  {
        if(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4))
    {
      Liushui();
    }
    if(!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5))
    {
      Faeoma();
    }
  }
}

