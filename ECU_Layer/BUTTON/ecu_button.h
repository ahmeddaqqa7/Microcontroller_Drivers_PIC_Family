/* 
 * File:     ecu_button.h
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:33 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section : Includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_button_cfg.h"



/* Section : Macro Declaration  */


/* Section : Macro Function Declaration  */


/* Section : Data Type Declaration  */
typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELESED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t btn_pin;
    button_state_t btn_state;
    button_active_t btn_connection;
}button_t;

/* ----------------- Software Interfaces Declarations -----------------*/
/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */

Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_status(const button_t *btn, button_state_t *btn_status);

#endif	/* ECU_BUTTON_H */

