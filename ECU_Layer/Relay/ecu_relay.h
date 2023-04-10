/* 
 * File:   ecu_relay.h
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7 
 * Created on April 11, 2023, 12:45 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"




/* Section : Macro Declaration  */

#define RELAY_ON_STATUS    0x01U
#define RELAY_OFF_STATUS   0x00U

/* Section : Macro Function Declaration  */


/* Section : Data Type Declaration  */


typedef struct{
    uint8 relay_port : 3;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);


#endif	/* ECU_RELAY_H */

