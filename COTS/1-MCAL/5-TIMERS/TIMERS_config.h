/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 10/2/2024      ************************/
/************************* SWC      : TIMERS        *************************/
/************************* VERSION  : 3.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_



/*****************************************************************************************************/
/******************************** Timer 0 Configuration  *********************************************/
/*****************************************************************************************************/

/* Timer 0 Mode Selection Option
 * 1- NORMAL_MODE
 * 2- PWM_PHASE_CORRECT_MODE
 * 3- CTC_MODE
 * 4- FAST_PWM_MODE
 * */
#define TIMER0_MODE                                                        NORMAL_MODE

/* Fast PWM Mode Selection Option
 * 1- Normal port operation, OC0 disconnected    (TIMER0_FPWM_DISCONNECTED)
 * 2- Clear OC0 on compare match, set OC0 at TOP (TIMER0_FPWM_NON_INVERTING_MODE)
 * 3- Set OC0 on compare match, clear OC0 at TOP (TIMER0_FPWM_INVERTING_MODE)
 * */
#define TIMER0_FPWM_MODE                                                   TIMER0_FPWM_DISCONNECTED

/* Phase Correct PWM Mode Selection Option
 * 1- Normal port operation, OC0 disconnected    (TIMER0PHASE_PWM_DISCONNECTED)
 * 2- Clear OC0 on compare match when up-counting. Set OC0 on compare
	  match when down counting. (TIMER0_PHASE_PWM_NON_INVERTING_MODE)
 * 3- Set OC0 on compare match when up-counting. Clear OC0 on compare
	  match when down counting. (TIMER0_PHASE_PWM_INVERTING_MODE)
 * */
#define TIMER0_PHASE_CORRECT_PWM_MODE                                      TIMER0PHASE_PWM_DISCONNECTED

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
#define TIMER0_OVF_REQ_NO                                                  0

/*Set Compare match unit register*/
#define TIMER0_CTC_VALUE                                                   0

/*Set number of Compare match "CTC" required before the action starts*/
#define TIMER0_CTC_REQ_NO                                                  0

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
#define TIMER0_PRESCALER_MODE                                              TIMER_OFF

/*****************************************************************************************************/
/*****************************************************************************************************/
/*****************************************************************************************************/



/*****************************************************************************************************/
/******************************** Timer 1 Configuration  *********************************************/
/*****************************************************************************************************/

/*
 * Note :-
 *  option = OperationMode_Top_UpdateOfOCR1X_TOV1FlagSetOn
 *
 *  1- NORMAL__0XFFFF_IM_MAX
 *  2- PWM_PC_8_BIT_0X00FF_TOP_BOTTOM
 *  3- PWM_PC_9_BIT_0X01FF_TOP_BOTTOM
 *  4- PWM_PC_10_BIT_0X03FF_TOP_BOTTOM
 *  5- CTC_OCR1A_IM_MAX
 *  6- FPWM_8_BIT_0X00FF_TOP_TOP
 *  7- FPWM_9_BIT_0X01FF_TOP_TOP
 *  8- FPWM_10_BIT_0X03FF_TOP_TOP
 *  9- PWM_PFC_ICR1_BOTTOM_BOTTOM
 * 10- PWM_PFC_OCR1A_BOTTOM_BOTTOM
 * 11- PWM_PC_ICR1_TOP_BOTTOM
 * 12- PWM_PC_OCR1A_TOP_BOTTOM
 * 13- CTC_ICR1_IM_MAX
 * 14- FPWM_ICR1_TOP_TOP
 * 15- FPWM_OCR1A_TOP_TOP
 * */
#define TIMER1_MODE                                                        FPWM_ICR1_TOP_TOP

/******************************** Timer 1 Non-PWM OPtions ********************************************/

/*Timer 1 CTC Operation Mode on pin OC1A "Non PWM Options"
 * 1- Normal port operation, OC0 disconnected (CTC_NORMAL_MODE)
 * 2- CTC_TOGGLE_MODE
 * 3- CTC_CLEAR_MODE
 * 4- CTC_SET_MODE
 * */
#define TIMER1_OC1A_CTC_MODE                                               CTC_NORMAL_MODE

/*Timer 1 CTC Operation Mode on pin OC1B "Non PWM Options"
 * 1- Normal port operation, OC0 disconnected (CTC_NORMAL_MODE)
 * 2- CTC_TOGGLE_MODE
 * 3- CTC_CLEAR_MODE
 * 4- CTC_SET_MODE
 * */
#define TIMER1_OC1B_CTC_MODE                                               CTC_NORMAL_MODE
/*****************************************************************************************************/

/******************************** Timer 1 Fast PWM OPtions *******************************************/

/*Timer 1 FPWM Operation Mode on pin OC1A "Fast PWM Options"
 *
 * 1- Normal port operation, OC1A disconnected. (TIMER1_FPWM_DISCONNECTED)
 *
 * 2- **If Timer 1 mode = FFPWM_OCR1A_TOP_TOP
 *    Toggle OC1A on compare match OC1B is disconnected
 *    Otherwise OC1A is disconnected**          (TIMER1_FPWM_TOGGLE_OC1A_MODE)
 *
 * 3- Clear OC1A on compare match, set
 *    OC1A at TOP                               (TIMER1_FPWM_NON_INVERTING_MODE)
 *
 *
 * 4- Set OC1A on compare match, clear
      OC1A at TOP                                (TIMER1_FPWM_INVERTING_MODE)
 *
 * */
#define TIMER1_OC1A_FPWM_MODE                                             TIMER1_FPWM_NON_INVERTING_MODE

/*Timer 1 FPWM Operation Mode on pin OC1B "Non PWM Options"
 *
 * 1- Normal port operation, OC1B disconnected. (TIMER1_FPWM_DISCONNECTED)
 *
 * 2- Clear OC1B on compare match, set
 *    OC1B at TOP                               (TIMER1_FPWM_NON_INVERTING_MODE)
 *
 *
 * 3- Set OC1B on compare match, clear
      OC1B at TOP                               (TIMER1_FPWM_INVERTING_MODE)
 *
 * */
#define TIMER1_OC1B_FPWM_MODE                                             TIMER1_FPWM_NON_INVERTING_MODE
/*****************************************************************************************************/

/******************************** Timer 1 Phase Correction OPtions ***********************************/
/* Timer 1 Phase Correct PWM Operation Mode on pin OC1A "PC PWM Options"
 * 1- Normal port operation, OC1A disconnected              (TIMER1_PHASE_PWM_DISCONNECTED)
 * 2- **If Timer 1 mode = PWM_PFC_OCR1A_BOTTOM_BOTTOM or FPWM_ICR1_TOP_TOP
 *    Toggle OC1A on compare match OC1B is disconnected.
 *    Otherwise OC1A is disconnected**                      (TIMER1_PC_PWM_TOGGLE_OC1A_MODE_MODE)
 * 3- Clear OC1A on compare match when up-counting.
 *     Set OC1A on compare match when down counting.        (TIMER1_PC_PWM_NON_INVERTING_MODE)
 * 4- Set OC1A on compare match when up-counting.
 *    Clear OC1A on compare match when down-counting.       (TIMER1_PC_PWM_INVERTING_MODE)
 * */
#define TIMER1_OC1A_PC_PWM_MODE                                           TIMER1_PC_PWM_DISCONNECTED

/* Timer 1 Phase Correct PWM Operation Mode on pin OC1B "PC PWM Options"
 * 1- Normal port operation, OC1B disconnected              (TIMER1_PC_PWM_DISCONNECTED)
 * 2- Clear OC1A on compare match when up-counting.
 *     Set OC1A on compare match when down counting.        (TIMER1_PC_PWM_NON_INVERTING_MODE)
 * 3- Set OC1B on compare match when up-counting.
 *    Clear OC1B on compare match when down-counting.       (TIMER1_PC_PWM_INVERTING_MODE)
 * */
#define TIMER1_OC1B_PC_PWM_MODE                                           TIMER1_PC_PWM_DISCONNECTED
/*****************************************************************************************************/
/*Set your Timer1 OVF Value Value*/
#define TIMER1_MAX_OVF_VALUE                                              1999
/*Set Timer1 Compare Match for pin OC1A*/
#define TIMER1_CTC_OC1A_VALUE                                             999
/*Set Timer1 Compare Match for pin OC1B*/
#define TIMER1_CTC_OC1B_VALUE                                             NULL


/* Timer 1 preScaler Options
 * 1-No clock source (TIMER_OFF)
 * 2-No PreScaler (DIVIDED_BY_1)
 * 3-DIVIDED_BY_8
 * 4-DIVIDED_BY_64
 * 5-DIVIDED_BY_256
 * 6-DIVIDED_BY_1024
 * 7-External clock source on T0 pin Falling edge (T1_FALLING)
 * 8-External clock source on T0 pin Rising edge (T1_RISING)
 */
#define TIMER1_PRESCALER_MODE                                              DIVIDED_BY_8


/*****************************************************************************************************/
/*****************************************************************************************************/
/*****************************************************************************************************/






#endif
