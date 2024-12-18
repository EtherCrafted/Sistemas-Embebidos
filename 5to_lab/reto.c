/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ256GB110
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#define FCY 16000000UL
#include "mcc_generated_files/system.h"

unsigned char display_index = 0; 
const uint8_t buff_7seg[10] = {
  0x77, // 'R'
  0x79, // 'E'
  0x31, // 'T'
  0x3F, // 'O'
  0x00, // ' '
  0x66, // '4'
  0x40, // '-'
  0x7D, // 'G'
  0x40, // '-'
  0x77  // 'A'
};

void mostrar_caracter_izq(uint8_t caracter) {
    _LATD13 = (caracter & 0x01) >> 0;     //bit 0x01 de las out_deco1(decenas)
    _LATA14 = (caracter & 0x02) >> 1;     //bit 0x02 de las out_deco1(decenas)
    _LATA15 = (caracter & 0x04) >> 2;     //bit 0x04 de las out_deco1(decenas)
    _LATD10 = (caracter & 0x08) >> 3;     //bit 0x08 de las out_deco1(decenas)
    _LATC4  = (caracter & 0x10) >> 4;     //bit 0x10 de las out_deco1(decenas)
    _LATD0  = (caracter & 0x20) >> 5;     //bit 0x20 de las out_deco1(decenas)
    _LATB14 = (caracter & 0x40) >> 6;     //bit 0x40 de las out_deco1(decenas)
    _LATG13 = (caracter & 0x80) >> 7;     //bit 0x80 de las out_deco1(decenas)
}

void mostrar_caracter_der(uint8_t caracter) {
    _LATG14 = (caracter & 0x01) >> 0;     //bit 0x01 de las out_deco2(decenas)
    _LATG6  = (caracter & 0x02) >> 1;     //bit 0x02 de las out_deco2(decenas)
    _LATG7  = (caracter & 0x04) >> 2;     //bit 0x04 de las out_deco2(decenas)
    _LATG8  = (caracter & 0x08) >> 3;     //bit 0x08 de las out_deco2(decenas)
    _LATD9  = (caracter & 0x10) >> 4;     //bit 0x10 de las out_deco2(decenas)
    _LATF2  = (caracter & 0x20) >> 5;     //bit 0x20 de las out_deco2(decenas)
    _LATF4  = (caracter & 0x40) >> 6;     //bit 0x40 de las out_deco2(decenas)
    _LATF5  = (caracter & 0x80) >> 7;     //bit 0x80 de las out_deco2(decenas)
}
void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void) {

    mostrar_caracter_izq(buff_7seg[display_index]);
    mostrar_caracter_der(buff_7seg[(display_index + 1) % 9]);

    display_index++;
    if (display_index >= 9) {
        display_index = 0; 
    }

    IFS0bits.T3IF = 0; 
}

int main(void) {
    SYSTEM_Initialize();

    while (1) {
    }

    return 1;
}

/**
 End of File
*/

