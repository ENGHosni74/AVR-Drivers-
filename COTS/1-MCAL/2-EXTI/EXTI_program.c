/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 8/2/2024      *************************/
/************************* SWC      : EXTI          *************************/
/************************* VERSION  : 1.1           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef EXTI_PROGRAM_C_
#define EXTI_PROGRAM_C_



#include "Std_types.h"
#include "Bit_utils.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/************************************** Global Pointers ********************************************/
static void (*EXTI_pfINT0CallBack) (void) = NULL;
static void (*EXTI_pfINT1CallBack) (void) = NULL;
static void (*EXTI_pfINT2CallBack) (void) = NULL;


/***************************************************************************************************/


void EXTI_voidInt0Init(void)
{
	                  /*Set INT0 SENS CONTROL FOR INT0*/

	     /*LOW LEVEL MODE*/
#if              INT0_SENS_MODE==LOW_LEVEL_MODE

	    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);

	    /*ON CHANGE MODE*/
#elif            INT0_SENS_MODE==ON_CHANGE_MODE

	    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);

	    /*FALLING EDGE MODE*/
#elif            INT0_SENS_MODE==FALL_EDGE_MODE

	    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);

	    /*RISING EDGE MODE*/
#elif            INT0_SENS_MODE==RISE_EDGE_MODE

	    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);

#endif

	    /*ENABLE INTERRUPT PERIPHERAL FOR INT0*/
	    SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT0);
}









void EXTI_voidInt1Init(void)
{
                        /*Set INT1 SENS CONTROL FOR INT0*/

        /*LOW LEVEL MODE*/
#if              INT1_SENS_MODE==LOW_LEVEL_MODE

    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);

        /*ON CHANGE MODE*/
#elif            INT1_SENS_MODE==ON_CHANGE_MODE

    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);

         /*FALLING EDGE MODE*/
#elif            INT1_SENS_MODE==FALL_EDGE_MODE

    CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);

          /*RISING EDGE MODE*/
#elif            INT1_SENS_MODE==RISE_EDGE_MODE

    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
    SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);

    /*ENABLE INTERRUPT PERIPHERAL FOR INT0*/
    SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT1);

#endif
}










void EXTI_voidInt2Init(void)
{

                         /*Set INT1 SENS CONTROL FOR INT2*/

        /*FALLING EDGE MODE*/
#if              INT2_SENS_MODE==FALL_EDGE_MODE

	 CLR_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);

        /*RISING EDGE MODE*/
#elif            INT2_SENS_MODE==RISE_EDGE_MODE

	 SET_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);

#endif
	/*ENABLE INTERRUPT PERIPHERAL FOR INT2*/
	SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT2);
}

u8 EXTI_u8INT0SetCallBack (void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pf!= NULL)
	{
	/*Set Call Back Function*/
	EXTI_pfINT0CallBack = Copy_pf ;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}









u8 EXTI_u8INT1SetCallBack (void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pf!= NULL)
	{
	/*Set Call Back Function*/
	EXTI_pfINT1CallBack = Copy_pf ;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}










u8 EXTI_u8INT2SetCallBack (void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pf!= NULL)
	{
	/*Set Call Back Function*/
	EXTI_pfINT2CallBack = Copy_pf ;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}


/************************************** Prototype for EXTI ISR ************************************/

/************************************** EXTI INT0 ISR *********************************************/

void __vector_1 (void) __attribute__((signal));
void __vector_1 ()
{

  /*Call The call back function for INT0*/
	EXTI_pfINT0CallBack ();
}
/**************************************************************************************************/


/************************************** EXTI INT1 ISR *********************************************/
void __vector_2 (void) __attribute__((signal));
void __vector_2 ()
{

  /*Call The call back function for INT1*/
	EXTI_pfINT1CallBack ();
}
/**************************************************************************************************/


/************************************** EXTI INT2 ISR *********************************************/

void __vector_3 (void) __attribute__((signal));
void __vector_3 ()
{

  /*Call The call back function for INT2*/
	EXTI_pfINT2CallBack ();
}
/**************************************************************************************************/










#endif
