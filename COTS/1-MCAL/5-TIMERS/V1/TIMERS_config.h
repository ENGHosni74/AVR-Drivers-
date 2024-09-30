/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 3/2/2024      *************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_



/* Timer 0 Mode Selection Option
 * 1- NORMAL_MODE
 * 2- PWM_MODE
 * 3- CTC_MODE
 * 4- FAST_PWM_MODE
 * */
#define TIMER0_MODE                               CTC_MODE

/* Timer 0 Overflow Interrupt Options
 * 1-ENABLE_OVERFLOW_INTERRUPT
 * 2-DISABLE_OVERFLOW_INTERRUPT
 */
#define TIMERE0_OVERFLOW_STATE                    DISABLE_OVERFLOW_INTERRUPT

/* Timer 0 Compare match Interrupt Options
 * 1-ENABLE_CTC_INTERRUPT
 * 2-DISABLE_CTC_INTERRUPT
 */
#define TIMER0_CTC_INTERRUPT_STATE                ENABLE_CTC_INTERRUPT

/*Set your preLoad value*/

#define TIMER0_PRELOAD                            0

/*Set number of overflow required before the action starts*/
#define TIMER0_OVF_REQ_NO                         3907

/*Set Compare match unit register*/
#define TIMER0_CTC_VALUE                          99

/*Set number of Compare match "CTC" required before the action starts*/
#define TIMER0_CTC_REQ_NO                         10000

/* Timer 0 preScaler Options
 * 1-No clock source (TIMER_OFF)
 * 2-No PreScaler (DIVIDED_BY_1)
 * 3-DIVIDED_BY_8
 * 4-DIVIDED_BY_64
 * 5-DIVIDED_BY_256
 * 6-DIVIDED_BY_1024
 * 7-External clock source on T0 pin Falling edge (TO_FALLING)
 * 8-External clock source on T0 pin Rising edge (TO_RISING)
 */
#define TIMER0_PRESCALER_MODE                     DIVIDED_BY_8



#endif
