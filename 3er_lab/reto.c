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

uint8_t cont = 0; //Variable contador 
uint8_t rotd = 0x80;  // Variable de rotacion a la derecha
uint8_t roti = 0x01;  // Variable de rotacion a la izquierda


void __attribute__ ( ( interrupt, no_auto_psv ) ) _T3Interrupt (  ){
    cont++;
    if (cont == 1 ){
        _LATB2 = (roti & 0x01) >> 0; //bit 0x01 de  roti
        _LATB3  = (roti & 0x02) >> 1; //bit 0x02 de  roti
        _LATB4  = (roti & 0x04) >> 2; //bit 0x04 de  roti
        _LATB5  = (roti & 0x08) >> 3; //bit 0x08 de  roti
        _LATB9  = (roti & 0x10) >> 4; //bit 0x10 de  roti
        _LATD6  = (roti & 0x20) >> 5; //bit 0x20 de  roti
        _LATD7  = (roti & 0x40) >> 6; //bit 0x40 de  roti
        _LATD12  = (roti & 0x80) >> 7; //bit 0x80 de  roti
        roti = roti << 1; // desplaza a la izquierda roti en 1 bit
        cont = 0;
        //Si el unico bit de roti "sale" de los 8 bits se reinicia a 0x01
        if(roti == 0x00){
            roti = 0x01;
            cont = 1;
            
            }  

        
    }
    else if (cont == 2){
        _LATD12  = 0;
        _LATD13 = (rotd & 0x01) >> 0; //bit 0x01 de  rotd
        _LATA14 = (rotd & 0x02) >> 1; //bit 0x02 de  rotd
        _LATA15 = (rotd & 0x04) >> 2; //bit 0x04 de  rotd
        _LATD10 = (rotd & 0x08) >> 3; //bit 0x08 de  rotd
        _LATC4  = (rotd & 0x10) >> 4; //bit 0x10 de  rotd
        _LATD0  = (rotd & 0x20) >> 5; //bit 0x20 de  rotd
        _LATB14 = (rotd & 0x40) >> 6; //bit 0x40 de  rotd
        _LATG13 = (rotd & 0x80) >> 7; //bit 0x80 de  rotd
        rotd = rotd >> 1; // desplaza a la derecha rotd en 1 bit
        cont = 1;
        //Si el unico bit de rotd "sale" de los 8 bits se reinicia a 0x80
        if(rotd == 0x00){rotd = 0x80;cont = 2;}
    }
    else if (cont == 3){
        _LATD13 = 0;
        _LATG14 = (roti & 0x01) >> 0; //bit 0x01 de  roti
        _LATG6  = (roti & 0x02) >> 1; //bit 0x02 de  roti
        _LATG7  = (roti & 0x04) >> 2; //bit 0x04 de  roti
        _LATG8  = (roti & 0x08) >> 3; //bit 0x08 de  roti
        _LATD9  = (roti & 0x10) >> 4; //bit 0x10 de  roti
        _LATF2  = (roti & 0x20) >> 5; //bit 0x20 de  roti
        _LATF4  = (roti & 0x40) >> 6; //bit 0x40 de  roti
        _LATF5  = (roti & 0x80) >> 7; //bit 0x80 de  roti
        roti = roti << 1; // desplaza a la izquierda roti en 1 bit
        cont = 2;
        //Si el unico bit de roti "sale" de los 8 bits se reinicia a 0x01
        if(roti == 0x00){roti = 0x01;cont = 3;}  
    }
    else if (cont == 4 ){
        _LATF5  = 0;
        _LATF8 = (rotd & 0x01) >> 0; //bit 0x01 de  rotd
        _LATF13 = (rotd & 0x02) >> 1; //bit 0x02 de  rotd
        _LATA0 = (rotd & 0x04) >> 2; //bit 0x04 de  rotd
        _LATA1 = (rotd & 0x08) >> 3; //bit 0x08 de  rotd
        _LATE8  = (rotd & 0x10) >> 4; //bit 0x10 de  rotd
        _LATE9  = (rotd & 0x20) >> 5; //bit 0x20 de  rotd
        _LATD8 = (rotd & 0x40) >> 6; //bit 0x40 de  rotd
        _LATD11 = (rotd & 0x80) >> 7; //bit 0x80 de  rotd
        rotd = rotd >> 1; // desplaza a la derecha rotd en 1 bit
        cont = 3;
        //Si el unico bit de rotd "sale" de los 8 bits se reinicia a 0x80
        if(rotd == 0x00){rotd = 0x80;cont = 4; }
        
    }
    else if (cont == 5){
        _LATF8 = 0;
        _LATG0 = (roti & 0x01) >> 0; //bit 0x01 de  roti
        _LATG1  = (roti & 0x02) >> 1; //bit 0x02 de  roti
        _LATF1  = (roti & 0x04) >> 2; //bit 0x04 de  roti
        _LATF0  = (roti & 0x08) >> 3; //bit 0x08 de  roti
        _LATD3  = (roti & 0x10) >> 4; //bit 0x10 de  roti
        _LATD1  = (roti & 0x20) >> 5; //bit 0x20 de  roti
        _LATA2  = (roti & 0x40) >> 6; //bit 0x40 de  roti
        _LATA3  = (roti & 0x80) >> 7; //bit 0x80 de  roti
        roti = roti << 1; // desplaza a la izquierda roti en 1 bit
        //Si el unico bit de roti "sale" de los 8 bits se reinicia a 0x01
        cont = 4;
        if(roti == 0x00){roti = 0x01;cont = 5;}  
        
    }
    else{
        _LATA3  =0; 
        cont =0;
    }
    
    IFS0bits.T3IF = 0;  
    
}
int main(void){
    SYSTEM_Initialize();  // initialize the device
    while (1){
    }
    return 1;
}
/**
 End of File
*/

