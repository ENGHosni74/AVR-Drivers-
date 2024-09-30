/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 8/2/2024      *************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_



void TIMERS_voidTimer0Init (void);

u8 TIMERS_u8Timer0OVFSetCallBack (void (*Copy_pf)(void));
u8 TIMERS_u8Timer0CTCSetCallBack (void (*Copy_pf)(void));

void TIMERS_u8Timer0SetCompareMatchValue (u8 Copy_u8OCR0Value);

#endif