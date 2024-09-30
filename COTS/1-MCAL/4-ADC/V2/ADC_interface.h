/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 1/2/2024      *************************/
/************************* SWC      : ADC           *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef    ADC_INTERFACE_H_
#define    ADC_INTERFACE_H_



/* single ended mode for ADC */
#define ADC_U8_CHANNEL_0                    0
#define ADC_U8_CHANNEL_1                    1
#define ADC_U8_CHANNEL_2                    2
#define ADC_U8_CHANNEL_3                    3
#define ADC_U8_CHANNEL_4                    4
#define ADC_U8_CHANNEL_5                    5
#define ADC_U8_CHANNEL_6                    6
#define ADC_U8_CHANNEL_7                    7
#define ADC_U8_INTERNAL_BAND_GAP_1_22V      30
#define ADC_U8_GROUND_VOLTAGE_0V            31

/* Differential mode
 * note :
 * ADC_positiveDifferintialInputChannelNum_NegativeDifferentialInputChannelNum_Gain */

#define ADC_ADC0_ADC0_10X                   8
#define ADC_ADC1_ADC0_10X                   9
#define ADC_ADC0_ADC0_200X                  10
#define ADC_ADC1_ADC0_200X                  11
#define ADC_ADC2_ADC2_10X                   12
#define ADC_ADC3_ADC2_10X                   13
#define ADC_ADC2_ADC2_200X                  14
#define ADC_ADC3_ADC2_200X                  15


#define ADC_ADC0_ADC1_1X                    16
#define ADC_ADC1_ADC1_1X                    17
#define ADC_ADC2_ADC1_1X                    18
#define ADC_ADC3_ADC1_1X                    19
#define ADC_ADC4_ADC1_1X                    20
#define ADC_ADC5_ADC1_1X                    21
#define ADC_ADC6_ADC1_1X                    22
#define ADC_ADC7_ADC1_1X                    23


#define ADC_ADC0_ADC2_1X                    24
#define ADC_ADC1_ADC2_1X                    25
#define ADC_ADC2_ADC2_1X                    26
#define ADC_ADC3_ADC2_1X                    27
#define ADC_ADC4_ADC2_1X                    28
#define ADC_ADC5_ADC2_1X                    29




void ADC_voidInit (void);

u8 ADC_u8GetReadSyncNonBlocking (u8 Copy_ChannelNum, u16 * Copy_pu16Read);

u8 ADC_u8GetReadAsync (u8 Copy_ChannelNum , void (*Copy_pfNotification) (u16 Copy_ADCValue));

u8 ADC_u8GetADCRegValue (u16 * Copy_pu16ADCValue);









#endif
