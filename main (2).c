#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "inc/lm4f120h5qr.h"
#include "LCD1602.h"
#include "SYSTICK.h"
#include "PLL_80MHZ.h"

void PLL_Init80MHZ(void);

unsigned char msg1[] ="Girilen:";
unsigned char *msg[] = {msg1};

unsigned char nokta[] =".";
unsigned char *nn[] = {nokta};
void init_port_E(){
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R  = 0x3F;
	GPIO_PORTE_AMSEL_R &= ~0x3F;      // 3) disable analog on PA5
	GPIO_PORTE_PCTL_R &= ~0x00FFFFFF; // 4) PCTL GPIO on PA5
	GPIO_PORTE_DIR_R &= ~0x3F;        // 5) direction PA5 input
	GPIO_PORTE_AFSEL_R &= ~0x3F;      // 6) PA5 regular port function
	GPIO_PORTE_DEN_R |= 0x3F;         // 7) enable PA5 digital port
	/*GPIO_PORTE_AMSEL_R = 0x00;
	GPIO_PORTE_PCTL_R = 0x00000000;
	GPIO_PORTE_DIR_R = 0x00;
	GPIO_PORTE_AFSEL_R = 0x00;
	GPIO_PORTE_PUR_R = 0x3F;
	GPIO_PORTE_DEN_R = 0x3F;*/
}
int hane_arttir(int hane){
	hane =(hane++)%10;
	return hane;
}
void hesapla(){

}
void ekrana_yaz(){

}
void* bozdur( int *dizi ,double * banknotlar,double para){

    banknotlar[0]=200.0;
    banknotlar[1]=100.0;
    banknotlar[2]=50.0;
    banknotlar[3]=20.0;
    banknotlar[4]=10.0;
    banknotlar[5]=5.0;
    banknotlar[6]=1.0;
    banknotlar[7]=0.5;
    banknotlar[8]=0.25;
    banknotlar[9]=0.1;
    banknotlar[10]=0.05;
    banknotlar[11]=0.01;

int i;

    for(i=0;i<12;i++){
        while( para>banknotlar[i]){
            para -= banknotlar[i];
            dizi[i]++;
        }
    }
}
int main(void){
	double banknotlar[12];


	    int dizi[12];
	    int i;
	    double para;

	    for(i=0;i<12;i++){
	        dizi[i]=0;
	    }
    /*unsigned int bir=0,iki=4,uc=1,dort=1,counter=0;
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
    }*/
	    PLL_Init80MHZ();
	    SysTick_Init();
	    LCD1602_Init();
	    //LCD1602_DisplayPosition(LINE1,0);
	    //LCD1602_DisplayString("ONURUN AMK");
	    //LCD1602_DisplayString(msg[0]);
	    //LCD1602_DisplayPosition(LINE1,13);
	    //LCD1602_DisplayString(nn[0]);
  	init_port_E();
  	int temp=1;
  	volatile int button1 ,button2, button3, button4, button5, button6;
  	int birler=0,onlar=0,ondabir=0,yuzdebir=0;
  	while(1){
  		/*LCD1602_DisplayPosition(LINE1,0);
  		button1 = GPIO_PORTE_DATA_R & 0x01;
  		  			LCD1602_DisplayDec(button1);
  		SysTick_Delay1ms(1000);
  		LCD1602_Clear();
*/
  		LCD1602_DisplayPosition(LINE1,0);
  		button6 = GPIO_PORTE_DATA_R & 0x20;
  		  		LCD1602_DisplayDec(button6);
  				  		 SysTick_Delay1ms(1000);
  		button5 = GPIO_PORTE_DATA_R & 0x10;
  			LCD1602_DisplayDec(button5);
  			SysTick_Delay1ms(1000);
  		button4 = GPIO_PORTE_DATA_R & 0x08;
  		  		LCD1602_DisplayDec(button4);
  		  	  		  		 SysTick_Delay1ms(1000);
  		button3 = GPIO_PORTE_DATA_R & 0x04;
  			LCD1602_DisplayDec(button3);
  			SysTick_Delay1ms(1000);
  		button2 = GPIO_PORTE_DATA_R & 0x02;
  		  		LCD1602_DisplayDec(button2);
  		  	  		  		 SysTick_Delay1ms(1000);
  		button1 = GPIO_PORTE_DATA_R & 0x01;
  			LCD1602_DisplayDec(button1);
  		  		  		 SysTick_Delay1ms(1000);


  		  		  	LCD1602_Clear();
  		  		SysTick_Delay1ms(1000);


  		/*LCD1602_DisplayPosition(LINE1,0);
  		LCD1602_DisplayString("Girdiniz:");
  		SysTick_Delay1ms(1000);*/






  		if(button1 == 0){
  			yuzdebir = hane_arttir(yuzdebir);
  			LCD1602_DisplayPosition(LINE2,0);
  			//LCD1602_DisplayDec(yuzdebir);
  			//LCD1602_DisplayDec(1-button1);
  			LCD1602_DisplayString("bir");
  			 SysTick_Delay1ms(1000);
  			LCD1602_DisplayPosition(LINE2,5);
  			  			LCD1602_DisplayDec(button1);
  			  			SysTick_Delay1ms(1000);
  			  			SysTick_Delay1ms(1000);
  			  			  			  LCD1602_Clear();
  		}
  		else if(button2 == 0){

  			ondabir = hane_arttir(ondabir);
  			LCD1602_DisplayPosition(LINE1,12);
  			//LCD1602_DisplayDec(ondabir);
  			//LCD1602_DisplayDec(992);
  			LCD1602_DisplayString("iki");
  			SysTick_Delay1ms(1000);
  			LCD1602_DisplayPosition(LINE1,16);
  			LCD1602_DisplayDec(button2);
  			SysTick_Delay1ms(1000);
  			SysTick_Delay1ms(1000);
  			  			  LCD1602_Clear();

  		}
  		else if(button3 == 0){
  			birler = hane_arttir(birler);
  			LCD1602_DisplayPosition(LINE1,14);
  			//LCD1602_DisplayDec(birler);
  			LCD1602_DisplayString("uc");
  			SysTick_Delay1ms(1000);
  			  			  LCD1602_Clear();
  		}
  		else if(button4 == 0){
  			onlar = hane_arttir(onlar);
  			LCD1602_DisplayPosition(LINE1,15);
  			//LCD1602_DisplayDec(onlar);
  			LCD1602_DisplayString("Zort");
  			SysTick_Delay1ms(1000);
  			  			  LCD1602_Clear();
  		}
  		else if(button5 == 0){//RESET
  			birler=0;
  			onlar=0;
  			ondabir=0;
  			yuzdebir=0;
  			//LCDYİ TEMİZLE
  			LCD1602_DisplayString("bes");
  			SysTick_Delay1ms(1000);
  			  			  LCD1602_Clear();
  		}
  		else if(button6 == 0){//HESAPLA
  			para = onlar*10 + birler + ondabir/10 + yuzdebir/100;
  			bozdur(&dizi,banknotlar,para);
  			for(i=0;i<12;i++){
  				if(dizi[i] != 0){
  					/*LCD1602_DisplayPosition(LINE2,7);
  					LCD1602_DisplayDec(dizi[i]);
  					LCD1602_DisplayPosition(LINE2,8);
  					LCD1602_DisplayString("X");
  					LCD1602_DisplayPosition(LINE2,9);
  					LCD1602_DisplayDec(banknotlar[i]);
  				    SysTick_Delay1ms(1000);
  				    SysTick_Delay1ms(1000);
  				    SysTick_Delay1ms(1000);*/
  				}
  			}
  			birler=0;
  			onlar=0;
  			ondabir=0;
  			yuzdebir=0;
  			//LCD'Yİ TEMİZLE
  		}
  		/*LCD1602_DisplayPosition(LINE2,0);
  		LCD1602_DisplayDec(button6);
  		 SysTick_Delay1ms(1000);
  		LCD1602_DisplayDec(button5);
  		 SysTick_Delay1ms(1000);
  		LCD1602_DisplayDec(button4);
  		 SysTick_Delay1ms(1000);
  		LCD1602_DisplayDec(button3);
  		 SysTick_Delay1ms(1000);
  		LCD1602_DisplayDec(button2);
  		 SysTick_Delay1ms(1000);
  		LCD1602_DisplayDec(button1);
  		 SysTick_Delay1ms(1000);*/
  	}
}
