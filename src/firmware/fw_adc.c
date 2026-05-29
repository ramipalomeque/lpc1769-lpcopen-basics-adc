/*
 * 		  File: /Ejercitacion_ADC/src/firmware/fw_adc.c
 *  Created on: 25 abr. 2026
 *      Author: Ramiro
 */

/* ============================================================================
 * PUBLIC HEADER INCLUDES
 * ============================================================================
 */
#include "fw_gpio.h"
 

/* ============================================================================
 * PRIVATE HEADER INCLUDES
 * ============================================================================
 */
#include "fw_adc.h"

/* ============================================================================
 * LOCAL DEFINES
 * ============================================================================
 */



/* ============================================================================
 * LOCAL MACROS
 * ============================================================================
 */



/* ============================================================================
 * GLOBAL VARIABLES
 * ============================================================================
 */
gpio_t adc_ch0 = {0,23};

uint16_t buffer_adc_ch0 = 0;



/* ============================================================================
 * STATIC VARIABLES (FILE-SCOPE)
 * ============================================================================
 */

static ADC_CLOCK_SETUP_T ADCSetup;


/* ============================================================================
 * FUNCTION DEFINITIONS
 * ============================================================================
 */

void FW_InitADC_InterruptMode()
{


	Chip_IOCON_PinMux(LPC_IOCON,adc_ch0.port,adc_ch0.pin,IOCON_MODE_INACT,IOCON_FUNC1);


	Chip_ADC_Init(LPC_ADC, &ADCSetup);									// Inicializar el ADC
	Chip_ADC_EnableChannel(LPC_ADC, ADC_CH0, ENABLE);					// Habilitar el canal ADC 0
	Chip_ADC_SetSampleRate(LPC_ADC, &ADCSetup , ADC_MAX_SAMPLE_RATE);	// Configurar la tasa de muestreo
	Chip_ADC_Int_SetChannelCmd(LPC_ADC, ADC_CH0, ENABLE);				// Habilitar interrupciones del ADC para el canal 0


    NVIC_ClearPendingIRQ(ADC_IRQn);										// Limpiar flags de interrupciones del ADC
	NVIC_EnableIRQ(ADC_IRQn);											// Habilitar interrupciones del ADC

	Chip_ADC_SetStartMode(LPC_ADC, ADC_START_NOW, ADC_TRIGGERMODE_RISING); 		// Lanzo una conversion unica

	return;
}

void ADC_IRQHandler(void)
{
	uint16_t ADCvalue;

	if(Chip_ADC_ReadValue(LPC_ADC, ADC_CH0,&ADCvalue)==SUCCESS)					// Si pude obtener el valor del adc
	{
		buffer_adc_ch0 = ADCvalue;												// Guardo en el buffer
		Chip_ADC_SetStartMode(LPC_ADC, ADC_START_NOW, ADC_TRIGGERMODE_RISING); 	// Lanzo una conversion unica
	}

	return;
}
