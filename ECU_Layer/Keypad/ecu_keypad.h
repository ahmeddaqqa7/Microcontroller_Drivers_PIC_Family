/* 
 * File:   ecu_keypad.h
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 13, 2023, 11:37 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H


/* Section : Includes */
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"



/* Section : Macro Declaration  */

#define ECU_KEYPAD_ROWS        4
#define ECU_KEYPAD_COLUMNS     4

/* Section : Macro Function Declaration  */


/* Section : Data Type Declaration  */

typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_column_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/* Section : Function Declaration  */

Std_ReturnType keypad_intialize(const keypad_t *keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *keypad_obj, uint8 *value);


#endif	/* ECU_KEYPAD_H */

