/*
 * File:   ecu1_main.c
 * Author: HP
 *
 * Created on 1 April, 2026, 1:08 PM
 */


#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#include "ssd_display.h"
#include "digital_keypad.h"
#include "clcd.h"

int main()
{
    //call the functions
    init_adc();
    
    init_clcd();
    
    TRISB0 = 0;
    TRISB1 = 0;
    TRISB6 = 0;
    TRISB7 = 0;
    
    PORTBbits.RB0 = 0;
    PORTBbits.RB1 = 0;
    PORTBbits.RB6 = 0;
    PORTBbits.RB7 = 0;
   // init_clcd();
    
    init_digital_keypad();
    
    init_ssd_control();
    init_can();
    while(1){
        get_rpm();
        
        process_indicator();
    }
}

