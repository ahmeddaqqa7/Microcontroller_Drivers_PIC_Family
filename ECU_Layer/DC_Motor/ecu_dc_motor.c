/* 
 * File:   ecu_dc_motor.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 12, 2023, 12:24 AM
 */


#include "ecu_dc_motor.h"



/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initailize(const dc_motor_t *_dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[0]));
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[1]));
    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), HIGH);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]), LOW);
    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]), HIGH);
    }
    return ret;
}
/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor){
    Std_ReturnType ret = E_OK;
    if(NULL == _dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]), LOW);
    }
    return ret;
}