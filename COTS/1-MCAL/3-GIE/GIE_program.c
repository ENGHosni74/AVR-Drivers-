/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 28/1/2024     *************************/
/************************* SWC      : GIE           *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef GIE_PROGRAM_C_
#define GIE_PROGRAM_C_


#include "Std_types.h"
#include "Bit_utils.h"


#include "GIE_register.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"




void GIE_voidEnable  (void)
{
	SET_BIT(GIE_SREG_REG,GIE_SREG_I);
}
void GIE_voidDisable (void)
{
	CLR_BIT(GIE_SREG_REG,GIE_SREG_I);
}

#endif
