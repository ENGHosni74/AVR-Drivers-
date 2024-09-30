/****************************************************************************/
/****************************************************************************/
/************************* NAME     : Mohamed Hosni *************************/
/************************* DATE     : 28/1/2024     *************************/
/************************* SWC      : EXTI          *************************/
/************************* VERSION  : 1.0           *************************/
/****************************************************************************/
/****************************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_



/*SENS control for INT0
 * options
 * 1- ( LOW_LEVEL_MODE )
 * 2- ( ON_CHANGE_MODE )
 * 3- ( FALL_EDGE_MODE )
 * 4- ( RISE_EDGE_MODE )
 * */

#define   INT0_SENS_MODE               FALL_EDGE_MODE



/*SENS control for INT1
 * options
 * 1- ( LOW_LEVEL_MODE )
 * 2- ( ON_CHANGE_MODE )
 * 3- ( FALL_EDGE_MODE )
 * 4- ( RISE_EDGE_MODE )
 * */

#define   INT1_SENS_MODE               RISE_EDGE_MODE


/*SENS control for INT2
 * options
 * 1- ( FALL_EDGE_MODE )
 * 2- ( RISE_EDGE_MODE )
 * */
#define   INT2_SENS_MODE               RISE_EDGE_MODE










#endif
