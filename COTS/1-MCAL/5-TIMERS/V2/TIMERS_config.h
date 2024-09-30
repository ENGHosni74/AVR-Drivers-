/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 8/2/2024      *************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_



/* Timer 0 Mode Selection Option
 * 1- NORMAL_MODE
 * 2- PWM_PHASE_CORRECT_MODE
 * 3- CTC_MODE
 * 4- FAST_PWM_MODE
 * */
#define TIMER0_MODE                                                        PWM_PHASE_CORRECT_MODE

/* Fast PWM Mode Selection Option
 * 1- Normal port operation, OC0 disconnected    (FPWM_DISCONNECTED)
 * 2- Clear OC0 on compare match, set OC0 at TOP (FPWM_NON_INVERTING_MODE)
 * 3- Set OC0 on compare match, clear OC0 at TOP (FPWM_INVERTING_MODE)
 * */
#define FPWM_MODE                                                          FPWM_NON_INVERTING_MODE

/* Phase Correct PWM Mode Selection Option
 * 1- Normal port operation, OC0 disconnected    (PHASE_PWM_DISCONNECTED)
 * 2- Clear OC0 on compare match when up-counting. Set OC0 on compare
	  match when downcounting. (PHASE_PWM_NON_INVERTING_MODE)
 * 3- Set OC0 on compare match when up-counting. Clear OC0 on compare
	  match when downcounting. (PHASE_PWM_INVERTING_MODE)
 * */
#define PHASE_CORRECT_PWM_MODE                                             PHASE_PWM_NON_INVERTING_MODE

/* Timer 0 Overflow Interrupt Options
 * 1-ENABLE_OVERFLOW_INTERRUPT
 * 2-DISABLE_OVERFLOW_INTERRUPT
 */
#define TIMERE0_OVERFLOW_STATE                                             DISABLE_OVERFLOW_INTERRUPT

/* Timer 0 Compare match Interrupt Options
 * 1-ENABLE_CTC_INTERRUPT
 * 2-DISABLE_CTC_INTERRUPT
 */
#define TIMER0_CTC_INTERRUPT_STATE                                         DISABLE_CTC_INTERRUPT

/* Timer 0 CTC Operation Mode on pin OC0 "Non PWM Options"
 * 1- Normal port operation, OC0 disconnected (CTC_NORMAL_MODE)
 * 2- CTC_TOGGLE_MODE
 * 3- CTC_CLEAR_MODE
 * 4- CTC_SET_MODE
 */
#define TIMER0_CTC_MODE                                                   CTC_NORMAL_MODE

/*Set your preLoad value*/
#define TIMER0_PRELOAD                                                     0

/*Set number of overflow required before the action starts*/
#define TIMER0_OVF_REQ_NO                                                  3907

/*Set Compare match unit register*/
#define TIMER0_CTC_VALUE                                                   240

/*Set number of Compare match "CTC" required before the action starts*/
#define TIMER0_CTC_REQ_NO                                                  10000

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
#define TIMER0_PRESCALER_MODE                                              DIVIDED_BY_8






#endif
