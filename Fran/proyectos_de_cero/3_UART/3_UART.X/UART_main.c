/*
 * File:   UART_main.c
 * Author: fran
 *
 * Created on May 8, 2020, 8:14 PM
 */


#include "xc.h"
#include "UART.h"
#include "delays.h"
#define MIPS 30


int main(void) {
    configUART(9600);
    while(1){
        UART_send_string("HOLA\0");
        delay_ms(100);
    }
    return 0;
}
