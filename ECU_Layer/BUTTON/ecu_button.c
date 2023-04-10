/* 
 * File:     ecu_button.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:33 PM
 */


/* Section : Includes */

#include "ecu_button.h"

/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */

Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(btn->btn_pin));
    }
    return ret;
}

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */ 
Std_ReturnType button_read_status(const button_t *btn, button_state_t *btn_status){
    Std_ReturnType ret = E_NOT_OK;
    logic_t pin_Logic_status = LOW;
    if(NULL == btn || NULL == btn_status){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_read_logic(&(btn->btn_pin), &pin_Logic_status);
        if(BUTTON_ACTIVE_HIGH == btn->btn_connection){
            if(HIGH == pin_Logic_status){
                *btn_status = BUTTON_PRESSED;
            }
            else{
                *btn_status = BUTTON_RELESED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->btn_connection){
            if(HIGH == pin_Logic_status){
                *btn_status = BUTTON_RELESED;
            }
            else{
                *btn_status = BUTTON_PRESSED;
            }
        }
        else{
            /* Nothing */
        }
        ret = E_OK;
    }
    return ret;
}