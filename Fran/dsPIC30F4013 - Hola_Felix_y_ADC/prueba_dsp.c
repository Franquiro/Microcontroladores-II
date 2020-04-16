/*
Prueba dsp en Dspic30f4013
incluir dsp.h y libdsp-coff.a
// en Projet properties agregar un heap de 200 0 300 bytes sino no compilara, aqui ya esta agregado 300
RS232 a 115200 y Xtal de 8 MHZ usando rutina clock_usart.h
Para habilitar ventana SIM Uart1 : Debugger ----> Setting ----> Usat1 IO  click ENABLE
*/

#define MIPS 30

//#include <p33fj256gp510.h>
#include <p30F4013.h>
#include <stdio.h>
#include <string.h>
#include <dsp.h>
#include <time.h>
//#include "clock_usart.h"
#include "terminal.h"
#include "delays.h"



// DSPIC30F4013 Configuration Bit Settings

// 'C' source line config statements

// FOSC
#pragma config FOSFPR = FRC             // Oscillator (Internal Fast RC (No change to Primary Osc Mode bits))
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
////-------------------------------------   VER !!!
//// Select Internal FRC at POR
//_FOSCSEL(FNOSC_FRC);  	// FRC Oscillator
//_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_XT);
//                         	// Clock Switching is enabled and Fail Safe Clock Monitor is disabled
//                          	// OSC2 Pin Function: OSC2 is Clock Output
//                          	// Primary Oscillator Mode: Disabled
//
//_FWDT(FWDTEN_OFF);          	// Watchdog Timer Enabled/disabled by user software
//                           	// (LPRC can be disabled by clearing SWDTEN bit in RCON register
////--------------------------------------------

//int main (void)
//
//	{
//
//	//clock_usart();
//	clock_t start, stop;
//    float prueba = 0.0;
//	static double count=0.0;
//
////	TERM_reset;	// Hyperterminal like VT100
////	TERM_BACK_black;
////	TERM_FORE_green;
////	TERM_FORE_bright;
////	TERM_clear;
////	TERM_HOME;
//
//
//
//	start = clock();
//    prueba = prueba + 1.0;
////	printf("\n\n\t\t\t ///Hola Felix en Dspic30f4013///\r\n\n");
////	Nop();
////    Nop();
//	stop = clock();
//
//
//
//	count=(stop-start)-19.0;  // 19 TCY start clock
//	printf("# TCY: %.1f\r\n\n",count);
//
//	while(1);
//
//
//
//
//
//
//
//
//
//
////
////	while(1)
////	{
////	printf("aca esta el marker !\r\n");
////	}
////	printf("\r\nstart = %ld", start);
////	printf("\r\nstop = %ld", stop);
////
////
////	while(1);	// pie final aca te quedas...
//	}

int main(void){
    int ADCValue = 0;
    ADPCFG = 0xFFFB; 	// Register 18-5: (oB1111111111111011) all PORTB = Digital;       // RB2=analog

    ADCON1 = 0x0000; 	// Register 18-1:
                // ADON=0
                // ADSIDL=0 Continue module operation in Idle mode
                // FORM 00 = Integer (DOUT = 0000 dddd dddd dddd)
                // SSRC=000 000 = Clearing SAMP bit ends sampling and starts conversión
                // ASAM=0 Sampling begins when SAMP bit set
                // SAM=  0  A/D sample/hold amplifiers are holding
                // DONE=0 Clearing this bit will not effect any operation in progress.

    // o sea:  SAMP bit = 0 ends sampling ...
    // and starts converting y luego esta en continue mode?.

    ADCHS = 0x0002; 	// Register 18-4: 
    // CHOSA=0010 Channel 0 positive input is AN2
//     CHONA=0  Channel 0 negative input is VREF-
    // aquí se usó el channel A  CHOXB todo 0

    ADCSSL = 0;		// Register 18-6: ADCSSL: A/D Input Scan Select Register
                // 0 = Skip ANx for input scan aquí se usa un solo canal

    ADCON3 = 0x0002;           // Register 18-3: 
                // SAMC=0   0 Tad
                // ADRC=0 Clock derived from system clock
                //  ADCS= 2 A/D conversión clock daría 3/2 TCY?    ver?.


    ADCON2 = 0;		// Register 18-2: 
    // VCFG=0 usara AVDD y AVSS como referencias + y ?
    // CSCNA=0 Do not scan inputs
    // BUFS =0 0  A/D is currently filling buffer 0x0-0x7, user should access 
    // data in 0x8-0xF
    // SMPI<3:0>: 0000 = Interrupts at the completion of conversion for each      // sample/convert sequence ( no se usan interrupciones en este ejemplo)
    // ALTS=0 Always use MUX A input multiplexer settings

    ADCON1bits.ADON = 1;  	// turn ADC ON,el bit de un registro se maneja individualmente    
                // como un struct


    while (1) // repeat continuously

    {
    ADCON1bits.SAMP = 1; 		// start sampling ...

    delay_ms(100); 	// for 100 mS  El tiempo de adquisición se maneja manual en // este ejemplo. Este Tad es enorme !!!!

    ADCON1bits.SAMP = 0; 		// start Converting

    while (!ADCON1bits.DONE); 	// conversion done? Espera a que DONE=1

    ADCValue = ADCBUF0; 		// yes then descargo en la varible ADCValue el ADCBUF0
    printf("ADCValue:\t%d\n",ADCValue);
    }

}









