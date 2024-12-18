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
#include "string.h"
#include "stdio.h"

uint8_t dato_rx;
uint8_t flag_rx = 0;
uint8_t cont_1 = 0;
uint8_t index = 0;

char EnL1[] = "Hola HC-05";
char DisL1[] = "Adios HC-05";


char buf_rx[17];

void UART1_Receive_ISR(void)
{
   dato_rx = U1RXREG;
   buf_rx[index] = dato_rx;
   IFS0bits.U1RXIF = 0;
    index++;
    flag_rx = 1;
     
}
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  ){
    UART1_Write(cont_1 + 0x30);
    cont_1++;
    if (cont_1 == 0x0A){cont_1 = 0;}
    IFS0bits.T1IF = 0;  //Baja la bandera del timer 1
}

int main(void){
    
    
    SYSTEM_Initialize();
    while (1){
        if(flag_rx == 1){                    
            flag_rx == 0;
        } 
        char *respL1e = strstr(buf_rx, EnL1);
        char *respL1a= strstr(buf_rx, DisL1);

        if (respL1e != 0) {
            _LATD9 = 1;
            //RX_data[]="";
            index=0;
            
        } 
        if (respL1a != 0) {
            _LATD9 = 0;
            //RX_data[]="";
            index=0;
        }
     
    }

    return 1;
}
/**
 End of File
*/

