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
char EnM1[] = "Encender Motor 1";
char DisM1[] = "Apagar Motor 1";
char EnM2[] = "Encender Motor 2";
char DisM2[] = "Apagar Motor 2";

char RX_data[] = "";


uint8_t dato_b1_e = 0;
uint8_t dato_b1_a = 0;
uint8_t dato_b2_e = 0;
uint8_t dato_b2_a = 0;

char buf_rx[17];

void UART1_Receive_ISR(void)
{
   dato_rx = U1RXREG;
   buf_rx[index] = dato_rx;
   IFS0bits.U1RXIF = 0;
   index++;
   flag_rx = 1;
     
}
// visualizar grupo 1 
void Out_G1(uint8_t dato){
  _LATD13 = (dato & 0x01) >> 0; //bit 0x01 de  dato
  _LATA14 = (dato & 0x02) >> 1; //bit 0x02 de  dato
  _LATA15 = (dato & 0x04) >> 2; //bit 0x04 de  dato
  _LATD10 = (dato & 0x08) >> 3; //bit 0x08 de  dato
  _LATC4  = (dato & 0x10) >> 4; //bit 0x10 de  dato
  _LATD0  = (dato & 0x20) >> 5; //bit 0x20 de  dato
  _LATB14 = (dato & 0x40) >> 6; //bit 0x40 de  dato
  _LATG13 = (dato & 0x80) >> 7; //bit 0x80 de  dato
}
void Write_com(uint8_t a,char b[]){
    if (a == 0){
            for (int i = 0; i < strlen(b);i++){
                UART1_Write(b[i]);
                __delay_ms(10); 
            }
        }
}
void Read_com(uint8_t a,char b[],char c){
    char EnM1[] = "Encender Motor 1";
    char DisM1[] = "Apagar Motor 1";
    char EnM2[] = "Encender Motor 2";
    char DisM2[] = "Apagar Motor 2";
        if (b != 0) {
            if(c == EnM1){
                _LATG6 = 1;
            }
            else if(c == DisM1){
                _LATG6 = 0;
            }
            else if(c == EnM2){
                _LATG7 = 1;
            }
            else if(c == DisM2){
                _LATG7 = 0;
            }
            else{}
            a=0;
            
        } 
}


int main(void){
    
    
    SYSTEM_Initialize();
    while (1){
        dato_b1_e = PORTFbits.RF13; 
        dato_b1_a = PORTAbits.RA0; 
        dato_b2_e = PORTAbits.RA1; 
        dato_b2_a = PORTEbits.RE8; 
        Write_com(dato_b1_e,EnM1);
        Write_com(dato_b1_a,DisM1);
        Write_com(dato_b2_e,EnM2);
        Write_com(dato_b2_a,DisM2);
        //Out_G1(strlen(EnM));
//        cont_1++;
//        __delay_ms(500); 
//        
//        UART1_Write(str[cont_1]);

        char *respM1e = strstr(buf_rx, EnM1);
        if(flag_rx == 1){                    
            flag_rx == 0;
        } 
        char *respM1e = strstr(buf_rx, EnM1);
        char *respM1a= strstr(buf_rx, DisM1);
        char *respM2e = strstr(buf_rx, EnM2);
        char *respM2a = strstr(buf_rx, DisM2);

        if (respM1e != 0) {
            _LATG6 = 1;
            //RX_data[]="";
            index=0;
            
        } 
        if (respM1a != 0) {
            _LATG6 = 0;
            //RX_data[]="";
            index=0;
        }
        if (respM2e != 0) {
            _LATG7 = 1;
            //RX_data[]="";
            index=0;
            
        } 
        if (respM2a != 0) {
            _LATG7 = 0;
            //RX_data[]="";
            index=0;
        }
    }

    return 1;
}
/**
 End of File
*/

