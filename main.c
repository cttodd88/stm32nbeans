/*Author: Chris Todd
 *Student #: C0304228
  
 * Description: Basic Template for the development of STM32
 * applications under Netbeans IDE / Linux. Toggles LED's 
 * on PORTD at 250ms intervals. 
 
 
 
 */



#include "cmsis_boot/stm32f4xx.h"
#include "cmsis_lib/include/stm32f4xx_gpio.h"
#include "cmsis_lib/include/stm32f4xx_rcc.h"
#include "cmsis_lib/include/misc.h"
#include <math.h>

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* Private define ------------------------------------------------------------*/
#define GREEN  GPIOD, GPIO_Pin_12
#define ORANGE GPIOD, GPIO_Pin_13
#define RED GPIOD, GPIO_Pin_14
#define BLUE GPIOD, GPIO_Pin_15
#define PI 3.14159265
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
unsigned int TimingDelay=0;

/* Private function prototypes -----------------------------------------------*/
void Delay(unsigned int nTime);
void TimingDelay_Decrement(void);
/* Private functions ---------------------------------------------------------*/


int main(void)
{
	SystemInit();

	if(SysTick_Config(SystemCoreClock/1000000)){

			while(1);
		}

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	 /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

          int result; 
          result= sin(30*(PI/180));

    while(1)
    {
    	 GPIO_SetBits(GREEN);
    	 Delay(250000);
    	 GPIO_ResetBits(GREEN);
    	 Delay(250000);

    	 GPIO_SetBits(ORANGE);
    	 Delay(250000);
    	 GPIO_ResetBits(ORANGE);
    	 Delay(250000);

    	 GPIO_SetBits(RED);
    	 Delay(250000);
    	 GPIO_ResetBits(RED);
    	 Delay(250000);

    	 GPIO_SetBits(BLUE);
    	 Delay(250000);
    	 GPIO_ResetBits(BLUE);
    	 Delay(250000);
    }
}

/*Delay function holds the program in a delay for the number of 1ms system ticks
 * defined by nTime */

void Delay(unsigned int nTime)
{

	 TimingDelay=nTime;
	 while(TimingDelay!=0);

 //TimingDelay=nTime;
 //while(TimingDelay!=0);
}

/*The systick handler in stm32f4xx_it.c calls this function and
 *decrements the TimingDelay variable every millisecond */

void TimingDelay_Decrement(void){
if(TimingDelay!=0x00){

TimingDelay--;
}

}

void SysTick_Handler(void) {
	TimingDelay_Decrement();
}
