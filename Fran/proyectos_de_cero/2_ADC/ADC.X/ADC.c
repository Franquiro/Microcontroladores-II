/*
 * File:   ADC.c
 * Author: fran
 *
 * Created on May 8, 2020, 7:49 PM
 */

#include <xc.h>

void configADC(int bits);

void configADC(int bits){
    /* Seis registros de configuracion del ADC
     * ADCON1   | Controlan el modo
     * ADCON2   | de operacion del 
     * ADCON3   | modulo ADC
     * 
     * ADCHS    | Selecciona el canal de entrada
     * 
     * ADPCFG   | Configura el puerto como entradas analogicas o I/O digital
     * 
     * ADCSSL   | Selecciona la entrada para escanear
     */
    ADCON1 = 0xA0E0; /* ADON - U - ADSIDL - U - U - FORM - SSRC - U - ASAM - SAMP - DONE
                      *  1 - 0 - 1 - 0 - 0 - 0 - 00 - 111 - 0 - 0 - 0 - 0 - 0 */         
    ADCON2 = 0x0000;
    ADCON3 = 0x0A81;
    ADCHS  = 0x0002;
    ADPCFG = 0xFFFB; //Todos los pines digitales menos el AN2
    ADCSSL = 0x0000; // no uso funcion scan
}