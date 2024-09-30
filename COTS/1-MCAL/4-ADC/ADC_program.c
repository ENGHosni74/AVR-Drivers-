/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 3/2/2024      *************************/
/************************* SWC      : ADC           *************************/
/************************* VERSION  : 2.1           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef    ADC_PROGRAM_C_
#define    ADC_PROGRAM_C_



#include "Std_types.h"
#include "Bit_utils.h"


#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"



/************************************* Global Variables *********************************************/

static void (*ADC_pfNotification) (u16 Copy_ADCValue) = NULL;
/*ADC BUSY FLAG*/
static u8 ADC_u8BusyFlag = ADC_READY;

/***************************************** Functions ************************************************/
void ADC_voidInit (void)
{
	/* 
	  1- select  VRef = AVCC
	  2- Right   adjust
	  3- Disable Auto Trigger
	  4- Select  CLK  divided by 64
	  5- Enable  ADC
	*/
	
	                         /*Set VRef */
#if                             VReff_Mode==EXTERNAL_AREF_VREFF
	/*External VReff at pin AREF*/
	CLR_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS1 );
	CLR_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS2 );



#elif                           VReff_Mode==EXTERNAL_AVCC_VREFF
	/*External VReff at pin AVCC*/

	CLR_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS1 );
	SET_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS2 );
	
#elif                           VReff_Mode==INTERNAL_VREFF
    /*Internal VReff */

	SET_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS1 );
	SET_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_REFS2 );

#endif

                     /*Select Adjustment mode */
#if                             Adjustment_Mode==RIGHT_ADJUSTMENT
	/*Set Right  Adjust */

	CLR_BIT ( ADC_U8_ADMUX_REG , ADC_ADMUX_ADLAR );
	
#elif                           Adjustment_Mode==LEFT_ADJUSTMENT

	/*Set Left Adjust */

	SET_BIT( ADC_U8_ADMUX_REG , ADC_ADMUX_ADLAR );

#endif

	/*Set Auto Trigger Mode*/
#if                             Auto_Trigger_Mode==DISABLE_AUTO_TRIGGER
	/*Disable AutoTrigger */
	CLR_BIT( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADATE );

#elif                           Auto_Trigger_Mode==ENABLE_AUTO_TRIGGER


		 /*Set bits ADTS2..0 For ADC Mode*/
	#if                         Auto_Trigger_Source_Mode==FREE_RUNNINGMODE

		/*Set bits ADTS2..0 for Free Running Mode*/
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );


	#elif                       Auto_Trigger_Source_Mode==ANALOG_COMPARATOR_MODE

		/*Set bits ADTS2..0 for Analog Comparator Mode*/
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==EXTERNAL_INTERRUPT_REQUEST_0

		/*Set bits ADTS2..0 for External interrupt request 0 Mode*/
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==TIMER0_COUNTER0_COMPARE_MATCH

		/*Set bits ADTS2..0 for Timer/Counter0 Compare Match Mode*/
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==TIMER0_COUNTER0_OVERFLOW

		/*Set bits ADTS2..0 for Timer/Counter0 Overflow Mode*/
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==TIMER_COUNTER_COMPARE_MATCH_B

		/*Set bits ADTS2..0 for Timer/Counter Compare Match B Mode*/
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==TIMER1_COUNTER1_OVERFLOW

		/*Set bits ADTS2..0 for Timer/Counter1 Overflow Mode*/
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		CLR_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#elif                       Auto_Trigger_Source_Mode==TIMER1_COUNTER1_CAPTURE_EVENT

		/*Set bits ADTS2..0 for Timer/Counter1 Capture Event Mode*/
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS2 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS1 );
		SET_BIT ( ADC_U8_SFIOR_REG , ADC_SFIOR_ADTS0 );

	#endif

    /*Enable Auto Trigger*/
	SET_BIT( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADATE );
#endif

#if                             ADC_PreScaler_Mode==DIVIDED_BY_2
	/*set PreScaler /2  */
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
  	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );

#elif                           ADC_PreScaler_Mode==DIVIDED_BY_4
	/*set PreScaler /4  */
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );

#elif                           ADC_PreScaler_Mode==DIVIDED_BY_16
	/*set PreScaler /16 */
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );

#elif                           ADC_PreScaler_Mode==DIVIDED_BY_32
	/*set PreScaler /32 */
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
  	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
  	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );

#elif                           ADC_PreScaler_Mode==DIVIDED_BY_64
	/*set PreScaler /64 */
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
	CLR_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );

#elif                           ADC_PreScaler_Mode==DIVIDED_BY_128
	/*set PreScaler /128 */
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS2 );
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS1 );
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADPS0 );
	
#endif



	/*ADC ENABLE*/
	SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADEN );
	
}

u8 ADC_u8GetReadSyncNonBlocking (u8 Copy_ChannelNum, u16 * Copy_pu16Read)
{
	u8 LocalStateError = OK;
	u32 Local_TimeOutCounter = 0 ;
	
	if (( Copy_ChannelNum < ADC_CHANNELS_MAXNUM )&&( Copy_pu16Read != NULL))
	{
		/*Clear ADMUX4..0*/
		ADC_U8_ADMUX_REG &= ADC_ADMUX_ClRMASK;

		/*ADC select channel*/
		ADC_U8_ADMUX_REG |= Copy_ChannelNum ;
		
		/*ADC Start Conversion*/
		SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADSC );

		/*wait for flag*/
		while ((!GET_BIT(ADC_U8_ADCSRA_REG,ADC_ADCSRA_ADIF))&&(Local_TimeOutCounter < ADC_U32_TIMEOUT_MAXVALUE ))
		{
			Local_TimeOutCounter++;

		}
		if ((GET_BIT(ADC_U8_ADCSRA_REG,ADC_ADCSRA_ADIF)))
		{
		 /*Clear flag*/
		 SET_BIT(ADC_U8_ADCSRA_REG,ADC_ADCSRA_ADIF);

		 /*Read Digital value */
		 *Copy_pu16Read = ADC_U16_ADC_REG ;
		}
		else 
		{
			LocalStateError =NOK;
		}
	}
	else 
	{
		LocalStateError = NOK;
	}
	return LocalStateError ;
}



u8 ADC_u8GetReadAsync (u8 Copy_ChannelNum , void (*Copy_pfNotification) (u16 Copy_ADCValue))
{
	u8 LocalStateError = OK;

    if (( Copy_ChannelNum < 32)&& (*Copy_pfNotification != NULL) && ( ADC_u8BusyFlag == ADC_READY ))
    {
    	/*Set ADC BUSY FLAG*/
    	ADC_u8BusyFlag = ADC_BUSY ;

      /* Update Global Pointer to function */
    	ADC_pfNotification = Copy_pfNotification ;

    	/*Enable ADC Interrupt*/
    	SET_BIT (ADC_U8_ADCSRA_REG,ADC_ADCSRA_ADIE);

    	/*Clear ADMUX4..0*/
		ADC_U8_ADMUX_REG &= ADC_ADMUX_ClRMASK;

		/*ADC select channel*/
		ADC_U8_ADMUX_REG |= Copy_ChannelNum ;

		/*ADC Start Conversion*/
		SET_BIT ( ADC_U8_ADCSRA_REG , ADC_ADCSRA_ADSC );
    }
    else
    {
    	LocalStateError = NOK;
    }
return LocalStateError ;
}

u8 ADC_u8GetADCRegValue (u16 * Copy_pu16ADCValue)
{
	u8 LocalStateError = OK;

	if (Copy_pu16ADCValue != NULL)
	{
    /* Read ADC Register */

    *Copy_pu16ADCValue= ADC_U16_ADC_REG ;

	}
	else
	{
		LocalStateError=NOK;
	}

	return LocalStateError;
}


/************************************** Prototype for ADC ISR *****************************************/
void __vector_16 (void) __attribute__ ((signal));
void __vector_16 (void)
{
	if (ADC_pfNotification!= NULL )
	{
		/*Clear ADC BUSY FLAG*/
		ADC_u8BusyFlag = ADC_READY;

		/* Disable Interrupt */
    	CLR_BIT (ADC_U8_ADCSRA_REG,ADC_ADCSRA_ADIE);

    	/* Call Notification Function */
		ADC_pfNotification(ADC_U16_ADC_REG);
	}

}










#endif
