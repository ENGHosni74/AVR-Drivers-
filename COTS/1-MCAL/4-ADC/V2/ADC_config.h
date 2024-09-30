/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 1/2/2024      *************************/
/************************* SWC      : ADC           *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef    ADC_CONFIG_H_
#define    ADC_CONFIG_H_



/*define your maximum time out value */
#define   ADC_U32_TIMEOUT_MAXVALUE          100000


/*VReff selection options
 1- External VReff AREF 5v   (EXTERNAL_AREF_VREFF)
 2- External VReff AVCC 5v   (EXTERNAL_AVCC_VREFF)
 3- Internal VReff 2.56v     (INTERNAL_VREFF     )
  */

#define   VReff_Mode                        EXTERNAL_AVCC_VREFF




/*Adjustment Options
 *1- Right Adjust (RIGHT_ADJUSTMENT)
 *2- Left  Adjust (LEFT_ADJUSTMENT ) */

#define   Adjustment_Mode                   RIGHT_ADJUSTMENT





/*Auto Trigger Options
 *1- Enable  Auto Trigger (ENABLE_AUTO_TRIGGER )
 *2- Disable Auto Trigger (DISABLE_AUTO_TRIGGER) */

#define   Auto_Trigger_Mode                 DISABLE_AUTO_TRIGGER


/*ADC Auto Trigger Source Options
 *1- Free Running Mood             (FREE_RUNNINGMODE             )
 *2- Analog Comparator             (ANALOG_COMPARATOR_MODE       )
 *3- External interrupt request 0  (EXTERNAL_INTERRUPT_REQUEST_0 )
 *4- Timer/Counter0 Compare Match  (TIMER0_COUNTER0_COMPARE_MATCH)
 *5- Timer/Counter0 Overflow       (TIMER0_COUNTER0_OVERFLOW     )
 *6- Timer/Counter Compare Match B (TIMER_COUNTER_COMPARE_MATCH_B)
 *7- Timer/Counter1 Overflow       (TIMER1_COUNTER1_OVERFLOW     )
 *8- Timer/Counter1 Capture Event  (TIMER1_COUNTER1_CAPTURE_EVENT) */

#define   Auto_Trigger_Source_Mode          FREE_RUNNINGMODE


/*PreScaler options
 *1- divided by 2    (DIVIDED_BY_2  )
 *2- divided by 4    (DIVIDED_BY_4  )
 *3- divided by 16   (DIVIDED_BY_16 )
 *3- divided by 32   (DIVIDED_BY_32 )
 *4- divided by 64   (DIVIDED_BY_64 )
 *5- divided by 128  (DIVIDED_BY_128) */

#define   PreScaler_Mode                    DIVIDED_BY_64









#endif
