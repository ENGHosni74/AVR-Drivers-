/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 25/12/2021    *************************/
/************************* SWC      : DIO           *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef DIO_INTERFACE_H_                                  
#define DIO_INTERFACE_H_                                         

#define DIO_u8_PORTA       0
#define DIO_u8_PORTB       1
#define DIO_u8_PORTC       2
#define DIO_u8_PORTD       3

#define DIO_U8_PIN0        0  
#define DIO_U8_PIN1        1 
#define DIO_U8_PIN2        2
#define DIO_U8_PIN3        3
#define DIO_U8_PIN4        4
#define DIO_U8_PIN5        5
#define DIO_U8_PIN6        6
#define DIO_U8_PIN7        7



#define DIO_PIN_HIGH       1
#define DIO_PIN_LOW        0

#define DIO_PORT_HIGH      0xff
#define DIO_PORT_LOW       0

#define DIO_PIN_OUT        1
#define DIO_PIN_INPUT      0

#define DIO_PORT_OUTPUT    0xff
#define DIO_PORT_INPUT     0











u8 DIO_u8SetPinDirection  (u8 Copy_u8Port ,u8 Copy_u8PinNum  ,u8 Copy_u8PinDirection);

u8 DIO_u8SetPortDirection (u8 Copy_u8Port ,u8 Copy_u8PortDirection);
                                           
u8 DIO_u8SetPinValue      (u8 Copy_u8Port ,u8 Copy_u8PinNum  ,u8 Copy_u8PinValue);

u8 DIO_u8SetPortValue     (u8 Copy_u8Port ,u8 Copy_u8PortValue);

u8 DIO_u8GetPinValue      (u8 Copy_u8Port ,u8 Copy_u8PinNum , u8 * Copy_u8PinValue);







#endif