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
#include "mcc_generated_files/system.h"//Configuraciones del MCC
#include "libpic30.h" // Libreria delay

uint8_t cont; //Variable contador 
uint8_t Group3; //Variable del grupo3

int main(void)
{
    SYSTEM_Initialize();// initialize the device
    while (1){
        //Si contador igual 255
        if (cont == 255){
            cont = 0; //reiniciar variable contador a 0
        }
        else{
            cont++; //Incrementar la variable contador en 1
        }
        Group3 = cont;  // Asignar el valor del contador a grupo3
        _LATF8  = (Group3 & 0x01) >> 0; //bit 0x01 del Grupo3
        _LATF13 = (Group3 & 0x02) >> 1; //bit 0x02 del Grupo3
        _LATA0  = (Group3 & 0x04) >> 2; //bit 0x04 del Grupo3
        _LATA1  = (Group3 & 0x08) >> 3; //bit 0x08 del Grupo3
        _LATE8  = (Group3 & 0x10) >> 4; //bit 0x10 del Grupo3
        _LATE9  = (Group3 & 0x20) >> 5; //bit 0x20 del Grupo3
        _LATD8  = (Group3 & 0x40) >> 6; //bit 0x40 del Grupo3
        _LATD11 = (Group3 & 0x80) >> 7; //bit 0x80 del Grupo3
        
        __delay_ms(200); //Delay para su visualizacion
    }

    return 1;
}
/**
 End of File
*/

