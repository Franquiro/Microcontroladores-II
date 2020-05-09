/*
 * File:   delays.c
 * Author: fran
 *
 * Created on May 8, 2020, 7:45 PM
 */
#include <xc.h>
void delay_ms(int t);
void delay_us(int t);

void delay_ms(int t){
    while(t){
        delay_us(1000);
        t--;
    }
}


void delay_us(int t){
    char i = 15;
    while(t){
        while(i){
            Nop();
            i--;
        }
        t--;
    }
}