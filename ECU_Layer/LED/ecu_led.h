/* 
 * File:     ecu_led.h
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:45 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/* Section : Includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"



/* Section : Macro Declaration  */


/* Section : Macro Function Declaration  */


/* Section : Data Type Declaration  */


typedef enum{
    LED_ON,
    LED_OFF
    
}led_status_t;

typedef struct{
    uint8 port_name  : 4;
    uint8 pin        : 3;
    uint8 led_status : 1;
}led_t;

/* Section : Function Declaration  */
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);


#endif	/* ECU_LED_H */

