/*
 * File:   ADC_main.c
 * Author: fran
 *
 * Created on April 24, 2020, 10:19 PM
 */


#include "xc.h"
#include "p30F4013.h"
#include "delays.h"
#include "ADC.h"
#define MIPS 30
_FOSC(0x008101);    // Configuro el Micro
_FWDT(0x000000);    // FRC con PLL x4
_FGS(0x000003);     // Sin watchdog y sin proteccion



int main(void) {
    int valor;
    configADC(12);
    
    while(1){
        ADCON1bits.SAMP = 1;
        delay_ms(10);
        ADCON1bits.SAMP = 0;
        while(!ADCON1bits.DONE);
        valor = ADCBUF0;
        printf("Valor:\t%d\n",valor);
    }
    return 0;
}



