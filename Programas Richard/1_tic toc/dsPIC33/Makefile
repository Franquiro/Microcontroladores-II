# MPLAB IDE generated this makefile for use with GNU make.
# Project: 10005_1.mcp
# Date: Sun Apr 21 15:29:12 2019

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

10005_1.hex : 10005_1.cof
	$(HX) "10005_1.cof"

10005_1.cof : prueba_dsp.o
	$(CC) -mcpu=33FJ256GP510 "prueba_dsp.o" "C:\Program Files\Microchip\MPLAB C30\lib\libdsp-coff.a" -o"10005_1.cof" -Wl,--script="..\..\..\..\..\Program Files\Microchip\MPLAB C30\support\dsPIC33F\gld\p33FJ256GP510.gld",--defsym=__MPLAB_BUILD=1,--heap=1000,--stack=1000,-Map="10005_1.map",--report-mem

prueba_dsp.o : delays.h terminal.h clock_usart.h ../../../../../program\ files/microchip/mplab\ c30/include/time.h ../../../../../program\ files/microchip/mplab\ c30/include/math.h ../../../../../program\ files/microchip/mplab\ c30/include/stdlib.h ../../../../../Program\ Files/Microchip/MPLAB\ C30/src/dsp/include/dsp.h ../../../../../program\ files/microchip/mplab\ c30/include/string.h ../../../../../program\ files/microchip/mplab\ c30/include/yvals.h ../../../../../program\ files/microchip/mplab\ c30/include/stdio.h ../../../../../program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj256gp510.h prueba_dsp.c
	$(CC) -mcpu=33FJ256GP510 -x c -c "prueba_dsp.c" -o"prueba_dsp.o" -I"C:\Program Files\Microchip\MPLAB C30\src\dsp\include" -g -Wall

clean : 
	$(RM) "prueba_dsp.o" "10005_1.cof" "10005_1.hex"

