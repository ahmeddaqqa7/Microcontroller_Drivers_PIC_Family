/* 
 * File:   application.c
 * Author: ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"

pin_config_t led_1 = {
    .port = PORTB_INDEX,
    .pin = PIN0,
    .direction = OUTPUT,
    .logic = LOW,
};


pin_config_t btn_1 = {
    .port = PORTC_INDEX,
    .pin = PIN0,
    .direction = INPUT,
    .logic = LOW,
};


Std_ReturnType ret = E_NOT_OK;
direction_t led_1_st;
logic_t btn_1_st;
uint8 port_st;
uint8 port_logic_st;


int main() {
     
    
     Application_Initialize();

    while(1){
        ret = gpio_port_read_logic(PORTD_INDEX,&port_logic_st);
        ret = gpio_port_toggle_logic(PORTD_INDEX);
        ret = gpio_port_read_logic(PORTD_INDEX,&port_logic_st);
         __delay_ms(250);

       
        
        ret = gpio_pin_read_logic(&btn_1, &btn_1_st);
        if(btn_1_st == HIGH){
            ret = gpio_pin_write_logic(&led_1, HIGH);
        }
        else{
            ret = gpio_pin_write_logic(&led_1, LOW);
        }
      
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
    ret = gpio_pin_intialize(&btn_1);
    ret = gpio_pin_intialize(&led_1);
    ret = gpio_port_direction_intialize(PORTD_INDEX, 0x00);
    ret = gpio_port_get_direction_status(PORTD_INDEX,&port_st);
    ret = gpio_port_write_logic(PORTD_INDEX, 0x55);
    ret = gpio_port_read_logic(PORTD_INDEX,&port_logic_st);
}