/*
===============================================================================
 Name        : Ejercitacion_ADC.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "fw_adc.h"
#include "pr_adc.h"

// TODO: insert other definitions and declarations here
#define MAX_SAMPLES 500

int main(void)
{
    static uint32_t acum =0;
    static uint32_t count = 0;

    uint16_t value;

	SystemCoreClockUpdate();
    Board_Init();
    FW_InitADC_InterruptMode();

    while(1)
    {
    	value = GetCountADC(ADC_CH0);

    	if(value != NO_ADC_VALUE)
    	{
    		acum += value;
    		count++;
    	}

    	if(count >= MAX_SAMPLES)
    	{
    		printf("Valor promedio de medicion %d\n",acum/MAX_SAMPLES);
    		printf("Valor de tension promedio %.2f\n",(float)(acum/MAX_SAMPLES)*ADC_LSB);
    		acum = count = 0;
    	}
        __asm volatile ("nop");
    }
    return 0 ;
}
