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
#define  FCY 16000000UL
#include "mcc_generated_files/system.h" //Configuraciones del MCC

unsigned contador = 0;  // Variable contador
unsigned decenas = 0;   // Variable decenas de contador
unsigned unidades = 0;  // Variable unidades de contador
// decodificador para un display de 7 segmentos
const  uint8_t buff_7seg[10] = {
    0x3F,   //0b0011 1111    0
    0x06,   //0b0000 0110    1
    0x5B,   //0b0101 1011    2
    0x4F,   //0b0100 1111    3
    0x66,   //0b0110 0110    4
    0x6D,   //0b0110 1101    5
    0x7D,   //0b0111 1101    6
    0x07,   //0b0000 0111    7
    0x7F,   //0b0111 1111    8
    0x6F    //0b0110 1111    9
};
// Funcion de Interrupcion del timer 3 Configurado a 500ms
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T3Interrupt (  ){
    
    uint8_t out_deco1 = buff_7seg[decenas]; // decodifica las decenas en out_deco1
    _LATD13 = (out_deco1 & 0x01) >> 0;     //bit 0x01 de las out_deco1(decenas)
    _LATA14 = (out_deco1 & 0x02) >> 1;     //bit 0x02 de las out_deco1(decenas)
    _LATA15 = (out_deco1 & 0x04) >> 2;     //bit 0x04 de las out_deco1(decenas)
    _LATD10 = (out_deco1 & 0x08) >> 3;     //bit 0x08 de las out_deco1(decenas)
    _LATC4  = (out_deco1 & 0x10) >> 4;     //bit 0x10 de las out_deco1(decenas)
    _LATD0  = (out_deco1 & 0x20) >> 5;     //bit 0x20 de las out_deco1(decenas)
    _LATB14 = (out_deco1 & 0x40) >> 6;     //bit 0x40 de las out_deco1(decenas)
    _LATG13 = (out_deco1 & 0x80) >> 7;     //bit 0x80 de las out_deco1(decenas)

    uint8_t out_deco2 = buff_7seg[unidades];  // decodifica las unidades en out_deco2
    _LATG14 = (out_deco2 & 0x01) >> 0;     //bit 0x01 de las out_deco2(decenas)
    _LATG6  = (out_deco2 & 0x02) >> 1;     //bit 0x02 de las out_deco2(decenas)
    _LATG7  = (out_deco2 & 0x04) >> 2;     //bit 0x04 de las out_deco2(decenas)
    _LATG8  = (out_deco2 & 0x08) >> 3;     //bit 0x08 de las out_deco2(decenas)
    _LATD9  = (out_deco2 & 0x10) >> 4;     //bit 0x10 de las out_deco2(decenas)
    _LATF2  = (out_deco2 & 0x20) >> 5;     //bit 0x20 de las out_deco2(decenas)
    _LATF4  = (out_deco2 & 0x40) >> 6;     //bit 0x40 de las out_deco2(decenas)
    _LATF5  = (out_deco2 & 0x80) >> 7;     //bit 0x80 de las out_deco2(decenas)
    contador++; //Incrementa el contador en 1
    IFS0bits.T3IF = 0;  //Baja la bandera del timer 3
}
int main(void){
    
    
    SYSTEM_Initialize();  // initialize the device
    while (1){
        decenas = contador / 10;    // Descomposicion en decenas
        unidades = contador % 10;   // Descomposicion en unidades
        if(contador == 100){contador =0;} //Si el contador excede a 99 reinicia contador
    }

    return 1;
}
/**
 End of File
*/

