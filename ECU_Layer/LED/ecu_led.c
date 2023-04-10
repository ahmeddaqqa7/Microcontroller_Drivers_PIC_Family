/* 
 * File:     ecu_led.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:45 PM
 */

#include "ecu_led.h"
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_write_logic(&pin_obj, HIGH);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_write_logic(&pin_obj, LOW);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}