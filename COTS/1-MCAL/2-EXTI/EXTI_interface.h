/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 8/2/2024      *************************/
/************************* SWC      : EXTI          *************************/
/************************* VERSION  : 1.1           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

u8 EXTI_u8INT0SetCallBack (void (*Copy_pf)(void));

u8 EXTI_u8INT1SetCallBack (void (*Copy_pf)(void));

u8 EXTI_u8INT2SetCallBack (void (*Copy_pf)(void));















#endif
