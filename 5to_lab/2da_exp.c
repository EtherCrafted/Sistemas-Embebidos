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
#include "mcc_generated_files/system.h"  //Configuraciones del MCC
#include "libpic30.h" // Libreria para el delay
uint8_t dato_rx;
uint8_t flag_rx = 0;
uint8_t cont_1 = 0;
unsigned char index = 0;

char buf_rx[800];

 unsigned char datos = 0;

 



void UART1_Receive_ISR(void)
{
   dato_rx = U1RXREG;
   buf_rx[index] = dato_rx;
   IFS0bits.U1RXIF = 0;
    index++;
    flag_rx = 1;
}

int main(void){
    
    
    SYSTEM_Initialize();
    while (1){
        cont_1++;
        __delay_ms(100); 
        
        UART1_Write(cont_1);
        if(flag_rx == 1){                    
            _LATD13 = (dato_rx & 0x01) >> 0; //bit 0x01 de  rotd
            _LATA14 = (dato_rx & 0x02) >> 1; //bit 0x02 de  rotd
            _LATA15 = (dato_rx & 0x04) >> 2; //bit 0x04 de  rotd
            _LATD10 = (dato_rx & 0x08) >> 3; //bit 0x08 de  rotd
            _LATC4  = (dato_rx & 0x10) >> 4; //bit 0x10 de  rotd
            _LATD0  = (dato_rx & 0x20) >> 5; //bit 0x20 de  rotd
            _LATB14 = (dato_rx & 0x40) >> 6; //bit 0x40 de  rotd
            _LATG13 = (dato_rx & 0x80) >> 7; //bit 0x80 de  rotd
            
            flag_rx == 0;
        } 
    }

    return 1;
}
/**
 End of File
*/

