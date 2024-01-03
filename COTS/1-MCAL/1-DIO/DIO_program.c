/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 25/12/2021    *************************/
/************************* SWC      : DIO           *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef DIO_PROGRAM_C_
#define DIO_PROGRAM_C_


#include "Std_types.h"
#include "Bit_utils.h"



#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"









u8 DIO_u8SetPinDirection  (u8 Copy_u8Port ,u8 Copy_u8PinNum  ,u8 Copy_u8PinDirection)
{  
    u8 LocalStateError = OK;
	
	if ( Copy_u8Port < Max_Port_Num )
		{ 
		  if (Copy_u8PinNum < Max_Pin_Num )
		  {
			 if( Copy_u8PinDirection == DIO_PIN_OUT )
			 {
				  switch (Copy_u8Port)
				  {
				  case DIO_u8_PORTA  : SET_BIT(DIO_DDRA,Copy_u8PinNum); break;
				  case DIO_u8_PORTB  : SET_BIT(DIO_DDRB,Copy_u8PinNum); break;
				  case DIO_u8_PORTC  : SET_BIT(DIO_DDRC,Copy_u8PinNum); break;
				  case DIO_u8_PORTD  : SET_BIT(DIO_DDRD,Copy_u8PinNum); break;
				  default : LocalStateError = NOK ;
				  }
			 }
			 else if (Copy_u8PinDirection == DIO_PIN_INPUT)
			 {
				  switch (Copy_u8Port) 
				  {
				  case DIO_u8_PORTA  : CLR_BIT(DIO_DDRA,Copy_u8PinNum); break;
				  case DIO_u8_PORTB  : CLR_BIT(DIO_DDRB,Copy_u8PinNum); break;
				  case DIO_u8_PORTC  : CLR_BIT(DIO_DDRC,Copy_u8PinNum); break;
				  case DIO_u8_PORTD  : CLR_BIT(DIO_DDRD,Copy_u8PinNum); break; 
				  default : LocalStateError = NOK ;
				 }
			 }
			 else 
			 {
				 LocalStateError = NOK ;
			 }
		  }
		  else
		  {
			  LocalStateError = NOK;
		  }
	 
		}
		else 
		{
			LocalStateError = NOK;
		}	

 return LocalStateError ;		
}

u8 DIO_u8SetPortDirection (u8 Copy_u8Port ,u8 Copy_u8PortDirection)
{
	u8 LocalStateError = OK;
	 if ( Copy_u8Port < Max_Port_Num )
	 {
		  switch (Copy_u8Port)
			  {
			  case DIO_u8_PORTA  : DIO_DDRA = Copy_u8PortDirection; break;
			  case DIO_u8_PORTB  : DIO_DDRB = Copy_u8PortDirection; break;
			  case DIO_u8_PORTC  : DIO_DDRC = Copy_u8PortDirection; break;
			  case DIO_u8_PORTD  : DIO_DDRD = Copy_u8PortDirection; break;
			  default : LocalStateError = NOK ;
			  }
	 }
	 else
	 {
		LocalStateError = NOK ;  
	 }
 return LocalStateError;	
}
                                           
u8 DIO_u8SetPinValue      (u8 Copy_u8Port ,u8 Copy_u8PinNum , u8 Copy_u8PinValue )
{
	u8 LocalStateError = OK;
	 if ( Copy_u8Port < Max_Port_Num )
	{ 
      if (Copy_u8PinNum < Max_Pin_Num )
	  {
		 if( Copy_u8PinValue == DIO_PIN_HIGH )
		 {
			  switch (Copy_u8Port)
			  {
			  case DIO_u8_PORTA  : SET_BIT(DIO_PORTA,Copy_u8PinNum); break;
			  case DIO_u8_PORTB  : SET_BIT(DIO_PORTB,Copy_u8PinNum); break;
			  case DIO_u8_PORTC  : SET_BIT(DIO_PORTC,Copy_u8PinNum); break;
			  case DIO_u8_PORTD  : SET_BIT(DIO_PORTD,Copy_u8PinNum); break;
			  default : LocalStateError = NOK ;
			  }
		 }
		 else if (Copy_u8PinValue == DIO_PIN_LOW)
		 {
			  switch (Copy_u8Port) 
			  {
			  case DIO_u8_PORTA  : CLR_BIT(DIO_DDRA,Copy_u8PinNum); break;
			  case DIO_u8_PORTB  : CLR_BIT(DIO_DDRB,Copy_u8PinNum); break;
			  case DIO_u8_PORTC  : CLR_BIT(DIO_DDRC,Copy_u8PinNum); break;
			  case DIO_u8_PORTD  : CLR_BIT(DIO_DDRD,Copy_u8PinNum); break; 
			  default : LocalStateError = NOK ;
			 }
		 }
		 else 
		 {
			 LocalStateError = NOK ;
		 }
	  }
	  else
	  {
		  LocalStateError = NOK;
	  }
 
	}
    else 
	{
		LocalStateError = NOK;
	}		
 return LocalStateError
}




u8 DIO_u8SetPortValue     (u8 Copy_u8Port ,u8 Copy_u8PortValue)
{
	    u8 LocalStateError = OK;

	 if ( Copy_u8Port < Max_Port_Num )
	 {
		  switch (Copy_u8Port)
			  {
			  case DIO_u8_PORTA  : DIO_PORTA = Copy_u8PortValue; break;
			  case DIO_u8_PORTB  : DIO_PORTB = Copy_u8PortValue; break;
			  case DIO_u8_PORTC  : DIO_PORTC = Copy_u8PortValue; break;
			  case DIO_u8_PORTD  : DIO_PORTD = Copy_u8PortValue; break;
			  default : LocalStateError = NOK ;
			  }
	 }
	 else
	 {
		LocalStateError = NOK ;  
	 }
return LocalStateError;
}

u8 DIO_u8GetPinValue      (u8 Copy_u8Port ,u8 Copy_u8PinNum , u8 * Copy_u8PinValue)
{
	u8 LocalStateError =OK;
	
	 if ( Copy_u8Port < Max_Port_Num )
	{ 
		  if (Copy_u8PinNum < Max_Pin_Num )
		  {
			  switch (Copy_u8Port)
				  {
				  case DIO_u8_PORTA  : * Copy_u8PinValue = GET_BIT(DIO_PINA,Copy_u8PinNum); break;
				  case DIO_u8_PORTB  : * Copy_u8PinValue = GET_BIT(DIO_PINB,Copy_u8PinNum); break;
				  case DIO_u8_PORTC  : * Copy_u8PinValue = GET_BIT(DIO_PINC,Copy_u8PinNum); break;
				  case DIO_u8_PORTD  : * Copy_u8PinValue = GET_BIT(DIO_PIND,Copy_u8PinNum); break;
				  default : LocalStateError = NOK ;
				  }
		 }
		 else 
		 {
			 LocalStateError = NOK ;
		 }
	}
	else
	{
	  LocalStateError = NOK;
	}	
return LocalStateError;
}

#endif