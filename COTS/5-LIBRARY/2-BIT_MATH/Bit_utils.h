/*
 * Bit_utils.h
 *
 *  Created on: 12 Feb 2022
 *      Author: karim
 */

#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#define SET_BIT(Reg,Bit)			((Reg) |=  (1<<(Bit)))
#define CLR_BIT(Reg,Bit)			((Reg) &= ~(1<<(Bit)))
#define GET_BIT(Reg,Bit)			(1 	   &   ((Reg)>>(Bit)))
#define RSHIFT_REG(Reg,No)			((Reg) >>= (No))
#define LSHIFT_REG(Reg,No)			((Reg) <<= (No))
#define CRSHIFT_REG(Reg,No)			((Reg) =   ((Reg)>>(No)) | ((Reg)<<(8-(No))))
#define CLSHIFT_REG(Reg,No)			((Reg) =   ((Reg)<<(No)) | ((Reg)>>(8-(No))))
#define ASSIGN_REG(Reg,Value)		((Reg) =   (Value))
#define SET_REG(Reg)				((Reg) =   (0xFF))
#define CLR_REG(Reg)				((Reg) =   (0))
#define TGL_BIT(Reg,Bit)			((Reg) ^=  (1<<(Bit)))
#define TGL_REG(Reg)				((Reg) ^=  (0xFF))
#define SET_H_NIB(Reg)				((Reg) |=  (0xF0))
#define SET_L_NIB(Reg)				((Reg) |=  (0x0F))
#define CLR_H_NIB(Reg)				((Reg) &=  (0x0F))
#define CLR_L_NIB(Reg)				((Reg) &=  (0xF0))
#define ASSIGN_H_NIB(Reg,Value)		((Reg) =   ((Reg)&(0x0F) | (((Value)&(0x0F))<<4)))
#define ASSIGN_L_NIB(Reg,Value)		((Reg) =   ((Reg)&(0xF0) | ((Value)&(0x0F))))
#define TGL_H_NIB(Reg)				((Reg) ^=  (0xF0))
#define TGL_L_NIB(Reg)				((Reg) ^=  (0x0F))
#define SWAP_NIB(Reg)				((Reg) =   ((Reg)>>4) 	 | ((Reg)<<4))

#endif /* BIT_UTILS_H_ */
