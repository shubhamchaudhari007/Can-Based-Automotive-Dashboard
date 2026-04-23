/*
 * File:   ecu1_sensor.c
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
#include<string.h>
#include "clcd.h"

unsigned short value;
unsigned int data;
unsigned char rpm[5];
char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
char ssd[4];
char key;

//unsigned char res[3][7] = {"LEFT","OFF","RIGHT"};

unsigned char ch;

unsigned short msg_id1;
unsigned char data1[5];
unsigned char len1;

unsigned int count = 0;
unsigned int count1 = 0;

unsigned short msg_id2;
unsigned char data2[7];
unsigned char len2;

uint16_t get_rpm() {
    //Implement the rpm function

    value = read_adc(CHANNEL4);


    data = (value / 10.23) * 60;


    rpm[0] = (data / 1000) + '0';
    rpm[1] = ((data / 100) % 10) + '0';
    rpm[2] = ((data / 10) % 10) + '0';
    rpm[3] = (data % 10) + '0';
    rpm[4] = '\0';

    can_transmit(RPM_MSG_ID,rpm,5);
    
    __delay_ms(80);
    
//    can_receive(&msg_id1,data1,&len1);
//    data1[len1] = '\0';
    
//    clcd_putch(data1[0],LINE1(0));
//    clcd_putch(data1[1],LINE1(1));
//    clcd_putch(data1[2],LINE1(2));
//    clcd_putch(data1[3],LINE1(3));
    //clcd_print(data1,LINE2(0));
    
//    ssd[0] = digit[data1[0] - '0'];
//    ssd[1] = digit[data1[1] - '0'];
//    ssd[2] = digit[data1[2] - '0'];
//    ssd[3] = digit[data1[3] - '0'];
//    
//    
//    //for(int i=0;i<50;i++)
//    display(ssd);
}

uint16_t get_engine_temp() {
    //Implement the engine temperature function
}

IndicatorStatus process_indicator() {
    //Implement the indicator function

    key = read_digital_keypad(STATE_CHANGE);
    
    if (key == SWITCH1) {
        ch = 'L';
    } else if (key == SWITCH3) {
        ch = 'R';
    } else if (key == SWITCH2) {
        ch = 'O';
    }
    
    can_transmit(INDICATOR_MSG_ID,&ch,1);
    
    __delay_ms(80);
    
////    can_receive(&msg_id2,data2,&len2);
////    data2[len2] = '\0';
//    
//    
////    count++;
////    count1++;
////    if(!strcmp(data2,"LEFT")){
////        if(count < 5){
////        PORTBbits.RB0 = 1;
////        PORTBbits.RB1 = 1;
////        PORTBbits.RB6 = 0;
////        PORTBbits.RB7 = 0;
////        }else if(count < 10){
////            PORTBbits.RB0 = 0;
////            PORTBbits.RB1 = 0;
////        
////        }else
////            count = 0;
////    }else if(!strcmp(data2,"OFF")){
////        PORTBbits.RB0 = 0;
////        PORTBbits.RB1 = 0;
////        PORTBbits.RB6 = 0;
////        PORTBbits.RB7 = 0;
////    }else if(!strcmp(data2,"RIGHT")){
////        if(count1 < 5){
////        PORTBbits.RB0 = 0;
////        PORTBbits.RB1 = 0;
////        PORTBbits.RB6 = 1;
////        PORTBbits.RB7 = 1;
////        }else if(count1 < 10){
////            PORTBbits.RB6 = 0;
////            PORTBbits.RB7 = 0;
////        }else
////            count1 = 0;
////    }
}