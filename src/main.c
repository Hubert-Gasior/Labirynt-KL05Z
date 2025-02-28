#include "MKL05Z4.h"
#include "ADC.h"
#include "pit.h"
#include "TPM.h"
#include "frdm_bsp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

volatile uint8_t wynik_ok_x=0;
volatile uint8_t wynik_ok_y=0;
volatile uint16_t dir;
volatile uint16_t dir_y;
volatile float	wynik_x;
volatile float	wynik_y;

volatile uint16_t cnvy = 0x410;
volatile uint16_t cnvx = 0x3D4;

void ADC0_IRQHandler()
{
    static uint8_t current_channel = 8;
    static float filtered_x = 0;        
    static float filtered_y = 0;
    uint16_t dir = ADC0->R[0];         // Odczyt danych i skasowanie flagi COCO
    
    if (current_channel == 8) {
        wynik_x = dir;
				filtered_x = filtered_x * 0.9 + wynik_x * 0.1;		//filtracja
        wynik_x = filtered_x;
        current_channel = 6;
				wynik_ok_x = 1;
    } else if (current_channel == 6) {
        wynik_y = dir; 
				filtered_y = filtered_y * 0.9 + wynik_y * 0.1;		//filtracja
        wynik_y = filtered_y;
        wynik_ok_y = 1;
        current_channel = 8;            
    }
    
    ADC0->SC1[0] = ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(current_channel); 
}

int main (void)
{
	uint8_t	kal_error;
	PWM_Init();
	
	kal_error=ADC_Init();		// Inicjalizacja i kalibracja przetwornika A/C
	if(kal_error)
	{
		while(1);							// Klaibracja się nie powiodła
	}
	
	ADC0->SC1[0] = ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(8);		// Odblokowanie przerwania i wybranie kanału nr 8
	PIT_Init();							// Inicjalizacja licznika PIT0
	
	while(1)
	{
		TPM0->CONTROLS[2].CnV = cnvy;
		TPM0->CONTROLS[3].CnV = cnvx; 
		
		if(wynik_ok_x)
		{
			wynik_x = 900 + (wynik_x/4000)*300;		
			cnvx = wynik_x;
			wynik_ok_x=0;
		}
		
		if(wynik_ok_y)
		{
			wynik_y = 900 + (wynik_y/4000)*150;		
			wynik_ok_y=0;
		}
	}
}
