/* 
 * File:   application.h
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:48 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* Section : Includes */
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/BUTTON/ecu_button.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"



/* Section : Macro Declaration  */
#define _XTAL_FREQ   4000000

/* Section : Macro Function Declaration  */


/* Section : Data Type Declaration  */



/* Section : Function Declaration  */
void Application_Initialize(void);


#endif	/* APPLICATION_H */

