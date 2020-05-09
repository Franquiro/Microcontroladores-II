/*
 * File:   UART.c
 * Author: fran
 *
 * Created on May 8, 2020, 8:15 PM
 */

#include <xc.h>
#define MIPS 30
void UART_send_string(char* texto);
void UART_send_char(char t);
void configUART();

void configUART(int baudrate){
//    U1MODE = 0xA040;
    U1MODEbits.UARTEN   = 1;
//  UNUSED
    U1MODEbits.USIDL    = 1;
//  UNUSED
//  RESERVED
    U1MODEbits.ALTIO    = 0;
//  RESERVED
//  RESERVED    
    U1MODEbits.WAKE     = 0;
    U1MODEbits.LPBACK   = 1;
    U1MODEbits.ABAUD    = 0;
//  UNUSED
//  UNUSED
    U1MODEbits.PDSEL    = 0b00;
    U1MODEbits.STSEL    = 0;

    
    
    
//    U1STA = 0x0400;
    U1STAbits.URXISEL   = 0;
//  UNUSED
//  UNUSED
//  UNUSED
    U1STAbits.UTXBRK    = 0;
    U1STAbits.UTXEN     = 1;
//  U1STAbits.UTXBF     = READ ONLY
//  U1STAbits.TRMT      = READ ONLY
    U1STAbits.URXISEL   = 0b00;
    U1STAbits.ADDEN     = 0;
//  U1STAbits.RIDLE     = READ ONLY
//  U1STAbits.PERR      = READ ONLY
//  U1STAbits.FERR      = READ ONLY
//  U1STAbits.OERR      = READ/CLEAR ONLY
//  U1STAbits.URXDA     = READ ONLY
    
    
//    BaudRate Generator
    U1BRG = MIPS/(16*baudrate) - 1;
}

void UART_send_string(char* texto){
    while(texto != NULL){
        UART_send_char(*texto);
        texto++;
    }
    UART_send_char('\r');
    UART_send_char('\n');
}

void UART_send_char(char t){
        U1TXREG = t;
}
