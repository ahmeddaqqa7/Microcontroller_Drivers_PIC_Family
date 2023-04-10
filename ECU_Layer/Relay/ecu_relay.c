/* 
 * File:   ecu_relay.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 11, 2023, 12:45 AM
 */


#include "ecu_relay.h"
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t *_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_write_logic(&pin_obj, HIGH);
    }
    return ret;
}
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *_relay){
    Std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_write_logic(&pin_obj, LOW);
    }
    return ret;
}
