/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 3/2/2024      *************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_

#define TIMERS_U8_TIMSK_REG           *((volatile u8 * ) 0x59)
#define TIMERS_TIMSK_OCIE0                      1
#define TIMERS_TIMSK_TOIE0                      0




#define TIMERS_U8_TIFR_REG            *((volatile u8 * ) 0x58)
#define TIMERS_TIFR_OCF0                        1
#define TIMERS_TIFR_TOV0                        0


#define TIMERS_U8_TCCR0_REG           *((volatile u8 * ) 0x53)
#define TIMERS_TCCR0_FOC0                       7
#define TIMERS_TCCR0_WGM00                      6
#define TIMERS_TCCR0_COM01                      5
#define TIMERS_TCCR0_COM00                      4
#define TIMERS_TCCR0_WGM01                      3
#define TIMERS_TCCR0_CS02                       2
#define TIMERS_TCCR0_CS01                       1
#define TIMERS_TCCR0_CS00                       0


#define TIMERS_U8_TCNT0_REG           *((volatile u8 * ) 0x52)


#define TIMERS_U8_OCR0_REG            *((volatile u8 * ) 0x5C)









#endif