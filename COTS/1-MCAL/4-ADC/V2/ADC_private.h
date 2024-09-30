/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 1/2/2024      *************************/
/************************* SWC      : ADC           *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef    ADC_PRIVATE_H_
#define    ADC_PRIVATE_H_



#define   ADC_ADMUX_ClRMASK                       0b11100000
#define   ADC_CHANNELS_MAXNUM                       32



/*************************************** VReff Selection options **********************************/
#define EXTERNAL_AREF_VREFF                          0
#define EXTERNAL_AVCC_VREFF                          1
#define INTERNAL_VREFF                               2
/**************************************************************************************************/


/*************************************** Left and Right Adjust options ****************************/
#define RIGHT_ADJUSTMENT                             0
#define LEFT_ADJUSTMENT                              1
/**************************************************************************************************/


/*************************************** Auto Trigger  options ***********************************/
#define ENABLE_AUTO_TRIGGER                          0
#define DISABLE_AUTO_TRIGGER                         1
/**************************************************************************************************/

/*************************************** Auto Trigger Source Options ******************************/
#define FREE_RUNNINGMODE                             0
#define ANALOG_COMPARATOR_MODE                       1
#define EXTERNAL_INTERRUPT_REQUEST_0                 2
#define TIMER0_COUNTER0_COMPARE_MATCH                3
#define TIMER0_COUNTER0_OVERFLOW                     4
#define TIMER_COUNTER_COMPARE_MATCH_B                5
#define TIMER1_COUNTER1_OVERFLOW                     6
#define TIMER1_COUNTER1_CAPTURE_EVENT                7
/**************************************************************************************************/


/*************************************** PreScaler  options ***************************************/
#define DIVIDED_BY_2                                 0
#define DIVIDED_BY_4                                 1
#define DIVIDED_BY_8                                 2
#define DIVIDED_BY_16                                3
#define DIVIDED_BY_32                                4
#define DIVIDED_BY_64                                5
#define DIVIDED_BY_128                               6
/**************************************************************************************************/


/******************************************* ADC Busy Flag States  ********************************/
#define ADC_READY                                    0
#define ADC_BUSY                                     1









#endif
