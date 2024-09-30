/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 3/2/2024      *************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_PROGRAM_C_
#define TIMERS_PROGRAM_C_



#include "Std_types.h"
#include "Bit_utils.h"


#include "TIMERS_interface.h"
#include "TIMERS_register.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"


#include "DIO_interface.h"

/***********************************Global Pointers to Function **********************************/
static void  (*TIMERS_pfTimer0OVF)(void) = NULL;
static void  (*TIMERS_pfTimer0CTC)(void) = NULL;
/************************************************************************************************/

void TIMERS_voidTimer0Init (void)
{
	                /*Select TIMER0 mode */
	
	#if           TIMER0_MODE == NORMAL_MODE
	                /* Normal mode  */
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM01);
	
	#elif         TIMER0_MODE == PWM_MODE 
	                /* PWM, Phase Correct  mode  */
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM01);
	
	#elif         TIMER0_MODE == CTC_MODE
					/* Clear ON Compare match mode  */
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM01);
	
	#elif         TIMER0_MODE == FAST_PWM_MODE
	             /*Fast PWM mode*/
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_WGM01);
	
	#endif 
	
                     	/*Over Flow interrupt*/
#if              TIMERE0_OVERFLOW_STATE == ENABLE_OVERFLOW_INTERRUPT
	SET_BIT(TIMERS_U8_TIMSK_REG,TIMERS_TIMSK_TOIE0);
	
#elif            TIMERE0_OVERFLOW_STATE == DISABLE_OVERFLOW_INTERRUPT
	CLR_BIT(TIMERS_U8_TIMSK_REG,TIMERS_TIMSK_TOIE0);
#endif

                          /*CTC interrupt*/
#if              TIMER0_CTC_INTERRUPT_STATE == ENABLE_CTC_INTERRUPT
    SET_BIT(TIMERS_U8_TIMSK_REG,TIMERS_TIMSK_OCIE0);

#elif            TIMER0_CTC_INTERRUPT_STATE == DISABLE_CTC_INTERRUPT
    CLR_BIT(TIMERS_U8_TIMSK_REG,TIMERS_TIMSK_OCIE0);
#endif

	                      /*Set preLoad value*/
	TIMERS_U8_TCNT0_REG = TIMER0_PRELOAD;

	                      /*Set Compare match unit register*/
	TIMERS_U8_OCR0_REG = TIMER0_CTC_VALUE;

                          /*Set preScaler*/
#if               TIMER0_PRESCALER_MODE  == TIMER_OFF

	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == DIVIDED_BY_1

	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == DIVIDED_BY_8

	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == DIVIDED_BY_64

	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == DIVIDED_BY_256

	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);


#elif             TIMER0_PRESCALER_MODE  == DIVIDED_BY_1024

	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == TO_FALLING

	CLR_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#elif             TIMER0_PRESCALER_MODE  == TO_RISING

	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS00);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS01);
	SET_BIT (TIMERS_U8_TCCR0_REG,TIMERS_TCCR0_CS02);

#endif
}

u8 TIMERS_u8Timer0OVFSetCallBack (void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pf != NULL)
	{
		TIMERS_pfTimer0OVF = Copy_pf ;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

u8 TIMERS_u8Timer0CTCSetCallBack (void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pf != NULL)
	{
		TIMERS_pfTimer0CTC = Copy_pf ;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

/**************************************Prototype for ISR of TIMER0 OverFlow***************************/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u16 Locale_u16CounterOVF = 0;


	Locale_u16CounterOVF++;
	if (Locale_u16CounterOVF == TIMER0_OVF_REQ_NO)
	{
		/*Update preLoad value*/
		TIMERS_U8_TCNT0_REG = TIMER0_PRELOAD;
		/*Clear OverFlow Counter*/
		Locale_u16CounterOVF = 0;
		/*Call App Function*/
		if (TIMERS_pfTimer0OVF != NULL)
		{
			TIMERS_pfTimer0OVF();
		}
	}


}
/*****************************************************************************************************/

/**************************************Prototype for ISR of TIMER0 CTC *******************************/

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{

	static u16 Local_u16CounterCTC = 0;

	Local_u16CounterCTC++;

	if (Local_u16CounterCTC == TIMER0_CTC_REQ_NO)
	{
		/*Clear CTC Counter*/
		Local_u16CounterCTC = 0;
		/*Call App Function*/
		if (TIMERS_pfTimer0CTC != NULL)
		{
			TIMERS_pfTimer0CTC();
		}
	}


}


#endif
