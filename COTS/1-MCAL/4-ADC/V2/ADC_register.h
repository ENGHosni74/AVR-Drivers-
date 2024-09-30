/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 1/2/2024      *************************/
/************************* SWC      : ADC           *************************/
/************************* VERSION  : 2.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef    ADC_REGISTER_H_
#define    ADC_REGISTER_H_



#define ADC_U8_ADMUX_REG       *((volatile u8 * ) 0x27)
#define ADC_ADMUX_REFS1           7
#define ADC_ADMUX_REFS2           6
#define ADC_ADMUX_ADLAR           5
#define ADC_ADMUX_MUX4            4
#define ADC_ADMUX_MUX3            3
#define ADC_ADMUX_MUX2            2
#define ADC_ADMUX_MUX1            1
#define ADC_ADMUX_MUX0            0





#define ADC_U8_ADCSRA_REG      *((volatile u8 * ) 0x26)
#define ADC_ADCSRA_ADEN           7
#define ADC_ADCSRA_ADSC           6
#define ADC_ADCSRA_ADATE          5
#define ADC_ADCSRA_ADIF           4
#define ADC_ADCSRA_ADIE           3
#define ADC_ADCSRA_ADPS2          2
#define ADC_ADCSRA_ADPS1          1
#define ADC_ADCSRA_ADPS0          0

 

 




#define ADC_U8_ADCH_REG        *((volatile u8 * ) 0x25)
#define ADC_U8_ADCL_REG        *((volatile u8 * ) 0x24)

#define ADC_U16_ADC_REG        *((volatile u16* ) 0x24)

#define ADC_U8_SFIOR_REG       *((volatile u8 * ) 0x50)
#define ADC_SFIOR_ADTS2           7
#define ADC_SFIOR_ADTS1           6
#define ADC_SFIOR_ADTS0           5









#endif
