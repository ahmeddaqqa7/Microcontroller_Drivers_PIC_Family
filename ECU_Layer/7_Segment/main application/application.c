/* 
 * File:     application.c
 * Author:   ENG_Ahmed_Daqqa
 * Linkedin: https://www.linkedin.com/in/ahmed-daqqa
 * GitHub  : https://github.com/ahmeddaqqa7
 * Created on April 2, 2023, 6:11 PM
 */


#include "application.h"

pin_config_t seg1_en = {
    .port = PORTB_INDEX,
    .pin = PIN0,
    .direction = OUTPUT,
    .logic = LOW
};

pin_config_t seg2_en = {
    .port = PORTB_INDEX,
    .pin = PIN1,
    .direction = OUTPUT,
    .logic = LOW
};

segment_t segment1 ={
    .segment_pins[0].port = PORTD_INDEX,
    .segment_pins[0].pin = PIN0,
    .segment_pins[0].direction = OUTPUT,
    .segment_pins[0].logic = LOW,
    
    .segment_pins[1].port = PORTD_INDEX,
    .segment_pins[1].pin = PIN1,
    .segment_pins[1].direction = OUTPUT,
    .segment_pins[1].logic = LOW,
    
    .segment_pins[2].port = PORTD_INDEX,
    .segment_pins[2].pin = PIN2,
    .segment_pins[2].direction = OUTPUT,
    .segment_pins[2].logic = LOW,
    
    .segment_pins[3].port = PORTD_INDEX,
    .segment_pins[3].pin = PIN3,
    .segment_pins[3].direction = OUTPUT,
    .segment_pins[3].logic = LOW,
    .segment_type = SEGMENT_COMMON_ANODE,
} ;



Std_ReturnType ret = E_NOT_OK;
uint8 number = 0, count = 0;
int main() {
     Application_Initialize();

    while(1){
       
        for(count = 0; count <=50; count++){
             ret = seven_segment_write_number(&segment1, (uint8)(number%10));
        ret = gpio_pin_write_logic(&seg2_en, HIGH);
        __delay_ms(10);
        ret = gpio_pin_write_logic(&seg2_en, LOW);
        
         ret = seven_segment_write_number(&segment1, (uint8)(number/10));
        ret = gpio_pin_write_logic(&seg1_en, HIGH);
        __delay_ms(10 );
        ret = gpio_pin_write_logic(&seg1_en, LOW);
        }
        number++;
    }
    return (EXIT_SUCCESS);
}

void Application_Initialize(void){
    ret = seven_segment_intialize(&segment1);
    ret = gpio_pin_intialize(&seg1_en);
    ret = gpio_pin_intialize(&seg2_en);
}

