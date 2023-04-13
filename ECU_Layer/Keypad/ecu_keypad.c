
/* 
 * File:   ecu_keypad.c
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 13, 2023, 11:37 AM
 */

#include "ecu_keypad.h"



static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS]={
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'},
};

/**
 * 
 * @param keypad_obj
 * @return 
 */
Std_ReturnType keypad_intialize(const keypad_t *keypad_obj){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT,columns_counter = ZERO_INIT;
    if(NULL == keypad_obj){
        ret = E_NOT_OK;
    }
    else{
        for(rows_counter = ZERO_INIT; rows_counter<ECU_KEYPAD_ROWS; rows_counter++){
            ret = gpio_pin_intialize(&(keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter = ZERO_INIT; columns_counter<ECU_KEYPAD_COLUMNS; columns_counter++){
            ret = gpio_pin_direction_intialize(&(keypad_obj->keypad_column_pins[columns_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param keypad_obj
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *keypad_obj, uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT,columns_counter = ZERO_INIT, counter = ZERO_INIT;
    uint8 column_value = ZERO_INIT;
    if((NULL == keypad_obj) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
        for(rows_counter = ZERO_INIT; rows_counter<ECU_KEYPAD_ROWS; rows_counter++){
            for(counter = ZERO_INIT; counter<ECU_KEYPAD_ROWS; counter++){
                    gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[counter]), LOW);
             }
            gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[rows_counter]), HIGH);
            __delay_ms(10);
           for(columns_counter = ZERO_INIT; columns_counter<ECU_KEYPAD_COLUMNS; columns_counter++){
                 ret = gpio_pin_read_logic(&(keypad_obj->keypad_column_pins[columns_counter]), & column_value);
                 if(HIGH == column_value){
                     *value = btn_values[rows_counter][columns_counter];
                 }
            }
        }
    }
    return ret;
}