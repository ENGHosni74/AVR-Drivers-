/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 8/2/2024      *************************/
/************************* SWC      : EXTI          *************************/
/************************* VERSION  : 1.1           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_




#define EXTI_GICR_REG      *((volatile u8 * ) 0x5B)
#define EXTI_GICR_INT1               7
#define EXTI_GICR_INT0               6
#define EXTI_GICR_INT2               5





#define EXTI_GIFR_REG      *((volatile u8 * ) 0x5A)
#define EXTI_GIFR_INTF1               7
#define EXTI_GIFR_INTF0               6
#define EXTI_GIFR_INTF2               5



#define EXTI_MCUCR_REG      *((volatile u8 * ) 0x55)
#define EXTI_MCUCR_ISC11               3
#define EXTI_MCUCR_ISC10               2
#define EXTI_MCUCR_ISC01               1
#define EXTI_MCUCR_ISC00               0





#define EXTI_MCUCSR_REG     *((volatile u8 * ) 0x54)

#define EXTI_MCUCSR_ISC2               6  









#endif
