/*
 * File:   main.c
 * Author: HP
 *
 * Created on 7 April, 2026, 12:00 PM
 */


#include <xc.h>
#include <stdint.h>
#include "can.h"
#include "clcd.h"
#include "msg_id.h"
#include "message_handler.h"
//#include "isr.h"
#include "timer0.h"


unsigned int sec = 0;
unsigned int count = 0;
static void init_leds() {
    TRISB = 0x08; // Set RB2 as output, RB3 as input, remaining as output
    PORTB = 0x00;
}

static void init_config(void) {
    // Initialize CLCD and CANBUS
    init_clcd();
 
    init_leds();

    // Enable Interrupts
    PEIE = 1;
    GIE = 1;
    init_timer0();
    init_can();
}

void __interrupt()ISR(){
    if(TMR0IF){
        TMR0 += 8;
        TMR0IF = 0;
        if(count++ == 20000){
            count = 0;
            sec++;
        }
    }
}

void main(void) {
    // Initialize peripherals
    init_config();

    /* ECU1 main loop */
    while (1) {
        // Read CAN Bus data and handle it
        clcd_print("SP",LINE1(0));
        clcd_print("GR",LINE1(3));
        clcd_print("RPM",LINE1(6));
        clcd_print("IN",LINE1(11));
        
        process_canbus_data();
    }

    return;
}

