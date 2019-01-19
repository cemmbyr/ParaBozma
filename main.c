#include <stdint.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "LCD1602.h"
#include "SYSTICK.h"
#include "PLL_80MHZ.h"

void PLL_Init80MHZ(void);

unsigned char msg1[] ="ANAN";
unsigned char *msg[] = {msg1};

unsigned char nokta[] =".";
unsigned char *nn[] = {nokta};

int main(void){
    unsigned int bir=0,iki=4,uc=1,dort=1,counter=0;
    PLL_Init80MHZ();
    SysTick_Init();
    LCD1602_Init();
    LCD1602_DisplayPosition(LINE1,0);
    LCD1602_DisplayString(msg[0]);
    LCD1602_DisplayPosition(LINE1,11);
    LCD1602_DisplayDec(bir);
    LCD1602_DisplayPosition(LINE1,12);
    LCD1602_DisplayDec(iki);
    LCD1602_DisplayPosition(LINE1,13);
    LCD1602_DisplayString(nn[0]);
    LCD1602_DisplayPosition(LINE1,14);
    LCD1602_DisplayDec(uc);
    LCD1602_DisplayPosition(LINE1,15);
    LCD1602_DisplayDec(dort);
    SysTick_Delay1ms(1000);
    SysTick_Delay1ms(1000);
    SysTick_Delay1ms(1000);

  while(1)
    {
        LCD1602_DisplayPosition(LINE2,7);
        LCD1602_DisplayDec(counter);
        counter ++;
        SysTick_Delay1ms(1000);
    }
}
