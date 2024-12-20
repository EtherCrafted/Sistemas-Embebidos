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
#include "mcc_generated_files/system.h"
#include "libpic30.h"
unsigned dato_rx = 0;  // Variable contador
unsigned buf[1000];   // Variable decenas de contador
unsigned index = 0;  // Variable unidades de contador


void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
{
    (*UART1_RxDefaultInterruptHandler)();

    IFS0bits.U1RXIF = 0;
    dato_rx = U1RXREG;
    buf[index]=dato_rx;
    index++;
    
}


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
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T3Interrupt (  ){

    IFS0bits.T3IF = 0;
}
int main(void){
    
    
    SYSTEM_Initialize();
    while (1){
    }

    return 1;
}
/**
 End of File
*/

