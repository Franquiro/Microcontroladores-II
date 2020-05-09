/*
 * File:   LED_main.c
 * Author: fran
 *
 * Created on April 24, 2020, 7:17 PM
 */


#include "xc.h"
#include "p30F4013.h"

#define MIPS 30
#define CONFIG_PUERTO TRISB
#define LED LATBbits.LATB11

_FOSC(0x008101);    // Configuro el Micro
_FWDT(0x000000);    // FRC con PLL x4
_FGS(0x000003);     // Sin watchdog y sin proteccion

void delay_ms(int t);

int main(void) {
    CONFIG_PUERTO = 0xF7FF;
    while(1){
        LED = 1;
        delay_ms(500);
        LED=0;
        delay_ms(500);
    }
    return 0;
}

void delay_ms(int t){
    t=t*MIPS*100;
	while(t--);
}